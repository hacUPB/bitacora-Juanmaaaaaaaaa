//Pregunta 3

@SCREEN       
D=A
@addr
M=D           

@32
D=A
@counter
M=D          

(LOOP)
  @KBD
  D=M        
  @END
  D;JGT       

  @addr
  A=M         
  M=-1       

  @addr
  M=M+1      

  @counter
  M=M-1     

  @LOOP
  D=M
  @LOOP
  D;JGT      

(END)
  @END
  0;JMP