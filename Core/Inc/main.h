#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER LED (LD2) Pin definition */
#define LD2_PIN                           GPIO_PIN_5
#define LD2_GPIO_PORT                     GPIOA
#define LD2_GPIO_CLK_ENABLE()            __HAL_RCC_GPIOA_CLK_ENABLE()

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
