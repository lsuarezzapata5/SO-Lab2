#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define NUMMAXCHAR 20
#define DEFAULT 100


typedef unsigned int uint;

typedef struct {
	char nombre[NUMMAXCHAR];
	float nota;
	uint creditos; 
}strMateria;

int num;
int numeroMaterias(FILE *file);
void getDatos(int n, strMateria (*_materias)[num], FILE *file);
int getMateriasGanadas(int n, strMateria (*_materias)[num], int *ganadas[num]);

int main(int argc, char const *argv[])
{	
	int ch;
	FILE *in_fileE;
	FILE *in_fileS;
	char entrada[NUMMAXCHAR];
	char salida[NUMMAXCHAR];
	strcpy(entrada, argv[1]);
	strcpy(salida, argv[2]);
	in_fileE=fopen(entrada,"r");
	in_fileS=fopen(salida, "w");
	strMateria (*materias)[DEFAULT];//estatico
	int *ganadas[100];
	char (*perdidas)[NUMMAXCHAR];
	int numeroGanadas=0;

	
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
	//Reservar memoria dinamica para el materias que apunta a un arreglo de strMateria
	materias=  (strMateria (*)[num]) malloc(sizeof(strMateria[num]));
	ganadas= (int *[num])malloc(sizeof(int[num]));

	//Escribir el encabezado del archivo de salida
	fprintf(in_fileS,"Materia | Nota | Creditos \n");

	//Llamado a la funcion para obtener los datos de la materia
	getDatos(num, materias, in_fileE);

	//llamado a la funcion para obtener el numero de materias ganadas
	numeroGanadas=getMateriasGanadas(num, materias, ganadas);

	

	//Escribe en el archivo de salida el total de materias
	printf("Total Materias: %d\n", num);
	//Escribe en el archivo de salida el total de materias ganadas
	printf("Numero de materias Ganadas: %d\n", numeroGanadas );

	fclose(in_fileE);
	fclose(in_fileS);

	return 0;
}

//Funcion para contar el numero de lineas y dividir entre 3 (Porque son 3 atributos)

int numeroMaterias(FILE *file){
	int num = 0;
	char buffer[NUMMAXCHAR];
	while(!feof(file)){
		fgets(buffer, NUMMAXCHAR, file);
		//fgets lee una cadena de caracteres de tamaño NUMMAXCHAR
		//si le pongo un tamaño de 1 tambien me cuenta el numero de lineas
		num++;
	}	
	rewind(file);
	return num/3;
}

void getDatos(int n, strMateria (*_materias)[num], FILE *file){
	int i;
	strMateria *materias;
	for (i=0; i<n;i++){
		materias=(strMateria *)(_materias+i);
			
		fscanf(file, "%s", materias->nombre);
		printf("%s\n",  (char *)materias->nombre);

		fscanf(file, "%f", &materias->nota);
		printf("%f\n",  materias->nota);

		fscanf(file, "%d", &materias->creditos);
		printf("%d\n",  materias->creditos);		

		materias++;
	}

}

int getMateriasGanadas(int n, strMateria (*_materias)[num], int *ganadas[num]){
	int i;
	strMateria *materias;
	int nGanadas=0;
	int nota;
	for (i=0; i<n;i++){
		materias=(strMateria *)(_materias+i);
		nota=materias->nota;
		if(nota>=3){
			//&(ganadas+nGanadas)=materias->nombre;
			nGanadas++;
		}
		
				
	}
	return nGanadas;

}