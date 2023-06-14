import numpy as np
import cv2


# Open the file for reading
with open("hex_img.txt", "r", encoding="utf8") as f:
    lines = f.readlines()

# Convert each line to a list of hex values
hex_values = [line.strip().split()[1:] for line in lines[1:]]
# Convert the hex values to little-endian float32 values and append them to a list
float_values = []
for hex_array in hex_values:
    for i in range(0, len(hex_array) - 3, 4):
        hex_group = hex_array[i:i+4]        
        # print(hex_group)

        hex_string = "".join(hex_group[::])
        # print(hex_string)

        float_values.append(np.frombuffer(bytes.fromhex(hex_string), dtype=np.float32)[0])
        # print(float_values[-1])

# print(float_values)
# Reshape the final list into a numpy array of shape 64*64*3
final_array = np.array(float_values).reshape((64, 64, 3))
cv2.imshow("Image", final_array)

img = cv2.resize(final_array, (256, 256), interpolation=cv2.INTER_NEAREST)
cv2.imshow("Image2", img[:,:,::-1])
cv2.waitKey(0)
cv2.destroyAllWindows()

import lite_inference_tflite

final_array = cv2.resize(final_array, (96, 96), interpolation=cv2.INTER_NEAREST)

output = lite_inference_tflite.model_inference(final_array[None,...]) 
frame = lite_inference_tflite.post_process(final_array, output[0], score_threshold=0.1)
frame = cv2.resize(frame, (512, 512), interpolation=cv2.INTER_NEAREST)     
cv2.imshow('out',frame)
cv2.waitKey()