/**
  ******************************************************************************
  * @file    network_phi.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Jun 14 09:13:06 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "network_phi.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



/*
#define AI_TOOLS_VERSION_MAJOR 6
#define AI_TOOLS_VERSION_MINOR 0
#define AI_TOOLS_VERSION_MICRO 0
#define AI_TOOLS_VERSION_EXTRA "RC6"

*/

/*
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 4
#define AI_TOOLS_API_VERSION_MICRO 0
*/

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network_phi
 
#undef AI_NETWORK_PHI_MODEL_SIGNATURE
#define AI_NETWORK_PHI_MODEL_SIGNATURE     "644607fd22819b675bb723b2d4ef7e9d"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Wed Jun 14 09:13:06 2023"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_PHI_N_BATCHES
#define AI_NETWORK_PHI_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array serving_default_images0_output_array;   /* Array #0 */
AI_STATIC ai_array conversion_0_output_array;   /* Array #1 */
AI_STATIC ai_array conv2d_2_output_array;   /* Array #2 */
AI_STATIC ai_array nl_3_output_array;   /* Array #3 */
AI_STATIC ai_array eltwise_4_output_array;   /* Array #4 */
AI_STATIC ai_array conv2d_6_output_array;   /* Array #5 */
AI_STATIC ai_array nl_7_output_array;   /* Array #6 */
AI_STATIC ai_array eltwise_8_output_array;   /* Array #7 */
AI_STATIC ai_array conv2d_9_output_array;   /* Array #8 */
AI_STATIC ai_array nl_10_output_array;   /* Array #9 */
AI_STATIC ai_array eltwise_11_output_array;   /* Array #10 */
AI_STATIC ai_array conv2d_13_output_array;   /* Array #11 */
AI_STATIC ai_array nl_14_output_array;   /* Array #12 */
AI_STATIC ai_array eltwise_15_output_array;   /* Array #13 */
AI_STATIC ai_array conv2d_16_output_array;   /* Array #14 */
AI_STATIC ai_array nl_17_output_array;   /* Array #15 */
AI_STATIC ai_array eltwise_18_output_array;   /* Array #16 */
AI_STATIC ai_array conv2d_20_output_array;   /* Array #17 */
AI_STATIC ai_array nl_21_output_array;   /* Array #18 */
AI_STATIC ai_array eltwise_22_output_array;   /* Array #19 */
AI_STATIC ai_array conv2d_23_output_array;   /* Array #20 */
AI_STATIC ai_array nl_24_output_array;   /* Array #21 */
AI_STATIC ai_array eltwise_25_output_array;   /* Array #22 */
AI_STATIC ai_array conv2d_27_output_array;   /* Array #23 */
AI_STATIC ai_array nl_28_output_array;   /* Array #24 */
AI_STATIC ai_array eltwise_29_output_array;   /* Array #25 */
AI_STATIC ai_array conv2d_30_output_array;   /* Array #26 */
AI_STATIC ai_array nl_31_output_array;   /* Array #27 */
AI_STATIC ai_array eltwise_32_output_array;   /* Array #28 */
AI_STATIC ai_array conv2d_50_output_array;   /* Array #29 */
AI_STATIC ai_array nl_51_output_array;   /* Array #30 */
AI_STATIC ai_array eltwise_52_output_array;   /* Array #31 */
AI_STATIC ai_array conv2d_53_output_array;   /* Array #32 */
AI_STATIC ai_array nl_54_output_array;   /* Array #33 */
AI_STATIC ai_array eltwise_55_output_array;   /* Array #34 */
AI_STATIC ai_array conv2d_56_output_array;   /* Array #35 */
AI_STATIC ai_array transpose_57_output_array;   /* Array #36 */
AI_STATIC ai_array reshape_58_fmt_output_array;   /* Array #37 */
AI_STATIC ai_array slice_75_output_array;   /* Array #38 */
AI_STATIC ai_array slice_75_fmt_output_array;   /* Array #39 */
AI_STATIC ai_array nl_76_output_array;   /* Array #40 */
AI_STATIC ai_array eltwise_77_output_array;   /* Array #41 */
AI_STATIC ai_array slice_71_output_array;   /* Array #42 */
AI_STATIC ai_array slice_71_fmt_output_array;   /* Array #43 */
AI_STATIC ai_array eltwise_72_output_array;   /* Array #44 */
AI_STATIC ai_array eltwise_73_output_array;   /* Array #45 */
AI_STATIC ai_array eltwise_74_output_array;   /* Array #46 */
AI_STATIC ai_array concat_78_output_array;   /* Array #47 */
AI_STATIC ai_array conv2d_40_output_array;   /* Array #48 */
AI_STATIC ai_array nl_41_output_array;   /* Array #49 */
AI_STATIC ai_array eltwise_42_output_array;   /* Array #50 */
AI_STATIC ai_array conv2d_43_output_array;   /* Array #51 */
AI_STATIC ai_array nl_44_output_array;   /* Array #52 */
AI_STATIC ai_array eltwise_45_output_array;   /* Array #53 */
AI_STATIC ai_array conv2d_46_output_array;   /* Array #54 */
AI_STATIC ai_array conv2d_33_output_array;   /* Array #55 */
AI_STATIC ai_array nl_34_output_array;   /* Array #56 */
AI_STATIC ai_array eltwise_35_output_array;   /* Array #57 */
AI_STATIC ai_array conv2d_36_output_array;   /* Array #58 */
AI_STATIC ai_array nl_37_output_array;   /* Array #59 */
AI_STATIC ai_array eltwise_38_output_array;   /* Array #60 */
AI_STATIC ai_array conv2d_39_output_array;   /* Array #61 */
AI_STATIC ai_array concat_47_output_array;   /* Array #62 */
AI_STATIC ai_array transpose_48_output_array;   /* Array #63 */
AI_STATIC ai_array reshape_49_fmt_output_array;   /* Array #64 */
AI_STATIC ai_array slice_68_output_array;   /* Array #65 */
AI_STATIC ai_array slice_68_fmt_output_array;   /* Array #66 */
AI_STATIC ai_array nl_69_output_array;   /* Array #67 */
AI_STATIC ai_array eltwise_70_output_array;   /* Array #68 */
AI_STATIC ai_array slice_59_output_array;   /* Array #69 */
AI_STATIC ai_array slice_59_fmt_output_array;   /* Array #70 */
AI_STATIC ai_array transpose_61_output_array;   /* Array #71 */
AI_STATIC ai_array transpose_62_output_array;   /* Array #72 */
AI_STATIC ai_array transpose_62_fmt_output_array;   /* Array #73 */
AI_STATIC ai_array nl_63_output_array;   /* Array #74 */
AI_STATIC ai_array nl_63_fmt_output_array;   /* Array #75 */
AI_STATIC ai_array conv2d_64_output_array;   /* Array #76 */
AI_STATIC ai_array reshape_65_fmt_output_array;   /* Array #77 */
AI_STATIC ai_array slice_80_output_array;   /* Array #78 */
AI_STATIC ai_array slice_80_fmt_output_array;   /* Array #79 */
AI_STATIC ai_array eltwise_81_output_array;   /* Array #80 */
AI_STATIC ai_array slice_66_output_array;   /* Array #81 */
AI_STATIC ai_array slice_66_fmt_output_array;   /* Array #82 */
AI_STATIC ai_array eltwise_67_output_array;   /* Array #83 */
AI_STATIC ai_array eltwise_84_output_array;   /* Array #84 */
AI_STATIC ai_array eltwise_82_output_array;   /* Array #85 */
AI_STATIC ai_array eltwise_83_output_array;   /* Array #86 */
AI_STATIC ai_array concat_85_output_array;   /* Array #87 */
AI_STATIC ai_array eltwise_86_output_array;   /* Array #88 */
AI_STATIC ai_array concat_87_output_array;   /* Array #89 */
AI_STATIC ai_array conversion_88_output_array;   /* Array #90 */
AI_STATIC ai_array model_2_tfmathmultiply_58_Mul_y_array;   /* Array #91 */
AI_STATIC ai_array model_2_tfmathdivide_truedivConst_9_array;   /* Array #92 */
AI_STATIC ai_array Const_12_array;   /* Array #93 */
AI_STATIC ai_array model_2_tfmathmultiply_49_Mul_y_array;   /* Array #94 */
AI_STATIC ai_array Const_15_array;   /* Array #95 */
AI_STATIC ai_array Const_20_array;   /* Array #96 */
AI_STATIC ai_array Const_8_array;   /* Array #97 */
AI_STATIC ai_array Const_13_array;   /* Array #98 */
AI_STATIC ai_array conv2d_2_weights_array;   /* Array #99 */
AI_STATIC ai_array conv2d_2_bias_array;   /* Array #100 */
AI_STATIC ai_array conv2d_6_weights_array;   /* Array #101 */
AI_STATIC ai_array conv2d_6_bias_array;   /* Array #102 */
AI_STATIC ai_array conv2d_9_weights_array;   /* Array #103 */
AI_STATIC ai_array conv2d_9_bias_array;   /* Array #104 */
AI_STATIC ai_array conv2d_13_weights_array;   /* Array #105 */
AI_STATIC ai_array conv2d_13_bias_array;   /* Array #106 */
AI_STATIC ai_array conv2d_16_weights_array;   /* Array #107 */
AI_STATIC ai_array conv2d_16_bias_array;   /* Array #108 */
AI_STATIC ai_array conv2d_20_weights_array;   /* Array #109 */
AI_STATIC ai_array conv2d_20_bias_array;   /* Array #110 */
AI_STATIC ai_array conv2d_23_weights_array;   /* Array #111 */
AI_STATIC ai_array conv2d_23_bias_array;   /* Array #112 */
AI_STATIC ai_array conv2d_27_weights_array;   /* Array #113 */
AI_STATIC ai_array conv2d_27_bias_array;   /* Array #114 */
AI_STATIC ai_array conv2d_30_weights_array;   /* Array #115 */
AI_STATIC ai_array conv2d_30_bias_array;   /* Array #116 */
AI_STATIC ai_array conv2d_50_weights_array;   /* Array #117 */
AI_STATIC ai_array conv2d_50_bias_array;   /* Array #118 */
AI_STATIC ai_array conv2d_53_weights_array;   /* Array #119 */
AI_STATIC ai_array conv2d_53_bias_array;   /* Array #120 */
AI_STATIC ai_array conv2d_56_weights_array;   /* Array #121 */
AI_STATIC ai_array conv2d_56_bias_array;   /* Array #122 */
AI_STATIC ai_array conv2d_40_weights_array;   /* Array #123 */
AI_STATIC ai_array conv2d_40_bias_array;   /* Array #124 */
AI_STATIC ai_array conv2d_43_weights_array;   /* Array #125 */
AI_STATIC ai_array conv2d_43_bias_array;   /* Array #126 */
AI_STATIC ai_array conv2d_46_weights_array;   /* Array #127 */
AI_STATIC ai_array conv2d_46_bias_array;   /* Array #128 */
AI_STATIC ai_array conv2d_33_weights_array;   /* Array #129 */
AI_STATIC ai_array conv2d_33_bias_array;   /* Array #130 */
AI_STATIC ai_array conv2d_36_weights_array;   /* Array #131 */
AI_STATIC ai_array conv2d_36_bias_array;   /* Array #132 */
AI_STATIC ai_array conv2d_39_weights_array;   /* Array #133 */
AI_STATIC ai_array conv2d_39_bias_array;   /* Array #134 */
AI_STATIC ai_array conv2d_64_weights_array;   /* Array #135 */
AI_STATIC ai_array conv2d_64_bias_array;   /* Array #136 */
AI_STATIC ai_array conv2d_2_scratch0_array;   /* Array #137 */
AI_STATIC ai_array conv2d_6_scratch0_array;   /* Array #138 */
AI_STATIC ai_array conv2d_9_scratch0_array;   /* Array #139 */
AI_STATIC ai_array conv2d_13_scratch0_array;   /* Array #140 */
AI_STATIC ai_array conv2d_16_scratch0_array;   /* Array #141 */
AI_STATIC ai_array conv2d_20_scratch0_array;   /* Array #142 */
AI_STATIC ai_array conv2d_23_scratch0_array;   /* Array #143 */
AI_STATIC ai_array conv2d_27_scratch0_array;   /* Array #144 */
AI_STATIC ai_array conv2d_30_scratch0_array;   /* Array #145 */
AI_STATIC ai_array conv2d_50_scratch0_array;   /* Array #146 */
AI_STATIC ai_array conv2d_53_scratch0_array;   /* Array #147 */
AI_STATIC ai_array conv2d_56_scratch0_array;   /* Array #148 */
AI_STATIC ai_array conv2d_40_scratch0_array;   /* Array #149 */
AI_STATIC ai_array conv2d_43_scratch0_array;   /* Array #150 */
AI_STATIC ai_array conv2d_46_scratch0_array;   /* Array #151 */
AI_STATIC ai_array conv2d_33_scratch0_array;   /* Array #152 */
AI_STATIC ai_array conv2d_36_scratch0_array;   /* Array #153 */
AI_STATIC ai_array conv2d_39_scratch0_array;   /* Array #154 */
AI_STATIC ai_array conv2d_64_scratch0_array;   /* Array #155 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor serving_default_images0_output;   /* Tensor #0 */
AI_STATIC ai_tensor conversion_0_output;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_2_output;   /* Tensor #2 */
AI_STATIC ai_tensor nl_3_output;   /* Tensor #3 */
AI_STATIC ai_tensor eltwise_4_output;   /* Tensor #4 */
AI_STATIC ai_tensor conv2d_6_output;   /* Tensor #5 */
AI_STATIC ai_tensor nl_7_output;   /* Tensor #6 */
AI_STATIC ai_tensor eltwise_8_output;   /* Tensor #7 */
AI_STATIC ai_tensor conv2d_9_output;   /* Tensor #8 */
AI_STATIC ai_tensor nl_10_output;   /* Tensor #9 */
AI_STATIC ai_tensor eltwise_11_output;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_13_output;   /* Tensor #11 */
AI_STATIC ai_tensor nl_14_output;   /* Tensor #12 */
AI_STATIC ai_tensor eltwise_15_output;   /* Tensor #13 */
AI_STATIC ai_tensor conv2d_16_output;   /* Tensor #14 */
AI_STATIC ai_tensor nl_17_output;   /* Tensor #15 */
AI_STATIC ai_tensor eltwise_18_output;   /* Tensor #16 */
AI_STATIC ai_tensor conv2d_20_output;   /* Tensor #17 */
AI_STATIC ai_tensor nl_21_output;   /* Tensor #18 */
AI_STATIC ai_tensor eltwise_22_output;   /* Tensor #19 */
AI_STATIC ai_tensor conv2d_23_output;   /* Tensor #20 */
AI_STATIC ai_tensor nl_24_output;   /* Tensor #21 */
AI_STATIC ai_tensor eltwise_25_output;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_27_output;   /* Tensor #23 */
AI_STATIC ai_tensor nl_28_output;   /* Tensor #24 */
AI_STATIC ai_tensor eltwise_29_output;   /* Tensor #25 */
AI_STATIC ai_tensor conv2d_30_output;   /* Tensor #26 */
AI_STATIC ai_tensor nl_31_output;   /* Tensor #27 */
AI_STATIC ai_tensor eltwise_32_output;   /* Tensor #28 */
AI_STATIC ai_tensor conv2d_50_output;   /* Tensor #29 */
AI_STATIC ai_tensor nl_51_output;   /* Tensor #30 */
AI_STATIC ai_tensor eltwise_52_output;   /* Tensor #31 */
AI_STATIC ai_tensor conv2d_53_output;   /* Tensor #32 */
AI_STATIC ai_tensor nl_54_output;   /* Tensor #33 */
AI_STATIC ai_tensor eltwise_55_output;   /* Tensor #34 */
AI_STATIC ai_tensor conv2d_56_output;   /* Tensor #35 */
AI_STATIC ai_tensor transpose_57_output;   /* Tensor #36 */
AI_STATIC ai_tensor reshape_58_fmt_output;   /* Tensor #37 */
AI_STATIC ai_tensor reshape_58_fmt_output0;   /* Tensor #38 */
AI_STATIC ai_tensor slice_75_output;   /* Tensor #39 */
AI_STATIC ai_tensor slice_75_fmt_output;   /* Tensor #40 */
AI_STATIC ai_tensor nl_76_output;   /* Tensor #41 */
AI_STATIC ai_tensor eltwise_77_output;   /* Tensor #42 */
AI_STATIC ai_tensor slice_71_output;   /* Tensor #43 */
AI_STATIC ai_tensor slice_71_fmt_output;   /* Tensor #44 */
AI_STATIC ai_tensor eltwise_72_output;   /* Tensor #45 */
AI_STATIC ai_tensor eltwise_73_output;   /* Tensor #46 */
AI_STATIC ai_tensor eltwise_74_output;   /* Tensor #47 */
AI_STATIC ai_tensor concat_78_output;   /* Tensor #48 */
AI_STATIC ai_tensor concat_78_output0;   /* Tensor #49 */
AI_STATIC ai_tensor conv2d_40_output;   /* Tensor #50 */
AI_STATIC ai_tensor nl_41_output;   /* Tensor #51 */
AI_STATIC ai_tensor eltwise_42_output;   /* Tensor #52 */
AI_STATIC ai_tensor conv2d_43_output;   /* Tensor #53 */
AI_STATIC ai_tensor nl_44_output;   /* Tensor #54 */
AI_STATIC ai_tensor eltwise_45_output;   /* Tensor #55 */
AI_STATIC ai_tensor conv2d_46_output;   /* Tensor #56 */
AI_STATIC ai_tensor conv2d_33_output;   /* Tensor #57 */
AI_STATIC ai_tensor nl_34_output;   /* Tensor #58 */
AI_STATIC ai_tensor eltwise_35_output;   /* Tensor #59 */
AI_STATIC ai_tensor conv2d_36_output;   /* Tensor #60 */
AI_STATIC ai_tensor nl_37_output;   /* Tensor #61 */
AI_STATIC ai_tensor eltwise_38_output;   /* Tensor #62 */
AI_STATIC ai_tensor conv2d_39_output;   /* Tensor #63 */
AI_STATIC ai_tensor concat_47_output;   /* Tensor #64 */
AI_STATIC ai_tensor transpose_48_output;   /* Tensor #65 */
AI_STATIC ai_tensor reshape_49_fmt_output;   /* Tensor #66 */
AI_STATIC ai_tensor reshape_49_fmt_output0;   /* Tensor #67 */
AI_STATIC ai_tensor slice_68_output;   /* Tensor #68 */
AI_STATIC ai_tensor slice_68_fmt_output;   /* Tensor #69 */
AI_STATIC ai_tensor nl_69_output;   /* Tensor #70 */
AI_STATIC ai_tensor eltwise_70_output;   /* Tensor #71 */
AI_STATIC ai_tensor slice_59_output;   /* Tensor #72 */
AI_STATIC ai_tensor slice_59_fmt_output;   /* Tensor #73 */
AI_STATIC ai_tensor slice_59_fmt_output0;   /* Tensor #74 */
AI_STATIC ai_tensor transpose_61_output;   /* Tensor #75 */
AI_STATIC ai_tensor transpose_62_output;   /* Tensor #76 */
AI_STATIC ai_tensor transpose_62_fmt_output;   /* Tensor #77 */
AI_STATIC ai_tensor nl_63_output;   /* Tensor #78 */
AI_STATIC ai_tensor nl_63_fmt_output;   /* Tensor #79 */
AI_STATIC ai_tensor conv2d_64_output;   /* Tensor #80 */
AI_STATIC ai_tensor reshape_65_fmt_output;   /* Tensor #81 */
AI_STATIC ai_tensor reshape_65_fmt_output0;   /* Tensor #82 */
AI_STATIC ai_tensor slice_80_output;   /* Tensor #83 */
AI_STATIC ai_tensor slice_80_fmt_output;   /* Tensor #84 */
AI_STATIC ai_tensor eltwise_81_output;   /* Tensor #85 */
AI_STATIC ai_tensor slice_66_output;   /* Tensor #86 */
AI_STATIC ai_tensor slice_66_fmt_output;   /* Tensor #87 */
AI_STATIC ai_tensor eltwise_67_output;   /* Tensor #88 */
AI_STATIC ai_tensor eltwise_84_output;   /* Tensor #89 */
AI_STATIC ai_tensor eltwise_82_output;   /* Tensor #90 */
AI_STATIC ai_tensor eltwise_83_output;   /* Tensor #91 */
AI_STATIC ai_tensor concat_85_output;   /* Tensor #92 */
AI_STATIC ai_tensor eltwise_86_output;   /* Tensor #93 */
AI_STATIC ai_tensor concat_87_output;   /* Tensor #94 */
AI_STATIC ai_tensor conversion_88_output;   /* Tensor #95 */
AI_STATIC ai_tensor model_2_tfmathmultiply_58_Mul_y;   /* Tensor #96 */
AI_STATIC ai_tensor model_2_tfmathdivide_truedivConst_9;   /* Tensor #97 */
AI_STATIC ai_tensor Const_12;   /* Tensor #98 */
AI_STATIC ai_tensor model_2_tfmathmultiply_49_Mul_y;   /* Tensor #99 */
AI_STATIC ai_tensor Const_15;   /* Tensor #100 */
AI_STATIC ai_tensor Const_20;   /* Tensor #101 */
AI_STATIC ai_tensor Const_8;   /* Tensor #102 */
AI_STATIC ai_tensor Const_13;   /* Tensor #103 */
AI_STATIC ai_tensor conv2d_2_weights;   /* Tensor #104 */
AI_STATIC ai_tensor conv2d_2_bias;   /* Tensor #105 */
AI_STATIC ai_tensor conv2d_6_weights;   /* Tensor #106 */
AI_STATIC ai_tensor conv2d_6_bias;   /* Tensor #107 */
AI_STATIC ai_tensor conv2d_9_weights;   /* Tensor #108 */
AI_STATIC ai_tensor conv2d_9_bias;   /* Tensor #109 */
AI_STATIC ai_tensor conv2d_13_weights;   /* Tensor #110 */
AI_STATIC ai_tensor conv2d_13_bias;   /* Tensor #111 */
AI_STATIC ai_tensor conv2d_16_weights;   /* Tensor #112 */
AI_STATIC ai_tensor conv2d_16_bias;   /* Tensor #113 */
AI_STATIC ai_tensor conv2d_20_weights;   /* Tensor #114 */
AI_STATIC ai_tensor conv2d_20_bias;   /* Tensor #115 */
AI_STATIC ai_tensor conv2d_23_weights;   /* Tensor #116 */
AI_STATIC ai_tensor conv2d_23_bias;   /* Tensor #117 */
AI_STATIC ai_tensor conv2d_27_weights;   /* Tensor #118 */
AI_STATIC ai_tensor conv2d_27_bias;   /* Tensor #119 */
AI_STATIC ai_tensor conv2d_30_weights;   /* Tensor #120 */
AI_STATIC ai_tensor conv2d_30_bias;   /* Tensor #121 */
AI_STATIC ai_tensor conv2d_50_weights;   /* Tensor #122 */
AI_STATIC ai_tensor conv2d_50_bias;   /* Tensor #123 */
AI_STATIC ai_tensor conv2d_53_weights;   /* Tensor #124 */
AI_STATIC ai_tensor conv2d_53_bias;   /* Tensor #125 */
AI_STATIC ai_tensor conv2d_56_weights;   /* Tensor #126 */
AI_STATIC ai_tensor conv2d_56_bias;   /* Tensor #127 */
AI_STATIC ai_tensor conv2d_40_weights;   /* Tensor #128 */
AI_STATIC ai_tensor conv2d_40_bias;   /* Tensor #129 */
AI_STATIC ai_tensor conv2d_43_weights;   /* Tensor #130 */
AI_STATIC ai_tensor conv2d_43_bias;   /* Tensor #131 */
AI_STATIC ai_tensor conv2d_46_weights;   /* Tensor #132 */
AI_STATIC ai_tensor conv2d_46_bias;   /* Tensor #133 */
AI_STATIC ai_tensor conv2d_33_weights;   /* Tensor #134 */
AI_STATIC ai_tensor conv2d_33_bias;   /* Tensor #135 */
AI_STATIC ai_tensor conv2d_36_weights;   /* Tensor #136 */
AI_STATIC ai_tensor conv2d_36_bias;   /* Tensor #137 */
AI_STATIC ai_tensor conv2d_39_weights;   /* Tensor #138 */
AI_STATIC ai_tensor conv2d_39_bias;   /* Tensor #139 */
AI_STATIC ai_tensor conv2d_64_weights;   /* Tensor #140 */
AI_STATIC ai_tensor conv2d_64_bias;   /* Tensor #141 */
AI_STATIC ai_tensor conv2d_2_scratch0;   /* Tensor #142 */
AI_STATIC ai_tensor conv2d_6_scratch0;   /* Tensor #143 */
AI_STATIC ai_tensor conv2d_9_scratch0;   /* Tensor #144 */
AI_STATIC ai_tensor conv2d_13_scratch0;   /* Tensor #145 */
AI_STATIC ai_tensor conv2d_16_scratch0;   /* Tensor #146 */
AI_STATIC ai_tensor conv2d_20_scratch0;   /* Tensor #147 */
AI_STATIC ai_tensor conv2d_23_scratch0;   /* Tensor #148 */
AI_STATIC ai_tensor conv2d_27_scratch0;   /* Tensor #149 */
AI_STATIC ai_tensor conv2d_30_scratch0;   /* Tensor #150 */
AI_STATIC ai_tensor conv2d_50_scratch0;   /* Tensor #151 */
AI_STATIC ai_tensor conv2d_53_scratch0;   /* Tensor #152 */
AI_STATIC ai_tensor conv2d_56_scratch0;   /* Tensor #153 */
AI_STATIC ai_tensor conv2d_40_scratch0;   /* Tensor #154 */
AI_STATIC ai_tensor conv2d_43_scratch0;   /* Tensor #155 */
AI_STATIC ai_tensor conv2d_46_scratch0;   /* Tensor #156 */
AI_STATIC ai_tensor conv2d_33_scratch0;   /* Tensor #157 */
AI_STATIC ai_tensor conv2d_36_scratch0;   /* Tensor #158 */
AI_STATIC ai_tensor conv2d_39_scratch0;   /* Tensor #159 */
AI_STATIC ai_tensor conv2d_64_scratch0;   /* Tensor #160 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conversion_0_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_2_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain nl_3_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain eltwise_4_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain conv2d_6_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain nl_7_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain eltwise_8_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain conv2d_9_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain nl_10_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain eltwise_11_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain conv2d_13_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain nl_14_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain eltwise_15_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain conv2d_16_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain nl_17_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain eltwise_18_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain conv2d_20_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain nl_21_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain eltwise_22_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain conv2d_23_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain nl_24_chain;   /* Chain #20 */
AI_STATIC_CONST ai_tensor_chain eltwise_25_chain;   /* Chain #21 */
AI_STATIC_CONST ai_tensor_chain conv2d_27_chain;   /* Chain #22 */
AI_STATIC_CONST ai_tensor_chain nl_28_chain;   /* Chain #23 */
AI_STATIC_CONST ai_tensor_chain eltwise_29_chain;   /* Chain #24 */
AI_STATIC_CONST ai_tensor_chain conv2d_30_chain;   /* Chain #25 */
AI_STATIC_CONST ai_tensor_chain nl_31_chain;   /* Chain #26 */
AI_STATIC_CONST ai_tensor_chain eltwise_32_chain;   /* Chain #27 */
AI_STATIC_CONST ai_tensor_chain conv2d_50_chain;   /* Chain #28 */
AI_STATIC_CONST ai_tensor_chain nl_51_chain;   /* Chain #29 */
AI_STATIC_CONST ai_tensor_chain eltwise_52_chain;   /* Chain #30 */
AI_STATIC_CONST ai_tensor_chain conv2d_53_chain;   /* Chain #31 */
AI_STATIC_CONST ai_tensor_chain nl_54_chain;   /* Chain #32 */
AI_STATIC_CONST ai_tensor_chain eltwise_55_chain;   /* Chain #33 */
AI_STATIC_CONST ai_tensor_chain conv2d_56_chain;   /* Chain #34 */
AI_STATIC_CONST ai_tensor_chain transpose_57_chain;   /* Chain #35 */
AI_STATIC_CONST ai_tensor_chain reshape_58_fmt_chain;   /* Chain #36 */
AI_STATIC_CONST ai_tensor_chain slice_75_chain;   /* Chain #37 */
AI_STATIC_CONST ai_tensor_chain slice_75_fmt_chain;   /* Chain #38 */
AI_STATIC_CONST ai_tensor_chain nl_76_chain;   /* Chain #39 */
AI_STATIC_CONST ai_tensor_chain eltwise_77_chain;   /* Chain #40 */
AI_STATIC_CONST ai_tensor_chain slice_71_chain;   /* Chain #41 */
AI_STATIC_CONST ai_tensor_chain slice_71_fmt_chain;   /* Chain #42 */
AI_STATIC_CONST ai_tensor_chain eltwise_72_chain;   /* Chain #43 */
AI_STATIC_CONST ai_tensor_chain eltwise_73_chain;   /* Chain #44 */
AI_STATIC_CONST ai_tensor_chain eltwise_74_chain;   /* Chain #45 */
AI_STATIC_CONST ai_tensor_chain concat_78_chain;   /* Chain #46 */
AI_STATIC_CONST ai_tensor_chain conv2d_40_chain;   /* Chain #47 */
AI_STATIC_CONST ai_tensor_chain nl_41_chain;   /* Chain #48 */
AI_STATIC_CONST ai_tensor_chain eltwise_42_chain;   /* Chain #49 */
AI_STATIC_CONST ai_tensor_chain conv2d_43_chain;   /* Chain #50 */
AI_STATIC_CONST ai_tensor_chain nl_44_chain;   /* Chain #51 */
AI_STATIC_CONST ai_tensor_chain eltwise_45_chain;   /* Chain #52 */
AI_STATIC_CONST ai_tensor_chain conv2d_46_chain;   /* Chain #53 */
AI_STATIC_CONST ai_tensor_chain conv2d_33_chain;   /* Chain #54 */
AI_STATIC_CONST ai_tensor_chain nl_34_chain;   /* Chain #55 */
AI_STATIC_CONST ai_tensor_chain eltwise_35_chain;   /* Chain #56 */
AI_STATIC_CONST ai_tensor_chain conv2d_36_chain;   /* Chain #57 */
AI_STATIC_CONST ai_tensor_chain nl_37_chain;   /* Chain #58 */
AI_STATIC_CONST ai_tensor_chain eltwise_38_chain;   /* Chain #59 */
AI_STATIC_CONST ai_tensor_chain conv2d_39_chain;   /* Chain #60 */
AI_STATIC_CONST ai_tensor_chain concat_47_chain;   /* Chain #61 */
AI_STATIC_CONST ai_tensor_chain transpose_48_chain;   /* Chain #62 */
AI_STATIC_CONST ai_tensor_chain reshape_49_fmt_chain;   /* Chain #63 */
AI_STATIC_CONST ai_tensor_chain slice_68_chain;   /* Chain #64 */
AI_STATIC_CONST ai_tensor_chain slice_68_fmt_chain;   /* Chain #65 */
AI_STATIC_CONST ai_tensor_chain nl_69_chain;   /* Chain #66 */
AI_STATIC_CONST ai_tensor_chain eltwise_70_chain;   /* Chain #67 */
AI_STATIC_CONST ai_tensor_chain slice_59_chain;   /* Chain #68 */
AI_STATIC_CONST ai_tensor_chain slice_59_fmt_chain;   /* Chain #69 */
AI_STATIC_CONST ai_tensor_chain transpose_61_chain;   /* Chain #70 */
AI_STATIC_CONST ai_tensor_chain transpose_62_chain;   /* Chain #71 */
AI_STATIC_CONST ai_tensor_chain transpose_62_fmt_chain;   /* Chain #72 */
AI_STATIC_CONST ai_tensor_chain nl_63_chain;   /* Chain #73 */
AI_STATIC_CONST ai_tensor_chain nl_63_fmt_chain;   /* Chain #74 */
AI_STATIC_CONST ai_tensor_chain conv2d_64_chain;   /* Chain #75 */
AI_STATIC_CONST ai_tensor_chain reshape_65_fmt_chain;   /* Chain #76 */
AI_STATIC_CONST ai_tensor_chain slice_80_chain;   /* Chain #77 */
AI_STATIC_CONST ai_tensor_chain slice_80_fmt_chain;   /* Chain #78 */
AI_STATIC_CONST ai_tensor_chain eltwise_81_chain;   /* Chain #79 */
AI_STATIC_CONST ai_tensor_chain slice_66_chain;   /* Chain #80 */
AI_STATIC_CONST ai_tensor_chain slice_66_fmt_chain;   /* Chain #81 */
AI_STATIC_CONST ai_tensor_chain eltwise_67_chain;   /* Chain #82 */
AI_STATIC_CONST ai_tensor_chain eltwise_84_chain;   /* Chain #83 */
AI_STATIC_CONST ai_tensor_chain eltwise_82_chain;   /* Chain #84 */
AI_STATIC_CONST ai_tensor_chain eltwise_83_chain;   /* Chain #85 */
AI_STATIC_CONST ai_tensor_chain concat_85_chain;   /* Chain #86 */
AI_STATIC_CONST ai_tensor_chain eltwise_86_chain;   /* Chain #87 */
AI_STATIC_CONST ai_tensor_chain concat_87_chain;   /* Chain #88 */
AI_STATIC_CONST ai_tensor_chain conversion_88_chain;   /* Chain #89 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_nl conversion_0_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d conv2d_2_layer; /* Layer #1 */
AI_STATIC ai_layer_nl nl_3_layer; /* Layer #2 */
AI_STATIC ai_layer_eltwise_integer eltwise_4_layer; /* Layer #3 */
AI_STATIC ai_layer_conv2d conv2d_6_layer; /* Layer #4 */
AI_STATIC ai_layer_nl nl_7_layer; /* Layer #5 */
AI_STATIC ai_layer_eltwise_integer eltwise_8_layer; /* Layer #6 */
AI_STATIC ai_layer_conv2d conv2d_9_layer; /* Layer #7 */
AI_STATIC ai_layer_nl nl_10_layer; /* Layer #8 */
AI_STATIC ai_layer_eltwise_integer eltwise_11_layer; /* Layer #9 */
AI_STATIC ai_layer_conv2d conv2d_13_layer; /* Layer #10 */
AI_STATIC ai_layer_nl nl_14_layer; /* Layer #11 */
AI_STATIC ai_layer_eltwise_integer eltwise_15_layer; /* Layer #12 */
AI_STATIC ai_layer_conv2d conv2d_16_layer; /* Layer #13 */
AI_STATIC ai_layer_nl nl_17_layer; /* Layer #14 */
AI_STATIC ai_layer_eltwise_integer eltwise_18_layer; /* Layer #15 */
AI_STATIC ai_layer_conv2d conv2d_20_layer; /* Layer #16 */
AI_STATIC ai_layer_nl nl_21_layer; /* Layer #17 */
AI_STATIC ai_layer_eltwise_integer eltwise_22_layer; /* Layer #18 */
AI_STATIC ai_layer_conv2d conv2d_23_layer; /* Layer #19 */
AI_STATIC ai_layer_nl nl_24_layer; /* Layer #20 */
AI_STATIC ai_layer_eltwise_integer eltwise_25_layer; /* Layer #21 */
AI_STATIC ai_layer_conv2d conv2d_27_layer; /* Layer #22 */
AI_STATIC ai_layer_nl nl_28_layer; /* Layer #23 */
AI_STATIC ai_layer_eltwise_integer eltwise_29_layer; /* Layer #24 */
AI_STATIC ai_layer_conv2d conv2d_30_layer; /* Layer #25 */
AI_STATIC ai_layer_nl nl_31_layer; /* Layer #26 */
AI_STATIC ai_layer_eltwise_integer eltwise_32_layer; /* Layer #27 */
AI_STATIC ai_layer_conv2d conv2d_50_layer; /* Layer #28 */
AI_STATIC ai_layer_nl nl_51_layer; /* Layer #29 */
AI_STATIC ai_layer_eltwise_integer eltwise_52_layer; /* Layer #30 */
AI_STATIC ai_layer_conv2d conv2d_53_layer; /* Layer #31 */
AI_STATIC ai_layer_nl nl_54_layer; /* Layer #32 */
AI_STATIC ai_layer_eltwise_integer eltwise_55_layer; /* Layer #33 */
AI_STATIC ai_layer_conv2d conv2d_56_layer; /* Layer #34 */
AI_STATIC ai_layer_transpose transpose_57_layer; /* Layer #35 */
AI_STATIC ai_layer_nl reshape_58_fmt_layer; /* Layer #36 */
AI_STATIC ai_layer_slice slice_75_layer; /* Layer #37 */
AI_STATIC ai_layer_nl slice_75_fmt_layer; /* Layer #38 */
AI_STATIC ai_layer_nl nl_76_layer; /* Layer #39 */
AI_STATIC ai_layer_eltwise_integer eltwise_77_layer; /* Layer #40 */
AI_STATIC ai_layer_slice slice_71_layer; /* Layer #41 */
AI_STATIC ai_layer_nl slice_71_fmt_layer; /* Layer #42 */
AI_STATIC ai_layer_eltwise_integer eltwise_72_layer; /* Layer #43 */
AI_STATIC ai_layer_eltwise_integer eltwise_73_layer; /* Layer #44 */
AI_STATIC ai_layer_eltwise_integer eltwise_74_layer; /* Layer #45 */
AI_STATIC ai_layer_concat concat_78_layer; /* Layer #46 */
AI_STATIC ai_layer_conv2d conv2d_40_layer; /* Layer #47 */
AI_STATIC ai_layer_nl nl_41_layer; /* Layer #48 */
AI_STATIC ai_layer_eltwise_integer eltwise_42_layer; /* Layer #49 */
AI_STATIC ai_layer_conv2d conv2d_43_layer; /* Layer #50 */
AI_STATIC ai_layer_nl nl_44_layer; /* Layer #51 */
AI_STATIC ai_layer_eltwise_integer eltwise_45_layer; /* Layer #52 */
AI_STATIC ai_layer_conv2d conv2d_46_layer; /* Layer #53 */
AI_STATIC ai_layer_conv2d conv2d_33_layer; /* Layer #54 */
AI_STATIC ai_layer_nl nl_34_layer; /* Layer #55 */
AI_STATIC ai_layer_eltwise_integer eltwise_35_layer; /* Layer #56 */
AI_STATIC ai_layer_conv2d conv2d_36_layer; /* Layer #57 */
AI_STATIC ai_layer_nl nl_37_layer; /* Layer #58 */
AI_STATIC ai_layer_eltwise_integer eltwise_38_layer; /* Layer #59 */
AI_STATIC ai_layer_conv2d conv2d_39_layer; /* Layer #60 */
AI_STATIC ai_layer_concat concat_47_layer; /* Layer #61 */
AI_STATIC ai_layer_transpose transpose_48_layer; /* Layer #62 */
AI_STATIC ai_layer_nl reshape_49_fmt_layer; /* Layer #63 */
AI_STATIC ai_layer_slice slice_68_layer; /* Layer #64 */
AI_STATIC ai_layer_nl slice_68_fmt_layer; /* Layer #65 */
AI_STATIC ai_layer_nl nl_69_layer; /* Layer #66 */
AI_STATIC ai_layer_eltwise_integer eltwise_70_layer; /* Layer #67 */
AI_STATIC ai_layer_slice slice_59_layer; /* Layer #68 */
AI_STATIC ai_layer_nl slice_59_fmt_layer; /* Layer #69 */
AI_STATIC ai_layer_transpose transpose_61_layer; /* Layer #70 */
AI_STATIC ai_layer_transpose transpose_62_layer; /* Layer #71 */
AI_STATIC ai_layer_nl transpose_62_fmt_layer; /* Layer #72 */
AI_STATIC ai_layer_nl nl_63_layer; /* Layer #73 */
AI_STATIC ai_layer_nl nl_63_fmt_layer; /* Layer #74 */
AI_STATIC ai_layer_conv2d conv2d_64_layer; /* Layer #75 */
AI_STATIC ai_layer_nl reshape_65_fmt_layer; /* Layer #76 */
AI_STATIC ai_layer_slice slice_80_layer; /* Layer #77 */
AI_STATIC ai_layer_nl slice_80_fmt_layer; /* Layer #78 */
AI_STATIC ai_layer_eltwise_integer eltwise_81_layer; /* Layer #79 */
AI_STATIC ai_layer_slice slice_66_layer; /* Layer #80 */
AI_STATIC ai_layer_nl slice_66_fmt_layer; /* Layer #81 */
AI_STATIC ai_layer_eltwise_integer eltwise_67_layer; /* Layer #82 */
AI_STATIC ai_layer_eltwise_integer eltwise_84_layer; /* Layer #83 */
AI_STATIC ai_layer_eltwise_integer eltwise_82_layer; /* Layer #84 */
AI_STATIC ai_layer_eltwise_integer eltwise_83_layer; /* Layer #85 */
AI_STATIC ai_layer_concat concat_85_layer; /* Layer #86 */
AI_STATIC ai_layer_eltwise_integer eltwise_86_layer; /* Layer #87 */
AI_STATIC ai_layer_concat concat_87_layer; /* Layer #88 */
AI_STATIC ai_layer_nl conversion_88_layer; /* Layer #89 */




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_images0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 49152, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conversion_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  nl_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  nl_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  nl_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_11_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  nl_14_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_15_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  nl_17_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8704, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  nl_21_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8704, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_22_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8704, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8704, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  nl_24_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8704, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_25_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8704, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  nl_28_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_29_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  nl_31_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_32_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  nl_51_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_52_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  nl_54_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_55_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  transpose_57_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  reshape_58_fmt_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 816, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  slice_75_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 272, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  slice_75_fmt_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 272, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  nl_76_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 272, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_77_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 272, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  slice_71_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 544, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  slice_71_fmt_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 544, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_72_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 544, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_73_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 544, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_74_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 544, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  concat_78_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_40_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  nl_41_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_42_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  nl_44_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_45_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  nl_34_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_35_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  nl_37_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_38_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  concat_47_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1040, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  transpose_48_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1040, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  reshape_49_fmt_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1040, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  slice_68_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  slice_68_fmt_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  nl_69_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_70_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  slice_59_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  slice_59_fmt_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  transpose_61_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  transpose_62_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  transpose_62_fmt_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  nl_63_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  nl_63_fmt_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  reshape_65_fmt_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  slice_80_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  slice_80_fmt_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_81_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  slice_66_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  slice_66_fmt_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_67_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_84_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_82_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_83_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  concat_85_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_86_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  concat_87_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  conversion_88_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 896, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  model_2_tfmathmultiply_58_Mul_y_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  model_2_tfmathdivide_truedivConst_9_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  Const_12_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  model_2_tfmathmultiply_49_Mul_y_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  Const_15_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  Const_20_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  Const_8_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  Const_13_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5184, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 15552, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 72, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 46656, AI_STATIC)

