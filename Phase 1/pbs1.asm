.data
arr: .word 50,40,10
.text
.global main
main:
    ADDI     x3,x3,3
    ADDI     x4,x4,3
for:
    BEQ     x2,x3,lab1
    LW      x1,0(arr)
for1:
    BEQ    x5,x4,lab2
    MULI   x16,x5,4
    LW     x30,x16(arr)
    SGT    x29,x30,x1
    ADD     x11,x10,x5
    ADDI    x5,x5,1
    JAL    for1
lab2:
    ADDI x5,x0,0
    SUBI  x3,x3,1
    MULI x16,x3,4
    LW  x30,x16(arr)
    SW x30,x29(arr)
    SW x1,x16(arr)
    SUBI x4,x4,1
    JAL    for
exit
lab1:
  ADDI    x6,x1,10
exit