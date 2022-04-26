#include <stdio.h>
#include <string.h>

char * convertNumber(int num);

int main(void)
{
    int num = 0;
	printf("Enter a number: ");
	scanf("%d", &num);
	char *numberito = convertNumber(num);
	//convertNumber(num);
	printf("El valor es %s", numberito);
	//char *resultado = convertNumber(num);
	//char original = "0000000000";
	//original = convertNumber(num);
	
	//printf("%s", original);
	
	return 0;
}

char * convertNumber(int num) {
    
	char text[10]; 

	sprintf(text, "%d", num);   
	
	int longText = 10;
    char *stuffing = "0000000000";
    char finalText[longText + 1];// Aquí almacenamos el resultado. Debe ser lo suficientemente larga
    // Obtener la diferencia de longitud
    int diference = longText - (int) strlen(text);
    sprintf(finalText, "%*.*s%s ", diference, diference, stuffing, text);
    printf("%s", finalText);
    
    char *result = finalText;
    
    return &result;
}