# cps360_assignment2

### Problem:
Create 2 sets and populate them according to stdin input. Then print out
the following information for each set:
  1. Set A contents
  2. Set B contents
  3. Union of set A and B
  4. Intersection of set A and B
  5. Difference of set A and B.
  
Do this 3 times

### Solution:
Unknown at this time...

### Specifications:
1. All writes done to stderr
2. No arithmetic operators for integer division (/) and (%)
(use bitwise operations).
2. elements available at run time in stdin
3. set size: 0 - 255
4. Use bitmap
5. format of input line: ./a2 num-elements list-elements
    * e.g.
      $ ./a1 4 12 32 15 10
          - 4 elements in list consisting of 12, 32, 15, 10.
6. Sample output:
```
    Set A: 12 3 45 110 239
    Set B: 3 12 45 115 221 149
    A union B: 3 12 45 110 115 149 221 239
    A intersection B: 3 12 45
    A difference B: 110 239
```

### Turn-in:
Submit via BB zip archive globalid-a2.zip containing files
a2/Makefile and a2/a2.c
