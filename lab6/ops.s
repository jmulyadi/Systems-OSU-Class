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

# function directives

.globl plus
    .type plus, @function
# add function
plus:
    #make stack frame
    pushq %rbp 
    movq %rsp, %rbp
    #set rax to 0
    movq $0, %rax
    #mov one of the things into rax
    movl %esi, %eax
    # add the other parameter
    addl %edi, %eax
    #leave
    leave
    #get out
    ret

    .size plus, .-plus 

# function directives

.globl left_shift
    .type left_shift, @function

left_shift:
    #make stack frame
    pushq %rbp 
    movq %rsp, %rbp
    #put rdi into rax
    movq %rdi, %rax
    #move amount shifted into cl
    movb %sil, %cl    
    #shift it 
    sall %cl, %eax
    #leave 
    leave
    #get out
    ret
    .size left_shift, .-left_shift 

# function directives

.globl times
    .type times, @function
times:
    #make stack frame
    pushq %rbp 
    movq %rsp, %rbp
    #set rax to 0
    movq $0, %rax
    #mov one of the things into rax
    movl %esi, %eax
    # multiply the other parameter
    imul %edi, %eax
    #leav
    leave
    #get out
    ret

    .size times, .-times 

# function directives

.globl divide
    .type divide, @function
divide:
    #make stack frame
    pushq %rbp 
    movq %rsp, %rbp
    #set rax to 0
    movq $0, %rax
    #move first parameter into eax
    movl %edi, %eax
    #trashes edx
    cltd
    # divied
    idivl %esi
    #leave
    leave
    #get out
    ret
    .size divide, .-divide 
