#include <stdio.h>

struct point
{
	int x;
	int y;
};
struct rect
{
	struct point pt1;
	struct point pt2;
	
};

main(){
	struct point pt1;
	struct point pt2;
	struct rect  rectangulo;
	int base;
	int altura;
	int area;
	
	printf("Ingrese pt1.x= ");
	scanf("%d", &pt1.x);
	printf("\nIngrese pt1.y= ");
	scanf("%d", &pt1.y);
	printf("\nIngrese pt2.x= ");
	scanf("%d", &pt2.x);
	printf("\nIngrese pt2.y= ");
	scanf("%d", &pt2.y);
	base=(pt2.x-pt1.x);
	altura=(pt2.y-pt1.y);
	area=(base*altura)/2;
	printf("El area del rectangulo es: %d\n", area);
	return 0;

}