# Embedde Operating System (EOS)

> ### *Embedded System is a system that perform dedicated task.*

* *for more info click on link:*
[Embedded System Definition](https://www.heavy.ai/technical-glossary/embedded-systems "HEAVI.AI")

---

> _Embedded Operating System is a type of Operating System that perform various managment activity such as:_
1. _Process Managment_
1. _Memory Managment_
1. _Input Output Managment_

* for more info click on the link: 
[EOS Definition](https://www.javatpoint.com/embedded-operating-system "JavaPoint.com")

___

## Day 1 

* **2 Tier & 3 Tier Embedded System**
* **Hardware**
    * CPU 
        * PC/IP
        * GPRs (R0-R12)
        * Flags
        * Stack Pointer (MSP & PSP)
    * Memory
        * Code 
        * Data
    * Peripherals
        * GPIO
        * On Board Peripherals
        * External Peripherals

* **Bare Metal System**
* **SP, SF, Stack**
    * **SP** - Register inside CPU -> Pointing to the top of Stack.
    * **Stack** - Chunk of memory.
    * **SF** - Frame created on the stack when you call a function & Deleted when you return from the function.
* **Frame Pointer** - Points to the base of frame.
* How are arguments pass to the function ?
    * on the Stack
    * on the Register

---

## Day 2

* **Booting procedure**
    * ROM BL (ROM Bootloader)
    * PBL (Primary Bootloader)
    * SBL (Secondary Bootloader)
        * Uboot
        * GRUB
    * Kernel
        * Linux
    * RFS (Root File System)
        * Build root

* **Makefile** -> _Makefile is a file where you define how the build process has to happen. It takes source code as input and generates the binaries that are required to excuite._

    * **make** - _make is a utility which helps you to compile and build the Project._
    * **make clen** - _is a another utility which helps you to clear the intermediate files and old excuitables._
    * make utilites _reads the data or rules from the file called as Makefile._

---

## Day 3

* Makefile (Command line):
    * Native compilation 
        * make CC=gcc
    * Cross compilation 
        * make CC=arm-linux-gnueabi-gcc (32-bit)
        * make CC=aarch64-none-linux-gnu-gcc (64-bit)

* ARM cross toolchain
    * **Build System** - where toolchain is compiled.
    * **Host System** - where application is compiled.
    * **Target System** - where binary / execuitable run.

* Uboot
* Program
    * Program sections:
        * **Stack** - function arguments, return address, local variables.
        * **Heap** - run time allocation or dynamic memory allocation. 
        * **.bss** - uninialised global variables
        * **.data** - initialised global variable
        * **.text / .code** - contains set of instructions.

* Address Space
* Program vs Process
* **Program** - Dorment entity
    * Execuitable / Binary
    * Compiled
* **Process** - Active entity
    * Thread
    * Process / Task - Program under execution

* **Operating System:**

    * Process Managment
    * Memory Managment
    * I/O Managment
        * Device Drivers
        * File System
        * Networking
        * GUI

* Kernel Mode vs User Mode
    * Kernel Mode / Supervisor Mode
        * Kernel Space
        * Kernel Heap
        * Kernel Stack
    * User Mode
        * User Space
        * User Heap
        * User Stack



