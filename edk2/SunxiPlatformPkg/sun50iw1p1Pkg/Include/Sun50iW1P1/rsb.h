/** @file
*
*  Copyright (c) 2007-2014, Allwinner Technology Co., Ltd. All rights reserved.
*  http://www.allwinnertech.com
*
*  lixiang <lixiang@allwinnertech.com>
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


#ifndef __RSB_HAL_H
#define __RSB_HAL_H

//#include <common.h>
//#include <asm/io.h>
//#include <smc.h>
//#define RSB_USE_INT

#ifndef R_RSB_BASE
#define R_RSB_BASE  (0x01f03400)//should modified acorrding to environment
#endif


#define RET_FAIL  -20



//#define rsb_printk(format,arg...) printf(format,##arg)
//#define rsb_printk  printk
//#define rsb_printk(format,arg...)

#define RSB_SCK   3000000
#define RSB_CDODLY  1
/* register define */
#define RSB_REG_CTRL  (R_RSB_BASE + 0x00)
#define RSB_REG_CCR   (R_RSB_BASE + 0x04)
#define RSB_REG_INTE  (R_RSB_BASE + 0x08)
#define RSB_REG_STAT  (R_RSB_BASE + 0x0c)
#define RSB_REG_DADDR0  (R_RSB_BASE + 0x10)
#define RSB_REG_DADDR1  (R_RSB_BASE + 0x14)
//#define RSB_REG_DLEN  (R_RSB_BASE + 0x18)
#define RSB_REG_DATA0 (R_RSB_BASE + 0x1c)
#define RSB_REG_DATA1 (R_RSB_BASE + 0x20)
#define RSB_REG_LCR   (R_RSB_BASE + 0x24)
#define RSB_REG_PMCR  (R_RSB_BASE + 0x28)
#define RSB_REG_CMD   (R_RSB_BASE + 0x2c)//RSB Command Register
#define RSB_REG_SADDR (R_RSB_BASE + 0x30)//RSB Slave address Register

/* bit field */
#define RSB_SOFT_RST    (1U << 0)
#define RSB_GLB_INTEN   (1U << 1)
#define RSB_ABT_TRANS   (1U << 6)
#define RSB_START_TRANS   (1U << 7)
#define RSB_USE_RSB     (1U<<8)//Use RSB

#define RSB_TOVER_INT   (1U << 0)
#define RSB_TERR_INT    (1U << 1)
#define RSB_LBSY_INT    (1U << 2)
#define RSB_TRANS_ERR_ID  (0xFF<<8)
#define RSB_TRANS_ERR_ID1 (0xFF<<16)//8��b00000001 �C no ack

#define RSB_PMU_INIT    (1U << 31)

/* RSB SHIFT */
#define RSB_RTSADDR_SHIFT (16)//runtime slave address shift
#define RSB_SADDR_SHIFT   (0)//Slave Address shift


/* RSB command */
#define RSB_CMD_BYTE_WRITE    (0x4E)//(0x27)//Byte write
#define RSB_CMD_HWORD_WRITE   (0x59)//(0x2c)//Half word write
#define RSB_CMD_WORD_WRITE    (0x63)//(0x31)//Word write
#define RSB_CMD_BYTE_READ   (0x8B)//(0x45)//Byte read
#define RSB_CMD_HWORD_READ    (0x9C)//(0x4e)//Half word read
#define RSB_CMD_WORD_READ   (0xA6)//(0x53)//Word read
#define RSB_CMD_SET_RTSADDR   (0xE8)//(0x74)//Set Run-time Address

/* RSB Device Slave Address */
//#define RSB_SADDR_AW1655    RSB_SADDR1
//#define RSB_SADDR_AW1653    RSB_SADDR2
#define RSB_SADDR1        (0x3A3)//AXP222(AW1655)
#define RSB_SADDR2        (0x4E6)//(0x0273)
#define RSB_SADDR3        (0x745)//(0x03a2)
#define RSB_SADDR4        (0x9CC)//(0x04e6)
#define RSB_SADDR5        (0xA6F)//(0x537)
#define RSB_SADDR6        (0xD2A)//(0x0695)
#define RSB_SADDR7        (0xE89)//(0x0744)
#define RSB_SADDR8        (0x103B)//(0x081d)
#define RSB_SADDR9        (0x1398)//(0x09cc)
#define RSB_SADDR10       (0x14DD)//(0x0a6e)
#define RSB_SADDR11       (0x177E)//(0x0bbf)


