/**
 * @file MKL46Z_HAL_SIM.c
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief The HAL layer source file for SIM contains implementation functions to interact with the SIM related field bits
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */
/*******************************************************************************************************************************
 * Includes
 ******************************************************************************************************************************/
#include "..\Includes\HAL\MKL46Z_HAL_SIM.h"
/*******************************************************************************************************************************
 * Code
 ******************************************************************************************************************************/
/**
 * @brief function to set bit in register SCGC4
 * bits corresponding to modules
 * @param bit      bit number corresponding to modules
 * @param clock_en enable/disable clock ton module
 */
void HAL_SIM_SCGC4_init(uint32_t bit, uint32_t clock_en)
{
    /* If it is allowed to grant clock to the module */
    if(clock_en)
    {
        /* Set bit to 1 to provide clock */
        SIM->SCGC4 |= (1 << bit);
    }
    else
    {
        /* Set the bit to 0 to stop providing the clock */
        SIM->SCGC4 &= ~(1 << bit);
    }
}


/**
 * @brief function to set bit in register SCGC5
 * bits corresponding to modules
 * @param bit      bit number corresponding to modules
 * @param clock_en enable/disable clock ton module
 */
void HAL_SIM_SCGC5_init(uint32_t bit, uint32_t clock_en)
{
    /* If it is allowed to grant clock to module */
    if(clock_en)
    {
        /* Set bit to 1 to provide clock */
        SIM->SCGC5 |= (1 << bit);
    }
    else
    {
        /* Set the bit to 0 to stop providing the clock */
        SIM->SCGC5 &= ~(1 << bit);
    }
}


/**
 * @brief function to set bit in register SCGC6
 * bits corresponding to modules
 * @param bit bit number corresponding to modules
 * @param clock_en enable/disable clock ton module
 */
void HAL_SIM_SCGC6_init(uint32_t bit, uint32_t clock_en)
{
    /* If it is allowed to grant clock to module */
    if(clock_en)
    {
        /* Set bit to 1 to provide clock */
        SIM->SCGC6 |= (1 << bit);
    }
    else
    {
        /* Set the bit to 0 to stop providing the clock */
        SIM->SCGC6 &= ~(1 << bit);
    }
}


/**
 * @brief function to set select source clock for compatible modules in SIM_SOPT2
 * @param conf_value Code corresponding to the clock source you want to select
 */
void HAL_SIM_SOPT2_init(uint32_t conf_value)
{
    /* set select source clock for compatible modules in SIM_SOPT2 */
    SIM->SOPT2 |= conf_value;
}
