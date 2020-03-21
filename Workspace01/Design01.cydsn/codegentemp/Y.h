/*******************************************************************************
* File Name: Y.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Y_H) /* Pins Y_H */
#define CY_PINS_Y_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Y_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Y__PORT == 15 && ((Y__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Y_Write(uint8 value);
void    Y_SetDriveMode(uint8 mode);
uint8   Y_ReadDataReg(void);
uint8   Y_Read(void);
void    Y_SetInterruptMode(uint16 position, uint16 mode);
uint8   Y_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Y_SetDriveMode() function.
     *  @{
     */
        #define Y_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Y_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Y_DM_RES_UP          PIN_DM_RES_UP
        #define Y_DM_RES_DWN         PIN_DM_RES_DWN
        #define Y_DM_OD_LO           PIN_DM_OD_LO
        #define Y_DM_OD_HI           PIN_DM_OD_HI
        #define Y_DM_STRONG          PIN_DM_STRONG
        #define Y_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Y_MASK               Y__MASK
#define Y_SHIFT              Y__SHIFT
#define Y_WIDTH              1u

/* Interrupt constants */
#if defined(Y__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Y_SetInterruptMode() function.
     *  @{
     */
        #define Y_INTR_NONE      (uint16)(0x0000u)
        #define Y_INTR_RISING    (uint16)(0x0001u)
        #define Y_INTR_FALLING   (uint16)(0x0002u)
        #define Y_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Y_INTR_MASK      (0x01u) 
#endif /* (Y__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Y_PS                     (* (reg8 *) Y__PS)
/* Data Register */
#define Y_DR                     (* (reg8 *) Y__DR)
/* Port Number */
#define Y_PRT_NUM                (* (reg8 *) Y__PRT) 
/* Connect to Analog Globals */                                                  
#define Y_AG                     (* (reg8 *) Y__AG)                       
/* Analog MUX bux enable */
#define Y_AMUX                   (* (reg8 *) Y__AMUX) 
/* Bidirectional Enable */                                                        
#define Y_BIE                    (* (reg8 *) Y__BIE)
/* Bit-mask for Aliased Register Access */
#define Y_BIT_MASK               (* (reg8 *) Y__BIT_MASK)
/* Bypass Enable */
#define Y_BYP                    (* (reg8 *) Y__BYP)
/* Port wide control signals */                                                   
#define Y_CTL                    (* (reg8 *) Y__CTL)
/* Drive Modes */
#define Y_DM0                    (* (reg8 *) Y__DM0) 
#define Y_DM1                    (* (reg8 *) Y__DM1)
#define Y_DM2                    (* (reg8 *) Y__DM2) 
/* Input Buffer Disable Override */
#define Y_INP_DIS                (* (reg8 *) Y__INP_DIS)
/* LCD Common or Segment Drive */
#define Y_LCD_COM_SEG            (* (reg8 *) Y__LCD_COM_SEG)
/* Enable Segment LCD */
#define Y_LCD_EN                 (* (reg8 *) Y__LCD_EN)
/* Slew Rate Control */
#define Y_SLW                    (* (reg8 *) Y__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Y_PRTDSI__CAPS_SEL       (* (reg8 *) Y__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Y_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Y__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Y_PRTDSI__OE_SEL0        (* (reg8 *) Y__PRTDSI__OE_SEL0) 
#define Y_PRTDSI__OE_SEL1        (* (reg8 *) Y__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Y_PRTDSI__OUT_SEL0       (* (reg8 *) Y__PRTDSI__OUT_SEL0) 
#define Y_PRTDSI__OUT_SEL1       (* (reg8 *) Y__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Y_PRTDSI__SYNC_OUT       (* (reg8 *) Y__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Y__SIO_CFG)
    #define Y_SIO_HYST_EN        (* (reg8 *) Y__SIO_HYST_EN)
    #define Y_SIO_REG_HIFREQ     (* (reg8 *) Y__SIO_REG_HIFREQ)
    #define Y_SIO_CFG            (* (reg8 *) Y__SIO_CFG)
    #define Y_SIO_DIFF           (* (reg8 *) Y__SIO_DIFF)
#endif /* (Y__SIO_CFG) */

/* Interrupt Registers */
#if defined(Y__INTSTAT)
    #define Y_INTSTAT            (* (reg8 *) Y__INTSTAT)
    #define Y_SNAP               (* (reg8 *) Y__SNAP)
    
	#define Y_0_INTTYPE_REG 		(* (reg8 *) Y__0__INTTYPE)
#endif /* (Y__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Y_H */


/* [] END OF FILE */
