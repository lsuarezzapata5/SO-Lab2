#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define numMaxChar 20
 int main(int argc, char const *argv[])
{	
	if(argc!=3){
	 	printf("Faltan argumentos, ejecute asi: a.out<nombreArchivoOriginal nombreArchivoCopia >\n");
	 	exit(0);
	 }
	int ch;
	FILE *in_fileO;
	FILE *in_fileC;
	char original[numMaxChar];
	char copia[numMaxChar];
	strcpy(original, argv[1]);
	strcpy(copia, argv[2]);
	in_fileO=fopen(original,"r");
	in_fileC=fopen(copia, "w");
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
		ch=fgetc(in_fileO);
		if(ch==EOF){
			break;
		}else{
			putc(ch, in_fileC);
		}
	}
	fclose(in_fileO);
	fclose(in_fileC);

	return 0;
}