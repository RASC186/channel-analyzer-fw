/***************************************************************************//**
* \file ANALYZER_UART.h
* \version 2.0
*
*  This file provides constants and parameter values for the UART component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(ANALYZER_UART_CY_SCB_UART_PDL_H)
#define ANALYZER_UART_CY_SCB_UART_PDL_H

#include "cyfitter.h"
#include "scb/cy_scb_uart.h"

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
*   Initial Parameter Constants
****************************************/

#define ANALYZER_UART_DIRECTION  (3U)
#define ANALYZER_UART_ENABLE_RTS (0U)
#define ANALYZER_UART_ENABLE_CTS (0U)

/* UART direction enum */
#define ANALYZER_UART_RX    (0x1U)
#define ANALYZER_UART_TX    (0x2U)

#define ANALYZER_UART_ENABLE_RX  (0UL != (ANALYZER_UART_DIRECTION & ANALYZER_UART_RX))
#define ANALYZER_UART_ENABLE_TX  (0UL != (ANALYZER_UART_DIRECTION & ANALYZER_UART_TX))


/***************************************
*        Function Prototypes
***************************************/
/**
* \addtogroup group_general
* @{
*/
/* Component specific functions. */
void ANALYZER_UART_Start(void);

/* Basic functions */
__STATIC_INLINE cy_en_scb_uart_status_t ANALYZER_UART_Init(cy_stc_scb_uart_config_t const *config);
__STATIC_INLINE void ANALYZER_UART_DeInit(void);
__STATIC_INLINE void ANALYZER_UART_Enable(void);
__STATIC_INLINE void ANALYZER_UART_Disable(void);

/* Register callback. */
__STATIC_INLINE void ANALYZER_UART_RegisterCallback(cy_cb_scb_uart_handle_events_t callback);

/* Configuration change. */
#if (ANALYZER_UART_ENABLE_CTS)
__STATIC_INLINE void ANALYZER_UART_EnableCts(void);
__STATIC_INLINE void ANALYZER_UART_DisableCts(void);
#endif /* (ANALYZER_UART_ENABLE_CTS) */

#if (ANALYZER_UART_ENABLE_RTS)
__STATIC_INLINE void     ANALYZER_UART_SetRtsFifoLevel(uint32_t level);
__STATIC_INLINE uint32_t ANALYZER_UART_GetRtsFifoLevel(void);
#endif /* (ANALYZER_UART_ENABLE_RTS) */

__STATIC_INLINE void ANALYZER_UART_EnableSkipStart(void);
__STATIC_INLINE void ANALYZER_UART_DisableSkipStart(void);

#if (ANALYZER_UART_ENABLE_RX)
/* Low level: Receive direction. */
__STATIC_INLINE uint32_t ANALYZER_UART_Get(void);
__STATIC_INLINE uint32_t ANALYZER_UART_GetArray(void *buffer, uint32_t size);
__STATIC_INLINE void     ANALYZER_UART_GetArrayBlocking(void *buffer, uint32_t size);
__STATIC_INLINE uint32_t ANALYZER_UART_GetRxFifoStatus(void);
__STATIC_INLINE void     ANALYZER_UART_ClearRxFifoStatus(uint32_t clearMask);
__STATIC_INLINE uint32_t ANALYZER_UART_GetNumInRxFifo(void);
__STATIC_INLINE void     ANALYZER_UART_ClearRxFifo(void);
#endif /* (ANALYZER_UART_ENABLE_RX) */

#if (ANALYZER_UART_ENABLE_TX)
/* Low level: Transmit direction. */
__STATIC_INLINE uint32_t ANALYZER_UART_Put(uint32_t data);
__STATIC_INLINE uint32_t ANALYZER_UART_PutArray(void *buffer, uint32_t size);
__STATIC_INLINE void     ANALYZER_UART_PutArrayBlocking(void *buffer, uint32_t size);
__STATIC_INLINE void     ANALYZER_UART_PutString(char_t const string[]);
__STATIC_INLINE void     ANALYZER_UART_SendBreakBlocking(uint32_t breakWidth);
__STATIC_INLINE uint32_t ANALYZER_UART_GetTxFifoStatus(void);
__STATIC_INLINE void     ANALYZER_UART_ClearTxFifoStatus(uint32_t clearMask);
__STATIC_INLINE uint32_t ANALYZER_UART_GetNumInTxFifo(void);
__STATIC_INLINE bool     ANALYZER_UART_IsTxComplete(void);
__STATIC_INLINE void     ANALYZER_UART_ClearTxFifo(void);
#endif /* (ANALYZER_UART_ENABLE_TX) */

