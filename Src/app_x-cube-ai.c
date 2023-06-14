
#ifdef __cplusplus
 extern "C" {
#endif
/**
  ******************************************************************************
  * @file           : app_x-cube-ai.c
  * @brief          : AI program body
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V.
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other
  *    contributors to this software may be used to endorse or promote products
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under
  *    this license is void and will automatically terminate your rights under
  *    this license.
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
 /*
  * Description
  *   v1.0 - Minimum template to show how to use the Embedded Client API
  *          model. Only one input and one output is supported. All
  *          memory resources are allocated statically (AI_NETWORK_XX, defines
  *          are used).
  *          Re-target of the printf function is out-of-scope.
  *
  *   For more information, see the embeded documentation:
  *
  *       [1] %X_CUBE_AI_DIR%/Documentation/index.html
  *
  *   X_CUBE_AI_DIR indicates the location where the X-CUBE-AI pack is installed
  *   typical : C:\Users\<user_name>\STM32Cube\Repository\STMicroelectronics\X-CUBE-AI\6.0.0
  */
/* Includes ------------------------------------------------------------------*/
/* System headers */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "app_x-cube-ai.h"
#include "main.h"
#include "ai_datatypes_defines.h"

/* USER CODE BEGIN includes */
#include "decoder_layer.h"
/* USER CODE END includes */
/* Global AI objects */
static ai_handle network_phi = AI_HANDLE_NULL;
static ai_network_report network_phi_info;

/* Global c-array to handle the activations buffer */
AI_ALIGNED(4)
static ai_u8 activations[AI_NETWORK_PHI_DATA_ACTIVATIONS_SIZE];

/*  In the case where "--allocate-inputs" option is used, memory buffer can be
 *  used from the activations buffer. This is not mandatory.
 */
#if !defined(AI_NETWORK_PHI_INPUTS_IN_ACTIVATIONS)
/* Allocate data payload for input tensor */
AI_ALIGNED(4)
static ai_u8 in_data_s[AI_NETWORK_PHI_IN_1_SIZE_BYTES];
#endif

/*  In the case where "--allocate-outputs" option is used, memory buffer can be
 *  used from the activations buffer. This is no mandatory.
 */
#if !defined(AI_NETWORK_PHI_OUTPUTS_IN_ACTIVATIONS)
/* Allocate data payload for the output tensor */
AI_ALIGNED(4)
static ai_u8 out_data_s[AI_NETWORK_PHI_OUT_1_SIZE_BYTES];
#endif

static void ai_log_err(const ai_error err, const char *fct)
{
  /* USER CODE BEGIN log */
  if (fct)
    printf("TEMPLATE - Error (%s) - type=0x%02x code=0x%02x\r\n", fct,
        err.type, err.code);
  else
    printf("TEMPLATE - Error - type=0x%02x code=0x%02x\r\n", err.type, err.code);

  do {} while (1);
  /* USER CODE END log */
}

static int ai_boostrap(ai_handle w_addr, ai_handle act_addr)
{
  ai_error err;

  /* 1 - Create an instance of the model */
  err = ai_network_phi_create(&network_phi, AI_NETWORK_PHI_DATA_CONFIG);
  if (err.type != AI_ERROR_NONE) {
    ai_log_err(err, "ai_network_phi_create");
    return -1;
  }

  /* 2 - Initialize the instance */
  const ai_network_params params = {
      AI_NETWORK_PHI_DATA_WEIGHTS(w_addr),
      AI_NETWORK_PHI_DATA_ACTIVATIONS(act_addr) };

  if (!ai_network_phi_init(network_phi, &params)) {
      err = ai_network_phi_get_error(network_phi);
      ai_log_err(err, "ai_network_phi_init");
      return -1;
    }

  /* 3 - Retrieve the network info of the created instance */
  if (!ai_network_phi_get_info(network_phi, &network_phi_info)) {
    err = ai_network_phi_get_error(network_phi);
    ai_log_err(err, "ai_network_phi_get_error");
    ai_network_phi_destroy(network_phi);
    network_phi = AI_HANDLE_NULL;
    return -3;
  }

  return 0;
}

static int ai_run(void *data_in, void *data_out)
{
  ai_i32 batch;

  ai_buffer *ai_input = network_phi_info.inputs;
  ai_buffer *ai_output = network_phi_info.outputs;

  ai_input[0].data = AI_HANDLE_PTR(data_in);
  ai_output[0].data = AI_HANDLE_PTR(data_out);

  batch = ai_network_phi_run(network_phi, ai_input, ai_output);
  if (batch != 1) {
    ai_log_err(ai_network_phi_get_error(network_phi),
        "ai_network_phi_run");
    return -1;
  }

  return 0;
}

/* USER CODE BEGIN 2 */
int acquire_and_process_data(ai_float data[128][128][3], ai_u8 fb[120][120][3])
{
  for (uint16_t i = 0; i < 128; i++) {
    for (uint16_t j = 0; j < 128; j++) {
        for (uint8_t k = 0; k < 3; k++) {
            // Map destination pixel to source pixel
            uint16_t srcRow = i * 1;
            uint16_t srcCol = j * 1;
            
            if (srcRow>120 || srcCol>120){
              data[i][j][k] = 0.0;
            } else {
              // Copy pixel from source to destination
              data[i][j][k] = ((ai_float)fb[srcRow][srcCol][k])/255.0;
            }
        }
    }
}
  return 0;
}

ai_float decode_pose(ai_float data[56*16], ai_float box[4], ai_float keypoints[51]){
  ai_float max_val = 0.0f;
  uint32_t max_index = 0;


  for (uint32_t i = 0; i < 16; i++) {
    ai_float curr_conf=data[4*16 + i];
    if (curr_conf > max_val) {
        max_val = curr_conf;
        max_index = i;
    }
  }

  for (uint32_t j = 0; j < 4; j++) {
    box[j]=data[j*16+ max_index];
  }

  for (uint32_t j = 5; j < 56; j++) {
    keypoints[j-5]=data[j*16+ max_index];
  }

  return max_val;
}

int post_process(void * data)
{
  return 0;
}

ai_float NN_Run_Inference(ai_float box[4], ai_float keypoints[51])
{
  int res = -1;
  uint8_t *in_data = NULL;
  uint8_t *out_data = NULL;

  in_data = network_phi_info.inputs[0].data;
  out_data = network_phi_info.outputs[0].data;
// #if AI_NETWORK_PHI_INPUTS_IN_ACTIVATIONS
//     out_data = network_phi_info.outputs[0].data;
// #else
//     out_data = out_data_s;
// #endif

    if ((!in_data) || (!out_data)) {
      printf("TEMPLATE - I/O buffers are invalid\r\n");
      return;
    }

  res = acquire_and_process_data(in_data, CAMERA_888_BUFF);
  /* 2 - process the data - call inference engine */
  if (res == 0)
    res = ai_run(in_data, out_data);
  /* 3- post-process the predictions */
  ai_float conf = decode_pose(out_data, box, keypoints);


  if (res) {
    ai_error err = {AI_ERROR_INVALID_STATE, AI_ERROR_CODE_NETWORK};
    ai_log_err(err, "Process has FAILED");
  }

  return conf;
}
/* USER CODE END 2 */

/*************************************************************************
  *
  */
void MX_X_CUBE_AI_Init(void)
{
    /* USER CODE BEGIN 5 */
  printf("\r\nTEMPLATE - initialization\r\n");

  ai_boostrap(ai_network_phi_data_weights_get(), activations);
    /* USER CODE END 5 */
}

void MX_X_CUBE_AI_Process(void)
{
    /* USER CODE BEGIN 6 */
  int res = -1;
  uint8_t *in_data = NULL;
  uint8_t *out_data = NULL;

  printf("TEMPLATE - run - main loop\r\n");

  if (network_phi) {

    if ((network_phi_info.n_inputs != 1) || (network_phi_info.n_outputs != 1)) {
      ai_error err = {AI_ERROR_INVALID_PARAM, AI_ERROR_CODE_OUT_OF_RANGE};
      ai_log_err(err, "template code should be updated\r\n to support a model with multiple IO");
      return;
    }

    /* 1 - Set the I/O data buffer */

#if AI_NETWORK_PHI_INPUTS_IN_ACTIVATIONS
    in_data = network_phi_info.inputs[0].data;
#else
    in_data = in_data_s;
#endif

// #define AI_NETWORK_PHI_INPUTS_IN_ACTIVATIONS 1
out_data = network_phi_info.outputs[0].data;

// #if AI_NETWORK_PHI_INPUTS_IN_ACTIVATIONS
//     out_data = network_phi_info.outputs[0].data;
// #else
//     out_data = out_data_s;
// #endif

    if ((!in_data) || (!out_data)) {
      printf("TEMPLATE - I/O buffers are invalid\r\n");
      return;
    }

    /* 2 - main loop */
    do {
      /* 1 - acquire and pre-process input data */
      res = acquire_and_process_data(in_data, RAW_FRAMEBUFFER);
      /* 2 - process the data - call inference engine */
      if (res == 0)
        res = ai_run(in_data, out_data);
      /* 3- post-process the predictions */
      if (res == 0)
        res = post_process(out_data);
    } while (res==0);
  }

  if (res) {
    ai_error err = {AI_ERROR_INVALID_STATE, AI_ERROR_CODE_NETWORK};
    ai_log_err(err, "Process has FAILED");
  }
    /* USER CODE END 6 */
}
#ifdef __cplusplus
}
#endif
