/**
 * @file MKL46Z_Driver_GPIO.c
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief Source file of Driver layer for GPIO contains implementation of functions to configure GPIO Out
 * @version 0.1
 * @date 2024-08-30
 *
 * @copyright Copyright (c) 2024
 *
 */
/*************************************************************************************************************
 * Includes
 ************************************************************************************************************/
#include "..\Includes\Driver\MKL46Z_Driver_GPIO.h"
/*************************************************************************************************************
 * Code
 ************************************************************************************************************/
/**
 * @brief Initializes a GPIO pin as an output pin.
 *
 * This function configures the specified pin of the given port as an output pin
 *
 * @param gpio Pointer to the GPIO register structure for the desired port.
 * @param pin  The pin number within the port to be configured.
 */
void driver_GPIO_output_init(GPIO_Type * gpio, uint32_t pin)
{
    /* Set the pin direction as output         */
    HAL_GPIO_PDDR_Output_Init(gpio, pin);
}


/**
 * @brief Set 0 for pin Output
 *
 * @param gpio  PORT
 * @param pin   PIN set to 0
 */
void driver_GPIO_output_low(GPIO_Type * gpio, uint32_t pin)
{
    HAL_GPIO_PDOR_Low(gpio, pin); /* set 0 the bit corresponding to the PIN code in GPIO_PDOR write */
}


/**
 * @brief Set 1 for pin Output
 *
 * @param gpio  PORT
 * @param pin   PIN set to 1
 */
void driver_GPIO_output_high(GPIO_Type * gpio, uint32_t pin)
{
    HAL_GPIO_PDOR_High(gpio, pin); /* set 1 the bit corresponding to the PIN code in GPIO_PDOR write */
}


/**
 * @brief Toggles the state of a GPIO pin.
 *
 * This function inverts the output value of the specified pin.
 *
 * @param gpio Pointer to the GPIO register structure for the desired port.
 * @param pin  The pin number within the port to be toggled.
 */
void driver_GPIO_toggle_pin(GPIO_Type * gpio, uint32_t pin)
{
    /* Change the state of the corresponding battery */
    HAL_GPIO_TogglePin(gpio, pin);
}


/**
 * @brief function to check state of pin output
 *
 * @param gpio PORT of pin
 * @param pin  pin to check
 * @return uint32_t return state of pin
 */
uint32_t driver_GPIO_output_state(GPIO_Type * gpio, uint32_t pin)
{
    /* Returns the status of the corresponding pin to be checked */
    return HAL_GPIO_pin_state(gpio, pin);
}
