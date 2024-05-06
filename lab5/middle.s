#Josh Mulyadi
# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE.

.file "middle.s"
.section .rodata
.data
    .align 16
.text
.globl middle
    .type middle, @function
.print1:
    #needs value in rsi and count in rdx
    .string "Middle: Looking for %d in array of %d ints\n"
.print2:
    #needs min in rsi and max in rdx, rval in rax
    .string "Middle: min is %d, max is %d, pointer is %p\n"
middle:
    #set stackframe up
    pushq %rbp
    movq %rsp, %rbp
    pushq %rbx #min
    pushq %r12 #max
    pushq %r13 #value
    pushq %r14 # count
    pushq %r15 # array
    #make space for local variables and keep it on a 16 byte boundary
    subq $24, %rsp
    #rdi holds value
    #rsi holds count
    #rdx holds array
    cmp $0, %esi
    jle done
    # allocate memory for variables
    leaq (%rsp), %rbx
    leaq 8(%rsp), %r12
    #save stuff I need
    movq %rdi, %r13
    movq %rsi, %r14
    movq %rdx, %r15
    #get parameters ready for first print
    movq $.print1, %rdi
    movq %r13, %rsi
    movq %r14, %rdx
    call print
    #get parameters ready for analyze call
    movq %r13, %rdi    
    movq %r14, %rsi    
    movq %r15, %rdx
    movq %rbx, %rcx
    movq %r12, %r8
    call a_shim 
    #get parameters ready for second print
    movq $.print2, %rdi
    movq (%rbx), %rsi
    movq (%r12), %rdx   
    movq %rax, %rcx   
    #save rax value
    movq %rax, %rbx
    call print
done:
    //get the correct return value
    movq %rbx, %rax 
    #get rid of local storage space
    addq $24, %rsp
    #pop stuff to restore stack
    popq %r15
    popq %r14
    popq %r13
    popq %r12
    popq %rbx
    #restore stack
    leave
    # current s
    ret 
.size middle, .-middle 
