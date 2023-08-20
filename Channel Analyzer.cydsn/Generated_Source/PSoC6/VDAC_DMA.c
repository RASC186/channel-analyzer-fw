/***************************************************************************//**
* \file VDAC_DMA.c
* \version 2.0
*
*  This file provides the source code to the API for the
*  VDAC_DMA component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "VDAC_DMA.h"

#if defined(__cplusplus)
extern "C" {
#endif

/* Generated code */
const cy_stc_dma_descriptor_config_t VDAC_DMA_vdacDmaDescriptor_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_1ELEMENT,
    .triggerOutType  = CY_DMA_1ELEMENT,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_WORD,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType  = CY_DMA_1D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 0L,
    .xCount          = 20UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 0L,
    .yCount          = 1UL,
    .nextDescriptor  = &VDAC_DMA_vdacDmaDescriptor
};

cy_stc_dma_descriptor_t VDAC_DMA_vdacDmaDescriptor =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};


/** VDAC_DMA_initVar indicates whether the VDAC_DMA 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time VDAC_DMA_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the VDAC_DMA_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  VDAC_DMA_Init() function can be called before the 
*  VDAC_DMA_Start() or VDAC_DMA_ChEnable() function.
*/
uint8 VDAC_DMA_initVar = 0u;


/*******************************************************************************
* Function Name: VDAC_DMA_Start
****************************************************************************//**
*
* Based on the settings for descriptor in the customizer this function runs the
* DMA_Descriptor_Init() and then initializes the channel using
* DMA_Chnl_Init(). Enables the VDAC_DMA block using the DMA_Chnl_Enable().
*  
*******************************************************************************/
void VDAC_DMA_Start(void const * srcAddress, void const * dstAddress)
{
    if (0U == VDAC_DMA_initVar)
    {
        VDAC_DMA_Init();
        VDAC_DMA_initVar = 1u;
    }
    
    Cy_DMA_Descriptor_SetSrcAddress(&VDAC_DMA_vdacDmaDescriptor, srcAddress);
    Cy_DMA_Descriptor_SetDstAddress(&VDAC_DMA_vdacDmaDescriptor, dstAddress);
    Cy_DMA_Channel_Enable(VDAC_DMA_HW, VDAC_DMA_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: VDAC_DMA_Init
****************************************************************************//**
*
* Based on the settings for the descriptor in the customizer this function runs the
* DMA_Descriptor_Init() and then initializes the channel using
* DMA_Chnl_Init().
*  
*******************************************************************************/
void VDAC_DMA_Init(void)
{
    cy_stc_dma_channel_config_t channelConfig;

    /* Init all descriptors */
    (void)Cy_DMA_Descriptor_Init(&VDAC_DMA_vdacDmaDescriptor, &VDAC_DMA_vdacDmaDescriptor_config);


    channelConfig.descriptor  = &VDAC_DMA_vdacDmaDescriptor;
    channelConfig.preemptable = VDAC_DMA_PREEMPTABLE;
    channelConfig.priority    = VDAC_DMA_PRIORITY;
    channelConfig.enable      = false;
    channelConfig.bufferable  = VDAC_DMA_BUFFERABLE;

    (void)Cy_DMA_Channel_Init(VDAC_DMA_HW, VDAC_DMA_DW_CHANNEL, &channelConfig);

    Cy_DMA_Enable(VDAC_DMA_HW);
}


#if defined(__cplusplus)
}
#endif

/* [] END OF FILE */
