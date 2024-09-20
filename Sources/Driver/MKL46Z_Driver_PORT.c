/**
 * @file MKL46Z_Driver_PORT.c
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief Source file of Driver layer for PORT contains implementation of functions to configure PORT
 * @version 0.1
 * @date 2024-08-30
 *
 * @copyright Copyright (c) 2024
 *
 */
/*************************************************************************************************************
 * Includes
 ************************************************************************************************************/
#include "..\Includes\Driver\MKL46Z_Driver_PORT.h"
/*************************************************************************************************************
 * Code
 ************************************************************************************************************/
/**
 * @brief Initializes a pin of PORT is GPIO pin.
 *
 * This function configures the specified pin of the given port as a GPIO pin..
 *
 * @param PORTx Pointer to the PORT register structure for the desired port.
 * @param PIN   The pin number within the port to be configured.
 */
void driver_PORT_GPIO_init(PORT_Type * PORTx, uint32_t PIN)
{
    /* Configure the pin as GPIO functionality */
    HAL_PORT_PCR_MUX_GPIO_init(PORTx, PIN);
}


/**
 * @brief Initializes a pin of PORT is Analog pin.
 *
 * This function configures the specified pin of the given port as an Analog pin.
 *
 * @param PORTx Pointer to the PORT register structure for the desired port.
 * @param PIN   The pin number within the port to be configured.
 */
void driver_PORT_analog_init(PORT_Type * PORTx, uint32_t PIN)
{
    /* Configure the pin as analog functionality */
    HAL_PORT_PCR_MUX_analog_init(PORTx, PIN);
}


/**
 * @brief Initializes a pin of PORT is UART pin.
 *
 * This function configures the specified pin of the given port as an UART pin.
 *
 * @param PORTx_Rx Pointer to the PORT register structure for the desired port
 * @param PIN_Rx   The pin number within the port to be configured Rx
 * @param PORTx_Tx Pointer to the PORT register structure for the desired port
 * @param PIN_Tx   The pin number within the port to be configured Tx
 */
void driver_PORT_UART_init(PORT_Type * PORTx_Rx, uint32_t PIN_Rx, PORT_Type * PORTx_Tx, uint32_t PIN_Tx)
{
    /* Configure the pin Rx as UART functionality */
    HAL_PORT_PCR_MUX_UART_init(PORTx_Rx, PIN_Rx);
    /* Configure the pin Tx as UART functionality */
    HAL_PORT_PCR_MUX_UART_init(PORTx_Tx, PIN_Tx);
}
