#Josh Mulyadi
# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE.
.file "analyze.s"
.section .rodata
.data
    .align 16
.text
.globl analyze
    .type analyze, @function
analyze: 
    #stack frame set up
    pushq %rbp
    movq %rsp, %rbp
    #%rdi first register has int value 32 bits
    #%rsi # second has int count 
    #%rdx # third has int array[]
    #%rcx # fourth has int *min_ptr
    #%r8 # fith has int *max_ptr
    # free caller %r9, %r10, %r11
    #make rsi one less for indexing
    dec %rsi
    #set r9 and r10 to the first value in the array
    movq (%rdx, %rsi, 4), %r9 
    movq %r9, %r10 
    #r9 is min r10 is max
    #set rax to 0
    movq $0, %rax
    # decrement again bc we put the last value in r9 and r10
    dec %rsi
    #start of loop
    loop: 
        #get the array value at the current index
        movq (%rdx, %rsi, 4), %r11 
        #see if current val is our target
        cmp %edi, %r11d 
        je setRet
        # max stuff
    min: 
        # check if value in array is less then value
        cmp %r9d, %r11d
        jl setMin
    max: 
        # check if value in array is greater then value
        cmp %r10d, %r11d
        jg setMax
    checkLoop:
        # decrements and loops again
        dec %rsi
        # checks is rsi is negative and end if it is
        js done
        #restart loop
        jmp loop
    #part for return value
    setRet: 
        #set rax to the correct return value
        leaq (%rdx, %rsi, 4), %rax
        jmp min
    setMin:
        #set min value
        movl %r11d, %r9d
        jmp checkLoop
    setMax:
        #set max value
        movl %r11d, %r10d
        jmp checkLoop

    done: 
        # mov the correct values into rcx and r8
        movl %r9d, (%rcx)
        movl %r10d, (%r8) 
        #restore the stack frame
        leave
        #get out
        ret
    .size analyze, .-analyze 
