# STM32 Blinky Project with CMake

This is a simple blinky project for the STM32 Nucleo-F446RE board using CMake as the build system.

## Prerequisites

- ARM GCC Toolchain (arm-none-eabi-gcc)
- CMake (version 3.15 or higher)
- OpenOCD or STM32CubeProgrammer for flashing
- Make or Ninja build system

## Building the Project

1. Create a build directory and navigate to it:
```bash
mkdir build && cd build
```

2. Generate the build files:
```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

3. Build the project:
```bash
make
```

## Flashing and Debugging

### Using OpenOCD

1. Connect your Nucleo board via USB

2. Flash the program:
```bash
openocd -f board/st_nucleo_f4.cfg -c "program stm32-blinky.elf verify reset exit"
```

3. For debugging, start OpenOCD in a separate terminal:
```bash
openocd -f board/st_nucleo_f4.cfg
```

4. In another terminal, connect GDB:
```bash
arm-none-eabi-gdb build/stm32-blinky.elf
(gdb) target extended-remote localhost:3333
(gdb) monitor reset halt
(gdb) load
(gdb) continue
```

### Using STM32CubeProgrammer

1. Connect your Nucleo board via USB

2. Launch STM32CubeProgrammer

3. Click 'Connect' to establish connection with the board

4. Click 'Open file' and select the generated .elf file

5. Click 'Download' to flash the program

## Expected Behavior

The onboard LED (LD2) will blink with a 1-second period (500ms on, 500ms off).

## Troubleshooting

1. If OpenOCD fails to connect, check if:
   - The board is properly connected via USB
   - You have the necessary permissions to access the USB device
   - The correct OpenOCD configuration file is being used

2. If the LED doesn't blink:
   - Check if the board is powered
   - Verify that the program was flashed successfully
   - Try resetting the board

## Project Structure

```
.
├── CMakeLists.txt              # Main CMake configuration file
├── cmake/
│   └── arm-none-eabi-toolchain.cmake  # Toolchain configuration
├── Core/
│   ├── Inc/                    # Header files
│   ├── Src/                    # Source files
│   └── Startup/                # Startup code
└── Drivers/                    # STM32 HAL drivers
```
