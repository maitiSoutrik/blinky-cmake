#ifndef __CORE_CM4_H_GENERIC
#define __CORE_CM4_H_GENERIC

#include <stdint.h>

#define __IO volatile
#define __I volatile const
#define __O volatile

typedef struct {
    __IO uint32_t CTRL;
    __IO uint32_t LOAD;
    __IO uint32_t VAL;
    __I  uint32_t CALIB;
} SysTick_Type;

#define SCS_BASE            (0xE000E000UL)
#define SysTick_BASE        (SCS_BASE +  0x0010UL)
#define SysTick             ((SysTick_Type *)     SysTick_BASE  )

#endif
