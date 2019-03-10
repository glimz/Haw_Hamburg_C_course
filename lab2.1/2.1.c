/*Author: Galdima Ahmed; Assignment: usinf for loop to print a 2d chess board*/
#include<stdio.h>

int main(void)
{
	printf("+----+----+----+----+----+----+----+\n");
	
	for (int row = 8; row >= 1; row--)
	{
		for (char column = 'a'; column < 'h'; column++)
		{
			printf("| %c%d ", column, row);
		}
		printf("|\n");
		printf("+----+----+----+----+----+----+----+\n");
	}
	
	getchar();
	return 0;
}