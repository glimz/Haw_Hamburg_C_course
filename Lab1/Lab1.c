/* Author: Galadima Ahmed, file content: Algorithmic operation for nteger numbers*/

#include<stdio.h>

int main(void)
{

	int a = 7;
	int b = 3;

	/*printing operand*/
	printf("Console output:\n\nSimple calculator:\n--------------------------\n");
	printf("1st operand: %d\n", a);
	printf("2st operand: %d\n\n", b);

	/*calculation of operand and printing to console*/
	printf("%d %d = %d\n", a, b, a + b);
	printf("%d %d = %d\n", a, b, a - b);
	printf("%d %d = %d\n", a, b, a * b);
	printf("%d %d = %d\n", a, b, a / b);
	printf("%d %d = %d\n", a, b, a % b);

	getchar();
	return 0;
}