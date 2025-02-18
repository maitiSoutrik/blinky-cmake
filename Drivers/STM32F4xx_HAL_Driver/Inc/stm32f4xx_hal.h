#ifndef __STM32F4xx_HAL_H
#define __STM32F4xx_HAL_H

#include "stm32f446xx.h"

typedef enum {
    HAL_OK = 0x00U,
    HAL_ERROR = 0x01U,
    HAL_BUSY = 0x02U,
    HAL_TIMEOUT = 0x03U
} HAL_StatusTypeDef;

#define GPIO_PIN_5                 ((uint16_t)0x0020)
#define GPIO_MODE_OUTPUT_PP        0x1UL
#define GPIO_MODER_MASK            0x3UL
#define GPIO_MODE_MASK             0x3UL

#define SET_BIT(REG, BIT)         ((REG) |= (BIT))
#define READ_BIT(REG, BIT)        ((REG) & (BIT))
#define UNUSED(X)                 (void)X

typedef struct {
    uint32_t Pin;
    uint32_t Mode;
    uint32_t Pull;
    uint32_t Speed;
} GPIO_InitTypeDef;

typedef struct {
    uint32_t OscillatorType;
    uint32_t HSEState;
    uint32_t HSIState;
    uint32_t HSICalibrationValue;
    struct {
        uint32_t PLLState;
        uint32_t PLLSource;
        uint32_t PLLM;
        uint32_t PLLN;
        uint32_t PLLP;
        uint32_t PLLQ;
        uint32_t PLLR;
    } PLL;
} RCC_OscInitTypeDef;

typedef struct {
    uint32_t ClockType;
    uint32_t SYSCLKSource;
    uint32_t AHBCLKDivider;
    uint32_t APB1CLKDivider;
    uint32_t APB2CLKDivider;
} RCC_ClkInitTypeDef;

#define RCC_OSCILLATORTYPE_HSI     0x00000002U
#define RCC_HSI_ON                 0x00000001U
#define RCC_HSICALIBRATION_DEFAULT 0x10U

#define __disable_irq()                __asm volatile("cpsid i" : : : "memory")
#define __enable_irq()                 __asm volatile("cpsie i" : : : "memory")
#define RCC_PLL_ON                 0x00000002U
#define RCC_PLLSOURCE_HSI         0x00000000U
#define RCC_CLOCKTYPE_HCLK        0x00000002U
#define RCC_CLOCKTYPE_SYSCLK      0x00000001U
#define RCC_CLOCKTYPE_PCLK1       0x00000004U
#define RCC_CLOCKTYPE_PCLK2       0x00000008U
#define RCC_SYSCLKSOURCE_PLLCLK   0x00000002U
#define RCC_SYSCLK_DIV1           0x00000000U
#define RCC_HCLK_DIV2            0x00000080U
#define RCC_HCLK_DIV4            0x00000090U
#define FLASH_LATENCY_5           0x00000005U

HAL_StatusTypeDef HAL_Init(void);
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency);
HAL_StatusTypeDef HAL_PWREx_EnableOverDrive(void);
void HAL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_Init);
void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void HAL_Delay(uint32_t Delay);

#define __HAL_RCC_PWR_CLK_ENABLE()
#define __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1)
#define __HAL_RCC_GPIOA_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg = 0x00U; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);\
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);\
                                        UNUSED(tmpreg); \
                                          } while(0U)

#define GPIO_SPEED_FREQ_LOW        0x00000000U
#define GPIO_NOPULL               0x00000000U

#endif
