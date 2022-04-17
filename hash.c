#include "travel.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "hash.h"


void creteFindTable(){
	FILE *fp, *fw;
	fp = fopen("datos.csv", "r");
	fw = fopen("list","wt");
	char cadena[100];
	char *dato;
	int cont=0; 
	Travel t;
	while(fgets(cadena,100,fp)){
		//printf("%s", cadena);
	//----------------- partiendo los datos ------------
		char *ido;
		long pos = ftell(fp); // guardamos la posicion actual del puntero
		dato = strtok(cadena,","); // atrapa el primer dato de la fila
		t.ido = ido;                //almacenamos datos en la estructura
		t.idd = strtok(NULL,",");
		t.hora = strtok(NULL,",");
		t.tiempo = atof(strtok(NULL,","));
	//------------------ buscando siguiente ido en la tabla ---------
		bool find;
		char caux[100]; //cadena de caracteres auxiliar para atrapar filas del archivo
		char *daux;	//variable dato auxiliar para almacenar los ido
		int paux = ftell(fp);
		while(!find && fgets(caux,100,fp)){
			daux = strtok(caux,",");
			if (strcmp(daux,ido)==0){
				t.next = paux;
				find = true;			
			}
			paux = ftell(fp);		
		}
		createIndexTable(t);//enviamos la estructura para adicionar si no existe
		fseek(fp,pos,SEEK_SET); //recuperamos la posicion del puntero
	

}


void createIndexTable(Travel t) {
	if(search(t.ido)<0){
		FILE *fp;
		fp = fopen("otro.txt","a+");
		char *ido = t.ido;
		char aux[10];
		strcat(strcpy(aux,ido),"\n");
		int index = atoi(ido);
		if();
		fputs(aux,fp);		
	}else{
		printf("indice existe");	
	}
};



int search(char *d) {

};
