/***************************************************************************//**
* \file ADC_DMA.h
* \version 2.0
*
*  This file provides constants, parameter values and API definition for the
*  ADC_DMA Component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(ADC_DMA_CH_H)
#define ADC_DMA_CH_H

#include "cy_device_headers.h"
#include "cyfitter.h"
#include "dma/cy_dma.h"
#include "trigmux/cy_trigmux.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define ADC_DMA_DW_BLOCK       (0u)
#define ADC_DMA_DW_CHANNEL     (1u)
#define ADC_DMA_HW             (DW0)
#define ADC_DMA_INTR_MASK      (CY_DMA_INTR_MASK)

/* Channel settings */
#define ADC_DMA_PRIORITY       (0u)
#define ADC_DMA_DESCRIPTOR_NUM (1u)
#define ADC_DMA_PREEMPTABLE    (true)
#define ADC_DMA_BUFFERABLE     (true)

/***************************************
*        Function Prototypes
***************************************/

                void ADC_DMA_Start(void const * srcAddress, void const * dstAddress);
__STATIC_INLINE void ADC_DMA_Stop(void);
                void ADC_DMA_Init(void);
__STATIC_INLINE void ADC_DMA_ChannelEnable(void);
__STATIC_INLINE void ADC_DMA_ChannelDisable(void);

__STATIC_INLINE void ADC_DMA_SetDescriptor       (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE void ADC_DMA_SetNextDescriptor   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE void ADC_DMA_SetPriority         (uint32_t priority);
__STATIC_INLINE void ADC_DMA_SetSrcAddress       (cy_stc_dma_descriptor_t * descriptor, void const * srcAddress);
__STATIC_INLINE void ADC_DMA_SetDstAddress       (cy_stc_dma_descriptor_t * descriptor, void const * dstAddress);
__STATIC_INLINE void ADC_DMA_SetXloopDataCount   (cy_stc_dma_descriptor_t * descriptor, uint32_t xCount);
__STATIC_INLINE void ADC_DMA_SetYloopDataCount   (cy_stc_dma_descriptor_t * descriptor, uint32_t yCount);
__STATIC_INLINE void ADC_DMA_SetXloopSrcIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t srcXincrement);
__STATIC_INLINE void ADC_DMA_SetXloopDstIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t dstXincrement);
__STATIC_INLINE void ADC_DMA_SetYloopSrcIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t srcYincrement);
__STATIC_INLINE void ADC_DMA_SetYloopDstIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t dstYincrement);
__STATIC_INLINE void ADC_DMA_SetInterruptType    (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t interruptType);
__STATIC_INLINE void ADC_DMA_SetTriggerInType    (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t triggerInType);
__STATIC_INLINE void ADC_DMA_SetTriggerOutType   (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t triggerOutType);
__STATIC_INLINE void ADC_DMA_SetDataSize         (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_data_size_t dataSize);
__STATIC_INLINE void ADC_DMA_SetSrcTransferSize  (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_transfer_size_t srcTransferSize);
__STATIC_INLINE void ADC_DMA_SetDstTransferSize  (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_transfer_size_t dstTransferSize);
__STATIC_INLINE void ADC_DMA_SetRetrigger        (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_retrigger_t retrigger);
__STATIC_INLINE void ADC_DMA_SetDescriptorType   (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_descriptor_type_t descriptorType);
__STATIC_INLINE void ADC_DMA_SetChannelState     (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_channel_state_t channelState);

