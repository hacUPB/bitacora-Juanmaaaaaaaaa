//Retos

//Reto 1

@1
D=A
@i
M=D

@0
D=A
@sum
M=D

(LOOP)

@i
D=M
@100
D=D-A
@END
D;JGT

@sum
D=M
@i
D=D+M
@sum
M=D

@i
M=M+1

@LOOP
0;JMP

(END)

//Reto 5

@10
D=A 
@var
M=D 
D=A 
@punt
M=D
@20
D=A 
@punt
A=M 
M=D

//Reto 7

@10
D=A 
@var
M=D

@5
D=A
@bis
M=D

@var
D=A 
@p_var
M=D
 
@p_var
A=M 
D=M
@bis
M=D 

//Reto 9

@6
D=A
@a     
M=D

@9
D=A
@b     
M=D

@a     
D=M

@b     
D=D+M

@result     
M=D

@result    
D=M
@c     
M=D
