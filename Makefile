# Esta regla ejecuta todo
all: programa abrir

# Esta regla compila el programa principal. Es necesario agregar cada archivo .c
programa: p1-odProgram.c interface.c 
		gcc	-o programa p1-odProgram.c interface.c
# Esta regla abre el programa
abrir:
		./programa