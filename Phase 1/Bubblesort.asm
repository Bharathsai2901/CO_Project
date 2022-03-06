.data
arr:  .word  60,50,40,30
.text
.global main
main:
    Li  x2,0
    Li  x3,0
    JAL loop1
loop1:
    Li  x3,0
    Li  x4,0
    BEQ x2,x30,exit
    JAL  loop2
loop2:
    LW  x0,x3(arr)
    ADDI x4,x3,4
    LW  x1,x4(arr)
    BGE  x0,x1,swap
    ADDI x3,x3,4
    BGE  x31,x3,loop2
    ADDI  x2,x2,1
    JAL  loop1
swap:
    SW  x0,x4(arr)
    SW  x1,x3(arr)
    ADDI x3,x3,4
    BGE  x31,x3,loop2
    ADDI x2,x2,1
    JAL loop1
exit:
exit
