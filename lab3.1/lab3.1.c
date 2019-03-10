#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int isNorthernHemisphere(int);
int isSouthernHemisphere(int);

int main(void)
{
	int lat;

	printf("Enter a latitude to determine if is north or south hemisphere\n");
	scanf("%d", &lat);
	getchar();

	if (lat == (isNorthernHemisphere(lat)))
	{
		 isNorthernHemisphere(lat);
	}
	
	if (lat == (isSouthernHemisphere(lat)))
	{
		printf("Southern Hemisphere: %d", isSouthernHemisphere(lat));
	}

	getchar();
	return 0;
}

int isNorthernHemisphere(int lat)
{
	if ((lat >= -90) && (lat <= 90))
		return 1;
	else
		return 0;
}

int isSouthernHemisphere(int lat)
{
	if ((lat >= -180) && (lat <= 180))
		return 1;
	else
		return 0;
}