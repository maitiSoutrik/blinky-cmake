set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)

# Find arm-none-eabi toolchain
find_program(ARM_TOOLCHAIN_PATH arm-none-eabi-gcc)
if(NOT ARM_TOOLCHAIN_PATH)
    message(FATAL_ERROR "arm-none-eabi-gcc not found in PATH")
endif()
get_filename_component(ARM_TOOLCHAIN_DIR ${ARM_TOOLCHAIN_PATH} DIRECTORY)

# The toolchain prefix for all toolchain executables
set(TOOLCHAIN_PREFIX arm-none-eabi-)

# specify the cross compiler
set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}g++)
set(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}objcopy)
set(CMAKE_SIZE ${TOOLCHAIN_PREFIX}size)

set(CMAKE_FIND_ROOT_PATH ${BINUTILS_PATH})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Prevent CMake from testing the compiler
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)
