

struct cdsMusica{
	char titulo[40];
	char artista[40];
	char genero[15];
	int numCanciones;
	int lanzamiento;
	int precio;
} cd1,cd2,cd3;

imprimir(struct cdsMusica cd1);

int main()
{
	struct cdsMusica cd1={"Brindo con el alma", 
						"Diomedes Diaz", 
						"Vallenato", 
						11,1986,19900};
	imprimir(cd1);
	//printf("titulo: %s \nartista: %s \ngenero: %s \nnumCanciones: %d \nlanzamiento: %d \nprecio:%d \n ",
	//cd1.titulo, cd1.artista, cd1.genero, cd1.numCanciones, cd1.lanzamiento, cd1.precio );
	return 0;
}

imprimir(struct cdsMusica cd1){
printf("titulo: %s \nartista: %s \ngenero: %s \nnumCanciones: %d \nlanzamiento: %d \nprecio:%d \n ",
	cd1.titulo, cd1.artista, cd1.genero, cd1.numCanciones, cd1.lanzamiento, cd1.precio );
}
