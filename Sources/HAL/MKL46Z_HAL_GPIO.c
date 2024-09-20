/**
 * @file MKL46Z_HAL_GPIO.c
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief The HAL layer source file for GPIO contains implementation functions to interact with the GPIO related field bits
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */
/*******************************************************************************************************************************
 * Includes
 ******************************************************************************************************************************/
#include "..\Includes\HAL\MKL46Z_HAL_GPIO.h"
/*******************************************************************************************************************************
 * Code
 ******************************************************************************************************************************/
/**
 * Configures the specified pin as an output pin.
 *
 * @param gpio Pointer to the GPIO register structure.
 * @param pin The pin number to configure.
 */
void HAL_GPIO_PDDR_Output_Init(GPIO_Type * gpio, uint32_t pin)
{
    /* Set the bit in the PDDR register corresponding to the pin to 1 to configure the pin as an output */
    gpio->PDDR |= (1 << pin);
}


/**
 * Sets the specified pin to high level.
 *
 * @param gpio Pointer to the GPIO register structure.
 * @param pin The pin number to set to high level.
 */
void HAL_GPIO_PDOR_High(GPIO_Type * gpio, uint32_t pin)
{
    /* set the corresponding battery status to high */
    gpio->PDOR |= (1 << pin);
}


/**
 * Sets the specified pin to low level.
 *
 * @param gpio Pointer to the GPIO register structure.
 * @param pin The pin number to set to high level.
 */
void HAL_GPIO_PDOR_Low(GPIO_Type * gpio, uint32_t pin)
{
    /* set the corresponding battery status to low */
    gpio->PDOR &= ~(1 << pin);
}


/**
 * Toggles the output level of the specified pin.
 *
 * @param gpio Pointer to the GPIO register structure.
 * @param pin The pin number to toggle.
 */
void HAL_GPIO_TogglePin(GPIO_Type * gpio, uint32_t pin)
{
    /* change the battery status accordingly */
    gpio->PTOR |= (1 << pin);
}


/**
 * @brief function to check state of pin
 *
 * @param gpio PORT of pin
 * @param pin  pin to check
 * @return uint32_t return state of pin
 */
uint32_t HAL_GPIO_pin_state(GPIO_Type * gpio, uint32_t pin)
{
    /* Returns the status of the corresponding pin to be checked */
    return (gpio->PDOR & (1 << pin));
}
