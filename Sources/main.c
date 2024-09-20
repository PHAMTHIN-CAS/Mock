/**
 * @file   main.c
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief  Program to turn on/off the Red led and Green led by commands which are send from PC
 * Implement the code for the UART module to get and set status for Red and Green Led as bellow:
 *     Send LED STATUS to get state of Leds and print to PC�s console.
 *     Send RED ON to turn on Red led and �RED OFF� to turn off Red led.
 *     Send GREEN ON to turn on Red led and �GREEN OFF� to turn off Red led.
 *     Send HELP to print guide line.
 *     Print Command not available If the command does not exist in the commands table
 * @version 0.1
 * @date 2024-09-9
 *
 * @copyright Copyright (c) 2024
 *
 */
/**********************************************************************************************
 * INCLUDES
 *********************************************************************************************/
#include "..\Includes\App\App_on_off_leds_by_commands.h"
/**********************************************************************************************
 * MAIN FUNCTION
 *********************************************************************************************/
int main(void)
{
    /* configure modules                                                                     */
    app_led_init();                      /* Call function in App layer to config using LEDs  */
    app_UART0_init();                    /* Call function in App layer to config using UART0 */

    /* display command table                                                                 */
    app_display_command_table();         /* Call function to display control commands table  */

    /* Loop program                                                                          */
    while(1)
    {
        /* Call function to perform control according to the commands                        */
        app_ctrl_leds_by_commands();
    }

    /* Never leave main */
    return 0;
}
