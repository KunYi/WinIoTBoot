/** @file
*
*  Copyright (c) 2007-2014, Allwinner Technology Co., Ltd. All rights reserved.
*  http://www.allwinnertech.com
*
*  tangmanliang <tangmanliang@allwinnertech.com>
*  
*  This program and the accompanying materials                          
*  are licensed and made available under the terms and conditions of the BSD License         
*  which accompanies this distribution.  The full text of the license may be found at        
*  http://opensource.org/licenses/bsd-license.php                                            
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.             
*
**/

#include "disp_features.h"

int bsp_disp_feat_get_num_screens(void)
{
  return de_feat_get_num_screens();
}

int bsp_disp_feat_get_num_devices(void)
{
  return de_feat_get_num_devices();
}

int bsp_disp_feat_get_num_channels(unsigned int disp)
{
  return de_feat_get_num_chns(disp);
}

int bsp_disp_feat_get_num_layers(unsigned int disp)
{
  return de_feat_get_num_layers(disp);
}

int bsp_disp_feat_get_num_layers_by_chn(unsigned int disp, unsigned int chn)
{
  return de_feat_get_num_layers_by_chn(disp, chn);
}

/*
 * Query whether specified timing controller support the output_type passed as parameter
 * @disp: the index of timing controller
 * @output_type: the display output type
 * On support, returns 1. Otherwise, returns 0.
 */
int bsp_disp_feat_is_supported_output_types(unsigned int disp, unsigned int output_type)
{
  return de_feat_is_supported_output_types(disp, output_type);
}

int disp_feat_is_support_smbl(unsigned int disp)
{
  return de_feat_is_support_smbl(disp);
}

int bsp_disp_feat_is_support_capture(unsigned int disp)
{
  return de_feat_is_support_wb(disp);
}

int disp_init_feat(void)
{
#if 0
  {
    unsigned int num_screens, disp;
    DE_INF("------------FEAT---------\n");
    num_screens = bsp_disp_feat_get_num_screens();
    DE_INF("screens:%d\n", num_screens);
    for (disp=0; disp<num_screens; disp++) {
      unsigned int num_chns = bsp_disp_feat_get_num_channels(disp);
      unsigned int num_layers =  bsp_disp_feat_get_num_layers(disp);
      unsigned int i;
      DE_INF("screen %d: %d chns, %d layers\n", disp, num_chns, num_layers);
      for (i=0; i<num_chns; i++) {
        num_layers = bsp_disp_feat_get_num_layers_by_chn(disp, i);
        DE_INF("screen %d, chn %d: %d layers\n", disp, i, num_layers);
      }

    }
    DE_INF("-------------------------\n");
  }
#endif
  return 0;
}