#if (ANALYZER_UART_ENABLE_RX)
/* High level: Ring buffer functions. */
__STATIC_INLINE void     ANALYZER_UART_StartRingBuffer(void *buffer, uint32_t size);
__STATIC_INLINE void     ANALYZER_UART_StopRingBuffer(void);
__STATIC_INLINE void     ANALYZER_UART_ClearRingBuffer(void);
__STATIC_INLINE uint32_t ANALYZER_UART_GetNumInRingBuffer(void);

/* High level: Receive direction functions. */
__STATIC_INLINE cy_en_scb_uart_status_t ANALYZER_UART_Receive(void *buffer, uint32_t size);
__STATIC_INLINE void     ANALYZER_UART_AbortReceive(void);
__STATIC_INLINE uint32_t ANALYZER_UART_GetReceiveStatus(void);
__STATIC_INLINE uint32_t ANALYZER_UART_GetNumReceived(void);
#endif /* (ANALYZER_UART_ENABLE_RX) */

#if (ANALYZER_UART_ENABLE_TX)
/* High level: Transmit direction functions. */
__STATIC_INLINE cy_en_scb_uart_status_t ANALYZER_UART_Transmit(void *buffer, uint32_t size);
__STATIC_INLINE void     ANALYZER_UART_AbortTransmit(void);
__STATIC_INLINE uint32_t ANALYZER_UART_GetTransmitStatus(void);
__STATIC_INLINE uint32_t ANALYZER_UART_GetNumLeftToTransmit(void);
#endif /* (ANALYZER_UART_ENABLE_TX) */

/* Interrupt handler */
__STATIC_INLINE void ANALYZER_UART_Interrupt(void);
/** @} group_general */


/***************************************
*    Variables with External Linkage
***************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t ANALYZER_UART_initVar;
extern cy_stc_scb_uart_config_t const ANALYZER_UART_config;
extern cy_stc_scb_uart_context_t ANALYZER_UART_context;
/** @} group_globals */


/***************************************
*         Preprocessor Macros
***************************************/
/**
* \addtogroup group_macros
* @{
*/
/** The pointer to the base address of the hardware */
#define ANALYZER_UART_HW     ((CySCB_Type *) ANALYZER_UART_SCB__HW)
/** @} group_macros */


/***************************************
*    In-line Function Implementation
***************************************/

/*******************************************************************************
* Function Name: ANALYZER_UART_Init
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_uart_status_t ANALYZER_UART_Init(cy_stc_scb_uart_config_t const *config)
{
   return Cy_SCB_UART_Init(ANALYZER_UART_HW, config, &ANALYZER_UART_context);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_DeInit
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_DeInit(void)
{
    Cy_SCB_UART_DeInit(ANALYZER_UART_HW);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_Enable
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Enable() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_Enable(void)
{
    Cy_SCB_UART_Enable(ANALYZER_UART_HW);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_Disable
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Disable() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_Disable(void)
{
    Cy_SCB_UART_Disable(ANALYZER_UART_HW, &ANALYZER_UART_context);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_RegisterCallback
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_RegisterCallback() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_RegisterCallback(cy_cb_scb_uart_handle_events_t callback)
{
    Cy_SCB_UART_RegisterCallback(ANALYZER_UART_HW, callback, &ANALYZER_UART_context);
}


#if (ANALYZER_UART_ENABLE_CTS)
/*******************************************************************************
* Function Name: ANALYZER_UART_EnableCts
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_EnableCts() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_EnableCts(void)
{
    Cy_SCB_UART_EnableCts(ANALYZER_UART_HW);
}


/*******************************************************************************
* Function Name: Cy_SCB_UART_DisableCts
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_DisableCts() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_DisableCts(void)
{
    Cy_SCB_UART_DisableCts(ANALYZER_UART_HW);
}
#endif /* (ANALYZER_UART_ENABLE_CTS) */