__STATIC_INLINE cy_stc_dma_descriptor_t *   ADC_DMA_GetDescriptor(void);
__STATIC_INLINE cy_stc_dma_descriptor_t *   ADC_DMA_GetNextDescriptor(void);
__STATIC_INLINE uint32_t                    ADC_DMA_GetPriority(void);
__STATIC_INLINE cy_en_dma_intr_cause_t      ADC_DMA_GetStatus(void);
__STATIC_INLINE cy_en_trigmux_status_t      ADC_DMA_Trigger(uint32_t cycles);
__STATIC_INLINE void *                      ADC_DMA_GetSrcAddress       (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE void *                      ADC_DMA_GetDstAddress       (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE uint32_t                    ADC_DMA_GetXloopDataCount   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE uint32_t                    ADC_DMA_GetYloopDataCount   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE int32_t                     ADC_DMA_GetXloopSrcIncrement(cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE int32_t                     ADC_DMA_GetXloopDstIncrement(cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE int32_t                     ADC_DMA_GetYloopSrcIncrement(cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE int32_t                     ADC_DMA_GetYloopDstIncrement(cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_trigger_type_t    ADC_DMA_GetInterruptType    (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_trigger_type_t    ADC_DMA_GetTriggerInType    (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_trigger_type_t    ADC_DMA_GetTriggerOutType   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_data_size_t       ADC_DMA_GetDataSize         (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_transfer_size_t   ADC_DMA_GetSrcTransferSize  (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_transfer_size_t   ADC_DMA_GetDstTransferSize  (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_retrigger_t       ADC_DMA_GetRetrigger        (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_descriptor_type_t ADC_DMA_GetDescriptorType   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_channel_state_t   ADC_DMA_GetChannelState     (cy_stc_dma_descriptor_t const * descriptor);

__STATIC_INLINE uint32_t ADC_DMA_GetInterruptStatus(void);
__STATIC_INLINE void     ADC_DMA_ClearInterrupt(void);
__STATIC_INLINE void     ADC_DMA_SetInterrupt(void);
__STATIC_INLINE uint32_t ADC_DMA_GetInterruptMask(void);
__STATIC_INLINE void     ADC_DMA_SetInterruptMask(uint32_t interrupt);
__STATIC_INLINE uint32_t ADC_DMA_GetInterruptStatusMasked(void);


/***************************************
*    Global Variables
***************************************/
extern uint8_t ADC_DMA_initVar;

extern const cy_stc_dma_descriptor_config_t ADC_DMA_adcDmaDescriptor_config;
extern cy_stc_dma_descriptor_t ADC_DMA_adcDmaDescriptor;



/***************************************
*    In-line Function Implementation
***************************************/

/*******************************************************************************
* Function Name: ADC_DMA_Stop
****************************************************************************//**
* Invokes the Cy_DMA_Channel_Disable() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_Stop(void)
{
    Cy_DMA_Channel_Disable(ADC_DMA_HW, ADC_DMA_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADC_DMA_ChannelEnable
****************************************************************************//**
* Invokes the Cy_DMA_Channel_Enable() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_ChannelEnable(void)
{
    Cy_DMA_Channel_Enable(ADC_DMA_HW, ADC_DMA_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADC_DMA_ChannelDisable
****************************************************************************//**
* Invokes the Cy_DMA_Channel_Disable() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_ChannelDisable(void)
{
    Cy_DMA_Channel_Disable(ADC_DMA_HW, ADC_DMA_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADC_DMA_SetDescriptor
****************************************************************************//**
* Invokes the Cy_DMA_Channel_SetDescriptor() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetDescriptor(cy_stc_dma_descriptor_t const * descriptor)
{
    Cy_DMA_Channel_SetDescriptor(ADC_DMA_HW, ADC_DMA_DW_CHANNEL, descriptor);
}


/*******************************************************************************
* Function Name: ADC_DMA_GetDescriptor
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetCurrentDescriptor() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_stc_dma_descriptor_t * ADC_DMA_GetDescriptor(void)
{
    return(Cy_DMA_Channel_GetCurrentDescriptor(ADC_DMA_HW, ADC_DMA_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADC_DMA_SetNextDescriptor
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetNextDescriptor() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetNextDescriptor(cy_stc_dma_descriptor_t const * descriptor)
{
    Cy_DMA_Descriptor_SetNextDescriptor(Cy_DMA_Channel_GetCurrentDescriptor(ADC_DMA_HW, ADC_DMA_DW_CHANNEL), descriptor);
}


/*******************************************************************************
* Function Name: ADC_DMA_GetNextDescriptor
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetNextDescriptor() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE cy_stc_dma_descriptor_t * ADC_DMA_GetNextDescriptor(void)
{
    return(Cy_DMA_Descriptor_GetNextDescriptor(Cy_DMA_Channel_GetCurrentDescriptor(ADC_DMA_HW, ADC_DMA_DW_CHANNEL)));
}


/*******************************************************************************
* Function Name: ADC_DMA_SetPriority
****************************************************************************//**
* Invokes the Cy_DMA_Channel_SetPriority() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetPriority(uint32_t priority)
{
    Cy_DMA_Channel_SetPriority(ADC_DMA_HW, ADC_DMA_DW_CHANNEL, priority);
}


/*******************************************************************************
* Function Name: ADC_DMA_GetPriority
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetPriority() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE uint32_t ADC_DMA_GetPriority(void)
{
    return (Cy_DMA_Channel_GetPriority(ADC_DMA_HW, ADC_DMA_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADC_DMA_SetSrcAddress
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetSrcAddress() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetSrcAddress(cy_stc_dma_descriptor_t * descriptor, void const * srcAddress)
{
    Cy_DMA_Descriptor_SetSrcAddress(descriptor, srcAddress);
}


/*******************************************************************************
* Function Name: ADC_DMA_GetSrcAddress
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetSrcAddress() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void * ADC_DMA_GetSrcAddress(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetSrcAddress(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_SetDstAddress
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetDstAddress() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetDstAddress(cy_stc_dma_descriptor_t * descriptor, void const * dstAddress)
{
    Cy_DMA_Descriptor_SetDstAddress(descriptor, dstAddress);
}


/*******************************************************************************
* Function Name: ADC_DMA_GetDstAddress
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetDestAddr() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void * ADC_DMA_GetDstAddress(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetDstAddress(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_SetDataSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetDataSize() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetDataSize(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_data_size_t dataSize)
{
    Cy_DMA_Descriptor_SetDataSize(descriptor, dataSize);
}


/*******************************************************************************
* Function Name: ADC_DMA_GetDataSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetDataSize() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE cy_en_dma_data_size_t ADC_DMA_GetDataSize(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetDataSize(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_SetSrcTransferSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetSrcTransferSize() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetSrcTransferSize(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_transfer_size_t srcTransferSize)
{
    Cy_DMA_Descriptor_SetSrcTransferSize(descriptor, srcTransferSize);
}


/*******************************************************************************
* Function Name: ADC_DMA_GetSrcTransferSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetSrcTransferSize() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE cy_en_dma_transfer_size_t ADC_DMA_GetSrcTransferSize(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetSrcTransferSize(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_SetDstTransferSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetDstTransferSize() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetDstTransferSize(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_transfer_size_t dstTransferSize)
{
    Cy_DMA_Descriptor_SetDstTransferSize(descriptor, dstTransferSize);
}


/*******************************************************************************
* Function Name: ADC_DMA_SetRetrigger
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetRetrigger() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetRetrigger(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_retrigger_t retrigger)
{
    Cy_DMA_Descriptor_SetRetrigger(descriptor, retrigger);
}


/*******************************************************************************
* Function Name: ADC_DMA_SetDescriptorType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetDescriptorType() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetDescriptorType(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_descriptor_type_t descriptorType)
{
    Cy_DMA_Descriptor_SetDescriptorType(descriptor, descriptorType);
}


/*******************************************************************************
* Function Name: ADC_DMA_SetChannelState
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetChannelState() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetChannelState(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_channel_state_t channelState)
{
    Cy_DMA_Descriptor_SetChannelState(descriptor, channelState);
}


/*******************************************************************************
* Function Name: ADC_DMA_GetDstTransferSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetDstTransferSize() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE cy_en_dma_transfer_size_t ADC_DMA_GetDstTransferSize(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetDstTransferSize(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_GetRetrigger
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetRetrigger() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE cy_en_dma_retrigger_t ADC_DMA_GetRetrigger(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetRetrigger(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_GetDescriptorType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetDescriptorType() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE cy_en_dma_descriptor_type_t ADC_DMA_GetDescriptorType(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetDescriptorType(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_GetChannelState
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetChannelState() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE cy_en_dma_channel_state_t ADC_DMA_GetChannelState(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetChannelState(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_SetXloopDataCount
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetXloopDataCount() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetXloopDataCount(cy_stc_dma_descriptor_t * descriptor, uint32_t xCount)
{
    Cy_DMA_Descriptor_SetXloopDataCount(descriptor, xCount);
}


/*******************************************************************************
* Function Name: ADC_DMA_GetXloopDataCount
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetXloopDataCount() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE uint32_t ADC_DMA_GetXloopDataCount(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetXloopDataCount(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_SetXloopSrcIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetXloopSrcIncrement() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetXloopSrcIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t srcXincrement)
{
    Cy_DMA_Descriptor_SetXloopSrcIncrement(descriptor, srcXincrement);
}


/*******************************************************************************
* Function Name: ADC_DMA_GetXloopSrcIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetXloopSrcIncrement() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE int32_t ADC_DMA_GetXloopSrcIncrement(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetXloopSrcIncrement(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_SetXloopDstIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetXloopDstIncrement() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetXloopDstIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t dstXincrement)
{
    Cy_DMA_Descriptor_SetXloopDstIncrement(descriptor, dstXincrement);
}


/*******************************************************************************
* Function Name: ADC_DMA_GetXloopDstIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetXloopDstIncrement() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE int32_t ADC_DMA_GetXloopDstIncrement(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetXloopDstIncrement(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_SetYloopDataCount
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetYloopDataCount() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetYloopDataCount(cy_stc_dma_descriptor_t * descriptor, uint32_t yCount)
{
    Cy_DMA_Descriptor_SetYloopDataCount(descriptor, yCount);
}


/*******************************************************************************
* Function Name: ADC_DMA_GetYloopDataCount
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetYloopDataCount() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE uint32_t ADC_DMA_GetYloopDataCount(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetYloopDataCount(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_SetYloopSrcIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetYloopSrcIncrement() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetYloopSrcIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t srcYincrement)
{
    Cy_DMA_Descriptor_SetYloopSrcIncrement(descriptor, srcYincrement);
}


/*******************************************************************************
* Function Name: ADC_DMA_GetYloopSrcIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetYloopSrcIncrement() PDL driver function.
*******************************************************************************/
__STATIC_INLINE int32_t ADC_DMA_GetYloopSrcIncrement(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetYloopSrcIncrement(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_SetYloopDstIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetYloopDstIncrement() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetYloopDstIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t dstYincrement)
{
    Cy_DMA_Descriptor_SetYloopDstIncrement(descriptor, dstYincrement);
}


/*******************************************************************************
* Function Name: ADC_DMA_SetInterruptType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetInterruptType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetInterruptType(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t interruptType)
{
    Cy_DMA_Descriptor_SetInterruptType(descriptor, interruptType);
}


/*******************************************************************************
* Function Name: ADC_DMA_SetTriggerInType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetTriggerInType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetTriggerInType(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t triggerInType)
{
    Cy_DMA_Descriptor_SetTriggerInType(descriptor, triggerInType);
}


/*******************************************************************************
* Function Name: ADC_DMA_SetTriggerOutType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetTriggerOutType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetTriggerOutType(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t triggerOutType)
{
    Cy_DMA_Descriptor_SetTriggerOutType(descriptor, triggerOutType);
}


/*******************************************************************************
* Function Name: ADC_DMA_GetYloopDstIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetYloopDstIncrement() PDL driver function.
*******************************************************************************/
__STATIC_INLINE int32_t ADC_DMA_GetYloopDstIncrement(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetYloopDstIncrement(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_GetInterruptType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetInterruptType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_en_dma_trigger_type_t ADC_DMA_GetInterruptType(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetInterruptType(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_GetTriggerInType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetTriggerInType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_en_dma_trigger_type_t ADC_DMA_GetTriggerInType(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetTriggerInType(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_GetTriggerOutType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetTriggerOutType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_en_dma_trigger_type_t ADC_DMA_GetTriggerOutType(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetTriggerOutType(descriptor));
}


/*******************************************************************************
* Function Name: ADC_DMA_GetInterruptStatus()
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetInterruptStatus() PDL driver function.
*******************************************************************************/
__STATIC_INLINE uint32_t ADC_DMA_GetInterruptStatus(void)
{
    return (Cy_DMA_Channel_GetInterruptStatus(ADC_DMA_HW, ADC_DMA_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADC_DMA_GetStatus
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetStatus() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_en_dma_intr_cause_t ADC_DMA_GetStatus(void)
{
    return (Cy_DMA_Channel_GetStatus(ADC_DMA_HW, ADC_DMA_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADC_DMA_ClearInterrupt
****************************************************************************//**
* Invokes the Cy_DMA_Channel_ClearInterrupt() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_ClearInterrupt(void)
{
    Cy_DMA_Channel_ClearInterrupt(ADC_DMA_HW, ADC_DMA_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADC_DMA_SetInterrupt
****************************************************************************//**
* Invokes the Cy_DMA_Channel_SetInterrupt() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetInterrupt(void)
{
    Cy_DMA_Channel_SetInterrupt(ADC_DMA_HW, ADC_DMA_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADC_DMA_GetInterruptMask
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetInterruptMask() PDL driver function.
*******************************************************************************/
__STATIC_INLINE uint32_t ADC_DMA_GetInterruptMask(void)
{
    return (Cy_DMA_Channel_GetInterruptMask(ADC_DMA_HW, ADC_DMA_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADC_DMA_SetInterruptMask
****************************************************************************//**
* Invokes the Cy_DMA_Channel_SetInterruptMask() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetInterruptMask(uint32_t interrupt)
{
    Cy_DMA_Channel_SetInterruptMask(ADC_DMA_HW, ADC_DMA_DW_CHANNEL, interrupt);
}


/*******************************************************************************
* Function Name: ADC_DMA_GetInterruptStatusMasked
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetInterruptStatusMasked() PDL driver function.
*******************************************************************************/
__STATIC_INLINE uint32_t ADC_DMA_GetInterruptStatusMasked(void)
{
    return (Cy_DMA_Channel_GetInterruptStatusMasked(ADC_DMA_HW, ADC_DMA_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADC_DMA_Trigger
****************************************************************************//**
*
* Invokes the Cy_TrigMux_SwTrigger() PDL driver function.
*
* \param cycles
*  The number of "Clk_Peri" cycles during which the trigger remains activated.
*  The valid range of cycles is 1 ... 254.
*  Also there are special values:
*  CY_TRIGGER_INFINITE - trigger remains activated untill user deactivates it by
*  calling this function with CY_TRIGGER_DEACTIVATE parameter.
*  CY_TRIGGER_DEACTIVATE - it is used to deactivate the trigger activated by
*  calling this function with CY_TRIGGER_INFINITE parameter.
*  Note: the DMA is clocked by "Clk_Slow" which can be slower than "Clk_Peri".
* 
* \return A status:
* - CY_TRIGMUX_SUCCESS: The trigger is succesfully activated/deactivated.
* - CY_TRIGMUX_INVALID_STATE: The trigger is already activated/not active.
*
*******************************************************************************/
__STATIC_INLINE cy_en_trigmux_status_t ADC_DMA_Trigger(uint32_t cycles)
{
    return (Cy_TrigMux_SwTrigger((uint32_t)ADC_DMA_DW__TR_IN, cycles));
}


#if(CY_DMA_BWC)
/* Definitions to support backward compatibility with the component version 1.0, 
*  they are strongly not recommended to use in new designs */

#define ADC_DMA_ChEnable                (ADC_DMA_ChannelEnable)
#define ADC_DMA_ChDisable               (ADC_DMA_ChannelDisable)
#define ADC_DMA_SetDataElementSize      (ADC_DMA_SetDataSize)
#define ADC_DMA_GetDataElementSize      (ADC_DMA_GetDataSize)
#define ADC_DMA_SetXloopNumDataElements (ADC_DMA_SetXloopDataCount)
#define ADC_DMA_GetXloopNumDataElements (ADC_DMA_GetXloopDataCount)
#define ADC_DMA_SetYloopNumDataElements (ADC_DMA_SetYloopDataCount)
#define ADC_DMA_GetYloopNumDataElements (ADC_DMA_GetYloopDataCount)
#define ADC_DMA_SetInterruptMask()      (ADC_DMA_SetInterruptMask(ADC_DMA_INTR_MASK))
#define ADC_DMA_GetInterruptCause       (ADC_DMA_GetStatus)

#define ADC_DMA_PREEMTAMBLE             (ADC_DMA_PREEMPTABLE)
/*******************************************************************************
* Function Name: ADC_DMA_SetSrcDstTransferWidth
****************************************************************************//**
* This is a legacy API function, it is left here just for backward compatibility
*******************************************************************************/
__STATIC_INLINE void ADC_DMA_SetSrcDstTransferWidth(cy_stc_dma_descriptor_t * descriptor, uint32_t options)
{
    uint32_t ctlRegVal = descriptor->ctl & ((uint32_t)~(DW_DESCR_STRUCT_DESCR_CTL_SRC_TRANSFER_SIZE_Msk | \
            DW_DESCR_STRUCT_DESCR_CTL_DST_TRANSFER_SIZE_Msk));
    
    descriptor->ctl = ctlRegVal |
        ((options << DW_DESCR_STRUCT_DESCR_CTL_SRC_TRANSFER_SIZE_Pos) &
        (DW_DESCR_STRUCT_DESCR_CTL_SRC_TRANSFER_SIZE_Msk | DW_DESCR_STRUCT_DESCR_CTL_DST_TRANSFER_SIZE_Msk));
}


/*******************************************************************************
* Function Name: DMA_1_GetSrcDstTransferWidth
****************************************************************************//**
* This is a legacy API function, it is left here just for backward compatibility
*******************************************************************************/
__STATIC_INLINE uint32_t ADC_DMA_GetSrcDstTransferWidth(cy_stc_dma_descriptor_t const * descriptor)
{
    uint32_t ctlRegVal = descriptor->ctl & (DW_DESCR_STRUCT_DESCR_CTL_SRC_TRANSFER_SIZE_Msk |
        DW_DESCR_STRUCT_DESCR_CTL_DST_TRANSFER_SIZE_Msk);
    
    return(ctlRegVal >> DW_DESCR_STRUCT_DESCR_CTL_SRC_TRANSFER_SIZE_Pos);
}

#endif /* CY_DMA_BWC */


#if defined(__cplusplus)
}
#endif

#endif/* (ADC_DMA_CH_H) */

/* [] END OF FILE */
