//Reto 1
 
@1978
D=A
 
//Reto 2
 
@69
D=A
@100
M=D
 
//Reto 3
 
@24
D=M
@200
M=D
 
//Reto 4
 
@100
D=M
@15
D=D-A
@100
M=D
 
//Reto 5
 
@0
D=M
@1
D=D+M
@69
D=D+A
@2
M=D
 
//Reto 6
 
@100
D;JEQ

//Reto 7

@100
D=M
D=D-A
@20
D;JLT

//Reto 8

@var1
D = M
@var2
D = D + M
@var3
M = D

//¿Qué hace este programa?
//suma var1 y var2, y el resultado lo pone en var3
//En qué posición de la memoria está var1, var2 y var3? ¿Por qué en esas posiciones?
//Están en 16,17 y 18 respectivamente, porque apartir de esa posición se guardan las variables (Estas son variables).

//Reto 9

//programa

i = 1
sum = 0
sum = sum + i
i = i + 1

//Traducción

// i = 1
@i
M=1
// sum = 0
@sum
M=0
// sum = sum + i
@i
D=M
@sum
M=D+M
// i = i + 1
@i
D=M+1
@i
M=D


//¿Qué hace este programa?
//le asignan el valor 1 a i y el valor 0 a sum, luego, se suma el valor de sum y de i y se asigna en sum, y por ultimo se le suma al valor de i un 1. 
//¿En qué parte de la memoria RAM está la variable i y sum? ¿Por qué en esas posiciones?
//Están en 16 y 17 respectivamente, porque apartir de esa posición se guardan las variables (Estas son variables).


//Optimiza esta parte del código para que use solo dos instrucciones:

// i = i + 1
@i
D=M+1
@i
M=D

//optimizado

@i
M=M+1

//Reto 10

@R0
D=M
@R1 
M=D+D 

//Reto 11

//Considera el siguiente programa:

i = 1000
LOOP:
if (i == 0) goto CONT
i = i - 1
goto LOOP
CONT:
​
//La traducción a lenguaje ensamblador del programa anterior es:

// i = 1000
@1000
D=A
@i
M=D
(LOOP)
// if (i == 0) goto CONT
@i
D=M
@CONT
D;JEQ
// i = i - 1
@i
M=M-1
// goto LOOP
@LOOP
0;JMP
(CONT)

// ¿Qué hace este programa?
// Hace un conteo regresivo desde el 1000 hasta el 0.
// ¿En qué memoria está almacenada la variable i? ¿En qué dirección de esa memoria?
// En la dirreción de RAM 16.
// ¿En qué memoria y en qué dirección de memoria está almacenado el comentario //i = 1000?
// Los comentarios no se guardan pues no le sirve a la maquina solo al usuario.
// ¿Cuál es la primera instrucción del programa anterior? ¿En qué memoria y en qué dirección de memoria está almacenada esa instrucción?
// @1000 y está en el registro A, y la instrucción en si está en la ROM en la dirección 0.
// ¿Qué son CONT y LOOP?
// Son etiquetas que se usan para hacer saltos.
// ¿Cuál es la diferencia entre los símbolos `i` y `CONT`?
// Uno es una variable que contiene un valor, el segundo es una etiqueta que no contiene un valor pero sirve para hacer saltos.

//Reto 12

@69
D=M 
@R2
D=M+D 
@R1
D=M+D 
@R4
M=D 

//Reto 13

@R0        
D=M       
@SALTO
D;JGE     
@R1        
M=-1      
@LOOP
0;JMP     
(SALTO)
@1        
M=1       
(LOOP)
@LOOP
0;JMP     

//Reto 14

@R1      
D=M     
@3
M=D     
@3
A=M     
D=M     
@R4      
M=D     

//Reto 15

@R0
D=M
@16
M=D
@R1
D=M
@17
M=D
(LOOP)
@17         
D=M
@FINAL
D;JEQ       
@16
A=M         
M=-1        
@16
M=M+1
@17
M=M-1
@LOOP
0;JMP   
(FINAL)

//Reto 16

@0
D=A
@26        
M=D
@0
D=A
@27        
M=D
(LOOP)
@27
D=M
@10
D=D-A
@FINAL
D;JGE
@27
D=M
@16
A=D+A
D=M
@26
M=D+M
@27
M=M+1
@LOOP
0;JMP
(FINAL)


//Reto 17

@7
D=D-A    // D = D - 7
@69
D;JEQ

//Reto 18



//Reto 19

//Este programa dibuja 4 valores en pantalla y luego los invierte si una tecla está presionada. Y hace un loop continuo que va alternando entre pintar e invertir