# Esta regla ejecuta todo
all: programa abrir

# Esta regla compila el programa principal. Es necesario agregar cada archivo .c
programa: p1-odProgram.c interface.c hash.c
		gcc	-o programa p1-odProgram.c interface.c hash.c
# Esta regla abre el programa
abrir:
		./programa