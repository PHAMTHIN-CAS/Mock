/**
 * @file MKL46Z_HAL_UART0.h
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief The HAL layer header file for UART0 contains prototype functions to interact with the UART0 related field bits
 * @version 0.1
 * @date 2024-09-09
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _INCLUDES_HAL_MKL46Z_HAL_UART0_H_
#define _INCLUDES_HAL_MKL46Z_HAL_UART0_H_
/*******************************************************************************************************************************
 * Includes
 ******************************************************************************************************************************/
#include "MKL46Z4.h"
#include <stdbool.h>
/*******************************************************************************************************************************
 * Prototypes
 ******************************************************************************************************************************/
/**
 * @brief configure value to 5 higher bits of the 13 bits UART baud rate bits
 *
 * @param SBR_high_value value to configure
 */
void HAL_UART0_BDH_init(uint32_t SBR_high_value);


/**
 * @brief configure value to 8 lower bits of the 13 bits UART baud rate bits
 *
 * @param SBR_low_value value to configure
 */
void HAL_UART0_BDL_init(uint32_t SBR_low_value);


/**
 * @brief Configure bits field in UART0 C2 register
 *
 * @param position_bit position of bits field in register
 * @param set_value    value want to configure
 */
void HAL_UART0_C2_init(uint32_t position_bit, bool set_value);


/**
 * @brief Read UART0 data register
 *
 * @return char return data readed
 */
char HAL_UART0_D_read(void);


/**
 * @brief sent data to UART0 data register
 *
 * @param data data want to sent
 */
void HAL_UART0_D_write(char data);


/**
 * @brief check flags in UART0 S1 register
 *
 * @param position_bit position flag want to check
 * @return true  flag in state 1
 * @return false flag in state 0
 */
bool HAL_UART0_S1_flag_state(uint32_t position_bit);

#endif /* _INCLUDES_HAL_MKL46Z_HAL_UART0_H_ */