//...

/*RSB run time address*/
//#define RSB_RTSADDR0  (0x00)
//#define RSB_RTSADDR1  (0x17)//(0x0B)
#define RSB_RTSADDR2  (0x2d)//(0x16)
#define RSB_RTSADDR3  (0x3a)//(0x1d)
#define RSB_RTSADDR4  (0x4E)//0x27
#define RSB_RTSADDR5  (0x59)//0x2c
#define RSB_RTSADDR6  (0x63)//0x31
#define RSB_RTSADDR7  (0x74)//0x3a
#define RSB_RTSADDR8  (0x8B)//0x45
#define RSB_RTSADDR9  (0x9C)//0x4e
#define RSB_RTSADDR10 (0xA6)//(0x53)
#define RSB_RTSADDR11 (0xB1)//(0x58)
#define RSB_RTSADDR12 (0xC5)//(0x62)
#define RSB_RTSADDR13 (0xD2)//(0x69)
#define RSB_RTSADDR14 (0xE8)//(0x74)
#define RSB_RTSADDR15 (0xFF)//(0x7f)


#define RSB_READ_FLAG (1<<4)
#define RSB_WRITE_FLAG  (0<<4)


#define PMU_INIT_DAT_SHIFT    (16)//Value of PMU��s initial data
#define PMU_MOD_REG_ADDR_SHIFT  (8)//PMU MODE Control Register Address

#define ERR_TRANS_1ST_BYTE    (0x1)//error happened with the transmission of the 1st byte of data
#define ERR_TRANS_2ND_BYTE    (0x2)//error happened with the transmission of the 2nd byte of data
#define ERR_TRANS_3RD_BYTE    (0x4)//error happened with the transmission of the 3rd byte of data
#define ERR_TRANS_4TH_BYTE    (0x8)// error happened with the transmission of the 4th byte of data
#define ERR_TRANS_RT_NO_ACK   (0x1<<8)//no ack when set runtime slave address.


struct rsb_info {
  volatile UINT32 rsb_flag;
  volatile UINT32 rsb_busy;
  volatile UINT32 rsb_load_busy;
};

struct rsb_slave_set{
  UINT8 *m_slave_name;
  UINT32 m_slave_addr;
  UINT32 m_rtaddr;
};


//struct rsb_ad {
//  UINT32 addr;
//  UINT32 data;
//};

#define  RSB_SADDR_AXP22X           (0x3A3)
#define  RSB_SADDR_AXP809           (0x3A3)
#define  RSB_SADDR_AXP806           (0x745)
#define  RSB_SADDR_AXP808           (0x745)
#define  RSB_SADDR_AXP81X           (0x3A3)
#define  RSB_SADDR_AXP238           (0x3A3)
#define  RSB_SADDR_AC100              (0xE89) 

/* RSB run time address */
#define RSB_RTSADDR_AXP809  (0x2d)
#define RSB_RTSADDR_AXP806  (0x3a)
#define RSB_RTSADDR_AXP808  (0x2d)
#define RSB_RTSADDR_AXP81X  (0x11)
#define RSB_RTSADDR_AC100   (0x4e)

extern UINT32 SunxiRsbInit(VOID);
extern UINT32 SunxiRsbConfig(UINT32 saddr, UINT32 rtsaddr);
extern UINT32 SunxiRsbRead(UINT32 rtsaddr,UINT32 daddr, UINT8 *data, UINT32 len);
extern UINT32 SunxiRsbWrite(UINT32 rtsaddr,UINT32 daddr, UINT8 *data, UINT32 len);




#endif