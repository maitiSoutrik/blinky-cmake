#ifndef __STM32F446xx_H
#define __STM32F446xx_H

#include "core_cm4.h"

typedef struct {
    __IO uint32_t MODER;
    __IO uint32_t OTYPER;
    __IO uint32_t OSPEEDR;
    __IO uint32_t PUPDR;
    __IO uint32_t IDR;
    __IO uint32_t ODR;
    __IO uint32_t BSRR;
    __IO uint32_t LCKR;
    __IO uint32_t AFR[2];
} GPIO_TypeDef;

typedef struct {
    __IO uint32_t CR;
    __IO uint32_t PLLCFGR;
    __IO uint32_t CFGR;
    __IO uint32_t CIR;
    __IO uint32_t AHB1RSTR;
    __IO uint32_t AHB2RSTR;
    __IO uint32_t AHB3RSTR;
    uint32_t RESERVED0;
    __IO uint32_t APB1RSTR;
    __IO uint32_t APB2RSTR;
    uint32_t RESERVED1[2];
    __IO uint32_t AHB1ENR;
    __IO uint32_t AHB2ENR;
    __IO uint32_t AHB3ENR;
} RCC_TypeDef;

#define PERIPH_BASE           0x40000000UL
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800UL)

#define GPIOA                 ((GPIO_TypeDef *) GPIOA_BASE)
#define RCC                   ((RCC_TypeDef *) RCC_BASE)

#define RCC_AHB1ENR_GPIOAEN_Pos             (0U)
#define RCC_AHB1ENR_GPIOAEN_Msk             (0x1UL << RCC_AHB1ENR_GPIOAEN_Pos)
#define RCC_AHB1ENR_GPIOAEN                 RCC_AHB1ENR_GPIOAEN_Msk

#endif
