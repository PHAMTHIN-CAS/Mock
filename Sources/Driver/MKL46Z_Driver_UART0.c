/**
 * @file MKL46Z_Driver_UART0.c
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief  The source file of the SIM Driver layer contains implementations of functions to work to UART0
 * @version 0.1
 * @date 2024-09-9
 *
 * @copyright Copyright (c) 2024
 *
 */
/*******************************************************************************************************************************
 * Includes
 ******************************************************************************************************************************/
#include "..\Includes\Driver\MKL46Z_Driver_UART0.h"
/*******************************************************************************************************************************
 * Prototypes
 ******************************************************************************************************************************/
/**
 * @brief Static function to sent bytes to recever
 *
 * @param data byte data want to sent
 */
static void driver_UART0_send_bytes(char data);
/*******************************************************************************************************************************
 * Variables
 ******************************************************************************************************************************/
void (* func_UART0_callback)(void); /* function pointer point to function on app layer                                        */
volatile uint32_t g_BDH_value = 0;  /* variable to store 5 higher bits of value to set baud rate                              */
volatile uint32_t g_BDL_value = 0;  /* variable to store 8 lower bits of value to set baud rate                               */
/*******************************************************************************************************************************
 * Code
 ******************************************************************************************************************************/
/**
 * @brief Function to calculate and set configure to UART0 baud rate
 *
 * @param baud_rate  UART baud rate want to configure
 * @param UART_clock Clock of UART
 * @param UART_OSR   OSR of UART
 */
void driver_UART0_SBR_init(uint32_t baud_rate, uint32_t UART_clock, uint32_t UART_OSR)
{
    uint32_t SBR_value = 0;                                                    /* variable store value set baud rate for UART */
    SBR_value = UART_clock/(baud_rate*UART_OSR);                               /* calculate value set baud rate for UART      */
    if(0 != (UART_clock%(baud_rate*UART_OSR)))
    {
        SBR_value++;                                                           /* error correction                            */
    }
    g_BDH_value = SBR_value >> 8;                                              /* 5 higher bits of set baud rate              */
    g_BDL_value = SBR_value & 0xFF;                                            /* 8 lower bits of set boaud rate              */
    HAL_UART0_BDH_init(g_BDH_value);                                           /* set value to UART_BDH register              */
    HAL_UART0_BDL_init(g_BDL_value);                                           /* set value to UART_BDL register              */
}


/**
 * @brief Function to configure modes in UART0_C2 register
 *
 * @param mode_set  mode want to configure
 * @param set_value value want to configure
 */
void driver_UART0_C2_init(UART0_C2_bit mode_set, bool set_value)
{
    /* Set the value for the bit position corresponding to the mode                                                           */
    HAL_UART0_C2_init(mode_set, set_value);
}


/**
 * @brief Function to configure use interrupt of UART0
 *
 * @param TIE_en  Transmit Interrupt Enable for TDRE
 * @param TCIE_en Transmission Complete Interrupt Enable for TC
 * @param RIE_en  Receiver Interrupt Enable for RDRF
 * @param func_callback Function pointer of function registed to callback function
 */
void driver_UART0_interrupt_init(bool TIE_en, bool TCIE_en, bool RIE_en, void (* func_callback)(void))
{
    /* Set the value for the bit position corresponding to Transmit Interrupt Enable for TDRE                                 */
    HAL_UART0_C2_init(TIE, TIE_en);
    /* Set the value for the bit position corresponding to Transmission Complete Interrupt Enable for TC                      */
    HAL_UART0_C2_init(TCIE, TCIE_en);
    /* Set the value for the bit position corresponding to Receiver Interrupt Enable for RDRF                                 */
    HAL_UART0_C2_init(RIE, RIE_en);
    /* Enable NVIC interrupts for UART0                                                                                       */
    NVIC_EnableIRQ(UART0_IRQn);
    /* Register for Function in App layer to be called back                                                                   */
    func_UART0_callback = func_callback;
}


/**
 * @brief Function to sent string data to receiver
 *
 * @param string string data want to sent
 */
void driver_UART0_sent_string(char * string)
{
    /* send bytes one by one until it encounters a NULL character                                                             */
    while ('\0' != *string)
    {
        driver_UART0_send_bytes(*string); /* call function to sent 1 byte data to receiver                                    */
        string++;                         /* move to next byte                                                                */
    }
}


/**
 * @brief Function to read 1 byte data from receiver
 *
 * @return char return 1 byte data from receiver
 */
char driver_UART0_receive_bytes(void)
{
    return HAL_UART0_D_read(); /* read UART0 data register                                                                    */
}


/**
 * @brief Function to sent 1 byte data to receiver
 *
 * @param data bytes data want to sent
 */
static void driver_UART0_send_bytes(char data)
{
    HAL_UART0_D_write(data); /* write data to UART0 data register                                                             */
    /* check Transmission Complete Flag                                                                                       */
    while (!(HAL_UART0_S1_flag_state(TC)))
    {
        /* waiting for transmission complete */
    }
}


/**
 * @brief The UART0 interrupt handler function is managed by the NVIC.
 *
 */
void UART0_IRQHandler(void)
{
    /* check Receive Data Register Full Flag */
    if(HAL_UART0_S1_flag_state(RDRF))
    {
        func_UART0_callback(); /* execute the function for which the callback has been registered */
    }
}

