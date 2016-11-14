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

#include <common.h>
#include <asm/io.h>
#include <asm/arch/spc.h>

/*
************************************************************************************************************
*
*                                             function
*
*    name          :
*
*    parmeters     :
*
*    return        :
*
*    note          :
*
*
************************************************************************************************************
*/
void sunxi_spc_set_to_ns(uint type)
{
  writel(0xbe, SPC_SET_REG(0));
  writel(0x7f, SPC_SET_REG(1));
  writel(0x10, SPC_SET_REG(2));
}
/*
************************************************************************************************************
*
*                                             function
*
*    name          :
*
*    parmeters     :
*
*    return        :
*
*    note          :
*
*
************************************************************************************************************
*/
void sunxi_spc_set_to_s(uint type)
{
  u8  sub_type0, sub_type1;

  sub_type0 = type & 0xff;
  sub_type1 = (type>>8) & 0xff;

  if(sub_type0)
  {
    writel(sub_type0, SPC_CLEAR_REG(0));
  }
  if(sub_type1)
  {
    writel(sub_type1, SPC_CLEAR_REG(1));
  }
}
/*
************************************************************************************************************
*
*                                             function
*
*    name          :
*
*    parmeters     :
*
*    return        :
*
*    note          :
*
*
************************************************************************************************************
*/
uint sunxi_spc_probe_status(uint type)
{
  if(type < 8)
  {
    return (readl(SPC_STATUS_REG(0)) >> type) & 1;
  }
  if(type < 16)
  {
    return (readl(SPC_STATUS_REG(1)) >> type) & 1;
  }

  return 0;
}

