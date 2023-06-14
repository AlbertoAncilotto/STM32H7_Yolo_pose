/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DECODER_LAYER_H
#define __DECODER_LAYER_H

#ifdef __cplusplus
 extern "C" {
#endif 

#include <math.h>
#include "ai_platform.h"

#define GRID_SZ 10
#define CLASS 1
#define BOX 5
#define SCORE_THRESHOLD 0.1
#define MAX_BOXES 10
#define SUPPRESS_THRESH 0.2 //iou threshold for nms

#define IMG_SIZE 120
#define NUM_CHANNELS 3
#define IMG_SIZE_AI 64


uint8_t decode_output_tensor(ai_float tensor[GRID_SZ][GRID_SZ][BOX*(5+CLASS)], ai_float boxes[MAX_BOXES][4], int labels[MAX_BOXES], ai_float scores[MAX_BOXES]);

#ifdef __cplusplus
}
#endif

#endif /* __DECODER_LAYER_H */

