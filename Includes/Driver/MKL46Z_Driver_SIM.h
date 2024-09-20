/**
 * @file MKL46Z_Driver_SIM.h
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief Header file of of the SIM Driver layer contains prototype of functions to supply clock pulses to peripherals
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _INCLUDES_DRIVER_MKL46Z_DRIVER_SIM_H_
#define _INCLUDES_DRIVER_MKL46Z_DRIVER_SIM_H_
/*******************************************************************************************************************************
 * Includes
 ******************************************************************************************************************************/
#include "..\Includes\HAL\MKL46Z_HAL_SIM.h"
/*******************************************************************************************************************************
 * Definitions
 ******************************************************************************************************************************/
/**
 * Enum representing SIM SCGC4 modules.
 */
typedef enum
{
    SIM_I2C0   = 6,  /* bit corresponding to I2C0 in register SCGC4   */
    SIM_I2C1   = 7,  /* bit corresponding to I2C1 in register SCGC4   */
	SIM_UART0  = 10, /* bit corresponding to UART0 in register SCGC4  */
	SIM_UART1  = 11, /* bit corresponding to UART1 in register SCGC4  */
	SIM_UART2  = 12, /* bit corresponding to UART2 in register SCGC4  */
	SIM_USBOTG = 18, /* bit corresponding to USBOTG in register SCGC4 */
    SIM_CMP    = 19, /* bit corresponding to CMP in register SCGC4    */
    SIM_SPI0   = 22, /* bit corresponding to SPI0 in register SCGC4   */
    SIM_SPI1   = 23  /* bit corresponding to SPI1 in register SCGC4   */
}SIM_SCGC4_bit;


/**
 * Enum representing SIM SCGC5 modules.
 */
typedef enum
{
    SIM_LPTMR  = 0, /* bit corresponding to LPTMR in register SCGC5 */
    SIM_TSI    = 5, /* bit corresponding to TSI in register SCGC5   */
    SIM_PORTA = 9,  /* bit corresponding to PORTA in register SCGC5 */
    SIM_PORTB = 10, /* bit corresponding to PORTB in register SCGC5 */
    SIM_PORTC = 11, /* bit corresponding to PORTC in register SCGC5 */
    SIM_PORTD = 12, /* bit corresponding to PORTD in register SCGC5 */
    SIM_PORTE = 13, /* bit corresponding to PORTE in register SCGC5 */
    SIM_SLCD   = 19 /* bit corresponding to SLCD in register SCGC5  */
}SIM_SCGC5_bit;

/**
 * Enum representing SIM SCGC6 modules.
 */
typedef enum
{
    SIM_FTF    = 0,  /* bit corresponding to FTF    in register SCGC6 */
    SIM_DMAMUX = 1,  /* bit corresponding to DMAMUX in register SCGC6 */
    SIM_I2S    = 15, /* bit corresponding to I2S    in register SCGC6 */
    SIM_PIT    = 23, /* bit corresponding to PIT    in register SCGC6 */
    SIM_TPM0   = 24, /* bit corresponding to TMP0   in register SCGC6 */
    SIM_TPM1   = 25, /* bit corresponding to TMP1   in register SCGC6 */
    SIM_TPM2   = 26, /* bit corresponding to TMP2   in register SCGC6 */
    SIM_ADC0   = 27, /* bit corresponding to ADC0   in register SCGC6 */
    SIM_RTC    = 29, /* bit corresponding to RTC    in register SCGC6 */
    SIM_DAC0   = 31  /* bit corresponding to DAC0   in register SCGC6 */
}SIM_SCGC6_bit;

///**
// * Enum representing SIM SOPT2 modules.
// */
//typedef enum
//{
//	SIM_RTCCLKOUTSEL = 4,
//	SIM_CLKOUTSEL    = 5,
//	SIM_PLLFLLSEL    = 16,
//	SIM_USBSRC       = 18,
//	SIM_TPMSRC       = 24,
//	SIM_UART0SRC     = 26
//}SIM_SOPT2_bit;

/*******************************************************************************************************************************
 * Prototypes
 ******************************************************************************************************************************/
/**
 * @brief Initializes the specified SIM SCGC4 module.
 *
 * This function enables the clock gate for the specified module in the SIM SCGC4 register.
 *
 * @param module   The SIM SCGC4 module to be initialized
 * @param clock_en enable/disable clock ton module
 */
void driver_SIM_SCGC4_init(SIM_SCGC4_bit module, uint32_t clock_en);


/**
 * @brief Initializes the specified SIM SCGC5 module.
 *
 * This function enables the clock gate for the specified module in the SIM SCGC5 register.
 *
 * @param module   The SIM SCGC5 module to be initialized
 * @param clock_en enable/disable clock ton module
 */
void driver_SIM_SCGC5_init(SIM_SCGC5_bit module, uint32_t clock_en);


/**
 * @brief Initializes the specified SIM SCGC6 module.
 *
 * This function enables the clock gate for the specified module in the SIM SCGC6 register.
 *
 * @param module The SIM SCGC6 module to be initialized
 * @param clock_en enable/disable clock ton module
 */
void driver_SIM_SCGC6_init(SIM_SCGC6_bit module, uint32_t clock_en);


/**
 * @brief Initializes the specified SIM SOPT2 module.
 *
 * This function enables the clock gate for the specified module in the SIM SOPT2 register.
 *
 * @param conf_value  The desired value is set at the module's field bits
 */
void driver_SIM_SOPT2_init(uint32_t conf_value);

#endif /* _INCLUDES_DRIVER_MKL46Z_DRIVER_SIM_H_ */
