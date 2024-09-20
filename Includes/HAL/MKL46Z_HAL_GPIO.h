/**
 * @file MKL46Z_HAL_GPIO.h
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief The HAL layer header file for GPIO contains prototype functions to interact with the GPIO related field bits
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _INCLUDES_HAL_MKL46Z_HAL_GPIO_H_
#define _INCLUDES_HAL_MKL46Z_HAL_GPIO_H_
/*******************************************************************************************************************************
 * Includes
 ******************************************************************************************************************************/
#include "MKL46Z4.h"
/*******************************************************************************************************************************
 * Prototypes
 ******************************************************************************************************************************/
/**
 * Configures the specified pin as an output pin.
 *
 * @param gpio Pointer to the GPIO register structure.
 * @param pin The pin number to configure.
 */
void HAL_GPIO_PDDR_Output_Init(GPIO_Type * gpio, uint32_t PIN);


/**
 * Sets the specified pin to high level.
 *
 * @param gpio Pointer to the GPIO register structure.
 * @param pin The pin number to set to high level.
 */
void HAL_GPIO_PDOR_High(GPIO_Type * gpio, uint32_t pin);


/**
 * Sets the specified pin to low level.
 *
 * @param gpio Pointer to the GPIO register structure.
 * @param pin The pin number to set to high level.
 */
void HAL_GPIO_PDOR_Low(GPIO_Type * gpio, uint32_t pin);


/**
 * Toggles the output level of the specified pin.
 *
 * @param gpio Pointer to the GPIO register structure.
 * @param pin The pin number to toggle.
 */
void HAL_GPIO_TogglePin(GPIO_Type * gpio, uint32_t pin);

/**
 * @brief function to check state of pin
 *
 * @param gpio PORT of pin
 * @param pin  pin to check
 * @return uint32_t return state of pin
 */
uint32_t HAL_GPIO_pin_state(GPIO_Type * gpio, uint32_t pin);

#endif /* _INCLUDES_HAL_MKL46Z_HAL_GPIO_H_ */
