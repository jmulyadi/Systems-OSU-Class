.data
    message:
        .ascii "Hello, World!\n"   # Define the message

.text
.globl _start

_start:
    # Write the message to stdout (file descriptor 1)
    movl $4, %eax       # Syscall number for sys_write
    movl $1, %ebx       # File descriptor 1 (stdout)
    movl $message, %ecx # Pointer to the message
    movl $14, %edx      # Length of the message
    int $0x80           # Call the kernel

    # Exit the program
    movl $1, %eax       # Syscall number for sys_exit
    xorl %ebx, %ebx     # Exit code 0
    int $0x80           # Call the kernel
    ret
