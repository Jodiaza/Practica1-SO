#include "hash.h"
#include "travel.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

/*
void createFindTable(){
	FILE *fp, *fw;
	fp = fopen("datos.csv", "r");
	fw = fopen("list","a+");
	char cadena[100];
	char *ido;
	int cont=0;
	Travel t;
	while(fgets(cadena,100,fp)){
		//printf("%s", cadena);
	//----------------- partiendo los datos ------------
		int pos = ftell(fp); // guardamos la posicion actual del puntero
		//printf("%s",cadena);
		ido = strtok(cadena,","); // atrapa el primer dato de la fila
		t.ido = ido;               //almacenamos datos en la estructura
		printf("primero %s y %s",t.ido,ido);
		t.idd = strtok(NULL,",");
		t.hora = strtok(NULL,",");
		t.tiempo = strtok(NULL,","); //atod(strtok(NULL,","));
		printf("\n - %f \n",t.tiempo);
		t.next = -1;
	//------------------ buscando siguiente ido en la tabla ---------
		bool find = false;
		char caux[100]; //cadena de caracteres auxiliar para atrapar filas del archivo
		char *daux;	//variable dato auxiliar para almacenar los ido
		int paux = ftell(fp);
		while(!find && fgets(caux,100,fp)){
			daux = strtok(caux,",");
			if (strcmp(daux,ido)==0){
				t.next = paux;
				find = true;			
			}else{
				//t.next = -1;
			}
			paux = ftell(fp);		
		}
		//createIndexTable(t);//enviamos la estructura para adicionar si no existe
		fseek(fp,pos,SEEK_SET); //recuperamos la posicion del puntero
		//printf("%s",t.ido);
		strcat(strcpy(caux,t.ido),",");
		//printf("\n %s \n",caux);
		strcat(caux,t.idd);
		strcat(caux,",");
		strcat(caux,t.hora);
		strcat(caux,",");
		char num[8];
		//sprintf(num, "%f",t.tiempo);
		strcat(caux,t.tiempo);
		strcat(caux,",");
		sprintf(num, "%d",t.next);
		printf("(%d) aux(%s)",t.next,num);
		strcat(caux,num);
		strcat(caux,"\n");
		printf("%s\n",caux);
		fputs(caux,fw);
	
	}

}*/
void createFindTable(){
	// hacer un archivo con los datos ordenados
	// mientras ordena los datos crear otro archivo con la direccion 
	//del cursor del primer elemento de cada ido en el  primer archivo
	FILE *fp, *fw;
	fp = fopen("datos.csv", "r");
	fw = fopen("list","a+"); //archivo con lista ordenada por ido
	char cadena[50];
	char *concat;
	char *caux;
	char *ido;
	Travel t;
	int index;
	for (int i = 0; i<1160){
		bool find = false;	//booleano para controlar que el ido exista en la primera columna
		bool first = true:  //buleano para evidenciar captura del primer elemento
		while(fgets(cadena,50,fp);){
			index = ftell(fw);				//capturamos posicion del cursor en el nuevo archivo
			ido = srttok(cadena,",");		//capturamos primer dato en columna 1 
			if(atoi(ido)== i+1){			//comparamos si es igual al indice que estamos guardando
				find = true;				// booleano en estado encontrado
				if(first){					//si es el primero guardamos posicion en el archivo de indices
					appendIndex(i+1,index);	
					fist = false;			//ya no es el primer elemento
				}
				strcat(stpcpy(concat,ido),",");	//concateno el ido
				for(int j = 0;j < 3; j++){      
					caux = strtok(NULL,",");	
					strcat(concat,caux);		//concatenamos los datos que vamos a guardar
				}
				strcat(concat,"\n");				
				fputs(fw,concat);		//escribimos los datos en el nuevo archivo ordenado
			}
		}		
		if(!find){
			//agregamos el indice vacio a la lista con valor negativo en la direccion
			appendIndex(i+1,-1);
		}
		fseek(fp,0,SEEK_SET);		//volvemos a poner el cursor en el inicio del archivo
	}	
	fclose(pf);
	fclose(fw);
}


void appendIndex(int ido, int dir){
	//agrega la direccion en una cadena de 9 caracteres con 
	//el indice, debe ser un numero de ocho caracteres, y relled¿nado su principio 
	//con ceros: ejm 456 =  000000456
	FILE *fi;
	fi = open("Index.txt","a+");
	printf("ido %i y posocion cursor %i ",ido,ftell(fi));
	char *cdir; //char donde se almacenara el ido con longitud de 10
	convertNumber(dir,cdir);
	strcat(cdir,"\n");
	fputs(fi,cdir);
	
		
}

/*
int MaxIdo(){
	FILE *fp;
	fp = fopen("datos.csv", "r");
	char cadena[50];
	int ido=0;
	char *idoT;
	int iaux = 0;
	while(!feof()){
		fgets(cadena,50,fp);
		idoT = strtok(caux,",");
		iaux = atoi(idoT);
		if (iaux>ido){
			ido = iaux
		}
		
	}
	return ido;
	
}*/


void convertNumber(int num, char* finalText) {
    
	char text[10]; 

	sprintf(text, "%d", num);   
	
	int longText = 10;
	if (num<0){
		char *stuffing = "-000000000";
	}else{
		char *stuffing = "-000000000";
	}
    //Aquí almacenamos el resultado. Debe ser lo suficientemente larga
    // Obtener la diferencia de longitud
    int diference = longText - (int) strlen(text);
    sprintf(finalText, "%*.*s%s ", diference, diference, stuffing, text);
    printf("%s\n", finalText);
    
   
    
}

/*
void createIndexTable(Travel t){
	if(search(t.ido)<0){
		FILE *fp;
		fp = fopen("otro.txt","a+");
		char *ido = t.ido;
		char aux[10];
		strcat(strcpy(aux,ido),"\n");
		int index = atoi(ido);
		//if()
		fputs(aux,fp);		
	}else{
		printf("indice existe");	
	}
}
*/
/*
int search(char *d) {
	return 0;
}*/

