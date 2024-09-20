/**
 * @file MKL46Z_HAL_PORT.c
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief The HAL layer source file for PORT contains implementation functions to interact with the PORT related field bits
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */
/*******************************************************************************************************************************
 * Includes
 ******************************************************************************************************************************/
#include "..\Includes\HAL\MKL46Z_HAL_PORT.h"
/*******************************************************************************************************************************
 * Code
 ******************************************************************************************************************************/
/**
 * Configures the specified pin as a general-purpose Analog pin.
 *
 * @param PORT Pointer to the PORT register structure.
 * @param PIN  The pin number to configure.
 */
void HAL_PORT_PCR_MUX_analog_init(PORT_Type * PORT,uint32_t PIN)
{
    /* Set MUX filed in PCR register is 1 to config is analog */
    PORT->PCR[PIN] |= PORT_PCR_MUX(0);
}


/**
 * Configures the specified pin as a general-purpose input/output (GPIO) pin.
 *
 * @param PORT Pointer to the PORT register structure.
 * @param PIN  The pin number to configure.
 */
void HAL_PORT_PCR_MUX_GPIO_init(PORT_Type * PORT,uint32_t PIN)
{
    /* Set MUX filed in PCR register is 1 to config is GPIO */
    PORT->PCR[PIN] |= PORT_PCR_MUX(1);
}


/**
 * Configures the specified pin as a general-purpose UART pin.
 *
 * @param PORT Pointer to the PORT register structure.
 * @param PIN  The pin number to configure.
 */
void HAL_PORT_PCR_MUX_UART_init(PORT_Type * PORT,uint32_t PIN)
{
    /* Set MUX filed in PCR register is 1 to config is UART */
    PORT->PCR[PIN] |= PORT_PCR_MUX(2);
}
