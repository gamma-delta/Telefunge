TELEFUNGE

Concepts:
2-D grid on which a turtle crawls. Starts at (0,0) in upper right, or at @
The turtle takes a step, then reads instructions from the space it is standing on.
The turtle has a stack of ints. It has 1000 cells. For maximum turing-completeness, change to infinity.
There is also an auxillary stack like the turtle's. It is more limited (you can't do math on it for example)
They are both initialized to a lot of 0s.
The grid wraps (it is toroidial).
PLEASE PLEASE make sure that every single line is the same length! Pad with spaces if needed. It won't work otherwise.

Instuctions:
@ Start position. If there are multiples, start at the first one from upper right.
. End program

^ Turn up
> Turn right
V Turn down
< Turn left
| If first slot in the turtle stack is 0, go up; else go down
_ If first slot is 0, go right; else go left
? Turn random

# Start/stop pushing hex numbers to turtle stack (0-F)
" Start/stop pushing ASCII text to turtle stack. Formats based on \n (maybe)

+ Pop a,b from turtle; push a+b
- Pop a,b; push a-b
* Pop a,b; push a*b
/ Pop a,b; push a/b (floor)
% Pop a,b; push a%b (mod)
: Pop and display ASCII from turtle
; Pop and display number from turtle

P Pop turtle stack
p Pop aux stack
S Pop from turtle and push to aux
s Pop from aux and push to turtle
C Copy value from turtle stack and push to aux
c Copy value from aux and push to turtle
W Swap the first values of turtle and aux

T Pop a,b from turtle; teleport to those coords (a,b). If it overflows, modulus by grid size.
t Pop a,b from aux; teleport to those coords. See above.

X Turn on hexadecimal number display (with ;). On by default.
x Turn off hexadecimal display.

Everything else is ignored.
