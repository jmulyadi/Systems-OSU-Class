#Josh Mulyadi
# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE
# file directives
.file "ops.s"
.section .rodata
.data
    .align 16
.text
.print1:
    #needs value in rsi and count in rdx
    .string "%d %c %d = ...\n"
.print2:
    #needs min in rsi and max in rdx, rval in rax
    .string "...%d %c %d = %d\n\n"
# function directives

.globl do_op
    .type do_op, @function
# function 
do_op:  
    # rdi holds struct operation
    # rsi holds function pointer array 
    #rbx will hold the Operation
    #r12 will hold the function pointers
    pushq %rbp 
    movq %rsp, %rbp
    pushq %rbx
    pushq %r12
    #save rdi and rsi
    movq %rdi, %rbx
    movq %rsi, %r12
    #print question
    movq $.print1, %rdi
    #put a into rsi
    movq 8(%rbx), %rsi
    #put printable into rdx
    movq 4(%rbx), %rdx
    #put b into rcx
    movq 12(%rbx), %rcx
    # clear rax
    movq $0, %rax
    call print
    # call correct function 
    #put operation into rax
    movzwq 6(%rbx), %rax
    #put address of function into rax
    #put a and b in correct spots
    movslq 8(%rbx), %rdi
    movslq 12(%rbx), %rsi
    # call function
    call *(%r12, %rax, 8)
    #save answer
    movl %eax, (%rbx)
    #get ready for last print
    movq $.print2, %rdi
    movq 8(%rbx), %rsi
    movq 4(%rbx), %rdx
    movq 12(%rbx), %rcx
    #put correct value in
    movslq %eax, %r8
    call print
    movslq (%rbx), %rax
    # clean up
    popq %r12
    popq %rbx
    #get out
    leave
    ret
    .size do_op, .-do_op 
