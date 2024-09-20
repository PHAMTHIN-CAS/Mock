/**
 * @file MKL46Z_HAL_SIM.h
 * @author PHAM CAO THIN (phamcaothin2992000@gmail.com)
 * @brief The HAL layer header file for SIM contains prototype functions to interact with the SIM related field bits
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _INCLUDES_HAL_MKL46Z_HAL_SIM_H_
#define _INCLUDES_HAL_MKL46Z_HAL_SIM_H_
/*******************************************************************************************************************************
 * Includes
 ******************************************************************************************************************************/
#include "MKL46Z4.h"
/*******************************************************************************************************************************
 * Prototypes
 ******************************************************************************************************************************/
/**
 * @brief function to set bit in register SCGC4
 * bits corresponding to modules
 * @param bit      bit number corresponding to modules
 * @param clock_en enable/disable clock ton module
 */
void HAL_SIM_SCGC4_init(uint32_t bit, uint32_t clock_en);


/**
 * @brief function to set bit in register SCGC5
 * bits corresponding to modules
 * @param bit      bit number corresponding to modules
 * @param clock_en enable/disable clock ton module
 */
void HAL_SIM_SCGC5_init(uint32_t bit, uint32_t clock_en);


/**
 * @brief function to set bit in register SCGC6
 * bits corresponding to modules
 * @param bit bit number corresponding to modules
 * @param clock_en enable/disable clock ton module
 */
void HAL_SIM_SCGC6_init(uint32_t bit, uint32_t clock_en);


/**
 * @brief function to set select source clock for compatible modules in SIM_SOPT2
 * @param conf_value Code corresponding to the clock source you want to select
 */
void HAL_SIM_SOPT2_init(uint32_t conf_value);

#endif /* _INCLUDES_HAL_MKL46Z_HAL_SIM_H_ */
