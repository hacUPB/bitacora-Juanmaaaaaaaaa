//RAM2 = RAM0 + RAM1 + 17

@0
D = M
@1
D = D + M
@17
D = D + A
@2 
M = D

@16384
D = A
@16
M = D

@20
D = A
@16
M = D
