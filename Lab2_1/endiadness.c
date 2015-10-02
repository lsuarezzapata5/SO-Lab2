#include <stdio.h>
#define LITTLE_ENDIAN 0
#define BIG_ENDIAN 1

int machineEndianness(){
	int i=1;
	char *p=(char *)&i; //se obtuvo la direccion de memoria de i
	//el espacio de almaenamiento es de 2 bytes
	printf("%p\n", p );
	//si es !=0 se almacena de menor a mayor peso:Little endian
	if(p[0]==1){
		return LITTLE_ENDIAN;
	}else{
		//si el byte 0 es ==0 entonces se almacena de mayor a menor peso: Big Endian
		return BIG_ENDIAN;
	}
}
int main(){
	if (machineEndianness()){
		printf("Big endian\n");
	}else{
		printf("Little endian\n");
	}
	return 0;
}