/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 72, AI_STATIC)

/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 88128, AI_STATIC)

/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 136, AI_STATIC)

/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 166464, AI_STATIC)

/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 136, AI_STATIC)

/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 244800, AI_STATIC)

/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 200, AI_STATIC)

/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 360000, AI_STATIC)

/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 200, AI_STATIC)

/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 91800, AI_STATIC)

/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 51, AI_STATIC)

/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 23409, AI_STATIC)

/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 51, AI_STATIC)

/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2601, AI_STATIC)

/* Array#122 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 51, AI_STATIC)

/* Array#123 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_40_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 360000, AI_STATIC)

/* Array#124 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_40_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 200, AI_STATIC)

/* Array#125 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 360000, AI_STATIC)

/* Array#126 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 200, AI_STATIC)

/* Array#127 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 200, AI_STATIC)

/* Array#128 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 1, AI_STATIC)

/* Array#129 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 115200, AI_STATIC)

/* Array#130 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#131 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#132 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#133 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#134 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#135 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16, AI_STATIC)

/* Array#136 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 1, AI_STATIC)

/* Array#137 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1196, AI_STATIC)

/* Array#138 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6032, AI_STATIC)

/* Array#139 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6320, AI_STATIC)

/* Array#140 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6992, AI_STATIC)

/* Array#141 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8720, AI_STATIC)

/* Array#142 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9616, AI_STATIC)

/* Array#143 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 11920, AI_STATIC)

/* Array#144 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12816, AI_STATIC)

/* Array#145 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 15120, AI_STATIC)

/* Array#146 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 13034, AI_STATIC)

/* Array#147 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7670, AI_STATIC)

/* Array#148 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 714, AI_STATIC)

/* Array#149 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_40_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 15120, AI_STATIC)

/* Array#150 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 15120, AI_STATIC)

/* Array#151 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 800, AI_STATIC)

/* Array#152 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 13216, AI_STATIC)

/* Array#153 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8320, AI_STATIC)

/* Array#154 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#155 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01865844801068306f),
    AI_PACK_INTQ_ZP(-14)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.8298152685165405f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_4_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8892789483070374f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(3.198676347732544f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_7_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.604809045791626f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.578269362449646f),
    AI_PACK_INTQ_ZP(43)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_10_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_11_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.5200995802879333f),
    AI_PACK_INTQ_ZP(-127)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.5574910640716553f),
    AI_PACK_INTQ_ZP(35)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_14_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_15_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.20211471617221832f),
    AI_PACK_INTQ_ZP(-127)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2666693925857544f),
    AI_PACK_INTQ_ZP(31)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_17_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_18_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10125287622213364f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.17893673479557037f),
    AI_PACK_INTQ_ZP(10)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_21_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_22_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08291853964328766f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16682308912277222f),
    AI_PACK_INTQ_ZP(20)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_25_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07127009332180023f),
    AI_PACK_INTQ_ZP(-124)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12757280468940735f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_28_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_29_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06491679698228836f),
    AI_PACK_INTQ_ZP(-124)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11181902140378952f),
    AI_PACK_INTQ_ZP(21)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_31_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_32_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04753577336668968f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_50_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1705610156059265f),
    AI_PACK_INTQ_ZP(25)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_51_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_52_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06902918219566345f),
    AI_PACK_INTQ_ZP(-124)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_53_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.055132295936346054f),
    AI_PACK_INTQ_ZP(93)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_54_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_55_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007413920015096664f),
    AI_PACK_INTQ_ZP(-90)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03225455805659294f),
    AI_PACK_INTQ_ZP(39)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(transpose_57_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03225455805659294f),
    AI_PACK_INTQ_ZP(39)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_75_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03225455805659294f),
    AI_PACK_INTQ_ZP(39)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_76_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_77_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.755348265171051f),
    AI_PACK_INTQ_ZP(-78)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_71_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03225455805659294f),
    AI_PACK_INTQ_ZP(39)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_72_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03536933660507202f),
    AI_PACK_INTQ_ZP(-10)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_73_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023604633286595345f),
    AI_PACK_INTQ_ZP(-78)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_74_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.755348265171051f),
    AI_PACK_INTQ_ZP(-78)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_78_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.755348265171051f),
    AI_PACK_INTQ_ZP(-78)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_40_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06014189496636391f),
    AI_PACK_INTQ_ZP(12)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_41_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_42_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.028217678889632225f),
    AI_PACK_INTQ_ZP(-118)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0608443021774292f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_44_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_45_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.030595095828175545f),
    AI_PACK_INTQ_ZP(-119)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_46_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09899362176656723f),
    AI_PACK_INTQ_ZP(-59)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05804198607802391f),
    AI_PACK_INTQ_ZP(1)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_34_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_35_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02963845059275627f),
    AI_PACK_INTQ_ZP(-119)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09537971019744873f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_37_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_38_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04748484864830971f),
    AI_PACK_INTQ_ZP(-122)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09899362176656723f),
    AI_PACK_INTQ_ZP(-59)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_47_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09899362176656723f),
    AI_PACK_INTQ_ZP(-59)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(transpose_48_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09899362176656723f),
    AI_PACK_INTQ_ZP(-59)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_68_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09899362176656723f),
    AI_PACK_INTQ_ZP(-59)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_69_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_70_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.755348265171051f),
    AI_PACK_INTQ_ZP(-78)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_59_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09899362176656723f),
    AI_PACK_INTQ_ZP(-59)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(transpose_61_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09899362176656723f),
    AI_PACK_INTQ_ZP(-59)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(transpose_62_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09899362176656723f),
    AI_PACK_INTQ_ZP(-59)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_63_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0154956029728055f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_80_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0154956029728055f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_81_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.013998848386108875f),
    AI_PACK_INTQ_ZP(-96)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(slice_66_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0154956029728055f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_67_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01659643091261387f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_84_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.017978981137275696f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_82_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.027901416644454002f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_83_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.017978981137275696f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_85_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.017978981137275696f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_86_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.755348265171051f),
    AI_PACK_INTQ_ZP(-78)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_87_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.755348265171051f),
    AI_PACK_INTQ_ZP(-78)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(model_2_tfmathmultiply_58_Mul_y_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.125490203499794f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(model_2_tfmathdivide_truedivConst_9_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0019607844296842813f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(Const_12_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3921568691730499f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #81 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(model_2_tfmathmultiply_49_Mul_y_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.125490203499794f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #82 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(Const_15_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0117647061124444f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #83 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(Const_20_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #84 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(Const_8_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3921568691730499f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #85 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(Const_13_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.013725490309298038f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #86 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06094788387417793f, 0.06092527508735657f, 0.08168159425258636f, 0.0761871412396431f, 0.13811074197292328f, 0.04751553758978844f, 0.06411674618721008f, 0.07277489453554153f, 0.03361650928854942f, 0.053655192255973816f, 0.06175811588764191f, 0.04614989086985588f, 0.0404425784945488f, 0.06216145679354668f, 0.022504523396492004f, 0.12369748204946518f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #87 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0011371929431334138f, 0.001136771054007113f, 0.0015240517677739263f, 0.0014215337578207254f, 0.0025769320782274008f, 0.0008865661802701652f, 0.0011963190045207739f, 0.0013578665675595403f, 0.0006272319005802274f, 0.0010011226404458284f, 0.0011523106368258595f, 0.0008610853110440075f, 0.0007545957341790199f, 0.0011598363053053617f, 0.0004198994720354676f, 0.0023080031387507915f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #88 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005813642404973507f, 0.007081313990056515f, 0.006307543255388737f, 0.005516619421541691f, 0.007259667851030827f, 0.008656869642436504f, 0.005493697710335255f, 0.00390569563023746f, 0.003934341482818127f, 0.0033271757420152426f, 0.004731804598122835f, 0.005768631584942341f, 0.007731499150395393f, 0.0037487486843019724f, 0.002333670388907194f, 0.005365363322198391f, 0.00877211894840002f, 0.005475628189742565f, 0.006503748241811991f, 0.004879347514361143f, 0.005927001126110554f, 0.009712549857795238f, 0.00337958917953074f, 0.0038522977847605944f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #89 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00516994995996356f, 0.006297263316810131f, 0.005609165411442518f, 0.0049058133736252785f, 0.006455869879573584f, 0.007698372006416321f, 0.0048854295164346695f, 0.0034732529893517494f, 0.0034987269900739193f, 0.0029587873723357916f, 0.004207894206047058f, 0.0051299226470291615f, 0.00687545957043767f, 0.0033336833585053682f, 0.002075284020975232f, 0.0047713047824800014f, 0.007800860796123743f, 0.004869360942393541f, 0.005783646367490292f, 0.004339101258665323f, 0.005270757246762514f, 0.00863716658204794f, 0.003005397506058216f, 0.0034257674124091864f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #90 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002055683871731162f, 0.00286958459764719f, 0.002018996514379978f, 0.0015502838650718331f, 0.001818473101593554f, 0.004694249015301466f, 0.0029547277372330427f, 0.0047088670544326305f, 0.0020287921652197838f, 0.0035655852407217026f, 0.0028658753726631403f, 0.0031942827627062798f, 0.0033214897848665714f, 0.003438608953729272f, 0.0018650611164048314f, 0.0010202617850154638f, 0.0014162738807499409f, 0.003590119071304798f, 0.0019153375178575516f, 0.0026319974567741156f, 0.0034579860512167215f, 0.003018583869561553f, 0.0023624729365110397f, 0.0030135184060782194f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #91 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0032989801838994026f, 0.004605135414749384f, 0.0032401038333773613f, 0.0024879095144569874f, 0.0029183020815253258f, 0.007533373311161995f, 0.0047417739406228065f, 0.007556832395493984f, 0.0032558240927755833f, 0.005722083617001772f, 0.004599182866513729f, 0.005126213654875755f, 0.005330356769263744f, 0.0055183107033371925f, 0.002993067028000951f, 0.0016373253893107176f, 0.002272849204018712f, 0.005761455744504929f, 0.0030737509950995445f, 0.004223853349685669f, 0.005549407098442316f, 0.004844250623136759f, 0.003791318042203784f, 0.004836121574044228f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #92 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 72,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008213802939280868f, 0.0012592588318511844f, 0.004040096420794725f, 0.002261826302856207f, 0.002819506684318185f, 0.0021806485019624233f, 0.001489604590460658f, 0.0025673729833215475f, 0.0025882988702505827f, 0.0011045451974496245f, 0.00232449802570045f, 0.0011381597723811865f, 0.0010308831697329879f, 0.0018331626197323203f, 0.0018532562535256147f, 0.002327040070667863f, 0.0028087252285331488f, 0.0013489782577380538f, 0.0016498251352459192f, 0.0035690530203282833f, 0.002082513179630041f, 0.0013261974090710282f, 0.0016905084485188127f, 0.001023744116537273f, 0.0011329780099913478f, 0.0016753935487940907f, 0.0015095843700692058f, 0.001770799164660275f, 0.001005849801003933f, 0.0021739674266427755f, 0.001319471630267799f, 0.0018215148011222482f, 0.0017334026051685214f, 0.0027228733524680138f, 0.000914089847356081f, 0.0016124161193147302f, 0.0013491854770109057f, 0.0021671559661626816f, 0.002588329603895545f, 0.002054748358204961f, 0.0028360190335661173f, 0.0031005109194666147f, 0.001642905524931848f, 0.0012515344424173236f, 0.00315294461324811f, 0.0016416761791333556f, 0.0013392276596277952f, 0.0013210579054430127f, 0.0009789641480892897f, 0.0016486287349835038f, 0.0023164874874055386f, 0.002228666329756379f, 0.0037379818968474865f, 0.0008658556616865098f, 0.0013798943255096674f, 0.0020802454091608524f, 0.0036910222843289375f, 0.0026235943660140038f, 0.0023552824277430773f, 0.0019358325516805053f, 0.002895553130656481f, 0.0022549109999090433f, 0.0036933172959834337f, 0.001522165723145008f, 0.0013943776721134782f, 0.0027840861584991217f, 0.0033097541891038418f, 0.0014889357844367623f, 0.004367928486317396f, 0.0012281450908631086f, 0.0026084636338055134f, 0.002004459034651518f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #93 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 72,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004271995567250997f, 0.000654939969535917f, 0.002101252553984523f, 0.001176374964416027f, 0.0014664242044091225f, 0.001134154386818409f, 0.000774742744397372f, 0.0013352895621210337f, 0.001346173114143312f, 0.000574473466258496f, 0.001208970439620316f, 0.0005919564282521605f, 0.0005361618823371828f, 0.0009534271084703505f, 0.0009638778283260763f, 0.0012102925684303045f, 0.0014608168276026845f, 0.0007016030140221119f, 0.0008580733556300402f, 0.0018562630284577608f, 0.0010831141844391823f, 0.0006897547282278538f, 0.0008792327134869993f, 0.0005324488738551736f, 0.000589261413551867f, 0.0008713714778423309f, 0.0007851342088542879f, 0.0009209918789565563f, 0.0005231420509517193f, 0.0011306795058771968f, 0.0006862566224299371f, 0.0009473690879531205f, 0.0009015419636853039f, 0.0014161652652546763f, 0.00047541773528791964f, 0.0008386169211007655f, 0.0007017108146101236f, 0.0011271368712186813f, 0.001346189179457724f, 0.0010686737950891256f, 0.0014750122791156173f, 0.0016125744441524148f, 0.0008544744923710823f, 0.0006509225349873304f, 0.0016398451989516616f, 0.0008538350812159479f, 0.000696531729772687f, 0.0006870816578157246f, 0.000509158824570477f, 0.0008574511157348752f, 0.0012048041680827737f, 0.0011591283837333322f, 0.0019441228359937668f, 0.0004503311647567898f, 0.0007176824728958309f, 0.0010819347808137536f, 0.0019196991343051195f, 0.0013645302969962358f, 0.0012249813880771399f, 0.0010068257106468081f, 0.001505975960753858f, 0.001172778313048184f, 0.001920892740599811f, 0.0007916777394711971f, 0.0007252152427099645f, 0.0014480020618066192f, 0.00172140181530267f, 0.0007743948954157531f, 0.0022717576939612627f, 0.0006387577741406858f, 0.0013566608540713787f, 0.0010425182990729809f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #94 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 72,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00221586087718606f, 0.001547615509480238f, 0.0020453932229429483f, 0.00045486120507121086f, 0.0013909743865951896f, 0.0013705240562558174f, 0.00118539878167212f, 0.0014680071035400033f, 0.0016639336245134473f, 0.0013215867802500725f, 0.001895071705803275f, 0.0008285248768515885f, 0.0011400062358006835f, 0.0017322401981800795f, 0.0007674838998354971f, 0.001956660533323884f, 0.00086258165538311f, 0.0011166376061737537f, 0.0010416313307359815f, 0.0010470023844391108f, 0.0010520885698497295f, 0.001640894333831966f, 0.001065202639438212f, 0.0027476632967591286f, 0.0017079291865229607f, 0.0012230145512148738f, 0.0017061413964256644f, 0.0018583479104563594f, 0.0005100407870486379f, 0.001051771454513073f, 0.0014808396808803082f, 0.0015711812302470207f, 0.0021487707272171974f, 0.0011018447112292051f, 0.000861533684656024f, 0.0011681420728564262f, 0.0013464471558108926f, 0.0021659673657268286f, 0.0014718108577653766f, 0.0006407165783457458f, 0.001157098449766636f, 0.0010809656232595444f, 0.001461198553442955f, 0.0006734359776601195f, 0.0006544223288074136f, 0.0007305601611733437f, 0.0009886248735710979f, 0.0021759814117103815f, 0.0017932862974703312f, 0.0011633267858996987f, 0.000908045272808522f, 0.0010956967016682029f, 0.0019970438443124294f, 0.0008531383355148137f, 0.0012586520751938224f, 0.002469097962602973f, 0.0017564779845997691f, 0.0013471398269757628f, 0.0017651832895353436f, 0.0018655720632523298f, 0.001956780906766653f, 0.0013411648105829954f, 0.0012951164972037077f, 0.0007008337997831404f, 0.001482766238041222f, 0.0018109186785295606f, 0.0022562190424650908f, 0.001095775980502367f, 0.0007608637097291648f, 0.0017552576027810574f, 0.001627860008738935f, 0.0008666314533911645f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #95 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 72,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004478580958675593f, 0.00031279586255550385f, 0.0004134040791541338f, 9.19341400731355e-05f, 0.0002811363956425339f, 0.0002770030696410686f, 0.00023958654492162168f, 0.0002967058389913291f, 0.000336305471137166f, 0.00026711213286034763f, 0.0003830218920484185f, 0.0001674570667091757f, 0.00023041204258333892f, 0.00035011122236028314f, 0.00015511979290749878f, 0.0003954698913730681f, 0.00017434044275432825f, 0.00022568889835383743f, 0.00021052901865914464f, 0.0002116145915351808f, 0.00021264258248265833f, 0.0003316488873679191f, 0.00021529312653001398f, 0.0005553431692533195f, 0.0003451976226642728f, 0.00024718925124034286f, 0.00034483629860915244f, 0.00037559945485554636f, 0.00010308674973202869f, 0.0002125784958479926f, 0.0002992994850501418f, 0.0003175588499289006f, 0.00043429818470031023f, 0.00022269903274718672f, 0.00017412863962817937f, 0.00023609869822394103f, 0.0002721367927733809f, 0.0004377738805487752f, 0.00029747464577667415f, 0.0001294982503168285f, 0.00023386662360280752f, 0.0002184790646424517f, 0.00029532972257584333f, 0.00013611132453661412f, 0.00013226838200353086f, 0.00014765695959795266f, 0.00019981563673354685f, 0.0004397978773340583f, 0.00036244955845177174f, 0.00023512546613346785f, 0.0001835293078329414f, 0.00022145643015392125f, 0.00040363194420933723f, 0.00017243181355297565f, 0.00025439210003241897f, 0.0004990410525351763f, 0.00035501003731042147f, 0.00027227678219787776f, 0.0003567695093806833f, 0.00037705956492573023f, 0.0003954942221753299f, 0.00027106914785690606f, 0.0002617620921228081f, 0.00014164882304612547f, 0.00029968886519782245f, 0.0003660133224911988f, 0.000456015084637329f, 0.00022147245181258768f, 0.00015378175885416567f, 0.00035476338234730065f, 0.00032901446684263647f, 0.00017515897343400866f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #96 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 136,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0035825634840875864f, 0.001750839059241116f, 0.0020131603814661503f, 0.0023330445401370525f, 0.0027175915893167257f, 0.001828642562031746f, 0.0030592973344027996f, 0.0035812456626445055f, 0.0015411435160785913f, 0.0013238543178886175f, 0.004033063072711229f, 0.0024644534569233656f, 0.0019795226398855448f, 0.001850434229709208f, 0.002478164853528142f, 0.001798618002794683f, 0.0021758549846708775f, 0.001583278994075954f, 0.003428918309509754f, 0.002948813373222947f, 0.00171536928974092f, 0.002769350539892912f, 0.0018063578754663467f, 0.0020807310938835144f, 0.002090238034725189f, 0.0017724204808473587f, 0.0014136943500488997f, 0.0004305202455725521f, 0.00270442315377295f, 0.0017333707073703408f, 0.0020116607192903757f, 0.0016440220642834902f, 0.0013908138498663902f, 0.00331226852722466f, 0.0023002298548817635f, 0.0021805937867611647f, 0.0012182306963950396f, 0.0021018057595938444f, 0.0018435860984027386f, 0.004439471289515495f, 0.001731118536554277f, 0.0019263949943706393f, 0.002205105032771826f, 0.003245578845962882f, 0.0017545856535434723f, 0.0015987278893589973f, 0.0026300230529159307f, 0.0017990319756790996f, 0.0013663583667948842f, 0.0024918459821492434f, 0.002574833808466792f, 0.0020436476916074753f, 0.0021243577357381582f, 0.001970927696675062f, 0.0017541022971272469f, 0.0015207281103357673f, 0.0027964455075562f, 0.0022032498382031918f, 0.0041440692730247974f, 0.0030662340577691793f, 0.001575575559400022f, 0.00334289763122797f, 0.0032330132089555264f, 0.0029248660430312157f, 0.0021280618384480476f, 0.0017326734960079193f, 0.002726045437157154f, 0.002480296418070793f, 0.0025853989645838737f, 0.0013424211647361517f, 0.001433120109140873f, 0.002308235503733158f, 0.0020106693264096975f, 0.0016700397245585918f, 0.002474845852702856f, 0.002073498908430338f, 0.0027658178005367517f, 0.003035078290849924f, 0.0021117222495377064f, 0.0021596739534288645f, 0.003096629399806261f, 0.0033681949134916067f, 0.0025007864460349083f, 0.0031914450228214264f, 0.002362215891480446f, 0.002454193541780114f, 0.003234005533158779f, 0.0016826762584969401f, 0.0022695004008710384f, 0.0021986498031765223f, 0.001583365141414106f, 0.002078757854178548f, 0.0019146421691402793f, 0.0014045715797692537f, 0.002501796232536435f, 0.00326826935634017f, 0.001414869213476777f, 0.002932438161224127f, 0.00301791587844491f, 0.0031704555731266737f, 0.0033876297529786825f, 0.001744417822919786f, 0.001458001439459622f, 0.001521892030723393f, 0.0030169531237334013f, 0.0017997409449890256f, 0.0014975687954574823f, 0.0017765009542927146f, 0.004410139750689268f, 0.0022935685701668262f, 0.0033746901899576187f, 0.002148050582036376f, 0.0020545348525047302f, 0.0017858415376394987f, 0.001981797395274043f, 0.002296552760526538f, 0.0014818061608821154f, 0.0018432983197271824f, 0.0025398044381290674f, 0.0014521912671625614f, 0.002091658767312765f, 0.002307073213160038f, 0.0033599708694964647f, 0.0013876856537535787f, 0.0016139179933816195f, 0.002387682907283306f, 0.0021116165444254875f, 0.0027364003472030163f, 0.0021112149115651846f, 0.001927772187627852f, 0.0024498840793967247f, 0.0015548684168606997f, 0.0022007355000823736f, 0.0015979164745658636f, 0.0032181397546082735f, 0.0020129154436290264f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #97 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 136,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00036274484591558576f, 0.0001772774849087f, 0.00020383828086778522f, 0.00023622746812179685f, 0.0002751639694906771f, 0.0001851553242886439f, 0.00030976266134530306f, 0.0003626114339567721f, 0.00015604520740453154f, 0.00013404405035544187f, 0.00040835925028659403f, 0.0002495330118108541f, 0.00020043236145284027f, 0.00018736178753897548f, 0.0002509213227313012f, 0.0001821152400225401f, 0.0002203115727752447f, 0.00016031155246309936f, 0.0003471878299023956f, 0.0002985758474096656f, 0.00017368607223033905f, 0.00028040469624102116f, 0.0001828989334171638f, 0.00021068000933155417f, 0.00021164261852391064f, 0.0001794626732589677f, 0.0001431406126357615f, 4.3591411667875946e-05f, 0.0002738306357059628f, 0.00017550877237226814f, 0.0002036864316323772f, 0.0001664619630901143f, 0.0001408239040756598f, 0.00033537670969963074f, 0.00023290488752536476f, 0.00022079139307606965f, 0.00012334936764091253f, 0.00021281387307681143f, 0.0001866683887783438f, 0.0004495092434808612f, 0.0001752807293087244f, 0.00019505302770994604f, 0.00022327322221826762f, 0.00032862418447621167f, 0.00017765683878678828f, 0.00016187579603865743f, 0.0002662974002305418f, 0.00018215716409031302f, 0.00013834772107657045f, 0.00025230657774955034f, 0.00026070931926369667f, 0.00020692520774900913f, 0.0002150973305106163f, 0.00019956209871452302f, 0.0001776079006958753f, 0.0001539780932944268f, 0.0002831481397151947f, 0.00022308538609649986f, 0.0004195989458821714f, 0.0003104650240857154f, 0.00015953155525494367f, 0.0003384780138731003f, 0.0003273518814239651f, 0.00029615109087899327f, 0.000215472377021797f, 0.00017543818103149533f, 0.0002760199422482401f, 0.0002511371567379683f, 0.00026177908875979483f, 0.00013592399773187935f, 0.00014510753680951893f, 0.0002337154874112457f, 0.00020358605252113193f, 0.000169096325407736f, 0.0002505852608010173f, 0.0002099477278534323f, 0.0002800470101647079f, 0.00030731040169484913f, 0.00021381795522756875f, 0.00021867320174351335f, 0.0003135426377411932f, 0.00034103941288776696f, 0.0002532118232920766f, 0.0003231430018786341f, 0.00023918115766718984f, 0.00024849415058270097f, 0.00032745234784670174f, 0.0001703758171061054f, 0.00022979344066698104f, 0.00022261962294578552f, 0.00016032026906032115f, 0.0002104802115354687f, 0.0001938630302902311f, 0.00014221691526472569f, 0.0002533140650484711f, 0.0003309216699562967f, 0.0001432595745427534f, 0.00029691780218854547f, 0.0003055726701859385f, 0.00032101775286719203f, 0.000343007268384099f, 0.0001766273198882118f, 0.00014762683713342994f, 0.00015409594925586134f, 0.0003054751723539084f, 0.00018222894868813455f, 0.00015163315401878208f, 0.0001798758312361315f, 0.0004465393431019038f, 0.00023223042080644518f, 0.0003416971012484282f, 0.00021749630104750395f, 0.0002080275589833036f, 0.0001808215893106535f, 0.00020066268916707486f, 0.000232532576774247f, 0.00015003712906036526f, 0.0001866392558440566f, 0.00025716249365359545f, 0.00014703854685649276f, 0.00021178646420594305f, 0.00023359779152087867f, 0.00034020672319456935f, 0.00014050716708879918f, 0.0001634138316148892f, 0.00024175975704565644f, 0.00021380724501796067f, 0.00027706840774044394f, 0.0002137665869668126f, 0.00019519247871357948f, 0.00024805779685266316f, 0.00015743490075692534f, 0.00022283080033957958f, 0.00016179363592527807f, 0.0003258459037169814f, 0.00020381348440423608f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #98 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 136,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0018083270406350493f, 0.0033148976508527994f, 0.0017337739700451493f, 0.001478719525039196f, 0.0009530088864266872f, 0.0035054029431194067f, 0.0027531113009899855f, 0.003506780369207263f, 0.0032779104076325893f, 0.0011322165373712778f, 0.0023220728617161512f, 0.0029584274161607027f, 0.0014369641430675983f, 0.0018533319234848022f, 0.0018506648484617472f, 0.0012165370862931013f, 0.002977618481963873f, 0.0013826200738549232f, 0.0016937500331550837f, 0.002747053513303399f, 0.0030031674541532993f, 0.002904494060203433f, 0.0014444889966398478f, 0.0027358122169971466f, 0.002388307359069586f, 0.0030659448821097612f, 0.006343072280287743f, 0.0017049498856067657f, 0.003371224505826831f, 0.0009592132992111146f, 0.0016010653926059604f, 0.0011607703054323792f, 0.0049724821001291275f, 0.0036176766734570265f, 0.0007127529243007302f, 0.005309049505740404f, 0.001980806468054652f, 0.0030814206693321466f, 0.003786587156355381f, 0.0013335947878658772f, 0.0016566995764151216f, 0.0034141517244279385f, 0.0030578915029764175f, 0.001163445645943284f, 0.002375369193032384f, 0.002319964347407222f, 0.002323018852621317f, 0.0035407443065196276f, 0.0036291293799877167f, 0.002220881637185812f, 0.0012099185260012746f, 0.0023182120639830828f, 0.0025805283803492785f, 0.0012540966272354126f, 0.0014079343527555466f, 0.001940190326422453f, 0.001192665658891201f, 0.0044067068956792355f, 0.001982698682695627f, 0.002155195688828826f, 0.001567889004945755f, 0.0032085240818560123f, 0.0017343650106340647f, 0.0020482614636421204f, 0.003470802679657936f, 0.002886743051931262f, 0.0011758115142583847f, 0.003480420680716634f, 0.0022853331174701452f, 0.0019968680571764708f, 0.0016782557358965278f, 0.0019162895623594522f, 0.00245605013333261f, 0.001133548328652978f, 0.0020024185068905354f, 0.0014175813412293792f, 0.0007786162896081805f, 0.004672137089073658f, 0.003414717735722661f, 0.0027725640684366226f, 0.0020141678396612406f, 0.0011673056287690997f, 0.0018712597666308284f, 0.0040371292270720005f, 0.0020691468380391598f, 0.0015342955011874437f, 0.001557420240715146f, 0.0024395762011408806f, 0.0019748182967305183f, 0.0018554198322817683f, 0.001340707065537572f, 0.004696421790868044f, 0.0030339325312525034f, 0.004500358831137419f, 0.0017303215572610497f, 0.0037783135194331408f, 0.0008346812101081014f, 0.0021817474626004696f, 0.0019196266075596213f, 0.004113201051950455f, 0.0024831644259393215f, 0.0026304132770746946f, 0.001388530363328755f, 0.006102163344621658f, 0.0026775922160595655f, 0.003119976259768009f, 0.0035903893876820803f, 0.003661141963675618f, 0.003615708090364933f, 0.0025157160125672817f, 0.003537903307005763f, 0.002509953686967492f, 0.0018038185080513358f, 0.0017989282496273518f, 0.0038080187514424324f, 0.003728484734892845f, 0.0016861887415871024f, 0.002016631653532386f, 0.0020569718908518553f, 0.002073142444714904f, 0.0029445604886859655f, 0.0027598903980106115f, 0.006289386190474033f, 0.0018274073954671621f, 0.0028693226631730795f, 0.002038653939962387f, 0.0019202298717573285f, 0.0011160155991092324f, 0.0022219775710254908f, 0.003723887726664543f, 0.0037694971542805433f, 0.003366719698533416f, 0.0026781302876770496f, 0.0016654437640681863f, 0.002544842893257737f, 0.0032278788276016712f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #99 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 136,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001499438367318362f, 0.0002748664701357484f, 0.00014376200851984322f, 0.0001226132590090856f, 7.902210199972615e-05f, 0.00029066289425827563f, 0.00022828397050034255f, 0.00029077709768898785f, 0.00027179953758604825f, 9.388173930346966e-05f, 0.0001925428950926289f, 0.00024530847440473735f, 0.00011915096547454596f, 0.00015367557352874428f, 0.0001534544280730188f, 0.00010087347618537024f, 0.0002468997845426202f, 0.0001146448339568451f, 0.00014044328418094665f, 0.00022778166749048978f, 0.00024901825236156583f, 0.0002408364089205861f, 0.00011977491521975026f, 0.00022684955911245197f, 0.0001980349625227973f, 0.00025422367616556585f, 0.0005259583122096956f, 0.00014137195830699056f, 0.00027953702374361455f, 7.953656313475221e-05f, 0.00013275801029521972f, 9.624937956687063e-05f, 0.00041231096838600934f, 0.00029997245292179286f, 5.9100431826664135e-05f, 0.0004402186314109713f, 0.00016424557543359697f, 0.0002555068931542337f, 0.00031397826387546957f, 0.00011057973460992798f, 0.0001373711129417643f, 0.000283096480416134f, 0.0002535558887757361f, 9.647121623856947e-05f, 0.0001969621516764164f, 0.00019236805383116007f, 0.0001926213299157098f, 0.00029359335894696414f, 0.0003009221109095961f, 0.00018415226077195257f, 0.00010032467980636284f, 0.00019222275295760483f, 0.00021397364616859704f, 0.00010398786253063008f, 0.00011674386041704565f, 0.00016087775293271989f, 9.889409557217732e-05f, 0.0003653976891655475f, 0.00016440247418358922f, 0.00017870568262878805f, 0.00013000707258470356f, 0.0002660461177583784f, 0.00014381101937033236f, 0.00016983885143417865f, 0.00028779389685951173f, 0.00023936451179906726f, 9.749657328939065e-05f, 0.00028859140002168715f, 0.00018949648074340075f, 0.00016557738126721233f, 0.00013915851013734937f, 0.0001588959275977686f, 0.00020365208911243826f, 9.399217378813773e-05f, 0.0001660376146901399f, 0.00011754377192119136f, 6.456172559410334e-05f, 0.00038740679156035185f, 0.00028314339579083025f, 0.00022989696299191564f, 0.00016701185086276382f, 9.679127833805978e-05f, 0.0001551621244288981f, 0.00033475286909379065f, 0.0001715706312097609f, 0.00012722154497168958f, 0.0001291390071855858f, 0.00020228610082995147f, 0.00016374904953408986f, 0.00015384869766421616f, 0.00011116947280243039f, 0.00038942042738199234f, 0.00025156926130875945f, 0.0003731631732080132f, 0.0001434757432434708f, 0.00031329222838394344f, 6.921054591657594e-05f, 0.00018090731464326382f, 0.000159172632265836f, 0.0003410606295801699f, 0.00020590037456713617f, 0.00021811002807226032f, 0.00011513491335790604f, 0.00050598249072209f, 0.0002220220339950174f, 0.0002587038616184145f, 0.000297709833830595f, 0.00030357655487023294f, 0.0002998092386405915f, 0.0002085994929075241f, 0.0002933577634394169f, 0.0002081216953229159f, 0.00014956999802961946f, 0.000149164508911781f, 0.0003157553437631577f, 0.00030916050309315324f, 0.00013981631491333246f, 0.00016721614520065486f, 0.00017056110664270818f, 0.00017190194921568036f, 0.0002441586693748832f, 0.0002288460818817839f, 0.0005215067067183554f, 0.0001515259500592947f, 0.00023792004503775388f, 0.0001690422068350017f, 0.00015922266175039113f, 9.253838652512059e-05f, 0.00018424313748255372f, 0.0003087793302256614f, 0.0003125611983705312f, 0.0002791634760797024f, 0.00022206665016710758f, 0.00013809616211801767f, 0.00021101465972606093f, 0.00026765099028125405f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #100 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 200,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0037829577922821045f, 0.0017846033442765474f, 0.0029808294493705034f, 0.002604146022349596f, 0.0016243901336565614f, 0.0005193751421757042f, 0.0017831489676609635f, 0.0029613818041980267f, 0.00269547151401639f, 0.0032905566040426493f, 0.0018864234443753958f, 0.0021655475720763206f, 0.001826109946705401f, 0.0026489929296076298f, 0.002669750014320016f, 0.0031639086082577705f, 0.0020460623782128096f, 0.0022239182144403458f, 0.0036474703811109066f, 0.002913192380219698f, 0.0023413177113980055f, 0.0018088050419464707f, 0.0028365047182887793f, 0.002831159858033061f, 0.0012780921533703804f, 0.0020352541469037533f, 0.0026514993514865637f, 0.002661782084032893f, 0.0016293548978865147f, 0.003702017478644848f, 0.0024503450840711594f, 0.001546062296256423f, 0.0017366260290145874f, 0.0030122711323201656f, 0.0022349043283611536f, 0.0026757759042084217f, 0.0021853800863027573f, 0.004247946664690971f, 0.003041053656488657f, 0.0024159473832696676f, 0.004499569535255432f, 0.0020504938438534737f, 0.0037461258471012115f, 0.003992980811744928f, 0.00239648949354887f, 0.0021064423490315676f, 0.003686188720166683f, 0.0021909947972744703f, 0.00425809295848012f, 0.001999679720029235f, 0.0029746515210717916f, 0.003193045035004616f, 0.0019320863066241145f, 0.0018739565275609493f, 0.0022518972400575876f, 0.0022842679172754288f, 0.0029226301703602076f, 0.003985890187323093f, 0.002637503668665886f, 0.002239466877654195f, 0.001467393827624619f, 0.0035347063094377518f, 0.003281003562733531f, 0.0030613576527684927f, 0.0020717214792966843f, 0.0029867147095501423f, 0.002157355658710003f, 0.001307405298575759f, 0.002293010475113988f, 0.003800556994974613f, 0.0033904188312590122f, 0.0020433305762708187f, 0.003906747791916132f, 0.0028704379219561815f, 0.002232885453850031f, 0.002638832665979862f, 0.005044204648584127f, 0.004314890597015619f, 0.003167200367897749f, 0.003257517935708165f, 0.003315762849524617f, 0.0013408331433311105f, 0.0029021750669926405f, 0.0027285679243505f, 0.002271587960422039f, 0.0027185578364878893f, 0.0015520310262218118f, 0.0022404638584703207f, 0.002324808156117797f, 0.002123408019542694f, 0.0032686651684343815f, 0.0024330727756023407f, 0.0015737360808998346f, 0.002979573095217347f, 0.0012476479168981314f, 0.001708372263237834f, 0.0023193415254354477f, 0.003010548884049058f, 0.0021813171915709972f, 0.002563243033364415f, 0.001685405382886529f, 0.0019431901164352894f, 0.0031188770662993193f, 0.0016820459859445691f, 0.0024412949569523335f, 0.002065973589196801f, 0.004189541097730398f, 0.0033442021813243628f, 0.0035395543090999126f, 0.0027906429022550583f, 0.002868657000362873f, 0.001992617966607213f, 0.0032536410726606846f, 0.0018968433141708374f, 0.0032405764795839787f, 0.002827397547662258f, 0.00212487718090415f, 0.0021873542573302984f, 0.0041184197179973125f, 0.0025765385944396257f, 0.003269398817792535f, 0.0033424522262066603f, 0.00258884415961802f, 0.003914752043783665f, 0.002373674651607871f, 0.0038020755164325237f, 0.002807017182931304f, 0.0025941103231161833f, 0.0028465879149734974f, 0.002413299633190036f, 0.0020893842447549105f, 0.002862125402316451f, 0.002275981241837144f, 0.0034477089066058397f, 0.003859642893075943f, 0.004900387953966856f, 0.0017531601479277015f, 0.0022734312806278467f, 0.0029862162191420794f, 0.0030828455928713083f, 0.003998608328402042f, 0.0021504894830286503f, 0.0016925103263929486f, 0.0018019621493294835f, 0.00292967283166945f, 0.0020116998348385096f, 0.002256843028590083f, 0.0030202583875507116f, 0.0026081078685820103f, 0.0020032753236591816f, 0.0037832881789654493f, 0.0019508595578372478f, 0.0036879898980259895f, 0.0024080739822238684f, 0.0036772063467651606f, 0.003809861373156309f, 0.0033442918211221695f, 0.0015676947077736259f, 0.002182281343266368f, 0.002282272092998028f, 0.002086661057546735f, 0.0028605544939637184f, 0.002954552648589015f, 0.0025122803635895252f, 0.001998352585360408f, 0.0018334629712626338f, 0.0020852794405072927f, 0.0029334763530641794f, 0.0031370033975690603f, 0.0019382578320801258f, 0.0021423145662993193f, 0.0029051515739411116f, 0.002208682242780924f, 0.003398517146706581f, 0.002461767289787531f, 0.004358173348009586f, 0.0032775255385786295f, 0.00293877930380404f, 0.002112094545736909f, 0.0033172413241118193f, 0.0016712525393813848f, 0.002759667346253991f, 0.002009872579947114f, 0.005163349211215973f, 0.001906813820824027f, 0.0016104212263599038f, 0.0038822833448648453f, 0.002459429670125246f, 0.002577472012490034f, 0.001424306188710034f, 0.0016391213284805417f, 0.004159983247518539f, 0.00353807769715786f, 0.002338679041713476f, 0.0028578280471265316f, 0.001946567092090845f, 0.0013382495380938053f, 0.0033835486974567175f, 0.005112696439027786f, 0.0017282427288591862f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #101 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 200,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00026961174444295466f, 0.00012718884681817144f, 0.0002124439924955368f, 0.0001855977316154167f, 0.00011577043915167451f, 3.7015914131188765e-05f, 0.00012708519352599978f, 0.00021105795167386532f, 0.00019210651225876063f, 0.00023451827291864902f, 0.0001344455813523382f, 0.0001543387770652771f, 0.00013014703290537f, 0.00018879397248383611f, 0.00019027333473786712f, 0.0002254920545965433f, 0.00014582305448129773f, 0.0001584988640388474f, 0.0002599555591586977f, 0.00020762349595315754f, 0.000166865938808769f, 0.000128913699882105f, 0.00020215795666445047f, 0.0002017770311795175f, 9.108975064009428e-05f, 0.00014505274884868413f, 0.00018897261179517955f, 0.00018970546079799533f, 0.00011612427624640986f, 0.0002638431324157864f, 0.00017463632684666663f, 0.00011018800432793796f, 0.0001237694959854707f, 0.00021468484192155302f, 0.0001592818443896249f, 0.0001907028054120019f, 0.00015575224824715406f, 0.0003027515485882759f, 0.0002167361817555502f, 0.00017218479479197413f, 0.0003206847468391061f, 0.0001461388892494142f, 0.00026698672445490956f, 0.0002845801063813269f, 0.00017079802637454122f, 0.00015012634685263038f, 0.0002627150097396225f, 0.0001561523968121037f, 0.00030347469146363437f, 0.00014251735410653055f, 0.0002120036951964721f, 0.00022756861289963126f, 0.00013769997167401016f, 0.00013355705596040934f, 0.00016049292753450572f, 0.000162799988174811f, 0.00020829612913075835f, 0.00028407477657310665f, 0.0001879751362139359f, 0.00015960700693540275f, 0.0001045812969096005f, 0.00025191885652020574f, 0.00023383743246085942f, 0.00021818323875777423f, 0.00014765177911613137f, 0.00021286343690007925f, 0.0001537549396743998f, 9.317889634985477e-05f, 0.00016342307208105922f, 0.00027086606132797897f, 0.00024163546913769096f, 0.0001456283644074574f, 0.0002784342796076089f, 0.00020457638311199844f, 0.0001591379550518468f, 0.00018806985463015735f, 0.0003595009329728782f, 0.0003075226559303701f, 0.00022572666057385504f, 0.00023216361296363175f, 0.00023631472140550613f, 9.556130680721253e-05f, 0.0002068382891593501f, 0.00019446529040578753f, 0.00016189628513529897f, 0.00019375186820980161f, 0.0001106133931898512f, 0.00015967806393746287f, 0.0001656893000472337f, 0.00015133549459278584f, 0.00023295807477552444f, 0.00017340532212983817f, 0.0001121603199862875f, 0.00021235445456113666f, 8.891998004401103e-05f, 0.0001217558528878726f, 0.0001652996870689094f, 0.00021456209651660174f, 0.00015546267968602479f, 0.00018268257554154843f, 0.0001201190025312826f, 0.0001384913339279592f, 0.00022228265879675746f, 0.00011987957259407267f, 0.00017399131320416927f, 0.0001472421281505376f, 0.00029858897323720157f, 0.00023834159947000444f, 0.0002522643771953881f, 0.00019888937822543085f, 0.0002044494467554614f, 0.00014201406156644225f, 0.00023188730119727552f, 0.0001351881946902722f, 0.00023095618234947324f, 0.0002015088830376044f, 0.00015144019562285393f, 0.0001558929361635819f, 0.00029352016281336546f, 0.000183630152605474f, 0.00023301035980693996f, 0.0002382168750045821f, 0.0001845071674324572f, 0.00027900474378839135f, 0.00016917200991883874f, 0.0002709742693696171f, 0.00020005638361908495f, 0.00018488249043002725f, 0.00020287658844608814f, 0.00017199608555529267f, 0.00014891060709487647f, 0.00020398394553922117f, 0.00016220939869526774f, 0.00024571854737587273f, 0.0002750771236605942f, 0.0003492511168587953f, 0.0001249478809768334f, 0.00016202765982598066f, 0.0002128279156750068f, 0.0002197146968683228f, 0.00028498118626885116f, 0.00015326558786910027f, 0.00012062536552548409f, 0.0001284260069951415f, 0.00020879805379081517f, 0.00014337403990793973f, 0.00016084541857708246f, 0.0002152540982933715f, 0.00018588009697850794f, 0.0001427736133337021f, 0.00026963528944179416f, 0.00013903794751968235f, 0.0002628433867357671f, 0.00017162365838885307f, 0.00026207484188489616f, 0.0002715291630011052f, 0.0002383479877607897f, 0.00011172975064255297f, 0.00015553139382973313f, 0.00016265774320345372f, 0.00014871652820147574f, 0.0002038719831034541f, 0.00021057124831713736f, 0.00017905046115629375f, 0.0001424227812094614f, 0.00013067107647657394f, 0.00014861805539112538f, 0.0002090691268676892f, 0.00022357451962307096f, 0.00013813981786370277f, 0.00015268295828718692f, 0.00020705042697954923f, 0.00015741298557259142f, 0.00024221262719947845f, 0.00017545039008837193f, 0.0003106074291281402f, 0.00023358955513685942f, 0.00020944706921000034f, 0.00015052917296998203f, 0.00023642009182367474f, 0.00011911032197531313f, 0.000196681750821881f, 0.00014324380026664585f, 0.00036799238296225667f, 0.00013589879381470382f, 0.00011477486987132579f, 0.00027669069822877645f, 0.00017528378521092236f, 0.00018369666940998286f, 0.0001015104353427887f, 0.00011682033073157072f, 0.00029648237978108227f, 0.00025215913774445653f, 0.00016667786985635757f, 0.00020367767137940973f, 0.0001387320226058364f, 9.537716687191278e-05f, 0.00024114582629408687f, 0.0003643823438324034f, 0.00012317202345002443f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #102 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 200,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013872843701392412f, 0.0041667381301522255f, 0.0038170162588357925f, 0.0014755894662812352f, 0.0013237742241472006f, 0.0035604906734079123f, 0.0035145145375281572f, 0.0014265921199694276f, 0.001176757737994194f, 0.003614025888964534f, 0.002410039771348238f, 0.0020934767089784145f, 0.0034261562395840883f, 0.0020500842947512865f, 0.00543568842113018f, 0.002895616227760911f, 0.0046334657818078995f, 0.002783555304631591f, 0.0031534917652606964f, 0.0014589043566957116f, 0.0029501672834157944f, 0.0025471930857747793f, 0.0029554946813732386f, 0.004865153692662716f, 0.0024280352517962456f, 0.0031605984549969435f, 0.0017579321283847094f, 0.004056544043123722f, 0.003343832679092884f, 0.0021213348954916f, 0.0018712545279413462f, 0.0020039775408804417f, 0.005032800603657961f, 0.002190309576690197f, 0.00255756382830441f, 0.0033259165938943624f, 0.0028510144911706448f, 0.002844065660610795f, 0.0023218842688947916f, 0.0032616066746413708f, 0.0011207113275304437f, 0.004954037256538868f, 0.0009207891416735947f, 0.003767395159229636f, 0.0053954231552779675f, 0.0028089326806366444f, 0.0016708408948034048f, 0.003295252798125148f, 0.004692820366472006f, 0.0015430987114086747f, 0.0019471158739179373f, 0.002452230779454112f, 0.00313771259970963f, 0.002666910644620657f, 0.0036029061302542686f, 0.0015241117216646671f, 0.003331389045342803f, 0.0019729058258235455f, 0.003633568761870265f, 0.0037012570537626743f, 0.002489708364009857f, 0.0007030686247162521f, 0.003970378544181585f, 0.005027770530432463f, 0.0017100119730457664f, 0.0014562602154910564f, 0.002617653924971819f, 0.0032107774168252945f, 0.002708784304559231f, 0.0034958506003022194f, 0.0035497869830578566f, 0.00127786910161376f, 0.002101678168401122f, 0.0021965906489640474f, 0.0037555526942014694f, 0.001001693424768746f, 0.0033270339481532574f, 0.0034113330766558647f, 0.0009481993038207293f, 0.003088138299062848f, 0.002098164288327098f, 0.0009662679512985051f, 0.0008626010967418551f, 0.0028048830572515726f, 0.003318783827126026f, 0.0023514709901064634f, 0.0013000473845750093f, 0.0005624956102110445f, 0.0014319324400275946f, 0.0007976579945534468f, 0.0032116856891661882f, 0.0043458822183310986f, 0.0023768870159983635f, 0.0030567299108952284f, 0.0036969890352338552f, 0.0033236141316592693f, 0.0028285481967031956f, 0.002436057198792696f, 0.0025736859533935785f, 0.001795724150724709f, 0.0020188335329294205f, 0.001453900127671659f, 0.002511286176741123f, 0.0034475072752684355f, 0.002748503815382719f, 0.0020500037353485823f, 0.0017197099514305592f, 0.0026304996572434902f, 0.0026590425986796618f, 0.0034792942460626364f, 0.004172186367213726f, 0.0013136385241523385f, 0.0024153629783540964f, 0.001853710156865418f, 0.0011035819770768285f, 0.0023850160650908947f, 0.001778705627657473f, 0.001973991747945547f, 0.0027034124359488487f, 0.0030784988775849342f, 0.0025507695972919464f, 0.005588914733380079f, 0.003123933682218194f, 0.003075519809499383f, 0.0017394120804965496f, 0.0022093667648732662f, 0.0025781989097595215f, 0.0023644673638045788f, 0.002225474687293172f, 0.00641943234950304f, 0.001949324388988316f, 0.004845381248742342f, 0.0030821121763437986f, 0.0019668748136609793f, 0.002963628154247999f, 0.003905662801116705f, 0.0025238581001758575f, 0.002186242025345564f, 0.0035359265748411417f, 0.0025336826220154762f, 0.001669594319537282f, 0.002220808295533061f, 0.0012913551181554794f, 0.004354614764451981f, 0.00334107200615108f, 0.0027847401797771454f, 0.002610304858535528f, 0.004179907497018576f, 0.0024088555946946144f, 0.0012367840390652418f, 0.0009143021306954324f, 0.0034250931348651648f, 0.0027750087901949883f, 0.0032442135270684958f, 0.0039078714326024055f, 0.0009255980257876217f, 0.003276829607784748f, 0.0033156503923237324f, 0.0020293460693210363f, 0.0033862569835036993f, 0.002629925962537527f, 0.003380092093721032f, 0.002197391353547573f, 0.005303164012730122f, 0.0021297468338161707f, 0.0026738853193819523f, 0.0022156056948006153f, 0.002787746721878648f, 0.003554691094905138f, 0.004080607555806637f, 0.002835904248058796f, 0.0021240748465061188f, 0.002734095323830843f, 0.002639650832861662f, 0.0017743029166013002f, 0.0023588924668729305f, 0.0019936368335038424f, 0.00326348259113729f, 0.00473840581253171f, 0.0026173198129981756f, 0.0027879260014742613f, 0.0030712545849382877f, 0.004280076827853918f, 0.0011943617137148976f, 0.0017057906370609999f, 0.0020030566956847906f, 0.0033751041628420353f, 0.0022088491823524237f, 0.004462313838303089f, 0.002506680553779006f, 0.0036286180838942528f, 0.003096093889325857f, 0.00576269906014204f, 0.002926402725279331f, 0.002716946182772517f, 0.002593576442450285f, 0.0030704434029757977f, 0.005387190729379654f, 0.0028750819619745016f, 0.0042029754258692265f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #103 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 200,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.005805623019114e-05f, 0.0002704912913031876f, 0.00024778847000561655f, 9.5790543127805e-05f, 8.59351857798174e-05f, 0.00023113565111998469f, 0.0002281510242028162f, 9.260979277314618e-05f, 7.639134128112346e-05f, 0.00023461098317056894f, 0.00015645206440240145f, 0.0001359018060611561f, 0.00022241509577725083f, 0.00013308490451890975f, 0.00035286747151985765f, 0.00018797413213178515f, 0.00030078974668867886f, 0.0001806994987418875f, 0.00020471458265092224f, 9.470740042161196e-05f, 0.00019151541346218437f, 0.00016535561007913202f, 0.00019186125427950174f, 0.00031583019881509244f, 0.0001576202776050195f, 0.00020517592201940715f, 0.00011411932064220309f, 0.0002633378317113966f, 0.0002170709049096331f, 0.0001377102598780766f, 0.00012147585221100599f, 0.00013009180838707834f, 0.00032671328517608345f, 0.0001421878841938451f, 0.0001660288544371724f, 0.0002159078576369211f, 0.00018507872300688177f, 0.00018462762818671763f, 0.00015072929090820253f, 0.00021173305867705494f, 7.275299140019342e-05f, 0.0003216002369299531f, 5.9774680266855285e-05f, 0.0002445672289468348f, 0.0003502535982988775f, 0.0001823469065129757f, 0.00010846563964150846f, 0.00021391725749708712f, 0.00030464286101050675f, 0.00010017302702181041f, 0.00012640052591450512f, 0.00015919096767902374f, 0.00020369025878608227f, 0.000173127293237485f, 0.00023388912086375058f, 9.894045069813728e-05f, 0.00021626311354339123f, 0.00012807472376152873f, 0.00023587964824400842f, 0.0002402737591182813f, 0.00016162388783413917f, 4.5640961616300046e-05f, 0.0002577442501205951f, 0.00032638676930218935f, 0.0001110084995161742f, 9.453574602957815e-05f, 0.00016992971359286457f, 0.0002084333827951923f, 0.00017584560555405915f, 0.00022693941718898714f, 0.00023044079716783017f, 8.29551718197763e-05f, 0.00013643421698361635f, 0.00014259562885854393f, 0.00024379845126532018f, 6.50267320452258e-05f, 0.0002159803843824193f, 0.0002214528212789446f, 6.155406299512833e-05f, 0.00020047204452566803f, 0.00013620610116049647f, 6.272702012211084e-05f, 5.599730138783343e-05f, 0.00018208402616437525f, 0.00021544481569435447f, 0.0001526499690953642f, 8.439490920864046e-05f, 3.651541192084551e-05f, 9.295647032558918e-05f, 5.178140054340474e-05f, 0.00020849234715569764f, 0.00028212074539624155f, 0.0001542998943477869f, 0.00019843311747536063f, 0.0002399966906523332f, 0.00021575838036369532f, 0.00018362028640694916f, 0.00015814103244338185f, 0.00016707544273231179f, 0.00011657265713438392f, 0.0001310562074650079f, 9.438253619009629e-05f, 0.00016302465519402176f, 0.0002238011365989223f, 0.00017842405941337347f, 0.00013307968038134277f, 0.00011163805902469903f, 0.00017076361109502614f, 0.00017261653556488454f, 0.00022586464183405042f, 0.00027084496105089784f, 8.527720638085157e-05f, 0.00015679762873332947f, 0.00012033692473778501f, 7.164100679801777e-05f, 0.0001548276050016284f, 0.0001154678757302463f, 0.00012814522779081017f, 0.00017549688345752656f, 0.0001998462830670178f, 0.00016558778588660061f, 0.0003628144331742078f, 0.00020279576710890979f, 0.0001996528881136328f, 0.00011291706323390827f, 0.0001434250152669847f, 0.0001673684164416045f, 0.00015349364548455924f, 0.00014447068679146469f, 0.0004167289880570024f, 0.000126543891383335f, 0.0003145466325804591f, 0.00020008084538858384f, 0.00012768321903422475f, 0.00019238924141973257f, 0.0002535431121941656f, 0.0001638407848076895f, 0.00014192382514011115f, 0.0002295410231454298f, 0.00016447856614831835f, 0.00010838471644092351f, 0.00014416775957215577f, 8.383063686778769e-05f, 0.0002826876298058778f, 0.00021689169807359576f, 0.00018077642016578466f, 0.00016945262905210257f, 0.00027134621632285416f, 0.00015637518663424999f, 8.028806041693315e-05f, 5.935356603004038e-05f, 0.00022234607604332268f, 0.00018014467786997557f, 0.0002106039464706555f, 0.0002536865067668259f, 6.008685886627063e-05f, 0.00021272127924021333f, 0.00021524140902329236f, 0.00013173864863347262f, 0.00021982495673000813f, 0.00017072637274395674f, 0.00021942474995739758f, 0.00014264760829973966f, 0.0003442644083406776f, 0.00013825634960085154f, 0.00017358007607981563f, 0.0001438300241716206f, 0.0001809715904528275f, 0.00023075916396919638f, 0.00026489997981116176f, 0.00018409782205708325f, 0.00013788814248982817f, 0.00017748870595823973f, 0.00017135767848230898f, 0.00011518206156324595f, 0.00015313173935282975f, 0.00012942051398567855f, 0.00021185484365560114f, 0.00030760213849134743f, 0.00016990801668725908f, 0.0001809832319850102f, 0.00019937600882258266f, 0.00027784888516180217f, 7.753413956379518e-05f, 0.00011073446512455121f, 0.00013003202911932021f, 0.0002191009552916512f, 0.0001433914148947224f, 0.0002896791265811771f, 0.00016272567154373974f, 0.00023555826919618994f, 0.00020098849199712276f, 0.0003740959509741515f, 0.00018997269216924906f, 0.00017637544078752398f, 0.00016836667782627046f, 0.0001993233454413712f, 0.0003497191646602005f, 0.00018664111848920584f, 0.0002728436957113445f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #104 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_50_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 51,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013687130995094776f, 0.0024451003409922123f, 0.003331010928377509f, 0.0015958804870024323f, 0.006819167174398899f, 0.0015395747032016516f, 0.002706248313188553f, 0.004135035909712315f, 0.0015094951959326863f, 0.003600094234570861f, 0.0019776916597038507f, 0.0019133437890559435f, 0.00406622514128685f, 0.002749756211414933f, 0.0027620946057140827f, 0.002257879124954343f, 0.0027682073414325714f, 0.0037192339077591896f, 0.003431265242397785f, 0.0024574340786784887f, 0.0014585144817829132f, 0.0016685979207977653f, 0.002761610085144639f, 0.002136847237125039f, 0.007778267841786146f, 0.0033244392834603786f, 0.003542287042364478f, 0.0031629607547074556f, 0.002882333006709814f, 0.004575513303279877f, 0.002486336277797818f, 0.0024514771066606045f, 0.003357871435582638f, 0.0015067718923091888f, 0.002171900123357773f, 0.0023682534229010344f, 0.006486681755632162f, 0.001305975834839046f, 0.006308475974947214f, 0.0016708511393517256f, 0.0012113970005884767f, 0.002225336618721485f, 0.004452982917428017f, 0.005708242766559124f, 0.0015087981009855866f, 0.0017151797655969858f, 0.002485938835889101f, 0.007891261018812656f, 0.0025395089760422707f, 0.0045721749775111675f, 0.0012435814132913947f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #105 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_50_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 51,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.506283534690738e-05f, 0.00011622973397606984f, 0.00015834218356758356f, 7.586141146020964e-05f, 0.00032415438909083605f, 7.318487769225612e-05f, 0.00012864360178355128f, 0.00019656213407870382f, 7.175502105383202e-05f, 0.0001711332588456571f, 9.401110582984984e-05f, 9.09522786969319e-05f, 0.00019329115457367152f, 0.00013071179273538291f, 0.00013129830767866224f, 0.00010733003000495955f, 0.00013158888032194227f, 0.0001767966605257243f, 0.00016310784849338233f, 0.00011681603064062074f, 6.933161057531834e-05f, 7.931809523142874e-05f, 0.00013127527199685574f, 0.00010157668293686584f, 0.00036974597605876625f, 0.0001580297976033762f, 0.00016838534793350846f, 0.00015035377873573452f, 0.0001370139216305688f, 0.00021750056475866586f, 0.00011818992061307654f, 0.00011653285764623433f, 0.00015961901226546615f, 7.162556721596047e-05f, 0.00010324294999008998f, 0.00011257675942033529f, 0.000308349437545985f, 6.208057311596349e-05f, 0.0002998782729264349f, 7.942520460346714e-05f, 5.758469342254102e-05f, 0.00010578309593256563f, 0.0002116759860655293f, 0.0002713457215577364f, 7.172188634285703e-05f, 8.15323946881108e-05f, 0.0001181710249511525f, 0.0003751172043848783f, 0.00012071752280462533f, 0.00021734187612310052f, 5.9114605392096564e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #106 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_53_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 51,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004059186903759837f, 0.0010745764011517167f, 0.0021071447990834713f, 0.0011517771054059267f, 0.0004809116944670677f, 0.001109170843847096f, 0.0006799132679589093f, 0.0018635918386280537f, 0.001815721858292818f, 0.0010179778328165412f, 0.000275235011940822f, 0.002027336275205016f, 0.00358785898424685f, 0.0031441724859178066f, 0.00196712464094162f, 0.0004975061165168881f, 0.0007946715923026204f, 0.003418933367356658f, 0.0006375015364028513f, 0.0004076649493072182f, 0.0007022705976851285f, 0.0007546167471446097f, 0.0003572254499886185f, 0.0009310350869782269f, 0.0014897031942382455f, 0.0005157972918823361f, 0.0005966940661892295f, 0.002283126348629594f, 0.00032644483144395053f, 0.0004989031585864723f, 0.00035196906537748873f, 0.0036738060880452394f, 0.00073701684596017f, 0.00039597004069946706f, 0.0009683002135716379f, 0.0008461683173663914f, 0.00041804954526014626f, 0.0012046553893014789f, 0.0028613791801035404f, 0.0003084359923377633f, 0.0008162364247255027f, 0.0016261489363387227f, 0.0006674927426502109f, 0.0004179116222076118f, 0.0016277969116345048f, 0.0020080963149666786f, 0.0011935572838410735f, 0.0009744962444528937f, 0.002996620023623109f, 0.003002083394676447f, 0.001617056899704039f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #107 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_53_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 51,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.802023482217919e-05f, 7.417712913593277e-05f, 0.00014545448357239366f, 7.950622966745868e-05f, 3.319694224046543e-05f, 7.656515663256869e-05f, 4.6933855628594756e-05f, 0.00012864221935160458f, 0.0001253377995453775f, 7.027018000371754e-05f, 1.8999247913598083e-05f, 0.00013994536129757762f, 0.0002476669615134597f, 0.0002170396619476378f, 0.0001357889996143058f, 3.4342439903412014e-05f, 5.485552901518531e-05f, 0.00023600617714691907f, 4.4006210373481736e-05f, 2.814077743096277e-05f, 4.847716627409682e-05f, 5.209057781030424e-05f, 2.4658980692038313e-05f, 6.426859181374311e-05f, 0.00010283299343427643f, 3.560506593203172e-05f, 4.118930519325659e-05f, 0.00015760234964545816f, 2.2534219169756398e-05f, 3.44388754456304e-05f, 2.42961359617766e-05f, 0.00025359983555972576f, 5.0875671149697155e-05f, 2.7333488105796278e-05f, 6.68409702484496e-05f, 5.841030724695884e-05f, 2.8857617508037947e-05f, 8.315637387568131e-05f, 0.00019751866057049483f, 2.1291083612595685e-05f, 5.634413173538633e-05f, 0.00011225172784179449f, 4.6076478611212224e-05f, 2.8848096917499788e-05f, 0.00011236548743909225f, 0.00013861725165043026f, 8.239028102252632e-05f, 6.726868014084175e-05f, 0.00020685422350652516f, 0.00020723136549349874f, 0.00011162411828991026f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #108 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 51,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0038966380525380373f, 0.009335014969110489f, 0.011803334578871727f, 0.00411002105101943f, 0.009319636039435863f, 0.011987881734967232f, 0.003727469826117158f, 0.009265809319913387f, 0.014125553891062737f, 0.004655973054468632f, 0.008043183945119381f, 0.008143147453665733f, 0.0032545675057917833f, 0.007889394648373127f, 0.011641855351626873f, 0.004459891933947802f, 0.005182701628655195f, 0.008842889219522476f, 0.005594088230282068f, 0.0051557887345552444f, 0.009135088883340359f, 0.004709799308329821f, 0.006820558570325375f, 0.0062323142774403095f, 0.007258858066052198f, 0.007870171219110489f, 0.007135826628655195f, 0.009619524702429771f, 0.016532357782125473f, 0.006220779847353697f, 0.0073203737847507f, 0.01913139782845974f, 0.006882074289023876f, 0.005271130707114935f, 0.006447619292885065f, 0.009296567179262638f, 0.005048136226832867f, 0.006270761601626873f, 0.009488804265856743f, 0.005509504117071629f, 0.0065398928709328175f, 0.011803334578871727f, 0.00537109375f, 0.006705216597765684f, 0.01189560815691948f, 0.00752414483577013f, 0.009442667476832867f, 0.014786847867071629f, 0.007997047156095505f, 0.00938884075731039f, 0.014840674586594105f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #109 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 51,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.888936251110863e-05f, 6.920905434526503e-05f, 8.750897541176528e-05f, 3.0471366699202918e-05f, 6.909503281349316e-05f, 8.887719741323963e-05f, 2.763516386039555e-05f, 6.869596836622804e-05f, 0.00010472572466824204f, 3.451901284279302e-05f, 5.963152216281742e-05f, 6.037264392944053e-05f, 2.4129103621817194e-05f, 5.8491339586908e-05f, 8.631178206996992e-05f, 3.306528378743678e-05f, 3.842413570964709e-05f, 6.556047446792945e-05f, 4.14741225540638e-05f, 3.822460348601453e-05f, 6.772681808797643e-05f, 3.491807365207933e-05f, 5.056707595940679e-05f, 4.620587787940167e-05f, 5.381659138947725e-05f, 5.834881812916137e-05f, 5.290444823913276e-05f, 7.131838356144726e-05f, 0.00012256957415957004f, 4.612036354956217e-05f, 5.4272666602628306e-05f, 0.00014183865278027952f, 5.102314753457904e-05f, 3.90797431464307e-05f, 4.7802132030483335e-05f, 6.892400415381417e-05f, 3.74264782294631e-05f, 4.6490924432873726e-05f, 7.034923328319564e-05f, 4.0847022319212556e-05f, 4.848624303122051e-05f, 8.750897541176528e-05f, 3.9820857637096196e-05f, 4.971193993696943e-05f, 8.819309005048126e-05f, 5.5783406423870474e-05f, 7.000718323979527e-05f, 0.0001096285050152801f, 5.9289468481438234e-05f, 6.960811151657254e-05f, 0.00011002757673850283f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #110 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_40_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 200,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001871795509941876f, 0.0014473001938313246f, 0.0013329017674550414f, 0.0038838116452097893f, 0.002821704838424921f, 0.0015962128527462482f, 0.00149709137622267f, 0.001601613126695156f, 0.0016074343584477901f, 0.001054366584867239f, 0.0010235540103167295f, 0.001723072724416852f, 0.0012767926091328263f, 0.0013635843060910702f, 0.0018558937590569258f, 0.0012320991372689605f, 0.0014104447327554226f, 0.001065651886165142f, 0.0015613057184964418f, 0.0007246636087074876f, 0.0013640237739309669f, 0.0023696962743997574f, 0.0014733674470335245f, 0.0010324805043637753f, 0.001307185972109437f, 0.0015743373660370708f, 0.0009596154559403658f, 0.001330666127614677f, 0.0024416062515228987f, 0.0008729515830054879f, 0.0009667029953561723f, 0.0019821529276669025f, 0.0013567276764661074f, 0.0014259861782193184f, 0.0015860064886510372f, 0.0034356943797320127f, 0.0026888723950833082f, 0.0038585143629461527f, 0.003956973552703857f, 0.0018047592602670193f, 0.001443883404135704f, 0.0011005784617736936f, 0.0013539891224354506f, 0.002363247564062476f, 0.0017700294265523553f, 0.0033055655658245087f, 0.0020088208839297295f, 0.0010981722734868526f, 0.0013392012333497405f, 0.0009871476795524359f, 0.0019974675960838795f, 0.0009639181080274284f, 0.0011026478605344892f, 0.0015941997990012169f, 0.002776307286694646f, 0.003251713467761874f, 0.0013372277608141303f, 0.0028261321131139994f, 0.0016787267522886395f, 0.001402009278535843f, 0.0017523478018119931f, 0.0014668848598375916f, 0.0013359340373426676f, 0.0011086751474067569f, 0.0015258777420967817f, 0.0020908480510115623f, 0.0023862957023084164f, 0.0033573268447071314f, 0.0021434230729937553f, 0.0021042856387794018f, 0.0011647260980680585f, 0.0016213705530390143f, 0.0016242414712905884f, 0.0014142621075734496f, 0.001778569188900292f, 0.002980373566970229f, 0.002159308874979615f, 0.001929719583131373f, 0.0018549078376963735f, 0.0015845542075112462f, 0.0014154902892187238f, 0.000958378310315311f, 0.001494126976467669f, 0.0012388145551085472f, 0.0008203597390092909f, 0.0012098111910745502f, 0.0019798623397946358f, 0.0015369642060250044f, 0.001508387504145503f, 0.0026746296789497137f, 0.0011888742446899414f, 0.0007886989624239504f, 0.0012257903581485152f, 0.00112434895709157f, 0.0021312565077096224f, 0.002179107628762722f, 0.0010451594134792686f, 0.0018023352604359388f, 0.001984659116715193f, 0.004797206725925207f, 0.001675936277024448f, 0.0013247971655800939f, 0.0031153468880802393f, 0.0016431238036602736f, 0.001284936210140586f, 0.001929360325448215f, 0.0012922544265165925f, 0.0030683744698762894f, 0.0016416441649198532f, 0.002162323798984289f, 0.002198269357904792f, 0.001173364114947617f, 0.0018208316760137677f, 0.002597152953967452f, 0.001096707652322948f, 0.003967811353504658f, 0.0027829238679260015f, 0.0008704844512976706f, 0.0016634472412988544f, 0.001868471154011786f, 0.0015081620076671243f, 0.0014309246325865388f, 0.0026754748541861773f, 0.003478760365396738f, 0.001123842317610979f, 0.0013125709956511855f, 0.0017029066802933812f, 0.0012400350533425808f, 0.0011160853318870068f, 0.0011567852925509214f, 0.001662621391005814f, 0.00122868362814188f, 0.0026196795515716076f, 0.0009703140240162611f, 0.0030312221497297287f, 0.0012071653036400676f, 0.0022345019970089197f, 0.003354043001309037f, 0.003466617548838258f, 0.0014135375386103988f, 0.0010285400785505772f, 0.001310418825596571f, 0.0027155443094670773f, 0.00225567608140409f, 0.0026625872123986483f, 0.0011349720880389214f, 0.0017492964398115873f, 0.003611144842579961f, 0.0013474239967763424f, 0.0012781514087691903f, 0.0012266249395906925f, 0.00172045873478055f, 0.003267092863097787f, 0.0012819243129342794f, 0.0019149326253682375f, 0.001507710781879723f, 0.0014880179660394788f, 0.0015619435580447316f, 0.0018386683659628034f, 0.0011325636878609657f, 0.00335523160174489f, 0.0018491980154067278f, 0.0013081529177725315f, 0.003542464692145586f, 0.001158265396952629f, 0.0008157318225130439f, 0.003124137409031391f, 0.0018101573223248124f, 0.001036942470818758f, 0.002307908609509468f, 0.0017734032589942217f, 0.003085359465330839f, 0.002139086602255702f, 0.0032441411167383194f, 0.001218136283569038f, 0.0013967296108603477f, 0.00162525475025177f, 0.0010759312426671386f, 0.0011695740977302194f, 0.0011244001798331738f, 0.0013497119070962071f, 0.0011458166409283876f, 0.0009313873015344143f, 0.0011809893185272813f, 0.001330948551185429f, 0.002743892604485154f, 0.0031717231031507254f, 0.0018417370738461614f, 0.0030519384890794754f, 0.0013319102581590414f, 0.0011055141221731901f, 0.0014028080040588975f, 0.0009370870538987219f, 0.0012741455575451255f, 0.0007631222833879292f, 0.0011262529296800494f, 0.0012197681935504079f, 0.003121392335742712f, 0.0018091327510774136f, 0.0013028424000367522f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #111 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_40_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 200,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.897724910639226e-05f, 6.879853754071519e-05f, 6.336051592370495e-05f, 0.00018461998843122274f, 0.00013413191481959075f, 7.587721484014764e-05f, 7.116539927665144e-05f, 7.613391790073365e-05f, 7.641063712071627e-05f, 5.012013207306154e-05f, 4.865543087362312e-05f, 8.19075939944014e-05f, 6.069332448532805e-05f, 6.481903255917132e-05f, 8.822134259389713e-05f, 5.8568784879753366e-05f, 6.70465815346688e-05f, 5.065658478997648e-05f, 7.42178744985722e-05f, 3.444744652369991e-05f, 6.483992183348164e-05f, 0.00011264534259680659f, 7.003766222624108e-05f, 4.907975744572468e-05f, 6.213809683686122e-05f, 7.483734225388616e-05f, 4.561606328934431e-05f, 6.325424328679219e-05f, 0.00011606363841565326f, 4.1496427002130076e-05f, 4.595297286869027e-05f, 9.422317089047283e-05f, 6.449309876188636e-05f, 6.778535316698253e-05f, 7.539204671047628e-05f, 0.00016331838560290635f, 0.00012781763507518917f, 0.00018341746181249619f, 0.00018809779430739582f, 8.57906270539388e-05f, 6.863611633889377e-05f, 5.231684917816892e-05f, 6.436291732825339e-05f, 0.00011233879922656342f, 8.41397195472382e-05f, 0.00015713261382188648f, 9.54908537096344e-05f, 5.220246748649515e-05f, 6.365996523527429e-05f, 4.692482980317436e-05f, 9.495116682955995e-05f, 4.5820594095857814e-05f, 5.241522012511268e-05f, 7.57815214456059e-05f, 0.00013197390944696963f, 0.00015457271365448833f, 6.356615631375462e-05f, 0.00013434237916953862f, 7.979957445058972e-05f, 6.664559623459354e-05f, 8.329920819960535e-05f, 6.972950359340757e-05f, 6.350465991999954e-05f, 5.270172914606519e-05f, 7.25337813491933e-05f, 9.939007577486336e-05f, 0.00011343441292410716f, 0.0001595931244082749f, 0.00010188927262788638f, 0.00010002884664572775f, 5.5366155720548704e-05f, 7.707310578553006e-05f, 7.720957364654168e-05f, 6.722804391756654e-05f, 8.454565977444872e-05f, 0.00014167436165735126f, 0.00010264441516483203f, 9.173071157420054e-05f, 8.817447815090418e-05f, 7.532301242463291e-05f, 6.728642620146275e-05f, 4.555725536192767e-05f, 7.102447852957994e-05f, 5.888800660613924e-05f, 3.89964334317483e-05f, 5.7509310863679275e-05f, 9.411428618477657e-05f, 7.306077895918861e-05f, 7.170236494857818e-05f, 0.00012714059266727418f, 5.6514058087486774e-05f, 3.749141615116969e-05f, 5.826889173476957e-05f, 5.3446798119693995e-05f, 0.00010131092858500779f, 0.00010358556755818427f, 4.9682461394695565e-05f, 8.567539771320298e-05f, 9.434230742044747e-05f, 0.00022803893079981208f, 7.966692646732554e-05f, 6.297526124399155e-05f, 0.00014809041749686003f, 7.81071576057002e-05f, 6.108043453423306e-05f, 9.171363490168005e-05f, 6.14283126196824e-05f, 0.0001458575570723042f, 7.80368281994015e-05f, 0.00010278773697791621f, 0.00010449643741594627f, 5.577677075052634e-05f, 8.655463898321614e-05f, 0.00012345767754595727f, 5.213284748606384e-05f, 0.0001886129757622257f, 0.00013228843454271555f, 4.137915311730467e-05f, 7.907325198175386e-05f, 8.881922258296981e-05f, 7.169164746301249e-05f, 6.802011193940416e-05f, 0.0001271807705052197f, 0.00016536556358914822f, 5.342271469999105e-05f, 6.239407957764342e-05f, 8.094898657873273e-05f, 5.894602509215474e-05f, 5.305398008204065e-05f, 5.4988682677503675e-05f, 7.903399091446772e-05f, 5.840642552357167e-05f, 0.00012452849477995187f, 4.612462726072408e-05f, 0.0001440914929844439f, 5.738353502238169e-05f, 0.00010621878027450293f, 0.0001594370260136202f, 0.00016478834731969982f, 6.7193599534221e-05f, 4.889244883088395e-05f, 6.229177233763039e-05f, 0.0001290854997932911f, 0.00010722530714701861f, 0.00012656814942602068f, 5.3951775043969974e-05f, 8.31541619845666e-05f, 0.00017165856843348593f, 6.405084423022345e-05f, 6.075791679904796e-05f, 5.83085638936609e-05f, 8.178333519026637e-05f, 0.00015530378732364625f, 6.093726187827997e-05f, 9.102780313696712e-05f, 7.167019793996587e-05f, 7.073408778524026e-05f, 7.42481934139505e-05f, 8.740252087591216e-05f, 5.3837291488889605e-05f, 0.00015949353110045195f, 8.790305582806468e-05f, 6.218405906111002e-05f, 0.00016839380259625614f, 5.505904118763283e-05f, 3.8776444853283465e-05f, 0.0001485082902945578f, 8.604722825111821e-05f, 4.929186252411455e-05f, 0.00010970822040690109f, 8.430009620497003e-05f, 0.0001466649555368349f, 0.00010168313747271895f, 0.00015421275747939944f, 5.790505019831471e-05f, 6.63946193526499e-05f, 7.725774048594758e-05f, 5.114522355142981e-05f, 5.559661076404154e-05f, 5.344923192751594e-05f, 6.415959796868265e-05f, 5.446728027891368e-05f, 4.4274216634221375e-05f, 5.613924076897092e-05f, 6.326766742859036e-05f, 0.00013043305079918355f, 0.0001507703127572313f, 8.754839655011892e-05f, 0.00014507625019177794f, 6.331338227028027e-05f, 5.255146970739588e-05f, 6.668356218142435e-05f, 4.454515874385834e-05f, 6.056749407434836e-05f, 3.6275607271818444e-05f, 5.353730375645682e-05f, 5.798262282041833e-05f, 0.00014837780327070504f, 8.599852299084887e-05f, 6.193161971168593e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #112 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 200,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0023416236508637667f, 0.004364116117358208f, 0.0009443492745049298f, 0.001877269591204822f, 0.0013205460272729397f, 0.002449361141771078f, 0.0010770944645628333f, 0.004357257392257452f, 0.0017216153210029006f, 0.0024569982197135687f, 0.0015727204736322165f, 0.0009271777817048132f, 0.0009525599889457226f, 0.0011444713454693556f, 0.002850267570465803f, 0.004609984811395407f, 0.0025511353742331266f, 0.0006538369343616068f, 0.0022619906812906265f, 0.0027323435060679913f, 0.0028412393294274807f, 0.002442026976495981f, 0.0015043773455545306f, 0.0016865057405084372f, 0.0017046566354110837f, 0.0021729781292378902f, 0.002031519543379545f, 0.0010698832338675857f, 0.0013658796669915318f, 0.001212920295074582f, 0.0005186397465877235f, 0.0016077011823654175f, 0.0035243581514805555f, 0.0012912689708173275f, 0.0011099980911239982f, 0.0023036296479403973f, 0.005671034101396799f, 0.0019557923078536987f, 0.0030747512355446815f, 0.0007239922997541726f, 0.003091682679951191f, 0.002717339899390936f, 0.001151339034549892f, 0.0036127970088273287f, 0.002619256265461445f, 0.0015980965690687299f, 0.001445865840651095f, 0.0016325974138453603f, 0.001996985636651516f, 0.0018317836802452803f, 0.0013858403544873f, 0.0016840394819155335f, 0.003636497538536787f, 0.00549659738317132f, 0.0010133875766769052f, 0.001191479153931141f, 0.0019459918839856982f, 0.0018872838700190187f, 0.0012143324129283428f, 0.0015309278387576342f, 0.0019637341611087322f, 0.0030062212608754635f, 0.001554418820887804f, 0.0011882883263751864f, 0.0028813867829740047f, 0.0027775149792432785f, 0.0015129292150959373f, 0.0011497901286929846f, 0.0020697915460914373f, 0.008272633887827396f, 0.004494897555559874f, 0.0020932683255523443f, 0.0006103649502620101f, 0.0012145284563302994f, 0.0033846688456833363f, 0.001350040314719081f, 0.0071257734671235085f, 0.0016995632322505116f, 0.0025530133862048388f, 0.0004914075834676623f, 0.0016380028100684285f, 0.0018327184952795506f, 0.002887309528887272f, 0.0009275145712308586f, 0.0028033044654875994f, 0.0018062349408864975f, 0.0013660653494298458f, 0.0015915724216029048f, 0.0005315643502399325f, 0.003257698379456997f, 0.0015034376410767436f, 0.0020930252503603697f, 0.004946011118590832f, 0.002234818646684289f, 0.0009764800779521465f, 0.002384955296292901f, 0.003403922775760293f, 0.002101910300552845f, 0.0013955087633803487f, 0.0033860497642308474f, 0.0022522995714098215f, 0.0017869381699711084f, 0.0009957158472388983f, 0.0032750077079981565f, 0.000886458670720458f, 0.0014578894479200244f, 0.0013723081210628152f, 0.0021355687640607357f, 0.0006864707684144378f, 0.0018567702500149608f, 0.004645889159291983f, 0.0010583586990833282f, 0.002725786529481411f, 0.001276551396586001f, 0.0006299478118307889f, 0.002610275987535715f, 0.0023468448780477047f, 0.002912764670327306f, 0.0017462732503190637f, 0.003797230776399374f, 0.0019499384798109531f, 0.004078190308064222f, 0.0009799578692764044f, 0.0020678893197327852f, 0.00266962475143373f, 0.0035485837142914534f, 0.0038734402041882277f, 0.0006694182520732284f, 0.0031249765306711197f, 0.0012742365943267941f, 0.0005094135412946343f, 0.0012129009701311588f, 0.004715905059129f, 0.002429510932415724f, 0.001681964029558003f, 0.001325082965195179f, 0.000845031812787056f, 0.0014148909831419587f, 0.0018993617268279195f, 0.0022086468525230885f, 0.0007798291044309735f, 0.0016446977388113737f, 0.0018205889500677586f, 0.0020212470553815365f, 0.0014367260737344623f, 0.002842293819412589f, 0.0009386255987919867f, 0.0017684886697679758f, 0.0027782670222222805f, 0.001496058190241456f, 0.002775323810055852f, 0.001161943655461073f, 0.006597178056836128f, 0.0014565448509529233f, 0.0007158811204135418f, 0.0007797718280926347f, 0.000369940884411335f, 0.001492594601586461f, 0.0013532377779483795f, 0.00103103241417557f, 0.001187636167742312f, 0.0008619248983450234f, 0.002156077418476343f, 0.0016605580458417535f, 0.002145919715985656f, 0.0023133123759180307f, 0.0010239937109872699f, 0.0035307544749230146f, 0.0028293344657868147f, 0.002421678975224495f, 0.0019783307798206806f, 0.00137489871121943f, 0.0006291540339589119f, 0.0016691412311047316f, 0.0034812649246305227f, 0.002389980712905526f, 0.002669174922630191f, 0.0021633803844451904f, 0.001410732977092266f, 0.0015586877707391977f, 0.0011797581100836396f, 0.0031793785747140646f, 0.0011967415921390057f, 0.0005015732022002339f, 0.00214269757270813f, 0.0011867635184898973f, 0.0026423512026667595f, 0.0015406712191179395f, 0.0025518150068819523f, 0.0025229824241250753f, 0.002581640612334013f, 0.003092982340604067f, 0.0022393015678972006f, 0.003538159653544426f, 0.002200766233727336f, 0.0007122607785277069f, 0.0027032995130866766f, 0.0016024697106331587f, 0.0009542006300762296f, 0.0015997090376913548f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #113 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 200,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.60751829855144e-05f, 0.000123145233374089f, 2.664734529389534e-05f, 5.297219104249962e-05f, 3.7262743717292324e-05f, 6.911528907949105e-05f, 3.039310649910476e-05f, 0.00012295169290155172f, 4.857999010710046e-05f, 6.933078839210793e-05f, 4.43785211245995e-05f, 2.61628047155682e-05f, 2.687903179321438e-05f, 3.229432331863791e-05f, 8.042793342610821e-05f, 0.00013008307723794132f, 7.198711682576686e-05f, 1.8449760318617336e-05f, 6.382812716765329e-05f, 7.710039062658325e-05f, 8.017318032216281e-05f, 6.890833174111322e-05f, 4.24500358349178e-05f, 4.7589277528459206e-05f, 4.810145401279442e-05f, 6.131640111561865e-05f, 5.7324767112731934e-05f, 3.0189621611498296e-05f, 3.854195529129356e-05f, 3.422579538892023e-05f, 1.4634810213465244e-05f, 4.536559572443366e-05f, 9.944920748239383e-05f, 3.64366132998839e-05f, 3.132157144136727e-05f, 6.50030851829797e-05f, 0.0001600234245415777f, 5.518792022485286e-05f, 8.676234574522823e-05f, 2.0429382857400924e-05f, 8.724010695004836e-05f, 7.667702448088676e-05f, 3.2488114811712876e-05f, 0.00010194474452873692f, 7.390933023998514e-05f, 4.509457721724175e-05f, 4.07989791710861e-05f, 4.606811125995591e-05f, 5.635029810946435e-05f, 5.1688683015527204e-05f, 3.910519808414392e-05f, 4.751968663185835e-05f, 0.0001026135214488022f, 0.00015510122466366738f, 2.859544474631548e-05f, 3.362077768542804e-05f, 5.4911375627852976e-05f, 5.3254771046340466e-05f, 3.426564217079431e-05f, 4.3199230276513845e-05f, 5.541201971936971e-05f, 8.482858538627625e-05f, 4.38620918430388e-05f, 3.353073770995252e-05f, 8.130604692269117e-05f, 7.837502926122397e-05f, 4.2691350245149806e-05f, 3.2444408134324476e-05f, 5.840471203555353e-05f, 0.00023343453358393162f, 0.00012683556997217238f, 5.90671734244097e-05f, 1.7223082977579907e-05f, 3.4271175536559895e-05f, 9.550750110065565e-05f, 3.8095004128990695e-05f, 0.0002010727912420407f, 4.795772838406265e-05f, 7.204011490102857e-05f, 1.3866381777916104e-05f, 4.622063715942204e-05f, 5.1715061999857426e-05f, 8.147317566908896e-05f, 2.6172308935201727e-05f, 7.910274871392176e-05f, 5.096775930724107e-05f, 3.8547193980775774e-05f, 4.491048093768768e-05f, 1.4999512131907977e-05f, 9.192468860419467e-05f, 4.2423522245371714e-05f, 5.9060315834358335e-05f, 0.00013956495968159288f, 6.306139403022826e-05f, 2.7554000553209335e-05f, 6.729790038662031e-05f, 9.605079685570672e-05f, 5.931103078182787e-05f, 3.9378017390845343e-05f, 9.55464638536796e-05f, 6.355466757668182e-05f, 5.042324846726842e-05f, 2.8096790629206225e-05f, 9.241311636287719e-05f, 2.5013805498019792e-05f, 4.1138257074635476e-05f, 3.872334855259396e-05f, 6.0260794271016493e-05f, 1.93706109712366e-05f, 5.239374513621442e-05f, 0.00013109621067997068f, 2.9864426323911175e-05f, 7.691537030041218e-05f, 3.602131619118154e-05f, 1.7775664673536085e-05f, 7.365593046415597e-05f, 6.6222513851244e-05f, 8.219145820476115e-05f, 4.92757790198084e-05f, 0.00010714904055930674f, 5.502273779711686e-05f, 0.00011507706221891567f, 2.7652136850520037e-05f, 5.83510372962337e-05f, 7.533061580033973e-05f, 0.00010013279825216159f, 0.00010929949348792434f, 1.888943006633781e-05f, 8.817958587314934e-05f, 3.5955999919679016e-05f, 1.4374467355082743e-05f, 3.422524969209917e-05f, 0.0001330718951066956f, 6.855515675852075e-05f, 4.7461122449021786e-05f, 3.739076419151388e-05f, 2.3844835595809855e-05f, 3.992494021076709e-05f, 5.3595580538967624e-05f, 6.232288433238864e-05f, 2.20049678318901e-05f, 4.6409553760895506e-05f, 5.137279367772862e-05f, 5.703490023734048e-05f, 4.054107557749376e-05f, 8.02029317128472e-05f, 2.64858354057651e-05f, 4.9902646424015984e-05f, 7.839624595362693e-05f, 4.221528797643259e-05f, 7.831319817341864e-05f, 3.27873531205114e-05f, 0.00018615704902913421f, 4.1100316593656316e-05f, 2.0200503058731556e-05f, 2.2003350750310346e-05f, 1.0438872777740471e-05f, 4.211755367578007e-05f, 3.8185229641385376e-05f, 2.9093342163832858e-05f, 3.351233681314625e-05f, 2.4321519958903082e-05f, 6.0839498473796993e-05f, 4.685709427576512e-05f, 6.055287303752266e-05f, 6.52763046673499e-05f, 2.8894724891870283e-05f, 9.962969488697127e-05f, 7.983724935911596e-05f, 6.833415682194754e-05f, 5.582390440395102e-05f, 3.879645009874366e-05f, 1.775326563802082e-05f, 4.709929271484725e-05f, 9.823321306612343e-05f, 6.743970880052075e-05f, 7.531791925430298e-05f, 6.104557542130351e-05f, 3.9807611756259575e-05f, 4.398255259729922e-05f, 3.32900344801601e-05f, 8.971468196250498e-05f, 3.37692690663971e-05f, 1.4153231859381776e-05f, 6.046195267117582e-05f, 3.3487711334601045e-05f, 7.45610159356147e-05f, 4.3474166886880994e-05f, 7.200629625003785e-05f, 7.119270594557747e-05f, 7.284790626727045e-05f, 8.727678505238146e-05f, 6.318789382930845e-05f, 9.9838653113693e-05f, 6.210051651578397e-05f, 2.0098346794839017e-05f, 7.628083403687924e-05f, 4.52179774583783e-05f, 2.6925326892524026e-05f, 4.5140077418182045e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #114 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_46_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0039446973241865635f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #115 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_46_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00012068838987033814f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #116 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0023997128009796143f, 0.002571935299783945f, 0.0022135579492896795f, 0.004044122062623501f, 0.0028804296161979437f, 0.004881314933300018f, 0.002528148703277111f, 0.0023021819069981575f, 0.003387839300557971f, 0.0023335199803113937f, 0.005620542448014021f, 0.009068181738257408f, 0.0037557652685791254f, 0.003767434973269701f, 0.0029199772980064154f, 0.0016061307396739721f, 0.0024473394732922316f, 0.0024476777762174606f, 0.002797410124912858f, 0.0026406750548630953f, 0.0026521843392401934f, 0.0033796716015785933f, 0.006135554052889347f, 0.0013113473542034626f, 0.0032185332383960485f, 0.003340862924233079f, 0.0030514663085341454f, 0.003787234891206026f, 0.0024748551659286022f, 0.0034950152039527893f, 0.004119893070310354f, 0.003437098115682602f, 0.003566971281543374f, 0.001663294737227261f, 0.0023881655652076006f, 0.00388034014031291f, 0.0019280645065009594f, 0.003893438261002302f, 0.0019517088076099753f, 0.003961589187383652f, 0.0020702495239675045f, 0.0030850176699459553f, 0.005552302580326796f, 0.0030261853244155645f, 0.00303448922932148f, 0.003022483317181468f, 0.0024108600337058306f, 0.0018720454536378384f, 0.004343104548752308f, 0.0031578377820551395f, 0.003938554786145687f, 0.0024975750129669905f, 0.0019303214503452182f, 0.0031966359820216894f, 0.0069712987169623375f, 0.005784899462014437f, 0.007387380115687847f, 0.0044895983301103115f, 0.0027141475584357977f, 0.004250812344253063f, 0.0021558331791311502f, 0.0025615785270929337f, 0.003246193053200841f, 0.002565740142017603f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #117 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011407220154069364f, 0.0001222589344251901f, 0.00010522318916628137f, 0.00019224046263843775f, 0.00013692345237359405f, 0.0002320370840607211f, 0.00012017750123050064f, 0.00010943599772872403f, 0.0001610435574548319f, 0.00011092567729065195f, 0.00026717683067545295f, 0.00043106303201057017f, 0.00017853321332950145f, 0.0001790879323380068f, 0.0001388033851981163f, 7.634866778971627e-05f, 0.00011633617396000773f, 0.00011635225382633507f, 0.00013297706027515233f, 0.0001255265378858894f, 0.0001260736316908151f, 0.00016065529780462384f, 0.00029165830346755683f, 6.233590829651803e-05f, 0.0001529954606667161f, 0.0001588105078553781f, 0.0001450538111384958f, 0.00018002913566306233f, 0.00011764415103243664f, 0.00016613825573585927f, 0.00019584230904001743f, 0.00016338512068614364f, 0.00016955874161794782f, 7.906600512797013e-05f, 0.00011352329602232203f, 0.00018445496971253306f, 9.165203664451838e-05f, 0.0001850776025094092f, 9.277599019696936e-05f, 0.00018831720808520913f, 9.841091377893463e-05f, 0.0001466487010475248f, 0.0002639330050442368f, 0.00014385205577127635f, 0.00014424679102376103f, 0.00014367607946041971f, 0.00011460209498181939f, 8.898913074517623e-05f, 0.00020645283802878112f, 0.00015011026698630303f, 0.00018722224922385067f, 0.00011872415780089796f, 9.175932063953951e-05f, 0.00015195456217043102f, 0.0003313860797788948f, 0.00027498966665007174f, 0.0003511648392304778f, 0.00021341652609407902f, 0.00012901909940410405f, 0.00020206565386615694f, 0.00010247919999528676f, 0.00012176661402918398f, 0.00015431029896717519f, 0.00012196444004075602f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #118 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0027636652812361717f, 0.0029499514494091272f, 0.00698412349447608f, 0.005929281935095787f, 0.005789631977677345f, 0.00392938544973731f, 0.004826800897717476f, 0.0034056620206683874f, 0.00567512447014451f, 0.0082189766690135f, 0.007431426085531712f, 0.003026819322258234f, 0.002197558991611004f, 0.0033116901759058237f, 0.003979833330959082f, 0.007932375185191631f, 0.004444145131856203f, 0.005728077609091997f, 0.004150490276515484f, 0.00802756566554308f, 0.0025167299900203943f, 0.004847620613873005f, 0.002586121903732419f, 0.0032663403544574976f, 0.006390650290995836f, 0.005276511888951063f, 0.0028696416411548853f, 0.0035736754070967436f, 0.004181869328022003f, 0.0043581086210906506f, 0.009219515137374401f, 0.007052933797240257f, 0.004965396132320166f, 0.004583130124956369f, 0.0059938631020486355f, 0.0016677419189363718f, 0.005679679568856955f, 0.005614279769361019f, 0.009925475344061852f, 0.0038644166197627783f, 0.0045675127767026424f, 0.0063155051320791245f, 0.005281070712953806f, 0.00785470474511385f, 0.004460461903363466f, 0.0022171486634761095f, 0.005621944088488817f, 0.009591178968548775f, 0.0046107047237455845f, 0.004763250704854727f, 0.007322143763303757f, 0.0051666549406945705f, 0.009219011291861534f, 0.0113917775452137f, 0.004285575821995735f, 0.004171206150203943f, 0.006992142181843519f, 0.007230150979012251f, 0.0046124835498631f, 0.0037101046182215214f, 0.003102955175563693f, 0.008652583695948124f, 0.004453984554857016f, 0.0035702590830624104f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #119 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.191075903596357e-05f, 8.74319885042496e-05f, 0.00020699859305750579f, 0.00017573473451193422f, 0.0001715957187116146f, 0.00011646089842543006f, 0.00014305890363175422f, 0.00010093854507431388f, 0.00016820189193822443f, 0.00024359773669857532f, 0.0002202559553552419f, 8.971023635240272e-05f, 6.513224070658907e-05f, 9.815336670726538e-05f, 0.00011795609316322953f, 0.00023510330356657505f, 0.00013171757746022195f, 0.00016977134509943426f, 0.0001230141060659662f, 0.0002379246143391356f, 7.459197513526306e-05f, 0.0001436759630450979f, 7.664864824619144e-05f, 9.680926450528204e-05f, 0.00018940898007713258f, 0.00015638764307368547f, 8.505173173034564e-05f, 0.0001059182031895034f, 0.00012394413352012634f, 0.0001291675871470943f, 0.0002732521388679743f, 0.00020903802942484617f, 0.00014716664736624807f, 0.00013583687541540712f, 0.00017764882068149745f, 4.942928717355244e-05f, 0.00016833690460771322f, 0.0001663985603954643f, 0.00029417569749057293f, 0.00011453532351879403f, 0.00013537400809582323f, 0.00018718178034760058f, 0.00015652275760658085f, 0.00023280127788893878f, 0.00013220118125900626f, 6.571284757228568e-05f, 0.0001666257157921791f, 0.0002842676767613739f, 0.00013665414007846266f, 0.00014117537648417056f, 0.000217016990063712f, 0.00015313165204133838f, 0.00027323720860295f, 0.00033763464307412505f, 0.00012701783271040767f, 0.00012362808047328144f, 0.00020723625493701547f, 0.00021429047046694905f, 0.00013670686166733503f, 0.00010996175114996731f, 9.196678729495034e-05f, 0.00025644918787293136f, 0.00013200919784139842f, 0.00010581695096334442f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #120 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004729023203253746f, 0.004313791636377573f, 0.004063884261995554f, 0.003606360638514161f, 0.0028451033867895603f, 0.002718227216973901f, 0.002143439371138811f, 0.001999261789023876f, 0.001708023133687675f, 0.0013014425057917833f, 0.001764732995070517f, 0.00215497356839478f, 0.002318374812602997f, 0.0023241417948156595f, 0.0021376721560955048f, 0.002231868216767907f, 0.004071573726832867f, 0.003875492140650749f, 0.0038235881365835667f, 0.0034890964161604643f, 0.0028912401758134365f, 0.0029489111620932817f, 0.0034468043595552444f, 0.003485251683741808f, 0.0024817760568112135f, 0.002531757578253746f, 0.0029489111620932817f, 0.002741295611485839f, 0.002264548558741808f, 0.002497154986485839f, 0.003106545191258192f, 0.004298412706702948f, 0.004779004491865635f, 0.0047636255621910095f, 0.00399467907845974f, 0.003187284804880619f, 0.002566360170021653f, 0.0024913877714425325f, 0.0020473210606724024f, 0.001498485216870904f, 0.0016138271894305944f, 0.001721479813568294f, 0.0017993355868384242f, 0.00168783834669739f, 0.001720518572255969f, 0.0015571173280477524f, 0.0011957123642787337f, 0.0012956754071637988f, 0.004094642121344805f, 0.004252275917679071f, 0.004063884261995554f, 0.003031573025509715f, 0.0026586337480694056f, 0.0025490587577223778f, 0.0021588183008134365f, 0.0017349363770335913f, 0.001664769952185452f, 0.0016541968798264861f, 0.0015840304549783468f, 0.001920444774441421f, 0.0019444742938503623f, 0.0016628475859761238f, 0.0011659156298264861f, 0.0012879859423264861f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #121 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00022455694852396846f, 0.00020483974367380142f, 0.0001929729332914576f, 0.0001712474913801998f, 0.00013509929704014212f, 0.00012907461496070027f, 0.00010178089723922312f, 9.493464312981814e-05f, 8.110522321658209e-05f, 6.179879710543901e-05f, 8.379807695746422e-05f, 0.00010232859494863078f, 0.00011008767614839599f, 0.00011036152136512101f, 0.00010150703747058287f, 0.00010597992513794452f, 0.00019333805539645255f, 0.0001840271579567343f, 0.0001815625000745058f, 0.00016567921556998044f, 0.00013729010242968798f, 0.00014002859825268388f, 0.00016367097850888968f, 0.00016549664724152535f, 0.00011784675734816119f, 0.00012022012379020452f, 0.00014002859825268388f, 0.0001301700103795156f, 0.00010753174865385517f, 0.00011857702338602394f, 0.00014751382695976645f, 0.00020410947035998106f, 0.00022693030769005418f, 0.00022620003437623382f, 0.00018968673248309642f, 0.0001513477327534929f, 0.00012186322419438511f, 0.0001183031708933413f, 9.721673268359154e-05f, 7.115534390322864e-05f, 7.663234282517806e-05f, 8.174420509021729e-05f, 8.54411773616448e-05f, 8.014674676815048e-05f, 8.169856300810352e-05f, 7.393948180833831e-05f, 5.677821900462732e-05f, 6.152495188871399e-05f, 0.0001944334653671831f, 0.00020191867952235043f, 0.0001929729332914576f, 0.00014395378821063787f, 0.0001262448204215616f, 0.0001210416667163372f, 0.00010251116327708587f, 8.238319423981011e-05f, 7.905135134933516e-05f, 7.854928844608366e-05f, 7.521744555560872e-05f, 9.119202877627686e-05f, 9.233306627720594e-05f, 7.896006718510762e-05f, 5.5363329011015594e-05f, 6.11598152318038e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #122 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11811023950576782f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #123 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00046136812306940556f),
    AI_PACK_INTQ_ZP(0)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_images0_output, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 128, 128), AI_STRIDE_INIT(4, 4, 4, 12, 1536),
  1, &serving_default_images0_output_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conversion_0_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 128, 128), AI_STRIDE_INIT(4, 1, 1, 3, 384),
  1, &conversion_0_output_array, &conversion_0_output_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 64, 64), AI_STRIDE_INIT(4, 1, 1, 16, 1024),
  1, &conv2d_2_output_array, &conv2d_2_output_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  nl_3_output, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 64, 64), AI_STRIDE_INIT(4, 1, 1, 16, 1024),
  1, &nl_3_output_array, &nl_3_output_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_4_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 64, 64), AI_STRIDE_INIT(4, 1, 1, 16, 1024),
  1, &eltwise_4_output_array, &eltwise_4_output_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 32, 32), AI_STRIDE_INIT(4, 1, 1, 24, 768),
  1, &conv2d_6_output_array, &conv2d_6_output_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  nl_7_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 32, 32), AI_STRIDE_INIT(4, 1, 1, 24, 768),
  1, &nl_7_output_array, &nl_7_output_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_8_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 32, 32), AI_STRIDE_INIT(4, 1, 1, 24, 768),
  1, &eltwise_8_output_array, &eltwise_8_output_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 32, 32), AI_STRIDE_INIT(4, 1, 1, 24, 768),
  1, &conv2d_9_output_array, &conv2d_9_output_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  nl_10_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 32, 32), AI_STRIDE_INIT(4, 1, 1, 24, 768),
  1, &nl_10_output_array, &nl_10_output_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_11_output, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 32, 32), AI_STRIDE_INIT(4, 1, 1, 24, 768),
  1, &eltwise_11_output_array, &eltwise_11_output_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_output, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 72, 16, 16), AI_STRIDE_INIT(4, 1, 1, 72, 1152),
  1, &conv2d_13_output_array, &conv2d_13_output_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  nl_14_output, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 1, 72, 16, 16), AI_STRIDE_INIT(4, 1, 1, 72, 1152),
  1, &nl_14_output_array, &nl_14_output_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_15_output, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 72, 16, 16), AI_STRIDE_INIT(4, 1, 1, 72, 1152),
  1, &eltwise_15_output_array, &eltwise_15_output_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 72, 16, 16), AI_STRIDE_INIT(4, 1, 1, 72, 1152),
  1, &conv2d_16_output_array, &conv2d_16_output_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  nl_17_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 72, 16, 16), AI_STRIDE_INIT(4, 1, 1, 72, 1152),
  1, &nl_17_output_array, &nl_17_output_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_18_output, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 1, 72, 16, 16), AI_STRIDE_INIT(4, 1, 1, 72, 1152),
  1, &eltwise_18_output_array, &eltwise_18_output_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_output, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 136, 8, 8), AI_STRIDE_INIT(4, 1, 1, 136, 1088),
  1, &conv2d_20_output_array, &conv2d_20_output_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  nl_21_output, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 1, 136, 8, 8), AI_STRIDE_INIT(4, 1, 1, 136, 1088),
  1, &nl_21_output_array, &nl_21_output_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_22_output, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 136, 8, 8), AI_STRIDE_INIT(4, 1, 1, 136, 1088),
  1, &eltwise_22_output_array, &eltwise_22_output_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_output, AI_STATIC,
  20, 0x1,
  AI_SHAPE_INIT(4, 1, 136, 8, 8), AI_STRIDE_INIT(4, 1, 1, 136, 1088),
  1, &conv2d_23_output_array, &conv2d_23_output_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  nl_24_output, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 136, 8, 8), AI_STRIDE_INIT(4, 1, 1, 136, 1088),
  1, &nl_24_output_array, &nl_24_output_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_25_output, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 1, 136, 8, 8), AI_STRIDE_INIT(4, 1, 1, 136, 1088),
  1, &eltwise_25_output_array, &eltwise_25_output_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_output, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 1, 200, 4, 4), AI_STRIDE_INIT(4, 1, 1, 200, 800),
  1, &conv2d_27_output_array, &conv2d_27_output_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  nl_28_output, AI_STATIC,
  24, 0x1,
  AI_SHAPE_INIT(4, 1, 200, 4, 4), AI_STRIDE_INIT(4, 1, 1, 200, 800),
  1, &nl_28_output_array, &nl_28_output_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_29_output, AI_STATIC,
  25, 0x1,
  AI_SHAPE_INIT(4, 1, 200, 4, 4), AI_STRIDE_INIT(4, 1, 1, 200, 800),
  1, &eltwise_29_output_array, &eltwise_29_output_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_output, AI_STATIC,
  26, 0x1,
  AI_SHAPE_INIT(4, 1, 200, 4, 4), AI_STRIDE_INIT(4, 1, 1, 200, 800),
  1, &conv2d_30_output_array, &conv2d_30_output_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  nl_31_output, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 1, 200, 4, 4), AI_STRIDE_INIT(4, 1, 1, 200, 800),
  1, &nl_31_output_array, &nl_31_output_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_32_output, AI_STATIC,
  28, 0x1,
  AI_SHAPE_INIT(4, 1, 200, 4, 4), AI_STRIDE_INIT(4, 1, 1, 200, 800),
  1, &eltwise_32_output_array, &eltwise_32_output_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_output, AI_STATIC,
  29, 0x1,
  AI_SHAPE_INIT(4, 1, 51, 4, 4), AI_STRIDE_INIT(4, 1, 1, 51, 204),
  1, &conv2d_50_output_array, &conv2d_50_output_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  nl_51_output, AI_STATIC,
  30, 0x1,
  AI_SHAPE_INIT(4, 1, 51, 4, 4), AI_STRIDE_INIT(4, 1, 1, 51, 204),
  1, &nl_51_output_array, &nl_51_output_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_52_output, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 1, 51, 4, 4), AI_STRIDE_INIT(4, 1, 1, 51, 204),
  1, &eltwise_52_output_array, &eltwise_52_output_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_output, AI_STATIC,
  32, 0x1,
  AI_SHAPE_INIT(4, 1, 51, 4, 4), AI_STRIDE_INIT(4, 1, 1, 51, 204),
  1, &conv2d_53_output_array, &conv2d_53_output_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  nl_54_output, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 1, 51, 4, 4), AI_STRIDE_INIT(4, 1, 1, 51, 204),
  1, &nl_54_output_array, &nl_54_output_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_55_output, AI_STATIC,
  34, 0x1,
  AI_SHAPE_INIT(4, 1, 51, 4, 4), AI_STRIDE_INIT(4, 1, 1, 51, 204),
  1, &eltwise_55_output_array, &eltwise_55_output_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_output, AI_STATIC,
  35, 0x1,
  AI_SHAPE_INIT(4, 1, 51, 4, 4), AI_STRIDE_INIT(4, 1, 1, 51, 204),
  1, &conv2d_56_output_array, &conv2d_56_output_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  transpose_57_output, AI_STATIC,
  36, 0x1,
  AI_SHAPE_INIT(4, 1, 4, 4, 51), AI_STRIDE_INIT(4, 1, 1, 4, 16),
  1, &transpose_57_output_array, &transpose_57_output_intq)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  reshape_58_fmt_output, AI_STATIC,
  37, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 4, 51), AI_STRIDE_INIT(4, 4, 4, 16, 64),
  1, &reshape_58_fmt_output_array, NULL)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  reshape_58_fmt_output0, AI_STATIC,
  38, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 3, 17), AI_STRIDE_INIT(4, 4, 4, 64, 192),
  1, &reshape_58_fmt_output_array, NULL)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  slice_75_output, AI_STATIC,
  39, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 17), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &slice_75_output_array, NULL)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  slice_75_fmt_output, AI_STATIC,
  40, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 17), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &slice_75_fmt_output_array, &slice_75_fmt_output_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  nl_76_output, AI_STATIC,
  41, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 17), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &nl_76_output_array, &nl_76_output_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_77_output, AI_STATIC,
  42, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 17), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &eltwise_77_output_array, &eltwise_77_output_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  slice_71_output, AI_STATIC,
  43, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 2, 17), AI_STRIDE_INIT(4, 4, 4, 64, 128),
  1, &slice_71_output_array, NULL)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  slice_71_fmt_output, AI_STATIC,
  44, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 2, 17), AI_STRIDE_INIT(4, 1, 1, 16, 32),
  1, &slice_71_fmt_output_array, &slice_71_fmt_output_intq)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_72_output, AI_STATIC,
  45, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 2, 17), AI_STRIDE_INIT(4, 1, 1, 16, 32),
  1, &eltwise_72_output_array, &eltwise_72_output_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_73_output, AI_STATIC,
  46, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 2, 17), AI_STRIDE_INIT(4, 1, 1, 16, 32),
  1, &eltwise_73_output_array, &eltwise_73_output_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_74_output, AI_STATIC,
  47, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 2, 17), AI_STRIDE_INIT(4, 1, 1, 16, 32),
  1, &eltwise_74_output_array, &eltwise_74_output_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  concat_78_output, AI_STATIC,
  48, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 3, 17), AI_STRIDE_INIT(4, 1, 1, 16, 48),
  1, &concat_78_output_array, &concat_78_output_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  concat_78_output0, AI_STATIC,
  49, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 51), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &concat_78_output_array, &concat_78_output_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_40_output, AI_STATIC,
  50, 0x1,
  AI_SHAPE_INIT(4, 1, 200, 4, 4), AI_STRIDE_INIT(4, 1, 1, 200, 800),
  1, &conv2d_40_output_array, &conv2d_40_output_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  nl_41_output, AI_STATIC,
  51, 0x1,
  AI_SHAPE_INIT(4, 1, 200, 4, 4), AI_STRIDE_INIT(4, 1, 1, 200, 800),
  1, &nl_41_output_array, &nl_41_output_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_42_output, AI_STATIC,
  52, 0x1,
  AI_SHAPE_INIT(4, 1, 200, 4, 4), AI_STRIDE_INIT(4, 1, 1, 200, 800),
  1, &eltwise_42_output_array, &eltwise_42_output_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_output, AI_STATIC,
  53, 0x1,
  AI_SHAPE_INIT(4, 1, 200, 4, 4), AI_STRIDE_INIT(4, 1, 1, 200, 800),
  1, &conv2d_43_output_array, &conv2d_43_output_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  nl_44_output, AI_STATIC,
  54, 0x1,
  AI_SHAPE_INIT(4, 1, 200, 4, 4), AI_STRIDE_INIT(4, 1, 1, 200, 800),
  1, &nl_44_output_array, &nl_44_output_intq)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_45_output, AI_STATIC,
  55, 0x1,
  AI_SHAPE_INIT(4, 1, 200, 4, 4), AI_STRIDE_INIT(4, 1, 1, 200, 800),
  1, &eltwise_45_output_array, &eltwise_45_output_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_output, AI_STATIC,
  56, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 4, 4), AI_STRIDE_INIT(4, 1, 1, 1, 4),
  1, &conv2d_46_output_array, &conv2d_46_output_intq)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_output, AI_STATIC,
  57, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 4, 4), AI_STRIDE_INIT(4, 1, 1, 64, 256),
  1, &conv2d_33_output_array, &conv2d_33_output_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  nl_34_output, AI_STATIC,
  58, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 4, 4), AI_STRIDE_INIT(4, 1, 1, 64, 256),
  1, &nl_34_output_array, &nl_34_output_intq)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_35_output, AI_STATIC,
  59, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 4, 4), AI_STRIDE_INIT(4, 1, 1, 64, 256),
  1, &eltwise_35_output_array, &eltwise_35_output_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_output, AI_STATIC,
  60, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 4, 4), AI_STRIDE_INIT(4, 1, 1, 64, 256),
  1, &conv2d_36_output_array, &conv2d_36_output_intq)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  nl_37_output, AI_STATIC,
  61, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 4, 4), AI_STRIDE_INIT(4, 1, 1, 64, 256),
  1, &nl_37_output_array, &nl_37_output_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_38_output, AI_STATIC,
  62, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 4, 4), AI_STRIDE_INIT(4, 1, 1, 64, 256),
  1, &eltwise_38_output_array, &eltwise_38_output_intq)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_output, AI_STATIC,
  63, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 4, 4), AI_STRIDE_INIT(4, 1, 1, 64, 256),
  1, &conv2d_39_output_array, &conv2d_39_output_intq)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  concat_47_output, AI_STATIC,
  64, 0x1,
  AI_SHAPE_INIT(4, 1, 65, 4, 4), AI_STRIDE_INIT(4, 1, 1, 65, 260),
  1, &concat_47_output_array, &concat_47_output_intq)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  transpose_48_output, AI_STATIC,
  65, 0x1,
  AI_SHAPE_INIT(4, 1, 4, 4, 65), AI_STRIDE_INIT(4, 1, 1, 4, 16),
  1, &transpose_48_output_array, &transpose_48_output_intq)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  reshape_49_fmt_output, AI_STATIC,
  66, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 4, 65), AI_STRIDE_INIT(4, 4, 4, 16, 64),
  1, &reshape_49_fmt_output_array, NULL)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  reshape_49_fmt_output0, AI_STATIC,
  67, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 65), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &reshape_49_fmt_output_array, NULL)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  slice_68_output, AI_STATIC,
  68, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &slice_68_output_array, NULL)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  slice_68_fmt_output, AI_STATIC,
  69, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &slice_68_fmt_output_array, &slice_68_fmt_output_intq)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  nl_69_output, AI_STATIC,
  70, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &nl_69_output_array, &nl_69_output_intq)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_70_output, AI_STATIC,
  71, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &eltwise_70_output_array, &eltwise_70_output_intq)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  slice_59_output, AI_STATIC,
  72, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 64), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &slice_59_output_array, NULL)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  slice_59_fmt_output, AI_STATIC,
  73, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 64), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &slice_59_fmt_output_array, &slice_59_fmt_output_intq)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  slice_59_fmt_output0, AI_STATIC,
  74, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 16, 4), AI_STRIDE_INIT(4, 1, 1, 16, 256),
  1, &slice_59_fmt_output_array, &slice_59_fmt_output_intq)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  transpose_61_output, AI_STATIC,
  75, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 4, 16), AI_STRIDE_INIT(4, 1, 1, 16, 64),
  1, &transpose_61_output_array, &transpose_61_output_intq)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  transpose_62_output, AI_STATIC,
  76, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 16, 4), AI_STRIDE_INIT(4, 1, 1, 16, 256),
  1, &transpose_62_output_array, &transpose_62_output_intq)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  transpose_62_fmt_output, AI_STATIC,
  77, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 16, 4), AI_STRIDE_INIT(4, 4, 4, 64, 1024),
  1, &transpose_62_fmt_output_array, NULL)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  nl_63_output, AI_STATIC,
  78, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 16, 4), AI_STRIDE_INIT(4, 4, 4, 64, 1024),
  1, &nl_63_output_array, NULL)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  nl_63_fmt_output, AI_STATIC,
  79, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 16, 4), AI_STRIDE_INIT(4, 1, 1, 16, 256),
  1, &nl_63_fmt_output_array, &nl_63_fmt_output_intq)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_output, AI_STATIC,
  80, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 16, 4), AI_STRIDE_INIT(4, 1, 1, 1, 16),
  1, &conv2d_64_output_array, &conv2d_64_output_intq)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  reshape_65_fmt_output, AI_STATIC,
  81, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 16, 4), AI_STRIDE_INIT(4, 4, 4, 4, 64),
  1, &reshape_65_fmt_output_array, NULL)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  reshape_65_fmt_output0, AI_STATIC,
  82, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 4), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &reshape_65_fmt_output_array, NULL)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  slice_80_output, AI_STATIC,
  83, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 2), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &slice_80_output_array, NULL)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  slice_80_fmt_output, AI_STATIC,
  84, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 2), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &slice_80_fmt_output_array, &slice_80_fmt_output_intq)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_81_output, AI_STATIC,
  85, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 2), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &eltwise_81_output_array, &eltwise_81_output_intq)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  slice_66_output, AI_STATIC,
  86, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 2), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &slice_66_output_array, NULL)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  slice_66_fmt_output, AI_STATIC,
  87, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 2), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &slice_66_fmt_output_array, &slice_66_fmt_output_intq)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_67_output, AI_STATIC,
  88, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 2), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &eltwise_67_output_array, &eltwise_67_output_intq)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_84_output, AI_STATIC,
  89, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 2), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &eltwise_84_output_array, &eltwise_84_output_intq)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_82_output, AI_STATIC,
  90, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 2), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &eltwise_82_output_array, &eltwise_82_output_intq)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_83_output, AI_STATIC,
  91, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 2), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &eltwise_83_output_array, &eltwise_83_output_intq)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  concat_85_output, AI_STATIC,
  92, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 4), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &concat_85_output_array, &concat_85_output_intq)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_86_output, AI_STATIC,
  93, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 4), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &eltwise_86_output_array, &eltwise_86_output_intq)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  concat_87_output, AI_STATIC,
  94, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 56), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &concat_87_output_array, &concat_87_output_intq)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conversion_88_output, AI_STATIC,
  95, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 56), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conversion_88_output_array, NULL)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  model_2_tfmathmultiply_58_Mul_y, AI_STATIC,
  96, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &model_2_tfmathmultiply_58_Mul_y_array, &model_2_tfmathmultiply_58_Mul_y_intq)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  model_2_tfmathdivide_truedivConst_9, AI_STATIC,
  97, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &model_2_tfmathdivide_truedivConst_9_array, &model_2_tfmathdivide_truedivConst_9_intq)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  Const_12, AI_STATIC,
  98, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &Const_12_array, &Const_12_intq)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  model_2_tfmathmultiply_49_Mul_y, AI_STATIC,
  99, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &model_2_tfmathmultiply_49_Mul_y_array, &model_2_tfmathmultiply_49_Mul_y_intq)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  Const_15, AI_STATIC,
  100, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 2, 1), AI_STRIDE_INIT(4, 1, 1, 16, 32),
  1, &Const_15_array, &Const_15_intq)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  Const_20, AI_STATIC,
  101, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &Const_20_array, &Const_20_intq)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  Const_8, AI_STATIC,
  102, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &Const_8_array, &Const_8_intq)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  Const_13, AI_STATIC,
  103, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 2), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &Const_13_array, &Const_13_intq)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  104, 0x1,
  AI_SHAPE_INIT(4, 3, 3, 3, 16), AI_STRIDE_INIT(4, 1, 3, 9, 27),
  1, &conv2d_2_weights_array, &conv2d_2_weights_intq)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  105, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_2_bias_array, &conv2d_2_bias_intq)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_weights, AI_STATIC,
  106, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 24), AI_STRIDE_INIT(4, 1, 16, 48, 144),
  1, &conv2d_6_weights_array, &conv2d_6_weights_intq)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_bias, AI_STATIC,
  107, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_6_bias_array, &conv2d_6_bias_intq)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  108, 0x1,
  AI_SHAPE_INIT(4, 24, 3, 3, 24), AI_STRIDE_INIT(4, 1, 24, 72, 216),
  1, &conv2d_9_weights_array, &conv2d_9_weights_intq)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  109, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_9_bias_array, &conv2d_9_bias_intq)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_weights, AI_STATIC,
  110, 0x1,
  AI_SHAPE_INIT(4, 24, 3, 3, 72), AI_STRIDE_INIT(4, 1, 24, 72, 216),
  1, &conv2d_13_weights_array, &conv2d_13_weights_intq)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_bias, AI_STATIC,
  111, 0x1,
  AI_SHAPE_INIT(4, 1, 72, 1, 1), AI_STRIDE_INIT(4, 4, 4, 288, 288),
  1, &conv2d_13_bias_array, &conv2d_13_bias_intq)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  112, 0x1,
  AI_SHAPE_INIT(4, 72, 3, 3, 72), AI_STRIDE_INIT(4, 1, 72, 216, 648),
  1, &conv2d_16_weights_array, &conv2d_16_weights_intq)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  113, 0x1,
  AI_SHAPE_INIT(4, 1, 72, 1, 1), AI_STRIDE_INIT(4, 4, 4, 288, 288),
  1, &conv2d_16_bias_array, &conv2d_16_bias_intq)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_weights, AI_STATIC,
  114, 0x1,
  AI_SHAPE_INIT(4, 72, 3, 3, 136), AI_STRIDE_INIT(4, 1, 72, 216, 648),
  1, &conv2d_20_weights_array, &conv2d_20_weights_intq)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_bias, AI_STATIC,
  115, 0x1,
  AI_SHAPE_INIT(4, 1, 136, 1, 1), AI_STRIDE_INIT(4, 4, 4, 544, 544),
  1, &conv2d_20_bias_array, &conv2d_20_bias_intq)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_weights, AI_STATIC,
  116, 0x1,
  AI_SHAPE_INIT(4, 136, 3, 3, 136), AI_STRIDE_INIT(4, 1, 136, 408, 1224),
  1, &conv2d_23_weights_array, &conv2d_23_weights_intq)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_bias, AI_STATIC,
  117, 0x1,
  AI_SHAPE_INIT(4, 1, 136, 1, 1), AI_STRIDE_INIT(4, 4, 4, 544, 544),
  1, &conv2d_23_bias_array, &conv2d_23_bias_intq)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_weights, AI_STATIC,
  118, 0x1,
  AI_SHAPE_INIT(4, 136, 3, 3, 200), AI_STRIDE_INIT(4, 1, 136, 408, 1224),
  1, &conv2d_27_weights_array, &conv2d_27_weights_intq)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_bias, AI_STATIC,
  119, 0x1,
  AI_SHAPE_INIT(4, 1, 200, 1, 1), AI_STRIDE_INIT(4, 4, 4, 800, 800),
  1, &conv2d_27_bias_array, &conv2d_27_bias_intq)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_weights, AI_STATIC,
  120, 0x1,
  AI_SHAPE_INIT(4, 200, 3, 3, 200), AI_STRIDE_INIT(4, 1, 200, 600, 1800),
  1, &conv2d_30_weights_array, &conv2d_30_weights_intq)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_bias, AI_STATIC,
  121, 0x1,
  AI_SHAPE_INIT(4, 1, 200, 1, 1), AI_STRIDE_INIT(4, 4, 4, 800, 800),
  1, &conv2d_30_bias_array, &conv2d_30_bias_intq)

/* Tensor #122 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_weights, AI_STATIC,
  122, 0x1,
  AI_SHAPE_INIT(4, 200, 3, 3, 51), AI_STRIDE_INIT(4, 1, 200, 600, 1800),
  1, &conv2d_50_weights_array, &conv2d_50_weights_intq)

/* Tensor #123 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_bias, AI_STATIC,
  123, 0x1,
  AI_SHAPE_INIT(4, 1, 51, 1, 1), AI_STRIDE_INIT(4, 4, 4, 204, 204),
  1, &conv2d_50_bias_array, &conv2d_50_bias_intq)

/* Tensor #124 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_weights, AI_STATIC,
  124, 0x1,
  AI_SHAPE_INIT(4, 51, 3, 3, 51), AI_STRIDE_INIT(4, 1, 51, 153, 459),
  1, &conv2d_53_weights_array, &conv2d_53_weights_intq)

/* Tensor #125 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_bias, AI_STATIC,
  125, 0x1,
  AI_SHAPE_INIT(4, 1, 51, 1, 1), AI_STRIDE_INIT(4, 4, 4, 204, 204),
  1, &conv2d_53_bias_array, &conv2d_53_bias_intq)

/* Tensor #126 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_weights, AI_STATIC,
  126, 0x1,
  AI_SHAPE_INIT(4, 51, 1, 1, 51), AI_STRIDE_INIT(4, 1, 51, 51, 51),
  1, &conv2d_56_weights_array, &conv2d_56_weights_intq)

/* Tensor #127 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_bias, AI_STATIC,
  127, 0x1,
  AI_SHAPE_INIT(4, 1, 51, 1, 1), AI_STRIDE_INIT(4, 4, 4, 204, 204),
  1, &conv2d_56_bias_array, &conv2d_56_bias_intq)

/* Tensor #128 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_40_weights, AI_STATIC,
  128, 0x1,
  AI_SHAPE_INIT(4, 200, 3, 3, 200), AI_STRIDE_INIT(4, 1, 200, 600, 1800),
  1, &conv2d_40_weights_array, &conv2d_40_weights_intq)

/* Tensor #129 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_40_bias, AI_STATIC,
  129, 0x1,
  AI_SHAPE_INIT(4, 1, 200, 1, 1), AI_STRIDE_INIT(4, 4, 4, 800, 800),
  1, &conv2d_40_bias_array, &conv2d_40_bias_intq)

/* Tensor #130 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_weights, AI_STATIC,
  130, 0x1,
  AI_SHAPE_INIT(4, 200, 3, 3, 200), AI_STRIDE_INIT(4, 1, 200, 600, 1800),
  1, &conv2d_43_weights_array, &conv2d_43_weights_intq)

/* Tensor #131 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_bias, AI_STATIC,
  131, 0x1,
  AI_SHAPE_INIT(4, 1, 200, 1, 1), AI_STRIDE_INIT(4, 4, 4, 800, 800),
  1, &conv2d_43_bias_array, &conv2d_43_bias_intq)

/* Tensor #132 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_weights, AI_STATIC,
  132, 0x1,
  AI_SHAPE_INIT(4, 200, 1, 1, 1), AI_STRIDE_INIT(4, 1, 200, 200, 200),
  1, &conv2d_46_weights_array, &conv2d_46_weights_intq)

/* Tensor #133 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_bias, AI_STATIC,
  133, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv2d_46_bias_array, &conv2d_46_bias_intq)

/* Tensor #134 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_weights, AI_STATIC,
  134, 0x1,
  AI_SHAPE_INIT(4, 200, 3, 3, 64), AI_STRIDE_INIT(4, 1, 200, 600, 1800),
  1, &conv2d_33_weights_array, &conv2d_33_weights_intq)

/* Tensor #135 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_bias, AI_STATIC,
  135, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_33_bias_array, &conv2d_33_bias_intq)

/* Tensor #136 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_weights, AI_STATIC,
  136, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_36_weights_array, &conv2d_36_weights_intq)

/* Tensor #137 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_bias, AI_STATIC,
  137, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_36_bias_array, &conv2d_36_bias_intq)

/* Tensor #138 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_weights, AI_STATIC,
  138, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 64), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_39_weights_array, &conv2d_39_weights_intq)

/* Tensor #139 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_bias, AI_STATIC,
  139, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_39_bias_array, &conv2d_39_bias_intq)

/* Tensor #140 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_weights, AI_STATIC,
  140, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 1), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_64_weights_array, &conv2d_64_weights_intq)

/* Tensor #141 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_bias, AI_STATIC,
  141, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv2d_64_bias_array, &conv2d_64_bias_intq)

/* Tensor #142 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  142, 0x0,
  AI_SHAPE_INIT(4, 1, 1196, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1196, 1196),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #143 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch0, AI_STATIC,
  143, 0x0,
  AI_SHAPE_INIT(4, 1, 6032, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6032, 6032),
  1, &conv2d_6_scratch0_array, NULL)

/* Tensor #144 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  144, 0x0,
  AI_SHAPE_INIT(4, 1, 6320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6320, 6320),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #145 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_scratch0, AI_STATIC,
  145, 0x0,
  AI_SHAPE_INIT(4, 1, 6992, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6992, 6992),
  1, &conv2d_13_scratch0_array, NULL)

/* Tensor #146 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  146, 0x0,
  AI_SHAPE_INIT(4, 1, 8720, 1, 1), AI_STRIDE_INIT(4, 1, 1, 8720, 8720),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #147 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_scratch0, AI_STATIC,
  147, 0x0,
  AI_SHAPE_INIT(4, 1, 9616, 1, 1), AI_STRIDE_INIT(4, 1, 1, 9616, 9616),
  1, &conv2d_20_scratch0_array, NULL)

/* Tensor #148 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch0, AI_STATIC,
  148, 0x0,
  AI_SHAPE_INIT(4, 1, 11920, 1, 1), AI_STRIDE_INIT(4, 1, 1, 11920, 11920),
  1, &conv2d_23_scratch0_array, NULL)

/* Tensor #149 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch0, AI_STATIC,
  149, 0x0,
  AI_SHAPE_INIT(4, 1, 12816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12816, 12816),
  1, &conv2d_27_scratch0_array, NULL)

/* Tensor #150 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_scratch0, AI_STATIC,
  150, 0x0,
  AI_SHAPE_INIT(4, 1, 15120, 1, 1), AI_STRIDE_INIT(4, 1, 1, 15120, 15120),
  1, &conv2d_30_scratch0_array, NULL)

/* Tensor #151 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_scratch0, AI_STATIC,
  151, 0x0,
  AI_SHAPE_INIT(4, 1, 13034, 1, 1), AI_STRIDE_INIT(4, 1, 1, 13034, 13034),
  1, &conv2d_50_scratch0_array, NULL)

/* Tensor #152 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_scratch0, AI_STATIC,
  152, 0x0,
  AI_SHAPE_INIT(4, 1, 7670, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7670, 7670),
  1, &conv2d_53_scratch0_array, NULL)

/* Tensor #153 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_scratch0, AI_STATIC,
  153, 0x0,
  AI_SHAPE_INIT(4, 1, 714, 1, 1), AI_STRIDE_INIT(4, 1, 1, 714, 714),
  1, &conv2d_56_scratch0_array, NULL)

/* Tensor #154 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_40_scratch0, AI_STATIC,
  154, 0x0,
  AI_SHAPE_INIT(4, 1, 15120, 1, 1), AI_STRIDE_INIT(4, 1, 1, 15120, 15120),
  1, &conv2d_40_scratch0_array, NULL)

/* Tensor #155 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_scratch0, AI_STATIC,
  155, 0x0,
  AI_SHAPE_INIT(4, 1, 15120, 1, 1), AI_STRIDE_INIT(4, 1, 1, 15120, 15120),
  1, &conv2d_43_scratch0_array, NULL)

/* Tensor #156 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_scratch0, AI_STATIC,
  156, 0x0,
  AI_SHAPE_INIT(4, 1, 800, 1, 1), AI_STRIDE_INIT(4, 1, 1, 800, 800),
  1, &conv2d_46_scratch0_array, NULL)

/* Tensor #157 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch0, AI_STATIC,
  157, 0x0,
  AI_SHAPE_INIT(4, 1, 13216, 1, 1), AI_STRIDE_INIT(4, 1, 1, 13216, 13216),
  1, &conv2d_33_scratch0_array, NULL)

/* Tensor #158 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_scratch0, AI_STATIC,
  158, 0x0,
  AI_SHAPE_INIT(4, 1, 8320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 8320, 8320),
  1, &conv2d_36_scratch0_array, NULL)

/* Tensor #159 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_scratch0, AI_STATIC,
  159, 0x0,
  AI_SHAPE_INIT(4, 1, 896, 1, 1), AI_STRIDE_INIT(4, 1, 1, 896, 896),
  1, &conv2d_39_scratch0_array, NULL)

/* Tensor #160 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_scratch0, AI_STATIC,
  160, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &conv2d_64_scratch0_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_images0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_0_layer, 0,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &conversion_0_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_2_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_2_output, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 1,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_2_chain,
  &AI_NET_OBJ_INSTANCE, &nl_3_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 nl_3_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -122, -93, 0, 93, 122, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_3_nl_params, AI_ARRAY_FORMAT_S8,
    nl_3_nl_params_data, nl_3_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_3_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_3_layer, 3,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_3_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_4_layer, AI_STATIC, 
  .nl_params = &nl_3_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_2_output, &nl_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_4_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_4_layer, 4,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_4_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_6_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_6_output, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_6_weights, &conv2d_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_layer, 5,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_6_chain,
  &AI_NET_OBJ_INSTANCE, &nl_7_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 nl_7_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -118, 0, 118, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_7_nl_params, AI_ARRAY_FORMAT_S8,
    nl_7_nl_params_data, nl_7_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_7_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_7_layer, 7,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_7_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_8_layer, AI_STATIC, 
  .nl_params = &nl_7_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_6_output, &nl_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_8_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_8_layer, 8,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_8_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_9_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_9_output, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 9,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_9_chain,
  &AI_NET_OBJ_INSTANCE, &nl_10_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 nl_10_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -126, -118, -84, 0, 84, 118, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_10_nl_params, AI_ARRAY_FORMAT_S8,
    nl_10_nl_params_data, nl_10_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_10_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_10_layer, 10,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_10_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_11_layer, AI_STATIC, 
  .nl_params = &nl_10_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_9_output, &nl_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_11_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_11_layer, 11,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_11_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_13_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_13_output, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_13_weights, &conv2d_13_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_13_layer, 12,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_13_chain,
  &AI_NET_OBJ_INSTANCE, &nl_14_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 nl_14_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -126, -125, -123, -119, -113, -103, -88, -65, -35, 0, 35, 65, 88, 103, 113, 119, 123, 125, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_14_nl_params, AI_ARRAY_FORMAT_S8,
    nl_14_nl_params_data, nl_14_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_14_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_14_layer, 14,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_14_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_15_layer, AI_STATIC, 
  .nl_params = &nl_14_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_13_output, &nl_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_15_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_15_layer, 15,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_15_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_16_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_16_output, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_16_weights, &conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_16_layer, 16,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_16_chain,
  &AI_NET_OBJ_INSTANCE, &nl_17_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 nl_17_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -126, -126, -125, -124, -123, -122, -120, -118, -115, -111, -107, -101, -94, -85, -75, -62, -49, -33, -17, 0, 17, 33, 49, 62, 75, 85, 94, 101, 107, 111, 115, 118, 120, 122, 123, 124, 125, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_17_nl_params, AI_ARRAY_FORMAT_S8,
    nl_17_nl_params_data, nl_17_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_17_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_17_layer, 17,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_17_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_18_layer, AI_STATIC, 
  .nl_params = &nl_17_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_16_output, &nl_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_18_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_18_layer, 18,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_18_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_20_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_20_output, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_20_weights, &conv2d_20_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_20_layer, 19,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_20_chain,
  &AI_NET_OBJ_INSTANCE, &nl_21_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 nl_21_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -126, -126, -126, -125, -125, -124, -123, -122, -121, -120, -118, -116, -114, -112, -109, -105, -101, -97, -91, -85, -79, -71, -63, -54, -44, -34, -23, -11, 0, 11, 23, 34, 44, 54, 63, 71, 79, 85, 91, 97, 101, 105, 109, 112, 114, 116, 118, 120, 121, 122, 123, 124, 125, 125, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_21_nl_params, AI_ARRAY_FORMAT_S8,
    nl_21_nl_params_data, nl_21_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_21_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_21_layer, 21,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_21_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_22_layer, AI_STATIC, 
  .nl_params = &nl_21_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_20_output, &nl_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_22_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_22_layer, 22,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_22_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_23_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_23_output, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_23_weights, &conv2d_23_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_23_layer, 23,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_23_chain,
  &AI_NET_OBJ_INSTANCE, &nl_24_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 nl_24_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -125, -125, -124, -123, -123, -122, -121, -119, -118, -116, -114, -111, -109, -105, -102, -98, -93, -87, -81, -75, -67, -59, -50, -41, -31, -21, -11, 0, 11, 21, 31, 41, 50, 59, 67, 75, 81, 87, 93, 98, 102, 105, 109, 111, 114, 116, 118, 119, 121, 122, 123, 123, 124, 125, 125, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_24_nl_params, AI_ARRAY_FORMAT_S8,
    nl_24_nl_params_data, nl_24_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_24_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_24_layer, 24,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_24_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_25_layer, AI_STATIC, 
  .nl_params = &nl_24_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_23_output, &nl_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_25_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_25_layer, 25,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_25_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_27_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_27_output, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_27_weights, &conv2d_27_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_27_layer, 26,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_27_chain,
  &AI_NET_OBJ_INSTANCE, &nl_28_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 nl_28_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -125, -125, -125, -124, -124, -123, -123, -122, -121, -120, -119, -118, -117, -115, -113, -112, -109, -107, -105, -102, -99, -95, -91, -87, -82, -77, -72, -66, -60, -54, -47, -39, -32, -24, -16, -8, 0, 8, 16, 24, 32, 39, 47, 54, 60, 66, 72, 77, 82, 87, 91, 95, 99, 102, 105, 107, 109, 112, 113, 115, 117, 118, 119, 120, 121, 122, 123, 123, 124, 124, 125, 125, 125, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_28_nl_params, AI_ARRAY_FORMAT_S8,
    nl_28_nl_params_data, nl_28_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_28_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_28_layer, 28,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_28_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_29_layer, AI_STATIC, 
  .nl_params = &nl_28_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_27_output, &nl_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_29_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_29_layer, 29,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_29_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_30_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_30_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_30_output, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_30_weights, &conv2d_30_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_30_layer, 30,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_30_chain,
  &AI_NET_OBJ_INSTANCE, &nl_31_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 nl_31_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -125, -125, -125, -124, -124, -124, -123, -122, -122, -121, -120, -119, -118, -117, -116, -115, -113, -112, -110, -108, -106, -103, -101, -98, -95, -91, -88, -84, -80, -75, -70, -65, -59, -54, -48, -41, -35, -28, -21, -14, -7, 0, 7, 14, 21, 28, 35, 41, 48, 54, 59, 65, 70, 75, 80, 84, 88, 91, 95, 98, 101, 103, 106, 108, 110, 112, 113, 115, 116, 117, 118, 119, 120, 121, 122, 122, 123, 124, 124, 124, 125, 125, 125, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_31_nl_params, AI_ARRAY_FORMAT_S8,
    nl_31_nl_params_data, nl_31_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_31_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_31_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_31_layer, 31,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_31_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_32_layer, AI_STATIC, 
  .nl_params = &nl_31_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_32_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_30_output, &nl_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &eltwise_32_output, &eltwise_32_output, &eltwise_32_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_32_layer, 32,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_32_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_50_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_50_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_50_output, &conv2d_50_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_50_weights, &conv2d_50_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_50_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_50_layer, 50,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_50_chain,
  &AI_NET_OBJ_INSTANCE, &nl_51_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 nl_51_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -126, -126, -126, -125, -125, -124, -124, -123, -122, -121, -120, -118, -117, -115, -112, -110, -106, -103, -99, -94, -89, -83, -76, -68, -60, -51, -42, -32, -22, -11, 0, 11, 22, 32, 42, 51, 60, 68, 76, 83, 89, 94, 99, 103, 106, 110, 112, 115, 117, 118, 120, 121, 122, 123, 124, 124, 125, 125, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_51_nl_params, AI_ARRAY_FORMAT_S8,
    nl_51_nl_params_data, nl_51_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_51_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_50_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_51_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_51_layer, 51,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_51_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_52_layer, AI_STATIC, 
  .nl_params = &nl_51_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_52_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_50_output, &nl_51_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_52_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_52_layer, 52,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_52_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_53_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_53_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_52_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_53_output, &conv2d_53_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_53_weights, &conv2d_53_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_53_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_53_layer, 53,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_53_chain,
  &AI_NET_OBJ_INSTANCE, &nl_54_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 nl_54_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -125, -124, -124, -124, -124, -124, -123, -123, -123, -122, -122, -122, -121, -121, -121, -120, -120, -119, -119, -118, -118, -117, -117, -116, -116, -115, -114, -113, -113, -112, -111, -110, -109, -108, -107, -106, -105, -104, -103, -101, -100, -99, -97, -96, -94, -92, -91, -89, -87, -85, -83, -81, -79, -76, -74, -72, -69, -67, -64, -62, -59, -56, -53, -50, -47, -44, -41, -38, -34, -31, -28, -24, -21, -18, -14, -11, -7, -4, 0, 4, 7, 11, 14, 18, 21, 24, 28, 31, 34, 38, 41, 44, 47, 50, 53, 56, 59, 62, 64, 67, 69, 72, 74, 76, 79, 81, 83, 85, 87, 89, 91, 92, 94 };
AI_ARRAY_OBJ_DECLARE(
    nl_54_nl_params, AI_ARRAY_FORMAT_S8,
    nl_54_nl_params_data, nl_54_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_54_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_53_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_54_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_54_layer, 54,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_54_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_55_layer, AI_STATIC, 
  .nl_params = &nl_54_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_55_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_53_output, &nl_54_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_55_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_55_layer, 55,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_55_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_56_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_56_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_55_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_56_weights, &conv2d_56_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_56_layer, 56,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_56_chain,
  &AI_NET_OBJ_INSTANCE, &transpose_57_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  transpose_57_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_57_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  transpose_57_layer, 57,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &transpose_57_chain,
  &AI_NET_OBJ_INSTANCE, &reshape_58_fmt_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(4, AI_SHAPE_IN_CHANNEL, AI_SHAPE_WIDTH, AI_SHAPE_HEIGHT, AI_SHAPE_CHANNEL), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reshape_58_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_57_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reshape_58_fmt_output, &reshape_58_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reshape_58_fmt_layer, 58,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &reshape_58_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &slice_75_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_u8 slice_75_axes_data[] = { 1 };
AI_ARRAY_OBJ_DECLARE(
    slice_75_axes, AI_ARRAY_FORMAT_U8,
    slice_75_axes_data, slice_75_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_75_starts_data[] = { 1 };
AI_ARRAY_OBJ_DECLARE(
    slice_75_starts, AI_ARRAY_FORMAT_S16,
    slice_75_starts_data, slice_75_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_75_ends_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_75_ends, AI_ARRAY_FORMAT_S16,
    slice_75_ends_data, slice_75_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_75_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reshape_58_fmt_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_75_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_75_layer, 75,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_75_chain,
  &AI_NET_OBJ_INSTANCE, &slice_75_fmt_layer, AI_STATIC, 
  .axes = &slice_75_axes, 
  .starts = &slice_75_starts, 
  .ends = &slice_75_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_75_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_75_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_75_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_75_fmt_layer, 75,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &slice_75_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_76_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_i8 nl_76_nl_params_data[] = { -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -125, -125, -125, -125, -125, -125, -124, -124, -124, -124, -124, -124, -124, -124, -123, -123, -123, -123, -123, -123, -122, -122, -122, -122, -122, -121, -121, -121, -121, -121, -120, -120, -120, -120, -119, -119, -119, -119, -118, -118, -118, -117, -117, -117, -116, -116, -115, -115, -115, -114, -114, -113, -113, -112, -112, -112, -111, -111, -110, -109, -109, -108, -108, -107, -106, -106, -105, -104, -104, -103, -102, -102, -101, -100, -99, -98, -97, -97, -96, -95, -94, -93, -92, -91, -90, -89, -88, -87, -85, -84, -83, -82, -81, -79, -78, -77, -75, -74, -73, -71, -70, -68, -67, -65, -64, -62, -61, -59, -58, -56, -54, -52, -51, -49, -47, -45, -44, -42, -40, -38, -36, -34, -32, -30, -28, -26, -24, -22, -20, -18, -16, -14, -12, -10, -8, -6, -4, -2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 45, 47, 49, 51, 52, 54, 56, 58, 59, 61, 62, 64, 65, 67, 68, 70, 71, 73, 74, 75, 77, 78, 79, 81, 82, 83, 84, 85, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 97, 98, 99, 100, 101, 102, 102, 103, 104, 104, 105, 106, 106, 107, 108, 108, 109, 109, 110, 111, 111, 112, 112, 112, 113, 113, 114 };
AI_ARRAY_OBJ_DECLARE(
    nl_76_nl_params, AI_ARRAY_FORMAT_S8,
    nl_76_nl_params_data, nl_76_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_76_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_75_fmt_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_76_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_76_layer, 76,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_76_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_77_layer, AI_STATIC, 
  .nl_params = &nl_76_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_77_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_76_output, &Const_12),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_77_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_77_layer, 77,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_77_chain,
  &AI_NET_OBJ_INSTANCE, &slice_71_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_u8 slice_71_axes_data[] = { 1 };
AI_ARRAY_OBJ_DECLARE(
    slice_71_axes, AI_ARRAY_FORMAT_U8,
    slice_71_axes_data, slice_71_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_71_starts_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_71_starts, AI_ARRAY_FORMAT_S16,
    slice_71_starts_data, slice_71_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_71_ends_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_71_ends, AI_ARRAY_FORMAT_S16,
    slice_71_ends_data, slice_71_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_71_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reshape_58_fmt_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_71_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_71_layer, 71,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_71_chain,
  &AI_NET_OBJ_INSTANCE, &slice_71_fmt_layer, AI_STATIC, 
  .axes = &slice_71_axes, 
  .starts = &slice_71_starts, 
  .ends = &slice_71_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_71_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_71_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_71_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_71_fmt_layer, 71,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &slice_71_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_72_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_72_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &slice_71_fmt_output, &Const_20),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_72_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_72_layer, 72,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_72_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_73_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_73_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_72_output, &Const_15),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_73_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_73_layer, 73,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_73_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_74_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_74_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_73_output, &model_2_tfmathmultiply_49_Mul_y),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_74_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_74_layer, 74,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_74_chain,
  &AI_NET_OBJ_INSTANCE, &concat_78_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_78_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_74_output, &eltwise_77_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_78_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_78_layer, 78,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_78_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_40_layer, AI_STATIC, 
  .axis = AI_SHAPE_WIDTH, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_40_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_40_output, &conv2d_40_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_40_weights, &conv2d_40_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_40_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_40_layer, 40,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_40_chain,
  &AI_NET_OBJ_INSTANCE, &nl_41_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 nl_41_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -124, -124, -124, -124, -124, -123, -123, -123, -122, -122, -122, -121, -121, -120, -120, -119, -119, -118, -118, -117, -117, -116, -115, -114, -114, -113, -112, -111, -110, -109, -108, -107, -106, -104, -103, -102, -100, -99, -97, -95, -94, -92, -90, -88, -86, -84, -81, -79, -77, -74, -72, -69, -66, -63, -60, -57, -54, -51, -48, -44, -41, -37, -34, -30, -27, -23, -19, -15, -12, -8, -4, 0, 4, 8, 12, 15, 19, 23, 27, 30, 34, 37, 41, 44, 48, 51, 54, 57, 60, 63, 66, 69, 72, 74, 77, 79, 81, 84, 86, 88, 90, 92, 94, 95, 97, 99, 100, 102, 103, 104, 106, 107, 108, 109, 110, 111, 112, 113, 114, 114, 115, 116, 117, 117, 118, 118, 119, 119, 120, 120, 121, 121, 122, 122, 122, 123, 123, 123, 124, 124, 124, 124, 124, 125, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_41_nl_params, AI_ARRAY_FORMAT_S8,
    nl_41_nl_params_data, nl_41_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_41_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_40_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_41_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_41_layer, 41,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_41_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_42_layer, AI_STATIC, 
  .nl_params = &nl_41_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_42_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_40_output, &nl_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_42_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_42_layer, 42,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_42_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_43_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_43_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_43_output, &conv2d_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_43_weights, &conv2d_43_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_43_layer, 43,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_43_chain,
  &AI_NET_OBJ_INSTANCE, &nl_44_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 nl_44_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -124, -124, -124, -124, -123, -123, -123, -123, -122, -122, -122, -121, -121, -120, -120, -119, -119, -118, -118, -117, -116, -116, -115, -114, -113, -112, -112, -111, -110, -108, -107, -106, -105, -104, -102, -101, -99, -98, -96, -94, -92, -91, -89, -87, -84, -82, -80, -77, -75, -72, -70, -67, -64, -61, -58, -55, -51, -48, -45, -41, -38, -34, -31, -27, -23, -19, -15, -12, -8, -4, 0, 4, 8, 12, 15, 19, 23, 27, 31, 34, 38, 41, 45, 48, 51, 55, 58, 61, 64, 67, 70, 72, 75, 77, 80, 82, 84, 87, 89, 91, 92, 94, 96, 98, 99, 101, 102, 104, 105, 106, 107, 108, 110, 111, 112, 112, 113, 114, 115, 116, 116, 117, 118, 118, 119, 119, 120, 120, 121, 121, 122, 122, 122, 123, 123, 123, 123, 124, 124, 124, 124, 125, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_44_nl_params, AI_ARRAY_FORMAT_S8,
    nl_44_nl_params_data, nl_44_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_44_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_44_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_44_layer, 44,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_44_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_45_layer, AI_STATIC, 
  .nl_params = &nl_44_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_45_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_43_output, &nl_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_45_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_45_layer, 45,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_45_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_46_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_46_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_46_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_46_weights, &conv2d_46_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_46_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_46_layer, 46,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_46_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_33_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_33_output, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_33_weights, &conv2d_33_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_33_layer, 33,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_33_chain,
  &AI_NET_OBJ_INSTANCE, &nl_34_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 nl_34_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -125, -124, -124, -124, -124, -123, -123, -123, -123, -122, -122, -122, -121, -121, -120, -120, -119, -119, -118, -118, -117, -117, -116, -115, -115, -114, -113, -112, -111, -110, -110, -109, -107, -106, -105, -104, -103, -101, -100, -98, -97, -95, -93, -92, -90, -88, -86, -84, -82, -79, -77, -75, -72, -70, -67, -64, -61, -58, -56, -52, -49, -46, -43, -40, -36, -33, -29, -26, -22, -18, -15, -11, -7, -4, 0, 4, 7, 11, 15, 18, 22, 26, 29, 33, 36, 40, 43, 46, 49, 52, 56, 58, 61, 64, 67, 70, 72, 75, 77, 79, 82, 84, 86, 88, 90, 92, 93, 95, 97, 98, 100, 101, 103, 104, 105, 106, 107, 109, 110, 110, 111, 112, 113, 114, 115, 115, 116, 117, 117, 118, 118, 119, 119, 120, 120, 121, 121, 122, 122, 122, 123, 123, 123, 123, 124, 124, 124, 124, 125, 125, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_34_nl_params, AI_ARRAY_FORMAT_S8,
    nl_34_nl_params_data, nl_34_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_34_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_34_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_34_layer, 34,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_34_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_35_layer, AI_STATIC, 
  .nl_params = &nl_34_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_35_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_33_output, &nl_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_35_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_35_layer, 35,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_35_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_36_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_36_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_36_output, &conv2d_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_36_weights, &conv2d_36_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_36_layer, 36,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_36_chain,
  &AI_NET_OBJ_INSTANCE, &nl_37_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 nl_37_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -125, -125, -125, -125, -124, -124, -123, -123, -122, -122, -121, -121, -120, -119, -118, -117, -116, -115, -114, -113, -111, -110, -108, -106, -104, -102, -100, -98, -95, -92, -89, -86, -82, -79, -75, -71, -66, -62, -57, -52, -47, -41, -36, -30, -24, -18, -12, -6, 0, 6, 12, 18, 24, 30, 36, 41, 47, 52, 57, 62, 66, 71, 75, 79, 82, 86, 89, 92, 95, 98, 100, 102, 104, 106, 108, 110, 111, 113, 114, 115, 116, 117, 118, 119, 120, 121, 121, 122, 122, 123, 123, 124, 124, 125, 125, 125, 125, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_37_nl_params, AI_ARRAY_FORMAT_S8,
    nl_37_nl_params_data, nl_37_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_37_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_37_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_37_layer, 37,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_37_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_38_layer, AI_STATIC, 
  .nl_params = &nl_37_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_38_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_36_output, &nl_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_38_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_38_layer, 38,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_38_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_39_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_39_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_39_weights, &conv2d_39_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_39_layer, 39,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_39_chain,
  &AI_NET_OBJ_INSTANCE, &concat_47_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_47_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_39_output, &conv2d_46_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_47_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_47_layer, 47,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_47_chain,
  &AI_NET_OBJ_INSTANCE, &transpose_48_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  transpose_48_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_47_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_48_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  transpose_48_layer, 48,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &transpose_48_chain,
  &AI_NET_OBJ_INSTANCE, &reshape_49_fmt_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(4, AI_SHAPE_IN_CHANNEL, AI_SHAPE_WIDTH, AI_SHAPE_HEIGHT, AI_SHAPE_CHANNEL), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reshape_49_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reshape_49_fmt_output, &reshape_49_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reshape_49_fmt_layer, 49,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &reshape_49_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &slice_68_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_u8 slice_68_axes_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_68_axes, AI_ARRAY_FORMAT_U8,
    slice_68_axes_data, slice_68_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_68_starts_data[] = { 64 };
AI_ARRAY_OBJ_DECLARE(
    slice_68_starts, AI_ARRAY_FORMAT_S16,
    slice_68_starts_data, slice_68_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_68_ends_data[] = { 65 };
AI_ARRAY_OBJ_DECLARE(
    slice_68_ends, AI_ARRAY_FORMAT_S16,
    slice_68_ends_data, slice_68_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_68_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reshape_49_fmt_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_68_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_68_layer, 68,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_68_chain,
  &AI_NET_OBJ_INSTANCE, &slice_68_fmt_layer, AI_STATIC, 
  .axes = &slice_68_axes, 
  .starts = &slice_68_starts, 
  .ends = &slice_68_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_68_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_68_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_68_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_68_fmt_layer, 68,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &slice_68_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_69_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_i8 nl_69_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -125, -125, -125, -124, -124, -124, -123, -123, -122, -122, -121, -120, -119, -119, -118, -117, -116, -114, -113, -111, -110, -108, -106, -104, -102, -100, -97, -94, -91, -88, -84, -81, -77, -73, -68, -64, -59, -54, -48, -43, -37, -31, -25, -19, -13, -6, 0, 6, 13, 19, 25, 31, 37, 43, 48, 54, 59, 64, 68, 73, 77, 81, 84, 88, 91, 94, 97, 100, 102, 104, 106, 108, 110, 111, 113, 114, 116, 117, 118, 119, 119, 120, 121, 122, 122, 123, 123, 124, 124, 124, 125, 125, 125, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_69_nl_params, AI_ARRAY_FORMAT_S8,
    nl_69_nl_params_data, nl_69_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_69_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_68_fmt_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_69_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_69_layer, 69,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_69_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_70_layer, AI_STATIC, 
  .nl_params = &nl_69_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_70_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_69_output, &Const_8),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_70_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_70_layer, 70,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_70_chain,
  &AI_NET_OBJ_INSTANCE, &slice_59_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)


AI_STATIC_CONST ai_u8 slice_59_axes_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_59_axes, AI_ARRAY_FORMAT_U8,
    slice_59_axes_data, slice_59_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_59_starts_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_59_starts, AI_ARRAY_FORMAT_S16,
    slice_59_starts_data, slice_59_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_59_ends_data[] = { 64 };
AI_ARRAY_OBJ_DECLARE(
    slice_59_ends, AI_ARRAY_FORMAT_S16,
    slice_59_ends_data, slice_59_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_59_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reshape_49_fmt_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_59_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_59_layer, 59,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_59_chain,
  &AI_NET_OBJ_INSTANCE, &slice_59_fmt_layer, AI_STATIC, 
  .axes = &slice_59_axes, 
  .starts = &slice_59_starts, 
  .ends = &slice_59_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_59_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_59_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_59_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_59_fmt_layer, 59,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &slice_59_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &transpose_61_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  transpose_61_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_59_fmt_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_61_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  transpose_61_layer, 61,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &transpose_61_chain,
  &AI_NET_OBJ_INSTANCE, &transpose_62_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(4, AI_SHAPE_IN_CHANNEL, AI_SHAPE_CHANNEL, AI_SHAPE_HEIGHT, AI_SHAPE_WIDTH), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  transpose_62_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_61_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_62_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  transpose_62_layer, 62,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &transpose_62_chain,
  &AI_NET_OBJ_INSTANCE, &transpose_62_fmt_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(4, AI_SHAPE_IN_CHANNEL, AI_SHAPE_HEIGHT, AI_SHAPE_CHANNEL, AI_SHAPE_WIDTH), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  transpose_62_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_62_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_62_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  transpose_62_fmt_layer, 62,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &transpose_62_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_63_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_63_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &transpose_62_fmt_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_63_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_63_layer, 63,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &nl_63_chain,
  &AI_NET_OBJ_INSTANCE, &nl_63_fmt_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_63_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_63_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_63_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_63_fmt_layer, 63,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &nl_63_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_64_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_64_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_63_fmt_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_64_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_64_weights, &conv2d_64_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_64_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_64_layer, 64,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA,
  &conv2d_64_chain,
  &AI_NET_OBJ_INSTANCE, &reshape_65_fmt_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reshape_65_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_64_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reshape_65_fmt_output, &reshape_65_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reshape_65_fmt_layer, 65,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &reshape_65_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &slice_80_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_u8 slice_80_axes_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_80_axes, AI_ARRAY_FORMAT_U8,
    slice_80_axes_data, slice_80_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_80_starts_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_80_starts, AI_ARRAY_FORMAT_S16,
    slice_80_starts_data, slice_80_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_80_ends_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_80_ends, AI_ARRAY_FORMAT_S16,
    slice_80_ends_data, slice_80_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_80_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reshape_65_fmt_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_80_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_80_layer, 80,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_80_chain,
  &AI_NET_OBJ_INSTANCE, &slice_80_fmt_layer, AI_STATIC, 
  .axes = &slice_80_axes, 
  .starts = &slice_80_starts, 
  .ends = &slice_80_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_80_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_80_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_80_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_80_fmt_layer, 80,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &slice_80_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_81_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_81_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &Const_13, &slice_80_fmt_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_81_output, &eltwise_81_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_81_layer, 81,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_81_chain,
  &AI_NET_OBJ_INSTANCE, &slice_66_layer, AI_STATIC, 
  .operation = ai_sub, 
  .buffer_operation = ai_sub_buffer_INT8, 
)


AI_STATIC_CONST ai_u8 slice_66_axes_data[] = { 0 };
AI_ARRAY_OBJ_DECLARE(
    slice_66_axes, AI_ARRAY_FORMAT_U8,
    slice_66_axes_data, slice_66_axes_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_66_starts_data[] = { 2 };
AI_ARRAY_OBJ_DECLARE(
    slice_66_starts, AI_ARRAY_FORMAT_S16,
    slice_66_starts_data, slice_66_starts_data, 1, AI_STATIC_CONST)

AI_STATIC_CONST ai_i16 slice_66_ends_data[] = { 4 };
AI_ARRAY_OBJ_DECLARE(
    slice_66_ends, AI_ARRAY_FORMAT_S16,
    slice_66_ends_data, slice_66_ends_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_66_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reshape_65_fmt_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_66_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_66_layer, 66,
  SLICE_TYPE, 0x0, NULL,
  slice, forward_slice,
  &slice_66_chain,
  &AI_NET_OBJ_INSTANCE, &slice_66_fmt_layer, AI_STATIC, 
  .axes = &slice_66_axes, 
  .starts = &slice_66_starts, 
  .ends = &slice_66_ends, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_66_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_66_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_66_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_66_fmt_layer, 66,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &slice_66_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_67_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_67_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &slice_66_fmt_output, &Const_13),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_67_output, &eltwise_67_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_67_layer, 67,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_67_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_84_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_84_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_67_output, &eltwise_81_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_84_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_84_layer, 84,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_84_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_82_layer, AI_STATIC, 
  .operation = ai_sub, 
  .buffer_operation = ai_sub_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_82_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_81_output, &eltwise_67_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_82_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_82_layer, 82,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_82_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_83_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_83_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_82_output, &model_2_tfmathdivide_truedivConst_9),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_83_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_83_layer, 83,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_83_chain,
  &AI_NET_OBJ_INSTANCE, &concat_85_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_85_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_83_output, &eltwise_84_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_85_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_85_layer, 85,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_85_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_86_layer, AI_STATIC, 
  .axis = AI_SHAPE_HEIGHT, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_86_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &concat_85_output, &model_2_tfmathmultiply_58_Mul_y),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_86_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_86_layer, 86,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_86_chain,
  &AI_NET_OBJ_INSTANCE, &concat_87_layer, AI_STATIC, 
  .operation = ai_mul, 
  .buffer_operation = ai_mul_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_87_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &eltwise_86_output, &eltwise_70_output, &concat_78_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_87_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_87_layer, 87,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_87_chain,
  &AI_NET_OBJ_INSTANCE, &conversion_88_layer, AI_STATIC, 
  .axis = AI_SHAPE_HEIGHT, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_88_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_87_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_88_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_88_layer, 88,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &conversion_88_chain,
  &AI_NET_OBJ_INSTANCE, &conversion_88_layer, AI_STATIC, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 1931484, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 196608, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_PHI_IN_NUM, &serving_default_images0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_PHI_OUT_NUM, &conversion_88_output),
  &conversion_0_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool network_phi_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, 4));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    serving_default_images0_output_array.data = AI_PTR(activations + 0);
    serving_default_images0_output_array.data_start = AI_PTR(activations + 0);
    conversion_0_output_array.data = AI_PTR(activations + 0);
    conversion_0_output_array.data_start = AI_PTR(activations + 0);
    conv2d_2_output_array.data = AI_PTR(activations + 131072);
    conv2d_2_output_array.data_start = AI_PTR(activations + 131072);
    nl_3_output_array.data = AI_PTR(activations + 0);
    nl_3_output_array.data_start = AI_PTR(activations + 0);
    eltwise_4_output_array.data = AI_PTR(activations + 65536);
    eltwise_4_output_array.data_start = AI_PTR(activations + 65536);
    conv2d_6_output_array.data = AI_PTR(activations + 6032);
    conv2d_6_output_array.data_start = AI_PTR(activations + 6032);
    nl_7_output_array.data = AI_PTR(activations + 30608);
    nl_7_output_array.data_start = AI_PTR(activations + 30608);
    eltwise_8_output_array.data = AI_PTR(activations + 55184);
    eltwise_8_output_array.data_start = AI_PTR(activations + 55184);
    conv2d_9_output_array.data = AI_PTR(activations + 6320);
    conv2d_9_output_array.data_start = AI_PTR(activations + 6320);
    nl_10_output_array.data = AI_PTR(activations + 30896);
    nl_10_output_array.data_start = AI_PTR(activations + 30896);
    eltwise_11_output_array.data = AI_PTR(activations + 55472);
    eltwise_11_output_array.data_start = AI_PTR(activations + 55472);
    conv2d_13_output_array.data = AI_PTR(activations + 6992);
    conv2d_13_output_array.data_start = AI_PTR(activations + 6992);
    nl_14_output_array.data = AI_PTR(activations + 25424);
    nl_14_output_array.data_start = AI_PTR(activations + 25424);
    eltwise_15_output_array.data = AI_PTR(activations + 43856);
    eltwise_15_output_array.data_start = AI_PTR(activations + 43856);
    conv2d_16_output_array.data = AI_PTR(activations + 8720);
    conv2d_16_output_array.data_start = AI_PTR(activations + 8720);
    nl_17_output_array.data = AI_PTR(activations + 27152);
    nl_17_output_array.data_start = AI_PTR(activations + 27152);
    eltwise_18_output_array.data = AI_PTR(activations + 45584);
    eltwise_18_output_array.data_start = AI_PTR(activations + 45584);
    conv2d_20_output_array.data = AI_PTR(activations + 9616);
    conv2d_20_output_array.data_start = AI_PTR(activations + 9616);
    nl_21_output_array.data = AI_PTR(activations + 0);
    nl_21_output_array.data_start = AI_PTR(activations + 0);
    eltwise_22_output_array.data = AI_PTR(activations + 18320);
    eltwise_22_output_array.data_start = AI_PTR(activations + 18320);
    conv2d_23_output_array.data = AI_PTR(activations + 27024);
    conv2d_23_output_array.data_start = AI_PTR(activations + 27024);
    nl_24_output_array.data = AI_PTR(activations + 0);
    nl_24_output_array.data_start = AI_PTR(activations + 0);
    eltwise_25_output_array.data = AI_PTR(activations + 8704);
    eltwise_25_output_array.data_start = AI_PTR(activations + 8704);
    conv2d_27_output_array.data = AI_PTR(activations + 0);
    conv2d_27_output_array.data_start = AI_PTR(activations + 0);
    nl_28_output_array.data = AI_PTR(activations + 3200);
    nl_28_output_array.data_start = AI_PTR(activations + 3200);
    eltwise_29_output_array.data = AI_PTR(activations + 6400);
    eltwise_29_output_array.data_start = AI_PTR(activations + 6400);
    conv2d_30_output_array.data = AI_PTR(activations + 0);
    conv2d_30_output_array.data_start = AI_PTR(activations + 0);
    nl_31_output_array.data = AI_PTR(activations + 3200);
    nl_31_output_array.data_start = AI_PTR(activations + 3200);
    eltwise_32_output_array.data = AI_PTR(activations + 6400);
    eltwise_32_output_array.data_start = AI_PTR(activations + 6400);
    conv2d_50_output_array.data = AI_PTR(activations + 0);
    conv2d_50_output_array.data_start = AI_PTR(activations + 0);
    nl_51_output_array.data = AI_PTR(activations + 816);
    nl_51_output_array.data_start = AI_PTR(activations + 816);
    eltwise_52_output_array.data = AI_PTR(activations + 1632);
    eltwise_52_output_array.data_start = AI_PTR(activations + 1632);
    conv2d_53_output_array.data = AI_PTR(activations + 0);
    conv2d_53_output_array.data_start = AI_PTR(activations + 0);
    nl_54_output_array.data = AI_PTR(activations + 816);
    nl_54_output_array.data_start = AI_PTR(activations + 816);
    eltwise_55_output_array.data = AI_PTR(activations + 1632);
    eltwise_55_output_array.data_start = AI_PTR(activations + 1632);
    conv2d_56_output_array.data = AI_PTR(activations + 716);
    conv2d_56_output_array.data_start = AI_PTR(activations + 716);
    transpose_57_output_array.data = AI_PTR(activations + 1532);
    transpose_57_output_array.data_start = AI_PTR(activations + 1532);
    reshape_58_fmt_output_array.data = AI_PTR(activations + 2348);
    reshape_58_fmt_output_array.data_start = AI_PTR(activations + 2348);
    slice_75_output_array.data = AI_PTR(activations + 0);
    slice_75_output_array.data_start = AI_PTR(activations + 0);
    slice_75_fmt_output_array.data = AI_PTR(activations + 1088);
    slice_75_fmt_output_array.data_start = AI_PTR(activations + 1088);
    nl_76_output_array.data = AI_PTR(activations + 0);
    nl_76_output_array.data_start = AI_PTR(activations + 0);
    eltwise_77_output_array.data = AI_PTR(activations + 272);
    eltwise_77_output_array.data_start = AI_PTR(activations + 272);
    slice_71_output_array.data = AI_PTR(activations + 9600);
    slice_71_output_array.data_start = AI_PTR(activations + 9600);
    slice_71_fmt_output_array.data = AI_PTR(activations + 544);
    slice_71_fmt_output_array.data_start = AI_PTR(activations + 544);
    eltwise_72_output_array.data = AI_PTR(activations + 1088);
    eltwise_72_output_array.data_start = AI_PTR(activations + 1088);
    eltwise_73_output_array.data = AI_PTR(activations + 544);
    eltwise_73_output_array.data_start = AI_PTR(activations + 544);
    eltwise_74_output_array.data = AI_PTR(activations + 1088);
    eltwise_74_output_array.data_start = AI_PTR(activations + 1088);
    concat_78_output_array.data = AI_PTR(activations + 1632);
    concat_78_output_array.data_start = AI_PTR(activations + 1632);
    conv2d_40_output_array.data = AI_PTR(activations + 2448);
    conv2d_40_output_array.data_start = AI_PTR(activations + 2448);
    nl_41_output_array.data = AI_PTR(activations + 9600);
    nl_41_output_array.data_start = AI_PTR(activations + 9600);
    eltwise_42_output_array.data = AI_PTR(activations + 12800);
    eltwise_42_output_array.data_start = AI_PTR(activations + 12800);
    conv2d_43_output_array.data = AI_PTR(activations + 2448);
    conv2d_43_output_array.data_start = AI_PTR(activations + 2448);
    nl_44_output_array.data = AI_PTR(activations + 9600);
    nl_44_output_array.data_start = AI_PTR(activations + 9600);
    eltwise_45_output_array.data = AI_PTR(activations + 12800);
    eltwise_45_output_array.data_start = AI_PTR(activations + 12800);
    conv2d_46_output_array.data = AI_PTR(activations + 800);
    conv2d_46_output_array.data_start = AI_PTR(activations + 800);
    conv2d_33_output_array.data = AI_PTR(activations + 2448);
    conv2d_33_output_array.data_start = AI_PTR(activations + 2448);
    nl_34_output_array.data = AI_PTR(activations + 3472);
    nl_34_output_array.data_start = AI_PTR(activations + 3472);
    eltwise_35_output_array.data = AI_PTR(activations + 4496);
    eltwise_35_output_array.data_start = AI_PTR(activations + 4496);
    conv2d_36_output_array.data = AI_PTR(activations + 2448);
    conv2d_36_output_array.data_start = AI_PTR(activations + 2448);
    nl_37_output_array.data = AI_PTR(activations + 3472);
    nl_37_output_array.data_start = AI_PTR(activations + 3472);
    eltwise_38_output_array.data = AI_PTR(activations + 4496);
    eltwise_38_output_array.data_start = AI_PTR(activations + 4496);
    conv2d_39_output_array.data = AI_PTR(activations + 3344);
    conv2d_39_output_array.data_start = AI_PTR(activations + 3344);
    concat_47_output_array.data = AI_PTR(activations + 4368);
    concat_47_output_array.data_start = AI_PTR(activations + 4368);
    transpose_48_output_array.data = AI_PTR(activations + 0);
    transpose_48_output_array.data_start = AI_PTR(activations + 0);
    reshape_49_fmt_output_array.data = AI_PTR(activations + 2448);
    reshape_49_fmt_output_array.data_start = AI_PTR(activations + 2448);
    slice_68_output_array.data = AI_PTR(activations + 0);
    slice_68_output_array.data_start = AI_PTR(activations + 0);
    slice_68_fmt_output_array.data = AI_PTR(activations + 64);
    slice_68_fmt_output_array.data_start = AI_PTR(activations + 64);
    nl_69_output_array.data = AI_PTR(activations + 0);
    nl_69_output_array.data_start = AI_PTR(activations + 0);
    eltwise_70_output_array.data = AI_PTR(activations + 16);
    eltwise_70_output_array.data_start = AI_PTR(activations + 16);
    slice_59_output_array.data = AI_PTR(activations + 6608);
    slice_59_output_array.data_start = AI_PTR(activations + 6608);
    slice_59_fmt_output_array.data = AI_PTR(activations + 32);
    slice_59_fmt_output_array.data_start = AI_PTR(activations + 32);
    transpose_61_output_array.data = AI_PTR(activations + 2448);
    transpose_61_output_array.data_start = AI_PTR(activations + 2448);
    transpose_62_output_array.data = AI_PTR(activations + 32);
    transpose_62_output_array.data_start = AI_PTR(activations + 32);
    transpose_62_fmt_output_array.data = AI_PTR(activations + 2448);
    transpose_62_fmt_output_array.data_start = AI_PTR(activations + 2448);
    nl_63_output_array.data = AI_PTR(activations + 6544);
    nl_63_output_array.data_start = AI_PTR(activations + 6544);
    nl_63_fmt_output_array.data = AI_PTR(activations + 32);
    nl_63_fmt_output_array.data_start = AI_PTR(activations + 32);
    conv2d_64_output_array.data = AI_PTR(activations + 1120);
    conv2d_64_output_array.data_start = AI_PTR(activations + 1120);
    reshape_65_fmt_output_array.data = AI_PTR(activations + 32);
    reshape_65_fmt_output_array.data_start = AI_PTR(activations + 32);
    slice_80_output_array.data = AI_PTR(activations + 288);
    slice_80_output_array.data_start = AI_PTR(activations + 288);
    slice_80_fmt_output_array.data = AI_PTR(activations + 416);
    slice_80_fmt_output_array.data_start = AI_PTR(activations + 416);
    eltwise_81_output_array.data = AI_PTR(activations + 288);
    eltwise_81_output_array.data_start = AI_PTR(activations + 288);
    slice_66_output_array.data = AI_PTR(activations + 320);
    slice_66_output_array.data_start = AI_PTR(activations + 320);
    slice_66_fmt_output_array.data = AI_PTR(activations + 32);
    slice_66_fmt_output_array.data_start = AI_PTR(activations + 32);
    eltwise_67_output_array.data = AI_PTR(activations + 64);
    eltwise_67_output_array.data_start = AI_PTR(activations + 64);
    eltwise_84_output_array.data = AI_PTR(activations + 32);
    eltwise_84_output_array.data_start = AI_PTR(activations + 32);
    eltwise_82_output_array.data = AI_PTR(activations + 96);
    eltwise_82_output_array.data_start = AI_PTR(activations + 96);
    eltwise_83_output_array.data = AI_PTR(activations + 64);
    eltwise_83_output_array.data_start = AI_PTR(activations + 64);
    concat_85_output_array.data = AI_PTR(activations + 96);
    concat_85_output_array.data_start = AI_PTR(activations + 96);
    eltwise_86_output_array.data = AI_PTR(activations + 32);
    eltwise_86_output_array.data_start = AI_PTR(activations + 32);
    concat_87_output_array.data = AI_PTR(activations + 96);
    concat_87_output_array.data_start = AI_PTR(activations + 96);
    conversion_88_output_array.data = AI_PTR(activations + 992);
    conversion_88_output_array.data_start = AI_PTR(activations + 992);
    conv2d_2_scratch0_array.data = AI_PTR(activations + 49152);
    conv2d_2_scratch0_array.data_start = AI_PTR(activations + 49152);
    conv2d_6_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_6_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_9_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_9_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_13_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_13_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_16_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_16_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_20_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_20_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_23_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_23_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_27_scratch0_array.data = AI_PTR(activations + 17408);
    conv2d_27_scratch0_array.data_start = AI_PTR(activations + 17408);
    conv2d_30_scratch0_array.data = AI_PTR(activations + 9600);
    conv2d_30_scratch0_array.data_start = AI_PTR(activations + 9600);
    conv2d_50_scratch0_array.data = AI_PTR(activations + 9600);
    conv2d_50_scratch0_array.data_start = AI_PTR(activations + 9600);
    conv2d_53_scratch0_array.data = AI_PTR(activations + 9600);
    conv2d_53_scratch0_array.data_start = AI_PTR(activations + 9600);
    conv2d_56_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_56_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_40_scratch0_array.data = AI_PTR(activations + 9600);
    conv2d_40_scratch0_array.data_start = AI_PTR(activations + 9600);
    conv2d_43_scratch0_array.data = AI_PTR(activations + 16000);
    conv2d_43_scratch0_array.data_start = AI_PTR(activations + 16000);
    conv2d_46_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_46_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_33_scratch0_array.data = AI_PTR(activations + 9600);
    conv2d_33_scratch0_array.data_start = AI_PTR(activations + 9600);
    conv2d_36_scratch0_array.data = AI_PTR(activations + 5520);
    conv2d_36_scratch0_array.data_start = AI_PTR(activations + 5520);
    conv2d_39_scratch0_array.data = AI_PTR(activations + 2448);
    conv2d_39_scratch0_array.data_start = AI_PTR(activations + 2448);
    conv2d_64_scratch0_array.data = AI_PTR(activations + 1056);
    conv2d_64_scratch0_array.data_start = AI_PTR(activations + 1056);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool network_phi_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    model_2_tfmathmultiply_58_Mul_y_array.format |= AI_FMT_FLAG_CONST;
    model_2_tfmathmultiply_58_Mul_y_array.data = AI_PTR(weights + 0);
    model_2_tfmathmultiply_58_Mul_y_array.data_start = AI_PTR(weights + 0);
    model_2_tfmathdivide_truedivConst_9_array.format |= AI_FMT_FLAG_CONST;
    model_2_tfmathdivide_truedivConst_9_array.data = AI_PTR(weights + 16);
    model_2_tfmathdivide_truedivConst_9_array.data_start = AI_PTR(weights + 16);
    Const_12_array.format |= AI_FMT_FLAG_CONST;
    Const_12_array.data = AI_PTR(weights + 20);
    Const_12_array.data_start = AI_PTR(weights + 20);
    model_2_tfmathmultiply_49_Mul_y_array.format |= AI_FMT_FLAG_CONST;
    model_2_tfmathmultiply_49_Mul_y_array.data = AI_PTR(weights + 24);
    model_2_tfmathmultiply_49_Mul_y_array.data_start = AI_PTR(weights + 24);
    Const_15_array.format |= AI_FMT_FLAG_CONST;
    Const_15_array.data = AI_PTR(weights + 40);
    Const_15_array.data_start = AI_PTR(weights + 40);
    Const_20_array.format |= AI_FMT_FLAG_CONST;
    Const_20_array.data = AI_PTR(weights + 72);
    Const_20_array.data_start = AI_PTR(weights + 72);
    Const_8_array.format |= AI_FMT_FLAG_CONST;
    Const_8_array.data = AI_PTR(weights + 76);
    Const_8_array.data_start = AI_PTR(weights + 76);
    Const_13_array.format |= AI_FMT_FLAG_CONST;
    Const_13_array.data = AI_PTR(weights + 80);
    Const_13_array.data_start = AI_PTR(weights + 80);
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(weights + 112);
    conv2d_2_weights_array.data_start = AI_PTR(weights + 112);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(weights + 544);
    conv2d_2_bias_array.data_start = AI_PTR(weights + 544);
    conv2d_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_weights_array.data = AI_PTR(weights + 608);
    conv2d_6_weights_array.data_start = AI_PTR(weights + 608);
    conv2d_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_bias_array.data = AI_PTR(weights + 4064);
    conv2d_6_bias_array.data_start = AI_PTR(weights + 4064);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(weights + 4160);
    conv2d_9_weights_array.data_start = AI_PTR(weights + 4160);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(weights + 9344);
    conv2d_9_bias_array.data_start = AI_PTR(weights + 9344);
    conv2d_13_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_weights_array.data = AI_PTR(weights + 9440);
    conv2d_13_weights_array.data_start = AI_PTR(weights + 9440);
    conv2d_13_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_bias_array.data = AI_PTR(weights + 24992);
    conv2d_13_bias_array.data_start = AI_PTR(weights + 24992);
    conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_weights_array.data = AI_PTR(weights + 25280);
    conv2d_16_weights_array.data_start = AI_PTR(weights + 25280);
    conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_bias_array.data = AI_PTR(weights + 71936);
    conv2d_16_bias_array.data_start = AI_PTR(weights + 71936);
    conv2d_20_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_weights_array.data = AI_PTR(weights + 72224);
    conv2d_20_weights_array.data_start = AI_PTR(weights + 72224);
    conv2d_20_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_bias_array.data = AI_PTR(weights + 160352);
    conv2d_20_bias_array.data_start = AI_PTR(weights + 160352);
    conv2d_23_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_weights_array.data = AI_PTR(weights + 160896);
    conv2d_23_weights_array.data_start = AI_PTR(weights + 160896);
    conv2d_23_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_bias_array.data = AI_PTR(weights + 327360);
    conv2d_23_bias_array.data_start = AI_PTR(weights + 327360);
    conv2d_27_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_weights_array.data = AI_PTR(weights + 327904);
    conv2d_27_weights_array.data_start = AI_PTR(weights + 327904);
    conv2d_27_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_bias_array.data = AI_PTR(weights + 572704);
    conv2d_27_bias_array.data_start = AI_PTR(weights + 572704);
    conv2d_30_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_weights_array.data = AI_PTR(weights + 573504);
    conv2d_30_weights_array.data_start = AI_PTR(weights + 573504);
    conv2d_30_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_bias_array.data = AI_PTR(weights + 933504);
    conv2d_30_bias_array.data_start = AI_PTR(weights + 933504);
    conv2d_50_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_50_weights_array.data = AI_PTR(weights + 934304);
    conv2d_50_weights_array.data_start = AI_PTR(weights + 934304);
    conv2d_50_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_50_bias_array.data = AI_PTR(weights + 1026104);
    conv2d_50_bias_array.data_start = AI_PTR(weights + 1026104);
    conv2d_53_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_53_weights_array.data = AI_PTR(weights + 1026308);
    conv2d_53_weights_array.data_start = AI_PTR(weights + 1026308);
    conv2d_53_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_53_bias_array.data = AI_PTR(weights + 1049720);
    conv2d_53_bias_array.data_start = AI_PTR(weights + 1049720);
    conv2d_56_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_56_weights_array.data = AI_PTR(weights + 1049924);
    conv2d_56_weights_array.data_start = AI_PTR(weights + 1049924);
    conv2d_56_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_56_bias_array.data = AI_PTR(weights + 1052528);
    conv2d_56_bias_array.data_start = AI_PTR(weights + 1052528);
    conv2d_40_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_40_weights_array.data = AI_PTR(weights + 1052732);
    conv2d_40_weights_array.data_start = AI_PTR(weights + 1052732);
    conv2d_40_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_40_bias_array.data = AI_PTR(weights + 1412732);
    conv2d_40_bias_array.data_start = AI_PTR(weights + 1412732);
    conv2d_43_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_43_weights_array.data = AI_PTR(weights + 1413532);
    conv2d_43_weights_array.data_start = AI_PTR(weights + 1413532);
    conv2d_43_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_43_bias_array.data = AI_PTR(weights + 1773532);
    conv2d_43_bias_array.data_start = AI_PTR(weights + 1773532);
    conv2d_46_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_46_weights_array.data = AI_PTR(weights + 1774332);
    conv2d_46_weights_array.data_start = AI_PTR(weights + 1774332);
    conv2d_46_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_46_bias_array.data = AI_PTR(weights + 1774532);
    conv2d_46_bias_array.data_start = AI_PTR(weights + 1774532);
    conv2d_33_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_weights_array.data = AI_PTR(weights + 1774536);
    conv2d_33_weights_array.data_start = AI_PTR(weights + 1774536);
    conv2d_33_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_bias_array.data = AI_PTR(weights + 1889736);
    conv2d_33_bias_array.data_start = AI_PTR(weights + 1889736);
    conv2d_36_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_weights_array.data = AI_PTR(weights + 1889992);
    conv2d_36_weights_array.data_start = AI_PTR(weights + 1889992);
    conv2d_36_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_bias_array.data = AI_PTR(weights + 1926856);
    conv2d_36_bias_array.data_start = AI_PTR(weights + 1926856);
    conv2d_39_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_39_weights_array.data = AI_PTR(weights + 1927112);
    conv2d_39_weights_array.data_start = AI_PTR(weights + 1927112);
    conv2d_39_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_39_bias_array.data = AI_PTR(weights + 1931208);
    conv2d_39_bias_array.data_start = AI_PTR(weights + 1931208);
    conv2d_64_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_64_weights_array.data = AI_PTR(weights + 1931464);
    conv2d_64_weights_array.data_start = AI_PTR(weights + 1931464);
    conv2d_64_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_64_bias_array.data = AI_PTR(weights + 1931480);
    conv2d_64_bias_array.data_start = AI_PTR(weights + 1931480);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_network_phi_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_PHI_MODEL_NAME,
      .model_signature   = AI_NETWORK_PHI_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 68922683,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_network_phi_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_phi_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_network_phi_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_phi_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= network_phi_configure_weights(net_ctx, &params->params);
  ok &= network_phi_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_phi_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_phi_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_PHI_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

