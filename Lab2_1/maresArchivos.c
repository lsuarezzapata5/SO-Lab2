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
int getMateriasGanadas(int n, strMateria (*_materias)[num], char *ganadas);
int getMateriasPerdidas(int n, strMateria (*_materias)[num], char  *perdidas);
float getPromedio(int n,strMateria (*_materias)[num] );
void imprimirMaterias(int n, strMateria (*_materias)[num], FILE *in_fileS );
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
	char *ganadas;
	char *perdidas;
	int numeroGanadas=0;
	int numeroPerdidas=0;
	float promedio=0;

	
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
	//Reservar memoria dinamica 
	materias=  (strMateria (*)[num]) malloc(sizeof(strMateria[num]));
	ganadas= (char *)malloc(sizeof(char)*num);
	perdidas=(char *)malloc(sizeof(char)*num);
	
	//Llamado a la funcion para obtener los datos de la materia
	getDatos(num, materias, in_fileE);

	//llamado a la funcion para obtener el numero de materias ganadas
	numeroGanadas=getMateriasGanadas(num, materias, ganadas);

	//llamado a la funcion para obtener el numero de materias perdidas
	numeroPerdidas=getMateriasPerdidas(num, materias,ganadas);
	
	//llamado a la funcion para obtener el promedio
	promedio=getPromedio(num, materias);

	//Llamado a la funcion para que imprima las amterias con sus respectivos atributos
	imprimirMaterias(num, materias, in_fileS);
	//Escribe en el archivo de salida el total de materias
	fprintf(in_fileS,"Total Materias: %d\n", num);
	//Escribe en el archivo de salida el total de materias ganadas
	fprintf(in_fileS,"Numero de materias Ganadas: %d\n", numeroGanadas );
	//Escribe en el archivo de salida el total de materias perdidas
	fprintf(in_fileS,"Numero de materias Perdidas: %d\n", numeroPerdidas );
	//Escribe en el archivo de salida el promedio
	fprintf(in_fileS,"Promedio ponderado: %.2f\n", promedio );

	
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
	strMateria *materia;
	for (i=0; i<n;i++){
		materia=(strMateria *)(_materias+i);
			
		fscanf(file, "%s", materia->nombre);
		//printf("%s\n",  (char *)materia->nombre);

		fscanf(file, "%f", &materia->nota);
		//printf("%f\n",  materia->nota);

		fscanf(file, "%d", &materia->creditos);
		//printf("%d\n",  materia->creditos);		

		materia++;
	}

}

int getMateriasGanadas(int n, strMateria (*_materias)[num], char  *ganadas){
	int i;
	strMateria *materia;
	int nGanadas=0;
	int nota;
	for (i=0; i<n;i++){
		materia=(strMateria *)(_materias+i);
		nota=materia->nota;
		if(nota>=3){
			sscanf(ganadas+nGanadas, "%s", materia->nombre);
			nGanadas++;
		}
		
				
	}
	return nGanadas;

}

int getMateriasPerdidas(int n, strMateria (*_materias)[num], char  *perdidas){
	int i;
	strMateria *materia;
	int nPerdidas=0;
	int nota;
	for (i=0; i<n;i++){
		materia=(strMateria *)(_materias+i);
		nota=materia->nota;
		if(nota<3){
			sscanf(perdidas+nPerdidas, "%s", materia->nombre);
			nPerdidas++;
		}
		
				
	}
	return nPerdidas;

}

float getPromedio(int n,strMateria (*_materias)[num] ){
	int totalCreditos=0;
	int suma=0;
	int i;
	strMateria *materia;
	for (i=0; i<n;i++){
		materia=(strMateria *)(_materias+i);
		suma+=((materia->nota)*(materia->creditos));
		totalCreditos+=materia->creditos;
				
	}

	return (suma/totalCreditos);
}

void imprimirMaterias(int n, strMateria (*_materias)[num],FILE *in_fileS ){
	fprintf(in_fileS,"MATERIA  | NOTA  |CREDITOS\n");
	int i;
	strMateria *materia;
	for (i=0; i<n;i++){
		materia=(strMateria *)(_materias+i);
		fprintf(in_fileS,"%-8s | %-6.2f| %d\n", materia->nombre, materia->nota, materia->creditos );
	}
}