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

## **Day 1**

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

## **Day 2**

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

## **Day 3**

* Makefile (Command line):
    * Native compilation 
        
        ```bash
        make CC=gcc
        ```
    * Cross compilation 
        
        ```bash
        make CC=arm-linux-gnueabi-gcc (32-bit)
        ```
       
        ```bash
        make CC=aarch64-none-linux-gnu-gcc (64-bit)
        ```
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

> Command to see Root File System:

```bash
ls /
```

* Root File System
    * **/bin** - Holds the binary.
    * **/sbin** - supervisor binary / privilleged binary.
    * **/dev** - holds Device Driver entry point
    * **/home** - every user has been created holds inside it.
    * **/boot** - hols information about Kernel itself.
    * **/root** - user which is super user is also called as root. It is highest privilleged user 
    * **/etc** - all the configuration details about linux is stored
    * **/var** - A lots of login information is stored & application data is also stored in some cases
    * **/proc** - when the system boots up all the runtime information is stored for kernel as well as for processes. Its a virtual file system.

* How to extract .rar files
    ```bash
    unrar e file_name.rar 
    ```
* Command to see the bianry file
    ```bash
    binwalk -e file_name.bin 
    cd squashfs-root/
    ```

* Some usefull commands
    ```bash
    ps -el  # To see the current process
    pstree  # To see the process tree
    ```

* man pages
    ```bash 
    man 1 ps     # To see the current process
    man -k pid   # For the Process ID
    man 2 getpid # to get the Process ID
    ```

* Process ID (PID)
    * getpid()
        * man -k pid
        * man 2 getpid
    * getppid()
        * man -k ppid
        * man 2 getppid
    
    ```bash
    ps  # To see the Parent process which is bash / terminal.
    ```

* **Process Control Block (PCB)** - data structure created by OS to store information of runnig task / Process such as: 
    * PID
    * Base address of the Process
    * Size of the Address Space

* **Library Calls** 
    * printf(), scanf()
    * gets(), puts()
    * getc(), putc()
    * fgetc(),fputc()
    * fgets(), fputs()
    * fopen(), fclose()
    * fread(), fwrite()

* **System Calls**
    * open()
    * read()
    * write()
    * close()

> Strace : utility to trace system calls

```bash
strace   # To see which system calls are used to perform library calls
```

* Differentiated between library & system calls

#### **Dynamic Library**

* **archive:** ".a" is collection of intermediate object files (or .o files)which contains the defination of the function. 

* How to extract archive library file
    ```bash
    find /usr/lib -name libc.a  # To find the library 
    cp /usr/lib/x86_64-linux-gnu/libc.a libc_user/ # To copy library to user directory
    ar --help  # To extract archive file 
    ar -x libc.a # To get all the object files from library
    objdump -S strlen.o
    objdump -S strcpy.o
    objdump -S strcpy.o
    objdump -S printf.o
    objdump -S scanf.o
    ```

* **libc:** is standard library of ANSI Standard.

* **Reverse Engineering** 
    * Disassembly
        
        ```bash
        arm-linux-gnueabi-objdump -S main.o  # disassembly of ARM 
        arm-linux-guneabi-objdump -S main | more  # disassembly of ARM with extra options
        ```

* Shell
    * Command line
    *  Parsing
    * Built-in Commands
    * Shell Scripts


* User & Groups 
    * User
        * User ID
        *  Group ID
        * User Name
        * Group Name
        * Home Directory
        * Shell
    * Groups
        * Group ID
        * Group Name
        * Group Members

* Superuser 

---

## **Day 4**

* Library
    * Static Libraries
        * .a

    * Dynamic Libraries aka Shared Libraries
        * Windows => .dll
        * Linux => .so

    * Standard Library
        * GCC -> libc.a / libc.so
        * Bundled as part of compiler / toolchain
        * ANSI
        * eg. printf(), scanf(), strcpy(), strlen(), fopen() 

    * User Library / Third Party Library
        * App Developer
        * eg. Your own arith functionality, mp3 decoding library

* Archive command to create and extract libraries
    ```bash
    ar crv  # To create library
    ar x    # To extract library 
    ``` 

* Command to compile Dynamic Libraries
    ```bash
    gcc -o projbin project.o -L. larith 
    export LD_LIBRARY_PATH=. # To say dynamic library (or .so file) is present in current directory
    ./projbin # Then execute
    ```
* Command to see disassembly of static & dynamic library

    ```bash
    objdump -S staticlib/arithlibUser/projbin | more
     # To see the disassembly of different sections. for static library
    objdump -S dynamiclib/arithlibUser/projbin | more
     # To see the disassembly of different sections. for dynamic library
    ```
