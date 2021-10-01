	AREA PROGRAM, CODE, READONLY 
ENTRY 
	MOV R0,#15               
	CMP R0,#01               
	BEQ PRIME                
	CMP R0,#02               
	BEQ PRIME                
	MOV R1,R0              
	MOV R2,#02             
UP                     
	BL DIVISION             
	CMP R8,#00               
	BEQ NOTPRIME             
	ADD R2,R2,#01           
	CMP R2,R1                
	BEQ PRIME               
	B UP                     
NOTPRIME 
	LDR R3,=0x11111111       
	B STOP                   
PRIME 
	LDR R3,=0xFFFFFFFF       
STOP B STOP               

DIVISION                 
	MOV R8,R0               
	MOV R9,R2               
LOOP                     
	SUB R8,R8,R9            
	ADD R10,R10,#01         
	CMP R8,R9                
	BPL LOOP                
	MOV PC,LR               
END