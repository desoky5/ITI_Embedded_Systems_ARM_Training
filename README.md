# ITI ARM Training

Driver development and coursework for the ITI ARM (STM32) Embedded Systems Diploma.
Companion repo to [`ITI_embedded_AVR_training`](https://github.com/desoky5/ITI_embedded_AVR_training).

[![GitHub](https://img.shields.io/badge/GitHub-desoky5-181717?logo=github)](https://github.com/desoky5)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-0A66C2?logo=linkedin)](https://www.linkedin.com/in/omardesoky5/)

---

## Table of Contents

- [Overview](#overview)
- [Architecture](#architecture)
- [Module Naming Convention](#module-naming-convention)
- [Toolchain](#toolchain)
- [Repository Structure](#repository-structure)
- [Getting Started](#getting-started)
- [Commit Convention](#commit-convention)
- [Progress Log](#progress-log)
- [Author](#author)

---

## Overview

This repository tracks driver-level and application-level development completed during the ITI ARM Embedded Systems Diploma, built around the STM32F4 series. It follows a layered architecture — the same discipline used in the AVR diploma — to keep peripheral drivers, hardware abstraction, and application logic cleanly separated and independently testable.

## Architecture

```
APP     Application layer      - task/business logic, calls HAL/MCAL
HAL     Hardware Abstraction   - device-level drivers built on MCAL (e.g. LCD, keypad, external ICs)
MCAL    Microcontroller Layer  - on-chip peripheral drivers (GPIO, RCC, NVIC, SysTick, UART, SPI, DMA, ADC, DAC, EXTI...)
LIB     Shared library         - STD_TYPES, BIT_MATH, common macros, used by every layer
```

Each layer is a flat folder — headers and source files live together, no `Inc`/`Src` subdivision.

## Module Naming Convention

Each driver module follows a 3-file split, consistent with the AVR diploma repo:

| File            | Purpose                                                    |
|-----------------|--------------------------------------------------------------|
| `<MOD>_cfg.h`   | Configuration (init-time parameters, selectable options)    |
| `<MOD>_int.h`   | Public interface (prototypes, macros, types)                 |
| `<MOD>_prg.c`   | Implementation                                                  |

Prefix indicates the owning layer:
- `M` prefix → MCAL (e.g. `MGPIO_int.h`, `MRCC_prg.c`)
- `H` prefix → HAL (e.g. `HLCD_int.h`)
- No prefix → APP

## Toolchain

- Eclipse-based STM32 SDK (SW4STM32 / AC6)
- Target: STM32F4 series
- GNU ARM Embedded Toolchain (arm-none-eabi-gcc)

## Repository Structure

```
ITI_ARM_training/
├── APP/          Application logic
├── HAL/          Hardware abstraction drivers
├── MCAL/         On-chip peripheral drivers
├── LIB/          Shared types and macros (STD_TYPES.h, BIT_MATH.h)
├── Inc/          Eclipse SDK generated headers
├── Src/          Eclipse SDK generated sources (main.c, startup, etc.)
├── Drivers/      Eclipse SDK generated CMSIS / HAL drivers
├── .project / .cproject   Eclipse project configuration
├── .gitignore
└── README.md
```

## Getting Started

1. Clone the repository:
   ```bash
   git clone https://github.com/desoky5/ITI_ARM_training.git
   ```
2. Import into Eclipse: `File → Import → Existing Projects into Workspace`, select the cloned folder.
3. Add each layer folder to the include path so `#include "MGPIO_int.h"` resolves from anywhere:
   `Project → Properties → C/C++ General → Paths and Symbols → Includes` → add `APP`, `HAL`, `MCAL`, `LIB`.
4. Build and flash using your configured ST-Link setup.

## Commit Convention

Conventional commits, one layer or concern per commit:

```
feat(mcal): add GPIO driver skeleton
feat(lib): add STD_TYPES and BIT_MATH
fix(mcal): correct AFRL/AFRH split logic in GPIO
docs: update README with RCC module notes
chore: add gitignore
```

Always **Clean + Rebuild** before flashing after any MCAL/HAL change.

## Progress Log

| Module      | Layer | Status       |
|-------------|-------|--------------|
| GPIO        | MCAL  | In progress  |
| RCC         | MCAL  | Not started  |
| NVIC        | MCAL  | Not started  |
| SysTick     | MCAL  | Not started  |

## Author

**Omar Desoky**
Mechatronics & Robotics Engineering — Egypt-Japan University of Science and Technology (E-JUST)

[GitHub](https://github.com/desoky5) · [LinkedIn](https://www.linkedin.com/in/omardesoky5/)
