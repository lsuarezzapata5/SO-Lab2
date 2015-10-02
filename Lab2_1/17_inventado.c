#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define numMaxChar 20
#define nombreArchivo mensaje
 int main()
{	
	
	int ch;
	FILE *in_fileO;
	FILE *in_fileC;
	char original[numMaxChar];
	char copia[numMaxChar];
	strcpy(original, nombreArchivo);

	in_fileO=fopen(original,"r");
	
	
	if(in_fileO==NULL){
		printf("No se puede abrir %s\n",original );
		exit(8);
	}
	if(in_fileC==NULL){
		printf("No se puede abrir %s\n",copia);
		fclose(in_fileO);
		exit(8);
	}
	while(1){
		fprintf(in_fileC, "Copia Realizada%s\n", );
		if(ch==EOF){
			break;
		}else{
			//putc(ch, in_fileC);
		}
	}
	fclose(in_fileO);
	fclose(in_fileC);

	return 0;
}