* System Calls:
    * open
    * write 
    * read
    * close
* File descriptor (fd)
    * Reserved File descriptor 
        * fd = 0 --> stdinput
        * fd = 1 --> stdout
        * fd = 2 --> stdinput
    * Unreserved File descriptor 
        * fd = 3 onwards.......

* Explore 
    * return values of read & write system calls
    * return values of open & close system calls

---

## **Day 5**

* CPU (Uniprocessor)
    * Physical Hardware
        * PC
        * SP
        * GPR
        * Flags
* One CPU:
    * One Process at any given instance
    * Multiple Process

* Memory
    * Each process given a separate address space
    * Address Space is divided into two parts :
        1. User Address Space
        1. Kernel Address Space
    * Each address space is divided into 5 sections :
        * text
        * data
        * bss
        * heap
        * stack
* Context (Context of process)
    * Contents of the registers PC, SP, GPR, FLags
    * Context Saving
        * Physical registers to logical copy
    * Context Restoring
        * Logical copy to physical registers
    * Context Switching
        * Save the current context
        * Scheduling
        * Switch the new context

    ```bash
    kill --help  # Kill command to stop running process.
    kill -l  # List all the signals that are avialble.
    killall -9 vlc # Kill signal to that
    ```
* Process State Diagram
    * New
    * Ready 
    * Runnig
    * Wating / Blocked
    * Terminated / Exit

* Utility to change file permission

    ```bash
    chmod 777  # read, write & excute (rwx_rwx_rwx) for Root, User, Group.

    chmod 766  # read, write & execute for Root & read & write for User & group (rwx_rw_ rw_).

    chmod 666  # read & write for all three Root, User, Group (rw_ rw_ rw).

    sudo chown vishu:vishu syscalls/syscalldemo/desdlog.txt
    ```
---

## **Day 6**
### Operating System Types
* Batch System
* Multi User System
* Multi Programing
* Multi Tasking System
* Multi Processing System
* Multi Threading System
 

### Process Scheduling
* Round Robin
* Priority
* FIFO
* Shortest Job First

#### Priority Based Scheduling
* Preemptive Scheduling
* Non-Preemptive Scheduling

#### Shortest Job First
* Preemptive Scheduling
* Non-preemptive Scheduling

* Response Times
* Throughput

### Fork
* Zombie Process
* Orphan Process
* Child inherits file descriptor from the parent


### **Docker Installation & Setup:**

* #### **Installation** 
    ```bash
    sudo apt  install docker.io 
    ```
* #### **Setup**
    ```bash
    docker --version # To check version of docker
    sudo systemctl status docker # To check status of docker 
    sudo systemctl enable --now docker # To enable docker if disable previously
    sudo systemctl status docker # To check status of docker again
    ```
* #### **How to test Docker**
    ```bash
    sudo docker run hello world # To test docker is running
    sudo docker images # To see available images
    ```
    
