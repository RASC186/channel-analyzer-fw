/***************************************************************************//**
* \file ADC_DMA.c
* \version 2.0
*
*  This file provides the source code to the API for the
*  ADC_DMA component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_DMA.h"

#if defined(__cplusplus)
extern "C" {
#endif

/* Generated code */
const cy_stc_dma_descriptor_config_t ADC_DMA_adcDmaDescriptor_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_1ELEMENT,
    .triggerOutType  = CY_DMA_1ELEMENT,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_WORD,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType  = CY_DMA_SINGLE_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 0L,
    .dstXincrement   = 0L,
    .xCount          = 1UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 0L,
    .yCount          = 1UL,
    .nextDescriptor  = &ADC_DMA_adcDmaDescriptor
};

cy_stc_dma_descriptor_t ADC_DMA_adcDmaDescriptor =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};


/** ADC_DMA_initVar indicates whether the ADC_DMA 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time ADC_DMA_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the ADC_DMA_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  ADC_DMA_Init() function can be called before the 
*  ADC_DMA_Start() or ADC_DMA_ChEnable() function.
*/
uint8 ADC_DMA_initVar = 0u;


/*******************************************************************************
* Function Name: ADC_DMA_Start
****************************************************************************//**
*
* Based on the settings for descriptor in the customizer this function runs the
* DMA_Descriptor_Init() and then initializes the channel using
* DMA_Chnl_Init(). Enables the ADC_DMA block using the DMA_Chnl_Enable().
*  
*******************************************************************************/
void ADC_DMA_Start(void const * srcAddress, void const * dstAddress)
{
    if (0U == ADC_DMA_initVar)
    {
        ADC_DMA_Init();
        ADC_DMA_initVar = 1u;
    }
    
    Cy_DMA_Descriptor_SetSrcAddress(&ADC_DMA_adcDmaDescriptor, srcAddress);
    Cy_DMA_Descriptor_SetDstAddress(&ADC_DMA_adcDmaDescriptor, dstAddress);
    Cy_DMA_Channel_Enable(ADC_DMA_HW, ADC_DMA_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADC_DMA_Init
****************************************************************************//**
*
* Based on the settings for the descriptor in the customizer this function runs the
* DMA_Descriptor_Init() and then initializes the channel using
* DMA_Chnl_Init().
*  
*******************************************************************************/
void ADC_DMA_Init(void)
{
    cy_stc_dma_channel_config_t channelConfig;

    /* Init all descriptors */
    (void)Cy_DMA_Descriptor_Init(&ADC_DMA_adcDmaDescriptor, &ADC_DMA_adcDmaDescriptor_config);


    channelConfig.descriptor  = &ADC_DMA_adcDmaDescriptor;
    channelConfig.preemptable = ADC_DMA_PREEMPTABLE;
    channelConfig.priority    = ADC_DMA_PRIORITY;
    channelConfig.enable      = false;
    channelConfig.bufferable  = ADC_DMA_BUFFERABLE;

    (void)Cy_DMA_Channel_Init(ADC_DMA_HW, ADC_DMA_DW_CHANNEL, &channelConfig);

    Cy_DMA_Enable(ADC_DMA_HW);
}


#if defined(__cplusplus)
}
#endif

/* [] END OF FILE */
