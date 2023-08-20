/*******************************************************************************
* File Name: OP1.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the OP1
*  component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_OP1_H)
#define CY_OP1_H

#include <cy_device_headers.h>
#include <ctb/cy_ctb.h>

/*******************************************************************************
                            Internal Constants
*******************************************************************************/
#define OP1_CTB_HW                         CTBM0
#define OP1_OPAMP_NUM                      ((OP1_cy_mxs40_opamp__OA_IDX == 0u) \
                                                        ? CY_CTB_OPAMP_0 : CY_CTB_OPAMP_1)

/*******************************************************************************
                                  Parameters
The parameters that are set in the customizer are redefined as constants here.
*******************************************************************************/
#define OP1_PARAM_Power                    (3UL)
#define OP1_PARAM_OutputDrive              (1UL)
#define OP1_PARAM_DeepSleep                (0UL)

/*******************************************************************************
                    Variables with External Linkage
*******************************************************************************/

/** Tracks whether block is initialized (1) or not (0). */
extern uint8_t OP1_initVar;

/** Tracks the power level setting. Initialized to the power level setting in the customizer. */
extern cy_en_ctb_power_t OP1_opampPower;

/** Configuration structure for initializing one opamp using the CTB PDL. */
extern const cy_stc_ctb_opamp_config_t OP1_opampConfig;


/*******************************************************************************
                        Opamp Configuration Defines
Constants used in the configuration structure for initializing the Opamp
*******************************************************************************/
#if (CYDEV_SYSTEM_AREF_CURRENT == CYDEV_SYSTEM_AREF_CURRENT_LOW)
    /* If the low reference current is used, disable the charge pump. */
    #define OP1_OPAMP_CHARGEPUMP           CY_CTB_PUMP_DISABLE
#else
    /* Charge pump configuration depends on Deep Sleep selection in the customizer. */
    #define OP1_OPAMP_CHARGEPUMP           CY_CTB_PUMP_ENABLE
#endif
/*******************************************************************************
                        Function Prototypes
*******************************************************************************/
void OP1_Start(void);
__STATIC_INLINE void OP1_Init(void);
__STATIC_INLINE void OP1_Enable(void);
__STATIC_INLINE void OP1_Stop(void);
__STATIC_INLINE void OP1_SetPower(cy_en_ctb_power_t power);
__STATIC_INLINE void OP1_SetDeepSleepMode(cy_en_ctb_deep_sleep_t deepSleep);

/*******************************************************************************
* Function Name: OP1_Init
****************************************************************************//**
*
* Initialize the component according to the customizer settings.
* This function can also be used to restore the customizer settings
* if they are changed at run time.
*
* It is not necessary to call OP1_Init() because
* OP1_Start() calls this function. OP1_Start() is the
* preferred method to begin component operation.
*
*******************************************************************************/
__STATIC_INLINE void OP1_Init(void)
{
    (void) Cy_CTB_OpampInit(OP1_CTB_HW, OP1_OPAMP_NUM, &OP1_opampConfig);
}

/*******************************************************************************
* Function Name: OP1_Enable
****************************************************************************//**
*
* Turn on the CTB and set the opamp power level based on last call to
* OP1_SetPower(). If OP1_SetPower() was never called,
* the power level set in the customizer is used.
*
* The other half of the CTB block is unaffected.
*
*******************************************************************************/
__STATIC_INLINE void OP1_Enable(void)
{
    Cy_CTB_Enable(OP1_CTB_HW);
    Cy_CTB_SetPower(OP1_CTB_HW, OP1_OPAMP_NUM, OP1_opampPower, OP1_OPAMP_CHARGEPUMP);
}

/*******************************************************************************
* Function Name: OP1_Stop
****************************************************************************//**
*
* Turn off the opamp in the CTB block.
*
* The other half of the CTB block is unaffected.
*
*******************************************************************************/
__STATIC_INLINE void OP1_Stop(void)
{
    Cy_CTB_SetPower(OP1_CTB_HW, OP1_OPAMP_NUM, CY_CTB_POWER_OFF, OP1_OPAMP_CHARGEPUMP);
}

/*******************************************************************************
* Function Name: OP1_SetPower
****************************************************************************//**
*
* Set the power level for the opamp.
*
* \param power
* - CY_CTB_POWER_OFF: This input option does nothing. OP1_Stop()
*   is the preferred method to turn off the opamp.
* - CY_CTB_POWER_LOW: Low power level
* - CY_CTB_POWER_MEDIUM: Medium power level
* - CY_CTB_POWER_HIGH: High power level
*
*******************************************************************************/
__STATIC_INLINE void OP1_SetPower(cy_en_ctb_power_t power)
{
    if (CY_CTB_POWER_OFF != power)
    {
        Cy_CTB_SetPower(OP1_CTB_HW, OP1_OPAMP_NUM, power, OP1_OPAMP_CHARGEPUMP);

        /* Update the tracking variable for the opamp power level */
        OP1_opampPower = power;
    }
}

/*******************************************************************************
* Function Name: OP1_SetDeepSleepMode
****************************************************************************//**
*
* Set whether the entire CTB block continues to stay powered in Deep Sleep mode.
* This impacts both opamps in the CTB. If there are multiple instances of
* the Opamp component or other components that use the opamp resource
* (for example, Comparator or VDAC12 components), this will affect all instances.
*
* If OP1_Stop() is called before entering Deep Sleep mode,
* the opamp will remain off in Deep Sleep.
*
* Deep Sleep should not be enabled at run time if it was not enabled
* in the customizer. Analog routing and AREF block configuration are performed
* at build time. If Deep Sleep is not enabled in the customizer at build time
* the AREF block and the analog route may not be available during Deep Sleep.
*
* \param deepSleep
* - CY_CTB_DEEPSLEEP_DISABLE: Disable entire CTB is Deep Sleep mode
* - CY_CTB_DEEPSLEEP_ENABLE: Enable entire CTB in Deep Sleep mode
*
*******************************************************************************/
__STATIC_INLINE void OP1_SetDeepSleepMode(cy_en_ctb_deep_sleep_t deepSleep)
{
    Cy_CTB_SetDeepSleepMode(OP1_CTB_HW, deepSleep);
}

#endif /* !defined(CY_OP1_H) */


/* [] END OF FILE */