#if (ANALYZER_UART_ENABLE_RTS)
/*******************************************************************************
* Function Name: ANALYZER_UART_SetRtsFifoLevel
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_SetRtsFifoLevel() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_SetRtsFifoLevel(uint32_t level)
{
    Cy_SCB_UART_SetRtsFifoLevel(ANALYZER_UART_HW, level);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_GetRtsFifoLevel
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetRtsFifoLevel() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ANALYZER_UART_GetRtsFifoLevel(void)
{
    return Cy_SCB_UART_GetRtsFifoLevel(ANALYZER_UART_HW);
}
#endif /* (ANALYZER_UART_ENABLE_RTS) */


/*******************************************************************************
* Function Name: ANALYZER_UART_EnableSkipStart
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_EnableSkipStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_EnableSkipStart(void)
{
    Cy_SCB_UART_EnableSkipStart(ANALYZER_UART_HW);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_DisableSkipStart
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_DisableSkipStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_DisableSkipStart(void)
{
    Cy_SCB_UART_DisableSkipStart(ANALYZER_UART_HW);
}


#if (ANALYZER_UART_ENABLE_RX)
/*******************************************************************************
* Function Name: ANALYZER_UART_Get
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Get() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ANALYZER_UART_Get(void)
{
    return Cy_SCB_UART_Get(ANALYZER_UART_HW);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_GetArray
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetArray() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ANALYZER_UART_GetArray(void *buffer, uint32_t size)
{
    return Cy_SCB_UART_GetArray(ANALYZER_UART_HW, buffer, size);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_GetArrayBlocking
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetArrayBlocking() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_GetArrayBlocking(void *buffer, uint32_t size)
{
    Cy_SCB_UART_GetArrayBlocking(ANALYZER_UART_HW, buffer, size);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_GetRxFifoStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetRxFifoStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ANALYZER_UART_GetRxFifoStatus(void)
{
    return Cy_SCB_UART_GetRxFifoStatus(ANALYZER_UART_HW);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_ClearRxFifoStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearRxFifoStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_ClearRxFifoStatus(uint32_t clearMask)
{
    Cy_SCB_UART_ClearRxFifoStatus(ANALYZER_UART_HW, clearMask);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_GetNumInRxFifo
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumInRxFifo() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ANALYZER_UART_GetNumInRxFifo(void)
{
    return Cy_SCB_UART_GetNumInRxFifo(ANALYZER_UART_HW);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_ClearRxFifo
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearRxFifo() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_ClearRxFifo(void)
{
    Cy_SCB_UART_ClearRxFifo(ANALYZER_UART_HW);
}
#endif /* (ANALYZER_UART_ENABLE_RX) */


#if (ANALYZER_UART_ENABLE_TX)
/*******************************************************************************
* Function Name: ANALYZER_UART_Put
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Put() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ANALYZER_UART_Put(uint32_t data)
{
    return Cy_SCB_UART_Put(ANALYZER_UART_HW,data);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_PutArray
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_PutArray() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ANALYZER_UART_PutArray(void *buffer, uint32_t size)
{
    return Cy_SCB_UART_PutArray(ANALYZER_UART_HW, buffer, size);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_PutArrayBlocking
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_PutArrayBlocking() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_PutArrayBlocking(void *buffer, uint32_t size)
{
    Cy_SCB_UART_PutArrayBlocking(ANALYZER_UART_HW, buffer, size);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_PutString
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_PutString() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_PutString(char_t const string[])
{
    Cy_SCB_UART_PutString(ANALYZER_UART_HW, string);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_SendBreakBlocking
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_SendBreakBlocking() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_SendBreakBlocking(uint32_t breakWidth)
{
    Cy_SCB_UART_SendBreakBlocking(ANALYZER_UART_HW, breakWidth);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_GetTxFifoStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetTxFifoStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ANALYZER_UART_GetTxFifoStatus(void)
{
    return Cy_SCB_UART_GetTxFifoStatus(ANALYZER_UART_HW);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_ClearTxFifoStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearTxFifoStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_ClearTxFifoStatus(uint32_t clearMask)
{
    Cy_SCB_UART_ClearTxFifoStatus(ANALYZER_UART_HW, clearMask);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_GetNumInTxFifo
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumInTxFifo() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ANALYZER_UART_GetNumInTxFifo(void)
{
    return Cy_SCB_UART_GetNumInTxFifo(ANALYZER_UART_HW);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_IsTxComplete
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_IsTxComplete() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE bool ANALYZER_UART_IsTxComplete(void)
{
    return Cy_SCB_UART_IsTxComplete(ANALYZER_UART_HW);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_ClearTxFifo
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearTxFifo() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_ClearTxFifo(void)
{
    Cy_SCB_UART_ClearTxFifo(ANALYZER_UART_HW);
}
#endif /* (ANALYZER_UART_ENABLE_TX) */


