/**
 * @file MKL46Z_Driver_UART0.h
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief  The header file of the SIM Driver layer contains prototypes of functions to work to UART0
 * @version 0.1
 * @date 2024-09-9
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _INCLUDES_DRIVER_MKL46Z_DRIVER_UART0_H_
#define _INCLUDES_DRIVER_MKL46Z_DRIVER_UART0_H_
/*******************************************************************************************************************************
 * Includes
 ******************************************************************************************************************************/
#include "..\Includes\HAL\MKL46Z_HAL_UART0.h"
/*******************************************************************************************************************************
 * Definitions
 ******************************************************************************************************************************/
/**
 * @brief Enum represents UART0 C2 bit fields
 */
typedef enum
{
    SBK  = 0,             /* corresponding bit position in register UART0_C2 of Sent Break                                    */
    RWU  = 1,             /* corresponding bit position in register UART0_C2 of Receiver Wakeup Control                       */
    RE   = 2,             /* corresponding bit position in register UART0_C2 of Receiver Enable                               */
    TE   = 3,             /* corresponding bit position in register UART0_C2 of Transmitter Enable                            */
    ILIE = 4,             /* corresponding bit position in register UART0_C2 of Idle Line Interrupt Enable for IDLE           */
    RIE  = 5,             /* corresponding bit position in register UART0_C2 of Receiver Interrupt Enable for RDRF            */
    TCIE = 6,             /* corresponding bit position in register UART0_C2 of Transmission Complete Interrupt Enable for TC */
    TIE  = 7              /* corresponding bit position in register UART0_C2 of Transmit Interrupt Enable for TDRE            */
}UART0_C2_bit;

/**
 * @brief Enum represents UART0 S1 bit fields
 *
 */
typedef enum
{
    PF   = 0,             /* corresponding bit position in register UART0_S1 of Parity Error Flag                             */
    FE   = 1,             /* corresponding bit position in register UART0_S1 of Framing Error Flag                            */
    NF   = 2,             /* corresponding bit position in register UART0_S1 of Noise Flag                                    */
    OR   = 3,             /* corresponding bit position in register UART0_S1 of Receiver Overrun Flag                         */
    IDLE = 4,             /* corresponding bit position in register UART0_S1 of Idle Line Flag                                */
    RDRF = 5,             /* corresponding bit position in register UART0_S1 of Receive Data Register Full Flag               */
    TC   = 6,             /* corresponding bit position in register UART0_S1 of Transmission Complete Flag                    */
    TDRE = 7              /* corresponding bit position in register UART0_S1 of Transmit Data Register Empty Flag             */
}UART0_S1_bit;
/*******************************************************************************************************************************
 * Prototypes
 ******************************************************************************************************************************/
/**
 * @brief Function to calculate and set configure to UART0 baud rate
 *
 * @param baud_rate  UART baud rate want to configure
 * @param UART_clock Clock of UART
 * @param UART_OSR   OSR of UART
 */
void driver_UART0_SBR_init(uint32_t baud_rate, uint32_t UART_clock, uint32_t UART_OSR);


/**
 * @brief Function to configure modes in UART0_C2 register
 *
 * @param mode_set  mode want to configure
 * @param set_value value want to configure
 */
void driver_UART0_C2_init(UART0_C2_bit mode_set, bool set_value);


/**
 * @brief Function to configure use interrupt of UART0
 *
 * @param TIE_en  Transmit Interrupt Enable for TDRE
 * @param TCIE_en Transmission Complete Interrupt Enable for TC
 * @param RIE_en  Receiver Interrupt Enable for RDRF
 * @param func_callback Function pointer of function registed to callback function
 */
void driver_UART0_interrupt_init(bool TIE_en, bool TCIE_en, bool RIE_en, void (* func_callback)(void));


/**
 * @brief Function to sent string data to receiver
 *
 * @param string string data want to sent
 */
void driver_UART0_sent_string(char * string);


/**
 * @brief Function to read 1 byte data from receiver
 *
 * @return char return 1 byte data from receiver
 */
char driver_UART0_receive_bytes(void);

#endif /* _INCLUDES_DRIVER_MKL46Z_DRIVER_UART0_H_ */
