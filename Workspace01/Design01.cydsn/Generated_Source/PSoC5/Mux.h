/*******************************************************************************
* File Name: Mux.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the AMuxSeq.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUXSEQ_Mux_H)
#define CY_AMUXSEQ_Mux_H

#include "cyfitter.h"
#include "cyfitter_cfg.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
         (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
         (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))    
    #include "cytypes.h"
#else
    #include "syslib/cy_syslib.h"
#endif /* ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define Mux_MUX_SINGLE 1
#define Mux_MUX_DIFF   2
#define Mux_MUXTYPE    1


/***************************************
*        Function Prototypes
***************************************/

void Mux_Start(void);
void Mux_Init(void);
void Mux_Stop(void);
#if (Mux_MUXTYPE == Mux_MUX_DIFF)
void Mux_Next(void);
void Mux_DisconnectAll(void);
#else
/* The Next and DisconnectAll functions are declared in cyfitter_cfg.h. */
/* void Mux_Next(void); */
/* void Mux_DisconnectAll(void); */
#endif
int8 Mux_GetChannel(void);


/***************************************
*           Global Variables
***************************************/

extern uint8 Mux_initVar;


/***************************************
*         Parameter Constants
***************************************/
#define Mux_CHANNELS 4


#endif /* CY_AMUXSEQ_Mux_H */


/* [] END OF FILE */