* ### **EMUX (formerly ARMX) Firmware Emulation Framework**
    ![EMUX logo](https://github.com/therealsaumil/emux/raw/master/docs/img/ARMX-EMUX.png)

* With the addition of MIPS, ARMX has changed its name to EMUX! Try out the Damn Vulnerable MIPS Router exercises included with the new EMUX Docker image.

    ![Welcome, MIPS](https://github.com/therealsaumil/emux/raw/master/docs/img/emux-docker-whale2.jpg)

* ### **EMUX installation & Setup**

    * ### **Installation**
        
        * ### **Step 1 - Clone this repository**
            ```bash
            git clone --depth 1 --single-branch  https://github.com/therealsaumil/emux.git
            ```
        * ### **Step 2 - Build the docker volume and image**
            ```bash
            sudo su
            cd emux
            ./build-emux-volume
            ./build-emux-docker
            ```
        * ### **Step 3 - Run EMUX!**
        * Open a new terminal, and start the emux-docker container:
            ```bash
            sudo su
            cd emux
            ./run-emux-docker
            ```
        * You will be greeted with a purple shell   prompt [EMUX-DOCKER 🐳:~$]. After a while, it is common to have many terminals attached to the container. Coloured shell prompts makes it easy to remember where you are.

        * Next, start the EMUX launcher:
            ```bash
            [EMUX-DOCKER 🐳:~$] launcher
            ```

            ![Launcher image](https://github.com/therealsaumil/emux/raw/master/docs/img/01-emux-launcher.png)

            ```bash
            MIPSX login: root
            ```
            ![WiFi Router Console](https://user-images.githubusercontent.com/87055637/173280112-579c5244-5bd2-4b80-80a7-34cf44535908.png)

        * and select any emulated device that you wish to run from above list.

            ![Screenshot of WiFi router Console](https://user-images.githubusercontent.com/87055637/173280611-3db9db7b-bee4-4dbc-afad-a2321ec5a2c8.png)

        * Now you will get the above console.        

        * ### **Step 4 - Launch the emulated device's userland processes.**
        * Next, open a new terminal and attach to the running emux-docker container:
            ```bash
            sudo su
            cd emux
            ./emux-docker-shell
            ```

            ![Userland Process](https://user-images.githubusercontent.com/87055637/173280847-80a2dd27-e2fe-479b-ba80-e65e81fbf70a.png)
        

        * All attached container shells have a blue shell prompt. Invoke the userspace command to bring up the userland processes of the emulated target:
            ```bash
            [emux-docker shell 🐚:~$] userspace
            ```

            ![Userspace launcher](https://user-images.githubusercontent.com/87055637/173280112-579c5244-5bd2-4b80-80a7-34cf44535908.png)

        * Select one of the avialble option.

            ![Screenshot of WiFi router Console](https://user-images.githubusercontent.com/87055637/173280611-3db9db7b-bee4-4dbc-afad-a2321ec5a2c8.png)

        * Now you are inside WiFi Router console.

        * For more information click on the link:
        [EMUX](https://github.com/therealsaumil/emux)        
        
---

## **Day 7**
### Interprocess Communication

* Pipes
    * Unidirectional
    * Related Processes
    * Data is Sequetial
    * pipe, read, write, close
* FIFO aka Named Pipes
    * Unidirectional
    * Unrelated Processes
    * Data is Sequential
    * open, read, write, close 

* ### **Assignment**

    1. Write your own utility using system calls (open, read, write, close) to copy data from one file to another file. Essentially you are implementing a copy utility. Fullfledged utility should support the following options:
        
        * Handling all the errors
        * cp srcfile destfile

    1. Write your own utility using library calls (fopen, fread, fwrite, fclose) to copy data from one file to another file. Essentially you are implementing a copy utility. Fullfledged utility should support the following options:
        
        * Handling all the errors
        * cp srcfile destfile
    
    1. Research 
        * Which of the following programs took more time to copy file
            1. Small ->  1 MB file
            1. Medium -> 100 MB file
            1. Large ->  1 GB 

    * Utilities Names
        * cps (copy using system call)
        * cpl (copy using library call)

    * Justify your result => Why does system call / library call takes time to copy file.

---

## Day 8

### Process Managment:-
  1. Manage Process:-
        * Create (or New)
        * Ready
        * Running
        * Waiting
        * Exit
  2. Scheduling
        * Context Save
        * Scheduling
        * Context Restore
  3. Synchronisation
        * Wating for Some Condition to meet
  4. IPC (Inter Process Communication)
        * PIPE
        * FIFO
        * Message Queue
        * Shared Memory

### POSIX Thread
  1. pthread_create
  2. pthread_join

### Threads
  1. Joinable Thread
  2. Detachable Thread

### Opaque Data Type ("_t")
  1. Set
  2. Get
   
Before you start using opaque data type:-
1. initialize
2. set
3. get
4. use and
5. destroy after use

    ```bash
    pthread_attr_init()             # Initialize
    pthread_attr_setdetachstate()   # Set
    pthread_attr_destroy()          # Destroy
    ```

### Thread Attributes

1. pthread_attr_t                  
2. pthread_attr_init();             
3. pthread_attr_setdetachstate();   
4. pthread_attr_destroy()
5. Scope
6. Inherit Scheduling
7. Scheduling Parameters (like priorities etc)
8. Satck & Stack Size

```bash
pthread_attr_t                   # Thread Attributes
pthread_attr_init();             # Thread init
pthread_attr_setdetachstate();   # Thread set
pthread_attr_destroy()           # Thread Destroy 
```
### Threads
- Threads are light weight process
- TCB (Thread Control Block)
- Threads share the following sections with process
    - Text
    - Data
    - Bss
    - Heap
- Threads don't share the following sections with process
    - Satck
    - means that each threads has its own stack

### Difference b/w Function & Thread

|   Funtion     |   Thread      |
|   ----------  |   ----------  |
|   Sequential  |   Concurent   |

### Resource
- Anything that is used by Thread or a Process is called resource. 
- Shared resource
  - Resource that is shared between Threads / Processes.
  - Race condition => Data corruption