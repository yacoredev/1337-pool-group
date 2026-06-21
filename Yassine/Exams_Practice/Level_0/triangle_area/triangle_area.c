int triangle_area(int base, int height)
{
	return((base * height) / 2);
}


#include <stdio.h>
int main(void)
{
	int base = 2;
	int height = 4;

	printf("base = %d\nheight = %d\n"
			"area of a triangle: %d\n", base, height, triangle_area(base, height));
	return (0);
}
