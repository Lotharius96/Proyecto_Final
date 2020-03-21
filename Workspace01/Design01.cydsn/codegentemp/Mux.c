/*******************************************************************************
* File Name: Mux.c
* Version 1.80
*
*  Description:
*    This file contains functions for the AMuxSeq.
*
*   Note:
*
*******************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "Mux.h"

uint8 Mux_initVar = 0u;


/*******************************************************************************
* Function Name: Mux_Start
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Mux_Start(void)
{
    Mux_DisconnectAll();
    Mux_initVar = 1u;
}


/*******************************************************************************
* Function Name: Mux_Init
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Mux_Init(void)
{
    Mux_DisconnectAll();
}


/*******************************************************************************
* Function Name: Mux_Stop
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Mux_Stop(void)
{
    Mux_DisconnectAll();
}

#if (Mux_MUXTYPE == Mux_MUX_DIFF)

/*******************************************************************************
* Function Name: Mux_Next
********************************************************************************
* Summary:
*  Disconnects the previous channel and connects the next one in the sequence.
*  When Next is called for the first time after Init, Start, Enable, Stop, or
*  DisconnectAll, it connects channel 0.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Mux_Next(void)
{
    Mux_CYAMUXSIDE_A_Next();
    Mux_CYAMUXSIDE_B_Next();
}


/*******************************************************************************
* Function Name: Mux_DisconnectAll
********************************************************************************
* Summary:
*  This function disconnects all channels. The next time Next is called, channel
*  0 will be connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Mux_DisconnectAll(void)
{
    Mux_CYAMUXSIDE_A_DisconnectAll();
    Mux_CYAMUXSIDE_B_DisconnectAll();
}


/*******************************************************************************
* Function Name: Mux_GetChannel
********************************************************************************
* Summary:
*  The currently connected channel is retuned. If no channel is connected
*  returns -1.
*
* Parameters:
*  void
*
* Return:
*  The current channel or -1.
*
*******************************************************************************/
int8 Mux_GetChannel(void)
{
    return Mux_CYAMUXSIDE_A_curChannel;
}

#else

/*******************************************************************************
* Function Name: Mux_GetChannel
********************************************************************************
* Summary:
*  The currently connected channel is retuned. If no channel is connected
*  returns -1.
*
* Parameters:
*  void
*
* Return:
*  The current channel or -1.
*
*******************************************************************************/
int8 Mux_GetChannel(void)
{
    return Mux_curChannel;
}

#endif


/* [] END OF FILE */
