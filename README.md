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
___
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
___
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
___

* ARM cross toolchain
