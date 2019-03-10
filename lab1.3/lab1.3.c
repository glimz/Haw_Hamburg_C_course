#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int main(void)
{
	int firstDigit, secondDigit, thirdDigit, fourthDigit;
	int dateBirth;
	int dateBirth2; 
	int dateBirth3; 
	int dateBirth4;
	
	printf("Enter your year of birth:\n");
	scanf("%d", &dateBirth);
	getchar();

	/*digital sum of the entered year*/
	firstDigit = dateBirth % 10;
	dateBirth2 = dateBirth / 10;
	secondDigit = dateBirth2 % 10;
	dateBirth3 = dateBirth2 / 10;
	thirdDigit = dateBirth3 % 10;
	dateBirth4 = dateBirth3 / 10;
	fourthDigit = dateBirth4 % 10;

	printf("The digital sum of %d is %d + %d + %d + %d = %d", dateBirth, firstDigit, secondDigit, thirdDigit, fourthDigit, firstDigit + secondDigit + thirdDigit + fourthDigit);

	getchar();
	return 0;
}