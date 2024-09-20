/**
 * @file App_on_off_leds_by_commands.h
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief The header file contains the prototypes functions for LED, UART and control leds by conmmands
 * @version 0.1
 * @date 2024-09-09
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef INCLUDES_APP_APP_ON_OFF_LEDS_BY_COMMANDS_H_
#define INCLUDES_APP_APP_ON_OFF_LEDS_BY_COMMANDS_H_
/*****************************************************************************************************************
 * Includes
 ****************************************************************************************************************/
#include "..\Includes\Driver\MKL46Z_Driver_SIM.h"
#include "..\Includes\Driver\MKL46Z_Driver_PORT.h"
#include "..\Includes\Driver\MKL46Z_Driver_GPIO.h"
#include "..\Includes\Driver\MKL46Z_Driver_UART0.h"
/*****************************************************************************************************************
 * Prototypes
 ****************************************************************************************************************/
/**
 * @brief Configuration function to use LEDs
 * The function body contains functions in the Driver layer that work with modules
 * and registers to configure the LED pins as GPIO Output.
 */
void app_led_init(void);


/**
 * @brief Configuration function to use UART0
 * The function body contains functions in the Driver layer that work with modules
 * and registers to configure use UART0
 */
void app_UART0_init(void);


/**
 * @brief Function to display commands table
 *
 */
void app_display_command_table(void);


/**
 * @brief Function performs controls based on commands
 *
 */
void app_ctrl_leds_by_commands(void);

#endif /* INCLUDES_APP_APP_ON_OFF_LEDS_BY_COMMANDS_H_ */
