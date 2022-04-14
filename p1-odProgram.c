//#include "Hash.h"
#include "Interfaz.h"

int main(int argc, char** argv) {

    int sourceId, dstId, hod, mtt, sdtt, gmtt, gsdtt;

    welcome(sourceId, dstId, hod);

    FILE *data;
	data = fopen ( "datos.csv", "r" );        
	if (data == NULL) {fputs ("File error",stderr); exit (1);}
    
    printf("\nGracias");

	fclose ( data );

    return 0;
}