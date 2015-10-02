#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define numMaxChar 20

typedef unsigned int uint;

typedef struct {
	char nombre[numMaxChar];
	float nota;
	uint creditos; 
}strMateria;

int numeroMaterias(FILE *file);
void getDatos(int n, strMateria *materias, FILE *file);

int main(int argc, char const *argv[])
{	
	int ch;
	FILE *in_fileE;
	FILE *in_fileS;
	char entrada[numMaxChar];
	char salida[numMaxChar];
	strcpy(entrada, argv[1]);
	strcpy(salida, argv[2]);
	in_fileE=fopen(entrada,"r");
	in_fileS=fopen(salida, "w");
	int num;
	strMateria materias[100];//estatico


	
	if(argc!=3){
	 	printf("Faltan argumentos, ejecute asi: a.out<nombreArchivoEntrada nombreArchivoSalida >\n");
	 	exit(0);
	}
	
	if(in_fileE==NULL){
		printf("No se puede abrir %s\n",entrada );
		exit(8);
	}
	if(in_fileS==NULL){
		printf("No se puede abrir %s\n",salida);
		fclose(in_fileE);
		exit(8);
	}
	num=numeroMaterias(in_fileE);
	printf("%d\n", sizeof(strMateria) );
//nombreMateria = (char(*)[numMaxNombre]) malloc(sizeof(char[numMaxNombre])*n);
	//materias=  (strMateria(*)[num]) malloc(sizeof(strMateria[num])*n);
/*
	fprintf(in_fileS,"Materia | Nota | Creditos \n");

	//Llamado a la funcion para obtener los datos de la materia
	getDatos(num, &materias[0], in_fileE);


	printf("Total Materias: %d\n", num);

	fclose(in_fileE);
	fclose(in_fileS);
*/
	return 0;
}

//Funcion para contar el numero de lineas y dividir entre 3 (Porque son 3 atributos)

int numeroMaterias(FILE *file){
	int num = 0;
	char buffer[numMaxChar];
	while(!feof(file)){
		fgets(buffer, numMaxChar, file);
		//fgets lee una cadena de caracteres de tamaño numMaxChar
		//si le pongo un tamaño de 1 tambien me cuenta el numero de lineas
		num++;
	}	
	rewind(file);
	return num/3;
}
/*
void getDatos(int n, strMateria *materias, FILE *file){
	int i;
	char buffer[numMaxChar];
	char bff[] = "so;3,4;2";
	
	//char *pch;
	
	//pch = strtok(bff, ";");
	
	
	for (i=0; i<n;i++){
	//fgets(buffer, numMaxChar, file);
	fscanf(file, "%s", materias->nombre);

	printf("%s\n",  (char *)materias->nombre);

	fscanf(file, "%s", materias->nota);
	
	printf("%s\n",  (char *)materias->nota);

	fscanf(file, "%s", materias->creditos);
	
	printf("%s\n",  (char *)materias->creditos);		

	
	materias++;

	}

}*/
