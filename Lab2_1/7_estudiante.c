#include <stdio.h>

struct estudiante{
	char nombre[40];
	int numEstudiante;
	int agnoMatricula;
	float nota;

};

int main(){
	struct estudiante estud1={"Jose", 4, 2009, 4.5};
	struct estudiante *ptrEstruct;

	ptrEstruct=&estud1;
	//printf("La nota de estud1 es %.2f (Con apuntador) \n", ptrEstruct->nota );
	//printf("La nota de estud1 es %.2f (Sin apuntador) \n", estud1.nota );

	printf("\n=====Datos =====\nNombre: %s \nNumero:%d \nAño matricula:%d \nNota: %.2f \n", 
		ptrEstruct->nombre, ptrEstruct->numEstudiante, ptrEstruct->agnoMatricula, ptrEstruct->nota );
	if(getchar()=='r'){
		printf("Ingrese para estud1 Nombre: \n" );
		scanf("%s",ptrEstruct->nombre);
		printf("Ingrese para estud1 numero de estudiante: \n" );
		scanf("%d",&ptrEstruct->numEstudiante);
		printf("Ingrese para estud1 año de matricula: \n" );
		scanf("%d",&ptrEstruct->agnoMatricula);
		printf("Ingrese para estud1 nota: \n" );
		scanf("%f",&ptrEstruct->nota);
	}
	printf("\n=====Datos =====\nNombre: %s \nNumero:%d \nAño matricula:%d \nNota: %.2f \n", 
		ptrEstruct->nombre, ptrEstruct->numEstudiante, ptrEstruct->agnoMatricula, ptrEstruct->nota );
	
	return 0;


}