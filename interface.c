#include "interface.h"
#include <stdio.h>
#include <stdlib.h>


void welcome(int sourceId, int dstId, int hod) {

    printf("Bienvenide \n \n");
    printf("1. Ingrese ID del origen, ingrese un número entre 1 y 1160: ");
    scanf("%i", &sourceId);
    printf("2. Ingrese ID del destino, ingrese un número entre 1 y 1160: ");
    scanf("%i", &dstId);
    printf("3. Ingrese hora del día: ");
    scanf("%i", &hod);
    printf("\n%d", dstId);

}