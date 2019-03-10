#include<stdio.h>

int main(void)
{
	int field = 0;
	unsigned long long onField = 1;
	unsigned long long sum = 0;

	printf("     Field | On field                | Sum\n");
	printf("-----------+-------------------------+---------------------------------------\n");

	for (int field = 1; field <= 64; field++, onField *= 2)
	{
		sum += onField;
		printf("%5d   %20llu   %20llu (= %.1e)\n", field, onField, sum, (double)sum);
	}


	getchar();
	return 0;
}