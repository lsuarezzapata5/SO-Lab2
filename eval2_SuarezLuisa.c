#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXCHAR 20
#define MAXITEMS 100

typedef struct {
	int code;
	char description[MAXCHAR];
	int value;
}str_item;

int num;
void newBill(str_item (*_items)[num], char salida[MAXCHAR]);
void printBill(int n, int *quantity,  int total, int *totals, str_item (*_items)[num], FILE *in_fileS);
void checkItem(str_item (*_items)[num]);
int numeroItems(FILE *file);
void getDatos(str_item (*_items)[num], FILE *file);

int main(int argc, char *argv[]){
	/*
	int codes[MAXITEMS] = {101,102,103,104,105,106};
	char descriptions[MAXITEMS][MAXCHAR] = {"Articulo#1", "Articulo#2", "Articulo#3","Articulo#4","Articulo#5", "Articulo#6"};
	int values[MAXITEMS]={300,500,250,100,900,600};
	*/

	char option;
	FILE *in_fileE;
	char entrada[MAXCHAR];
	char salida[MAXCHAR];
	strcpy(entrada, argv[1]);
	strcpy(salida, argv[2]);
	in_fileE=fopen(entrada,"r+");
	str_item (*items)[MAXITEMS];


	
	if(argc!=3){
	 	printf("Faltan argumentos, ejecute asi: a.out<nombreArchivoEntrada nombreArchivoSalida >\n");
	 	exit(0);
	}
	
	if(in_fileE==NULL){
		printf("No se puede abrir %s\n",entrada );
		exit(8);
	}
	

	num=numeroItems(in_fileE);

	//Memoria dinamica
	items=  (str_item (*)[num]) malloc(sizeof(str_item[num]));
	
	//Llamado a la funcion para obtener los datos de los items
	getDatos(items, in_fileE);
	
	

	while(option!='q'){

		printf("Ingrese \n a. Nueva factura \n b. Consultar articulo \n c. Ingresar articulo \n q. Salir \n");
		setbuf(stdin, NULL);
		scanf("%c", &option);

		 if (option=='a'){
		 	//Creating a new ticket
		 	newBill(items, salida);
		 } else  if(option=='b'){
		 	//Checking an item
		 	checkItem(items);
		 } else  if(option=='c'){
		 	//Add new item to list
		 	
		 } else  if(option=='q'){
		 	return 0;
		 } else{
		 	 printf("Opcion no valida\n");
		 }
	}

	fclose(in_fileE);
	
	return 0;
}


void newBill(str_item (*_items)[num], char salida[MAXCHAR]){
	int numItems;
	int inCode;
	int flag=0;
	int i=0;
	int j=0;

	int *pCodes;	
	int *pQuantities;
	int *pTotalPerCode;
	int total = 0;

	str_item *item;
	FILE *in_fileS;
	in_fileS=fopen(salida, "w");

	if(in_fileS==NULL){
		printf("No se puede abrir %s\n",salida);
		exit(8);
	}

	printf("Numero de articulos a facturar: ");
	scanf("%d", &numItems);

	pCodes = (int *)malloc(sizeof(int)*numItems);
	pQuantities = (int *)malloc(sizeof(int)*numItems);
	pTotalPerCode = (int *)malloc(sizeof(int)*numItems);
	//Se repite por el numero de articulos a facturar
	while ( i<numItems ){
		setbuf(stdin, NULL);
		printf("\n\nArticulo #%d\n", i+1);
		printf("Codigo: \n");
		scanf("%d", &inCode);
		flag=0;

		//Para validar que el codigo es de un articulo existente		
		for (j=0; j<MAXITEMS;j++){
		item=(str_item *)(_items+j);
		//printf("CODIGO: %d\n", item->code);
			if(inCode == item->code){
				pCodes[i] = inCode;

				printf("Cantidad: \n" );
				scanf("%d", pQuantities+i);
	
				pTotalPerCode[i] = item->value*pQuantities[i];
				total += pTotalPerCode[i];

				printf("Valor: %d --- Acumulado:  %d \n", pTotalPerCode[i], total);
		
				flag=1;
				i++;
			}	
		}
		if(flag==0){
			printf("El articulo con codigo %d no se encontró\n", inCode);
		}
		
	}

	printBill(numItems, pQuantities,  total, pTotalPerCode, _items,in_fileS );
	
	fclose(in_fileS);
	
	
}

void printBill(int n, int *quantity,  int total, int *totals, str_item (*_items)[num], FILE *in_fileS){
	str_item *item;
	fprintf(in_fileS,"\n\n\t\tFactura de Venta\n");
	fprintf(in_fileS,"\t\t Nombre Empresa \n");
	
	fprintf(in_fileS,"Cantidad  | Codigo | V. unit   | Total\n");
	int i;
	for (i=0; i<n;i++){
		setbuf(stdin, NULL);
		item=(str_item *)(_items+i);
		fprintf(in_fileS,"%-8d  | %-5d  | %-10.2d| %d\n", quantity[i], item->code, item->value, totals[i] );
	}
	fprintf(in_fileS,"Total: %d\n\n",total );
}

void checkItem(str_item (*_items)[num]){
	str_item *item;
	int inCode;
	int flag = 0;
	printf("\nCodigo Articulo: ");
	scanf("%d", &inCode);
	

	int cnt;
	for (cnt=0; cnt<MAXITEMS;cnt++){
		setbuf(stdin, NULL);
		item=(str_item *)(_items+cnt);
		if(inCode==item->code){
			
			printf("%s --> %d \n\n", (item->description), (item->value) );	
			flag=1;		
		}
	}
	if(flag == 0)
		printf("El articulo con codigo %d no se encontró\n", inCode);
}

int numeroItems(FILE *file){
int num = 0;
	char buffer[MAXCHAR];
	while(!feof(file)){
		fgets(buffer, MAXCHAR, file);
		//fgets lee una cadena de caracteres de tamaño NUMMAXCHAR
		num++;
	}	
	rewind(file);
	return num/3;

}

void getDatos(str_item (*_items)[num], FILE *file){
	int i;
	str_item *item;
	for (i=0; i<num;i++){
		setbuf(stdin, NULL);
		item=(str_item *)(_items+i);

		fscanf(file, "%d", &item->code);
		//printf("%d\n",  item->code);
			
		fscanf(file, "%s", item->description);
		//printf("%s\n",  (char *)item->description);
		
		fscanf(file, "%d", &item->value);
		//printf("%d\n",  item->value);	

		item++;
	}

}
