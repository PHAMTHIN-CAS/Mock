/**
 * @file MKL46Z_Driver_GPIO.h
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief Header file of Driver layer for GPIO contains prototypes of functions to configure GPIO In/Out
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _INCLUDES_DRIVER_MKL46Z_DRIVER_GPIO_H_
#define _INCLUDES_DRIVER_MKL46Z_DRIVER_GPIO_H_
/***********************************************************************************************************
 * Includes
 **********************************************************************************************************/
#include "..\Includes\HAL\MKL46Z_HAL_GPIO.h"
/***********************************************************************************************************
 * Prototypes
 **********************************************************************************************************/
/**
 * @brief Initializes a GPIO pin as an output pin.
 *
 * This function configures the specified pin of the given port as an output pin
 * and sets its initial state to high.
 *
 * @param gpio Pointer to the GPIO register structure for the desired port.
 * @param pin  The pin number within the port to be configured.
 */
void driver_GPIO_output_init(GPIO_Type * gpio, uint32_t pin);

/**
 * @brief Set 0 for pin Output
 *
 * @param gpio  PORT
 * @param pin   PIN set to 0
 */
void driver_GPIO_output_low(GPIO_Type * gpio, uint32_t pin);

/**
 * @brief Set 1 for pin Output
 *
 * @param gpio  PORT
 * @param pin   PIN set to 1
 */
void driver_GPIO_output_high(GPIO_Type * gpio, uint32_t pin);


/**
 * @brief Toggles the state of a GPIO pin.
 *
 * This function inverts the output value of the specified pin.
 *
 * @param gpio Pointer to the GPIO register structure for the desired port.
 * @param pin  The pin number within the port to be toggled.
 */
void driver_GPIO_toggle_pin(GPIO_Type * gpio, uint32_t pin);

/**
 * @brief function to check state of pin output
 *
 * @param gpio PORT of pin
 * @param pin  pin to check
 * @return uint32_t return state of pin
 */
uint32_t driver_GPIO_output_state(GPIO_Type * gpio, uint32_t pin);

#endif /* _INCLUDES_DRIVER_MKL46Z_DRIVER_GPIO_H_ */
