cmake_minimum_required(VERSION 3.15)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/arm-none-eabi-toolchain.cmake)

# Project name
project(stm32-blinky C ASM)

# Enable ASM
enable_language(ASM)

# CPU/FPU specific definitions
add_compile_definitions(
    STM32F446xx
    USE_HAL_DRIVER
)

# MCU specific flags
set(CPU_FLAGS "-mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard")
set(COMMON_FLAGS "${CPU_FLAGS} -Wall -Wextra -Wno-unused-parameter -ffunction-sections -fdata-sections")

set(CMAKE_C_FLAGS "${COMMON_FLAGS}")
set(CMAKE_ASM_FLAGS "${COMMON_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CPU_FLAGS} -Wl,--gc-sections -T${CMAKE_CURRENT_SOURCE_DIR}/STM32F446RETx_FLASH.ld -specs=nosys.specs")

# Include directories
include_directories(
    Core/Inc
    Drivers/STM32F4xx_HAL_Driver/Inc
    Drivers/CMSIS/Device/ST/STM32F4xx/Include
    Drivers/CMSIS/Include
)

# Source files
set(SOURCES
    Core/Src/main.c
    Core/Src/system_stm32f4xx.c
    Core/Startup/startup_stm32f446retx.s
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
)

# Create executable
add_executable(${PROJECT_NAME}.elf ${SOURCES})

# Post build commands to create hex and bin files
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
)