#if (ANALYZER_UART_ENABLE_RX)
/*******************************************************************************
* Function Name: ANALYZER_UART_StartRingBuffer
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_StartRingBuffer() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_StartRingBuffer(void *buffer, uint32_t size)
{
    Cy_SCB_UART_StartRingBuffer(ANALYZER_UART_HW, buffer, size, &ANALYZER_UART_context);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_StopRingBuffer
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_StopRingBuffer() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_StopRingBuffer(void)
{
    Cy_SCB_UART_StopRingBuffer(ANALYZER_UART_HW, &ANALYZER_UART_context);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_ClearRingBuffer
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearRingBuffer() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_ClearRingBuffer(void)
{
    Cy_SCB_UART_ClearRingBuffer(ANALYZER_UART_HW, &ANALYZER_UART_context);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_GetNumInRingBuffer
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumInRingBuffer() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ANALYZER_UART_GetNumInRingBuffer(void)
{
    return Cy_SCB_UART_GetNumInRingBuffer(ANALYZER_UART_HW, &ANALYZER_UART_context);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_Receive
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Receive() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_uart_status_t ANALYZER_UART_Receive(void *buffer, uint32_t size)
{
    return Cy_SCB_UART_Receive(ANALYZER_UART_HW, buffer, size, &ANALYZER_UART_context);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_GetReceiveStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetReceiveStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ANALYZER_UART_GetReceiveStatus(void)
{
    return Cy_SCB_UART_GetReceiveStatus(ANALYZER_UART_HW, &ANALYZER_UART_context);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_AbortReceive
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_AbortReceive() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_AbortReceive(void)
{
    Cy_SCB_UART_AbortReceive(ANALYZER_UART_HW, &ANALYZER_UART_context);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_GetNumReceived
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumReceived() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ANALYZER_UART_GetNumReceived(void)
{
    return Cy_SCB_UART_GetNumReceived(ANALYZER_UART_HW, &ANALYZER_UART_context);
}
#endif /* (ANALYZER_UART_ENABLE_RX) */


#if (ANALYZER_UART_ENABLE_TX)
/*******************************************************************************
* Function Name: ANALYZER_UART_Transmit
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Transmit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_uart_status_t ANALYZER_UART_Transmit(void *buffer, uint32_t size)
{
    return Cy_SCB_UART_Transmit(ANALYZER_UART_HW, buffer, size, &ANALYZER_UART_context);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_GetTransmitStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetTransmitStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ANALYZER_UART_GetTransmitStatus(void)
{
    return Cy_SCB_UART_GetTransmitStatus(ANALYZER_UART_HW, &ANALYZER_UART_context);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_AbortTransmit
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_AbortTransmit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_AbortTransmit(void)
{
    Cy_SCB_UART_AbortTransmit(ANALYZER_UART_HW, &ANALYZER_UART_context);
}


/*******************************************************************************
* Function Name: ANALYZER_UART_GetNumLeftToTransmit
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumLeftToTransmit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ANALYZER_UART_GetNumLeftToTransmit(void)
{
    return Cy_SCB_UART_GetNumLeftToTransmit(ANALYZER_UART_HW, &ANALYZER_UART_context);
}
#endif /* (ANALYZER_UART_ENABLE_TX) */


/*******************************************************************************
* Function Name: ANALYZER_UART_Interrupt
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Interrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ANALYZER_UART_Interrupt(void)
{
    Cy_SCB_UART_Interrupt(ANALYZER_UART_HW, &ANALYZER_UART_context);
}

#if defined(__cplusplus)
}
#endif

#endif /* ANALYZER_UART_CY_SCB_UART_PDL_H */


/* [] END OF FILE */
