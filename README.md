# Next OS

[한국어 README](docs/README.KO.md)

**A custom operating system built with C++ and Assembly.**

Next OS is an operating system project developed from scratch, beginning with the boot process and kernel. The long-term goal is to build a lightweight, practical OS with its own native APIs, graphical interface, application system, and scripting environment.

> **Status:** Early development. Some features described below are planned and have not been implemented yet.

## Goals

- Develop the kernel and core system components from the ground up.

- Maintain an understandable, modular, and efficient architecture.

- Build a desktop environment, window system, settings, file manager, and basic applications.

- Develop **ILScript**, a planned scripting system for OS automation, system control, and application development.

- Add native application execution and package management.

- Design an update and recovery system that protects user data and supports rollback.

- Research Linux and Windows application compatibility as long-term goals.

These are project goals, not claims that all listed features are currently available.

## Technology Stack

| Technology           | Purpose                           |
| -------------------- | --------------------------------- |
| C++                  | Kernel and system development     |
| Assembly             | Boot code and low-level CPU setup |
| GRUB                 | Bootloader                        |
| Docker               | Development environment           |
| Make                 | Build automation                  |
| NASM                 | Assembly                          |
| x86_64 ELF toolchain | Cross-compilation and linking     |
| QEMU                 | Virtual-machine testing           |

## Project Structure

```text
next-os/
├── src/
│   ├── boot.asm
│   ├── kernel.cpp
│   ├── keyboard.cpp
│   ├── keyboard.h
│   ├── types.h
│   ├── vga.cpp
│   ├── vga.h
│   └── linker.ld
├── build/
├── grub.cfg
├── Makefile
├── Dockerfile
├── build.bat
├── README.md
└── README.ko.md
```

The `build/` directory contains generated build artifacts. Its contents may change during development.

## Current Features

- GRUB-based kernel boot

- Initial x86-64 boot setup and long-mode transition

- Initial page-table setup for early memory mapping

- C++ kernel entry point

- VGA text-mode output

- Basic keyboard input

- Shift state handling

- Caps Lock and Num Lock state handling

- Caps Lock and Num Lock LED control

- Basic keypad input

- Backspace handling

Keyboard input and other low-level systems are still under development.

## Roadmap

1. Complete keyboard special-key handling

2. Inspect the memory map and implement memory management

3. Add interrupts and a timer

4. Implement processes, threads, and scheduling

5. Add system calls and disk access

6. Implement a filesystem and program loader

7. Develop the native API

8. Build the graphical interface and input system

9. Develop the application system and ILScript

10. Design update and recovery mechanisms

11. Research Linux and Windows application compatibility

The roadmap is tentative and may change as the project evolves.

## Source Comments and Documentation

Source-code comments and development notes are currently written mainly in Korean.

English comments will be added progressively while retaining Korean comments where useful. The goal is to make the code easier to understand and maintain for both Korean-speaking and English-speaking developers. Existing comments will not be translated indiscriminately; changes will prioritize clarity and maintainability.

The primary README is written in English. The Korean version is available in [`README.ko.md`](https://chatgpt.com/c/README.ko.md).

## Development Principles

- Implement small features incrementally.

- Test existing behavior before adding new functionality.

- Clearly distinguish implemented features from planned work.

- Record bugs and design issues and address them systematically.

- Prioritize readability, maintainability, and stability.

## Status

**Early Development**

Next OS currently focuses on kernel boot and basic input/output. The project will expand gradually as each subsystem is developed and tested.
