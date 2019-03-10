/* Author: Galadima Ahmed, file content: Algorithmic operation for integer numbers*/
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int main(void)
{

	int a;
	int b;

	/*collecting keyboard input from users*/
	printf("Console output:\n\nSimple calculator:\n--------------------------\n");
	printf("Enter the 1st and 2nd operands:\n");
	scanf("%d %d", &a, &b);
	getchar();

	/*calculation of operand and printing to console*/
	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);
	printf("%d / %d = %d\n", a, b, a / b);
	printf("%d %% %d = %d\n", a, b, a % b);

	getchar();
	return 0;
}