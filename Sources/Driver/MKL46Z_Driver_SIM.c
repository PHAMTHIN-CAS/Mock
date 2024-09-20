/**
 * @file MKL46Z_Driver_SIM.c
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief The source file of the SIM Driver layer contains implementations of functions to supply clock pulses to peripherals
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */
/*******************************************************************************************************************************
 * Includes
 ******************************************************************************************************************************/
#include "..\Includes\Driver\MKL46Z_Driver_SIM.h"
/*******************************************************************************************************************************
 * Code
 ******************************************************************************************************************************/
/**
 * @brief Initializes the specified SIM SCGC4 module.
 *
 * This function enables the clock gate for the specified module in the SIM SCGC4 register.
 *
 * @param module The SIM SCGC4 module to be initialized
 * @param clock_en enable/disable clock ton module
 */
void driver_SIM_SCGC4_init(SIM_SCGC4_bit module, uint32_t clock_en)
{
    /* Call the function to set the bit in the SSGC4 register corresponding to the module to be powered */
    HAL_SIM_SCGC4_init(module, clock_en);
}


/**
 * @brief Initializes the specified SIM SCGC5 module.
 *
 * This function enables the clock gate for the specified module in the SIM SCGC5 register.
 *
 * @param module The SIM SCGC5 module to be initialized
 * @param clock_en enable/disable clock ton module
 */
void driver_SIM_SCGC5_init(SIM_SCGC5_bit module, uint32_t clock_en)
{
    /* Call the function to set the bit in the SSGC5 register corresponding to the module to be powered */
    HAL_SIM_SCGC5_init(module, clock_en);
}


/**
 * @brief Initializes the specified SIM SCGC6 module.
 *
 * This function enables the clock gate for the specified module in the SIM SCGC6 register.
 *
 * @param module The SIM SCGC6 module to be initialized
 * @param clock_en enable/disable clock ton module
 */
void driver_SIM_SCGC6_init(SIM_SCGC6_bit module, uint32_t clock_en)
{
    /* Call the function to set the bit in the SSGC6 register corresponding to the module to be powered */
    HAL_SIM_SCGC6_init(module, clock_en);
}


/**
 * @brief Initializes the specified SIM SOPT2 module.
 *
 * This function enables the clock gate for the specified module in the SIM SOPT2 register.
 *
 * @param conf_value  The desired value is set at the module's field bits
 */
void driver_SIM_SOPT2_init(uint32_t conf_value)
{
    /* set the desired value at the module's field bits */
    HAL_SIM_SOPT2_init(conf_value);
}
