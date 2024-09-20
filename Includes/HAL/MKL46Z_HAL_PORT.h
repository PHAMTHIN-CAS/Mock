/**
 * @file MKL46Z_HAL_PORT.h
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief The HAL layer header file for PORT contains prototypes functions to interact with the PORT related field bits
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _INCLUDES_HAL_MKL46Z_HAL_PORT_H_
#define _INCLUDES_HAL_MKL46Z_HAL_PORT_H_
/*******************************************************************************************************************************
 * Includes
 ******************************************************************************************************************************/
#include "MKL46Z4.h"
/*******************************************************************************************************************************
 * Prototypes
 ******************************************************************************************************************************/
/**
 * Configures the specified pin as a general-purpose Analog pin.
 *
 * @param PORT Pointer to the PORT register structure.
 * @param PIN The pin number to configure.
 */
void HAL_PORT_PCR_MUX_analog_init(PORT_Type * PORT,uint32_t PIN);


/**
 * Configures the specified pin as a general-purpose input/output (GPIO) pin.
 *
 * @param PORT Pointer to the PORT register structure.
 * @param PIN The pin number to configure.
 */
void HAL_PORT_PCR_MUX_GPIO_init(PORT_Type * PORT,uint32_t PIN);


/**
 * Configures the specified pin as a general-purpose UART pin.
 *
 * @param PORT Pointer to the PORT register structure.
 * @param PIN  The pin number to configure.
 */
void HAL_PORT_PCR_MUX_UART_init(PORT_Type * PORT,uint32_t PIN);

#endif /* _INCLUDES_HAL_MKL46Z_HAL_PORT_H_ */
