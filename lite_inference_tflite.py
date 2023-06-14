import numpy as np
import cv2
import tensorflow as tf

# Load the TFLite model.
model_path = 'best_float32_96_noSPPF_small.tflite'
interpreter = tf.lite.Interpreter(model_path=model_path)
interpreter.allocate_tensors()

# Get input and output tensors.
input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()

def model_inference(input=None):
    # Set input tensor.
    interpreter.set_tensor(input_details[0]['index'], input)

    # Run inference.
    interpreter.invoke()

    # Get output tensor.
    output = interpreter.get_tensor(output_details[0]['index'])
    return output


IMG_SZ=(96,96)

sk = [15,13, 13,11, 16,14, 14,12, 11,12, 
            5,11, 6,12, 5,6, 5,7, 6,8, 7,9, 8,10, 
            1,2, 0,1, 0,2, 1,3, 2,4, 3,5, 4,6]

def preprocess_img(frame):
    img = frame[:, :, ::-1]
    img = img/255.00
    img = np.asarray(img, dtype=np.float32)
    img = np.expand_dims(img,0)
    img = img*0
    # img = img.transpose(0,3,1,2)
    return img


def single_non_max_suppression(prediction):
    argmax = np.argmax(prediction[4,:])
    x = (prediction.T)[argmax]
    print(prediction[4,:])
    print(argmax)
    box = x[:4] #Cx,Cy,w,h
    conf = x[4]
    keypts = x[5:]

    return box, conf, keypts

def post_process(img, output, score_threshold=0.1):
    box, conf, keypts = single_non_max_suppression(output)
    # for i, pred in enumerate(output):
        # keypts = smooth_pred(keypts)
    print(conf)
    plot_keypoints(img, keypts, score_threshold)
    return img


def plot_keypoints(img, keypoints, threshold=0.1):
    print(keypoints)
    for i in range(0,len(keypoints)//3):
        x = int(keypoints[3*i])
        y = int(keypoints[3*i+1])
        conf = keypoints[3*i+2]
        if conf > threshold: # Only draw the circle if confidence is above some threshold
            cv2.circle(img, (x, y), 5, (0,255,255), -1)

    for i in range(0,len(sk)//2):
        pos1 = (int(keypoints[3*sk[2*i]]), int(keypoints[3*sk[2*i]+1]))
        pos2 = (int(keypoints[3*sk[2*i+1]]), int(keypoints[3*sk[2*i+1]+1]))
        conf1 = keypoints[3*sk[2*i]+2]
        conf2 = keypoints[3*sk[2*i+1]+2]
        if conf1>threshold and conf2>threshold: # For a limb, both the keypoint confidence must be greater than 0.5
            cv2.line(img, pos1, pos2, (0,255,255), thickness=4)

keypoints_old = None
def smooth_pred(keypoints):
    global keypoints_old
    if keypoints_old is None:
        keypoints_old = keypoints.copy()
        return keypoints
    
    smoothed_keypoints = []
    for i in range(0, len(keypoints), 3):
        x_keypoint = keypoints[i]
        y_keypoint = keypoints[i+1]
        conf = keypoints[i+2]
        x_keypoint_old = keypoints_old[i]
        y_keypoint_old = keypoints_old[i+1]
        conf_old = keypoints_old[i+2]
        x_smoothed = (conf * x_keypoint + conf_old * x_keypoint_old)/(conf+conf_old)
        y_smoothed = (conf * y_keypoint + conf_old * y_keypoint_old)/(conf+conf_old)
        smoothed_keypoints.extend([x_smoothed, y_smoothed, (conf+conf_old)/2])
    keypoints_old = smoothed_keypoints
    return smoothed_keypoints

if __name__== "__main__":
    cap = cv2.VideoCapture('input_loop2.mp4')
    while True:
        frame = cv2.resize(cap.read()[1], IMG_SZ, interpolation=cv2.INTER_LINEAR)
        input_img = preprocess_img(frame)
        output = model_inference(input_img)
        # print(output)
        print(output[0][4])
        frame = post_process(frame, output[0], score_threshold=0.1)
        
        cv2.imshow('out',frame)
        cv2.waitKey(1)