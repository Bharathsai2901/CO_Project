.data
arr:  .word  6,5,4,3,2
.text
.global main

main:
      Li  x5,7
      ADDI x1,x2,5
      ADDI x2,x1,10
      ADD x3,x2,x1
      SUBI x4,x3,15 
      ADD  x1,x1,x2
      LW   x1,8(arr)
      SW   x1,20(arr)
exit