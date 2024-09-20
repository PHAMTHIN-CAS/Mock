/**
 * @file App_on_off_leds_by_commands.c
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief The source file contains the implementation functions for LED, UART and control leds by conmmands
 * @version 0.1
 * @date 2024-09-09
 *
 * @copyright Copyright (c) 2024
 *
 */
/*******************************************************************************************************************************
 * Includes
 ******************************************************************************************************************************/
#include "..\Includes\App\App_on_off_leds_by_commands.h"
#include <string.h>
/*******************************************************************************************************************************
 * Definitions
 ******************************************************************************************************************************/
/* Define LED                                                                                                                 */
#define RED_LED_PIN   29                                                         /* PIN of PORT that connects to RED LED      */
#define GREEN_LED_PIN 5                                                          /* PIN of PORT that connects to GREEN LED    */

/* Define UART0                                                                                                               */
#define UART0_RX_PORT   PORTA                                                    /* PORT that connects to UART0_Rx            */
#define UART0_TX_PORT   PORTA                                                    /* PORT that connects to UART0_Tx            */
#define UART0_RX_PIN    1                                                        /* PIN of PORT that connects to UART0_Rx     */
#define UART0_TX_PIN    2                                                        /* PIN of PORT that connects to UART0_Tx     */
#define UART0_BAUD_RATE 115200                                                   /* Baud rate value of UART0 is 115200 Hz     */
#define UART0_Clock     20971520                                                 /* Clock of UART0 is 20.97152MHz             */
#define UART0_OSR       16                                                       /* OSR of UART0  is 16                       */
/* Define commands                                                                                                            */
#define MAX_LENGHT_COMMAND 20                                                    /* Commands are 20 characters long           */
/*******************************************************************************************************************************
 * Variables
 ******************************************************************************************************************************/
bool     g_read_command_flag = false;                                   /* Flag indicating successful command control read    */
char     g_command_buff[20];                                            /* Temporary memory area for storing control commands */
uint32_t g_index_buff = 0;                                              /* Index in string command                            */
/*******************************************************************************************************************************
 * Prototypes
 ******************************************************************************************************************************/
/**
 * @brief Function called when there is an interrupt from UART0
 *
 */
void interrupt_UART0_receiver_callback(void);
/*******************************************************************************************************************************
 * Code
 ******************************************************************************************************************************/
/**
 * @brief Configuration function to use LEDs
 * The function body contains functions in the Driver layer that work with modules
 * and registers to configure the LED pins as GPIO Output.
 */
void app_led_init(void)
{
    /* Init RED LED                                                                                                           */
    driver_SIM_SCGC5_init(SIM_PORTE, 1);               /* Call Function to Enable clock for RED LED                           */
    driver_PORT_GPIO_init(PORTE, RED_LED_PIN);         /* Configure using GPIO function for PIN corresponding to RED LED      */
    driver_GPIO_output_init(PTE, RED_LED_PIN);         /* Configure using Output function for PIN corresponding to RED LED    */
    driver_GPIO_output_high(PTE, RED_LED_PIN);         /* Set PIN to high to turn off the RED LED                             */

    /* Init GREEN LED                                                                                                         */
    driver_SIM_SCGC5_init(SIM_PORTD, 1);               /* Call Function to Enable clock for GREEN LED                         */
    driver_PORT_GPIO_init(PORTD, GREEN_LED_PIN);       /* Configure using GPIO function for PIN corresponding to GREEN LED    */
    driver_GPIO_output_init(PTD, GREEN_LED_PIN);       /* Configure using Output function for PIN corresponding to GREEN LED  */
    driver_GPIO_output_high(PTD, GREEN_LED_PIN);       /* Set PIN to high to turn off the GREEN LED                           */
}


/**
 * @brief Configuration function to use UART0
 * The function body contains functions in the Driver layer that work with modules
 * and registers to configure use UART0
 */
void app_UART0_init(void)
{
    /* Selects MCGFLLCLK clock source for the UART0 transmit and receive clock                                                */
    driver_SIM_SOPT2_init(0x1u << 26);

    /* Enable clock gate for PortA (TX RX)                                                                                    */
    driver_SIM_SCGC5_init(SIM_PORTA, 1);

    /* Configure UART mode for pin Rx & Tx                                                                                    */
    driver_PORT_UART_init(UART0_RX_PORT, UART0_RX_PIN, UART0_TX_PORT, UART0_TX_PIN);

    /* Enable clock gate for UART0                                                                                            */
    driver_SIM_SCGC4_init(SIM_UART0, 1);

    /* Configure UART Baud rate                                                                                               */
    driver_UART0_SBR_init(UART0_BAUD_RATE, UART0_Clock, UART0_OSR);

    /* Transmitter Enable                                                                                                     */
    driver_UART0_C2_init(TE, 1);

    /* Receiver Enable                                                                                                        */
    driver_UART0_C2_init(RE, 1);

    /* Configure to use interrupt of UART0 and register function called when an interrupt occurs                              */
    driver_UART0_interrupt_init(0, 0, 1, interrupt_UART0_receiver_callback);
}


