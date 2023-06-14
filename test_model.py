import numpy as np
import tensorflow as tf

# Load the TFLite model
interpreter = tf.lite.Interpreter(model_path="best_integer_quant_noSPPF64.tflite")
interpreter.allocate_tensors()

# Get the input and output tensors
input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()

# Create an input array of ones with shape (1, 96, 96, 3)
input_data = np.zeros((1, 64, 64, 3), dtype=np.float32)

# Set the input tensor to the input data
interpreter.set_tensor(input_details[0]['index'], input_data)

# Run the model
interpreter.invoke()

# Get the output tensor and print it
output_data = interpreter.get_tensor(output_details[0]['index'])
output_data = output_data.reshape([-1])