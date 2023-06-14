/* Includes ------------------------------------------------------------------*/
#include "decoder_layer.h"


ai_float ANCHORS[BOX][2]= {{0.72,1.43}, {1.12,1.09}, {1.31,2.25}, {2.37,3.50}, {4.23,5.70}}; //wider o10

static ai_float sigmoid(ai_float x){
  return 1/(1+expf(-x));
}

static void add_box(ai_float boxes[MAX_BOXES][4], ai_float scores[MAX_BOXES], ai_float xmin, ai_float ymin, ai_float xmax, ai_float ymax, ai_float score){
  if (score<scores[MAX_BOXES-1]) return;
  //check for iou>threshold and suppress/replace box
  //actually, intersection/area(new_box) is a bit faster
  ai_float area=(xmax-xmin)*(ymax-ymin);
  uint8_t new_idx=MAX_BOXES-1; //index where to start shifting places

  //eh, we paid for the full FPU, now we use it
  for(uint8_t box_id=0; box_id<MAX_BOXES; box_id++){
      if (scores[box_id]<SCORE_THRESHOLD){
        new_idx=box_id;
        break;
      }
      ai_float int_x_min=fmax(xmin,boxes[box_id][0]);
      ai_float int_x_max=fmin(xmax,boxes[box_id][2]);
      ai_float int_y_min=fmax(ymin,boxes[box_id][1]);
      ai_float int_y_max=fmin(ymax,boxes[box_id][3]);

      ai_float int_area=fmax(0, (int_x_max-int_x_min)*(int_y_max-int_y_min));

      if (int_area/area > SUPPRESS_THRESH){
        //already the best box is in place
        if (scores[box_id]>=score) return;

        //shift detections to the right, keep array ordered by score
        new_idx=box_id;
        break;
      }
  }   

  
  while (new_idx>0 && scores[new_idx]<score){
    boxes[new_idx][0]= boxes[new_idx-1][0];
    boxes[new_idx][2]= boxes[new_idx-1][2];
    boxes[new_idx][1]= boxes[new_idx-1][1];
    boxes[new_idx][3]= boxes[new_idx-1][3];
    scores[new_idx]=scores[new_idx-1];
    new_idx--;
  }
  //insert new box in the right place
  boxes[new_idx][0]=xmin;
  boxes[new_idx][1]=ymin;
  boxes[new_idx][2]=xmax;
  boxes[new_idx][3]=ymax;
  scores[new_idx]=score;
  return;
  
}

uint8_t decode_output_tensor(ai_float tensor[GRID_SZ][GRID_SZ][BOX*(5+CLASS)], ai_float boxes[MAX_BOXES][4], int labels[MAX_BOXES], ai_float scores[MAX_BOXES])
{ 
  for(uint8_t box_id=0; box_id<MAX_BOXES; box_id++){
      boxes[box_id][0]=0;
      boxes[box_id][2]=0;
      boxes[box_id][1]=0;
      boxes[box_id][3]=0;
      scores[box_id]=0;
  }
  uint8_t obj_count=0;
  ai_float out_x, out_y, out_w, out_h, xmin, ymin, xmax, ymax, obj_prob;
  for(uint8_t coord_x=0; coord_x<GRID_SZ; coord_x++){
    for(uint8_t coord_y=0; coord_y<GRID_SZ; coord_y++){
      for(uint8_t anchor_idx=0; anchor_idx<BOX; anchor_idx++){
        obj_prob=tensor[coord_y][coord_x][anchor_idx*(5+CLASS)+ 4];
        obj_prob=sigmoid(obj_prob);
        if (obj_prob>SCORE_THRESHOLD){

          //read box coordinates from output tensor
          out_x=tensor[coord_y][coord_x][anchor_idx*(5+CLASS)+ 0];
          out_y=tensor[coord_y][coord_x][anchor_idx*(5+CLASS)+ 1];
          out_w=tensor[coord_y][coord_x][anchor_idx*(5+CLASS)+ 2];
          out_h=tensor[coord_y][coord_x][anchor_idx*(5+CLASS)+ 3];

          //process coordinates
          out_x=sigmoid(out_x)+coord_x;
          out_y=sigmoid(out_y)+coord_y;
          out_w=expf(out_w)*ANCHORS[anchor_idx][0];
          out_h=expf(out_h)*ANCHORS[anchor_idx][1];

          //find corners
          xmin=(out_x - out_w/2) /GRID_SZ;
          ymin=(out_y - out_h/2) /GRID_SZ;
          xmax=(out_x + out_w/2) /GRID_SZ;
          ymax=(out_y + out_h/2) /GRID_SZ;

          //clip output in [0,1)
          if (xmin<0) xmin=0;
          if (xmax>0.99) xmax=0.99;
          if (ymin<0) ymin=0;
          if (ymax>0.99) ymax=0.99;

          //write output vector (manually, hope that it doesn't crash)
          //if (obj_count==MAX_BOXES) return obj_count-1;
          //boxes[obj_count][0]=xmin;
          //boxes[obj_count][1]=ymin;
          //boxes[obj_count][2]=xmax;
          //boxes[obj_count][3]=ymax;
          add_box(boxes, scores, xmin, ymin, xmax, ymax, obj_prob);

          //increment counter
          obj_count++;

        }
      }
    }
  }

  return obj_count;

}