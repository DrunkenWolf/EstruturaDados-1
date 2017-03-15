#include <stdio.h>

int main(){
	printf("int = %lu bytes\n", sizeof(int));
	printf("double = %lu bytes\n", sizeof(double));
	printf("char = %lu bytes\n", sizeof(char));
	printf("float = %lu bytes\n", sizeof(float));
	printf("long = %lu bytes\n", sizeof(long));
	//printf("boolean = %lu bytes\n", sizeof(bool));
	return 0;
}
