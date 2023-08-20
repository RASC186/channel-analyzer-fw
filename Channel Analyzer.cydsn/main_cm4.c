#include "project.h"
#include "math.h"
#include "arm_math.h"

#define BLOCK_SIZE      20U
#define VDAC_CLK_FREQ   50E+6

volatile uint32_t y[BLOCK_SIZE];

void uartIrqHandler()
{
    float32_t div;
    uint32_t divInt, fracDivInt;
    uint8_t rxBuffer[8];
    
    Cy_SCB_UART_GetArray(ANALYZER_UART_HW,rxBuffer,sizeof(rxBuffer));
    
    float32_t magnitude = *((float*)&(rxBuffer[0]));
    float32_t frequency = *((float*)&(rxBuffer[4]));
    
    div = (VDAC_CLK_FREQ)/(20*frequency);
    divInt = floor(div);
    fracDivInt = round((div-divInt)*32);
    
    for(uint32_t n=0; n<BLOCK_SIZE; n++){
        y[n] = round(4095*(magnitude/3.3)*(0.5+0.5*sin(2*M_PI*((float32_t)1/BLOCK_SIZE)*n)));
    }
    
    Cy_SysClk_PeriphDisableDivider(VDAC_CLK_DIV_TYPE,VDAC_CLK_DIV_NUM);        
    VDAC_CLK_SetFracDivider(div,fracDivInt);    
    Cy_SysClk_PeriphEnableDivider(VDAC_CLK_DIV_TYPE,VDAC_CLK_DIV_NUM);
    
    ANALYZER_UART_ClearRxFifo();
    ANALYZER_UART_ClearRxFifoStatus(CY_SCB_UART_RX_TRIGGER);
}

int main(void)
{
    __enable_irq();
        
    for(uint32_t n=0; n<BLOCK_SIZE; n++){
        y[n] = round(255*(0.5+0.5*sin(2*M_PI*((float32_t)1/BLOCK_SIZE)*n)));
    }
    
    ANALIZER_PWM_Start();
    ANALYZER_ADC_Start();
    ANALYZER_VDAC_Start();
    ANALYZER_UART_Start();
    
    OP0_Start();
    OP1_Start();
        
    ANALYZER_ADC_StartConvert();
    
    ADC_DMA_Start((uint32_t *)&(SAR->CHAN_RESULT[0]), (uint32_t *)&(SCB5->TX_FIFO_WR));
    VDAC_DMA_Start((uint32_t *)&(y[0]), (uint32_t *)&(CTDAC0->CTDAC_VAL_NXT));
    
    Cy_SysInt_Init(&UART_INTERRUPT_cfg,&uartIrqHandler);
    NVIC_ClearPendingIRQ(UART_INTERRUPT_cfg.intrSrc);
	NVIC_EnableIRQ(UART_INTERRUPT_cfg.intrSrc);
    
    for(;;)
    {
        CyDelay(500);
        Cy_GPIO_Write(STATUS_LED_PORT,STATUS_LED_NUM,1);
        CyDelay(500);
        Cy_GPIO_Write(STATUS_LED_PORT,STATUS_LED_NUM,0);
    }
}