/**
 * @brief Function to display commands table
 *
 */
void app_display_command_table(void)
{
    driver_UART0_sent_string("\nCOMMAND TABLE\n");
    driver_UART0_sent_string("- Send LED STATUS to get state of Leds and print to PC�s console\n");
    driver_UART0_sent_string("- Send RED ON     to turn on  Red led\n");
    driver_UART0_sent_string("- Send RED OFF    to turn off Red led\n");
    driver_UART0_sent_string("- Send GREEN ON   to turn on  Green led and �GREEN OFF� to turn off Red led\n");
    driver_UART0_sent_string("- Send GREEN OFF  to turn off Green led and �GREEN OFF� to turn off Red led\n");
    driver_UART0_sent_string("- Send HELP       to print guide line\n");
}


/**
 * @brief Function performs controls based on commands
 *
 */
void app_ctrl_leds_by_commands(void)
{
    /* If the command read completion flag is set                                                                             */
    if (g_read_command_flag)
    {
        /* If command is "LED STATUS" then                                                                                    */
        if (strcmp(g_command_buff, "LED STATUS") == 0)
        {
            /* display RED LED Status                                                                                         */
            if(driver_GPIO_output_state(PTE, RED_LED_PIN)) /* If the pin corresponding to the RED LED is at level 1 then      */
            {
                driver_UART0_sent_string("\nLED RED is in OFF state");
            }
            else /* If the pin corresponding to the RED LED is at level 0 then                                                */
            {
                driver_UART0_sent_string("\nLED RED is in ON state");
            }
            /* display GREEN LED Status */
            if(driver_GPIO_output_state(PTD, GREEN_LED_PIN)) /* If the pin corresponding to the GREEN LED is at level 1 then  */
            {
                driver_UART0_sent_string("\nLED GREEN is in OFF state\n");
            }
            else /* If the pin corresponding to the GREEN LED is at level 1 then                                              */
            {
                driver_UART0_sent_string("\nLED GREEN is in ON state\n");
            }
        }
        else if (strcmp(g_command_buff, "RED ON") == 0)     /* If command is "RED ON" then                                    */
        {
            driver_GPIO_output_low(PTE, RED_LED_PIN);       /* Set PIN to low to turn on the RED LED                          */
        }
        else if (strcmp(g_command_buff, "RED OFF") == 0)    /* If command is "RED OFF" then                                   */
        {
            driver_GPIO_output_high(PTE, RED_LED_PIN);      /* Set PIN to high to turn off the RED LED                        */
        }
        else if (strcmp(g_command_buff, "GREEN ON") == 0)   /* If command is "GREEN ON" then                                  */
        {
            driver_GPIO_output_low(PTD, GREEN_LED_PIN);     /* Set PIN to low to turn on the GREEN LED                        */
        }
        else if (strcmp(g_command_buff, "GREEN OFF") == 0)  /* If command is "GREEN OFF" then                                 */
        {
            driver_GPIO_output_high(PTD, GREEN_LED_PIN);    /* Set PIN to high to turn off the GREEN LED                      */
        }
        else if (strcmp(g_command_buff, "HELP") == 0)       /* If command is "HELP" then                                      */
        {
            app_display_command_table();                    /* Print again commands table                                     */
        }
        else /* If the command does not exist in the commands table                                                           */
        {
            driver_UART0_sent_string("\nCOMMAND NOT AVAILABLE\nPlease send HELP to see command list\n");
        }
        g_read_command_flag = false; /* reset read completion flag                                                            */
    }
}


/**
 * @brief Function called when there is an interrupt from UART0
 *
 */
void interrupt_UART0_receiver_callback(void)
{
    /* read and save each character of the command into a temporary variable                                                  */
    g_command_buff[g_index_buff] = driver_UART0_receive_bytes();
    /* If NULL character is detected (end of command)                                                                         */
    if(g_command_buff[g_index_buff] == '\0')
    {
        g_index_buff = 0;             /* reset the index variable to 0 to save the new command                                */
        g_read_command_flag = true;   /* set read completion flag                                                             */
    }
    else
    {
        g_index_buff++;               /* increment index to read and save next character                                      */
    }
}
