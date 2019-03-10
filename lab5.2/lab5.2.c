//Travel planning using double arrays
//Authors: Galadima Ahmed
#define _CRT_SECURE_NO_DEPRECATE
#define PI 3.14159265359
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double radians(double);
double distanceKm(double *, double *, double *, int);

int main(void)
{
	int arraySize = 0;
	double totalDistance = 0;
	char* lat_buffer[200];
	char* lon_buffer[200];

	printf("Enter the number of waypoints: ");
	while (1)
	{
		if (scanf("%d", &arraySize) == 1)
			break;
		else while (getchar() != '\n')
			continue;
		printf("Try again (expected number >= 0): ");
	}
	getchar();
	//array 1 longitude
	double *longitude = (double *)malloc(arraySize * sizeof(double));
	//array 2 latitude
	double *latitude = (double *)malloc(arraySize * sizeof(double));
	printf("Enter waypoints as \"<latitude> <longitude>\": ");
	for (int i = 0; i < arraySize; i++)
	{
		while (1)
		{
			printf("\n Waypoint %d: ", i + 1);
			scanf("%s", lat_buffer);
			scanf("%s", lon_buffer);
			int lat_success = sscanf(lat_buffer, "%lf", &latitude[i]);
			int lon_success = sscanf(lon_buffer, "%lf", &longitude[i]);
			if (!lat_success || !lon_success)
			{
				printf("Invalid input (expected \"<latitude> <longitude>\"):  ");

				if (!lat_success)
					printf("%s", lat_buffer);
				if (!lon_success)
					printf("%s", lon_buffer);
			}
			else
			{
				break;
			}
			while (getchar() != '\n')
				continue;
		}
	}
	getchar();
	distanceKm(latitude, longitude, &totalDistance, arraySize);
	printf("\nBy taking this route you will travel %.1lf Km.", totalDistance);

	//function loop to go through and add up all the way points (can use previous lab module)
	//Clear memory
	free(longitude);
	free(latitude);
	getchar();
	return 0;
}
double distanceKm(double *latitude, double *longitude, double *totalDistance, int arraySize)
{
	double deltaX, deltaY, lDistKm;
	double latA, lonA, latB, lonB;
	int x = 1;

	//with each loop y increases until it is 7 but x is always 1 ahead.
	for (int y = 0; y < arraySize - 1; y++)
	{
		latA = latitude[y];
		lonA = longitude[y];
		lonB = longitude[x];
		latB = latitude[x];

		//used local distance KM formula
		deltaY = 111.3 * fabs((radians(latA - latB)));
		deltaX = 111.3 * cos((radians(latA + latB)) / 2) * fabs(radians(lonA - lonB));
		lDistKm = sqrt(deltaX * deltaX + deltaY * deltaY) * (180 / PI);

		//Sets value in pointer
		*totalDistance += lDistKm;

		//x is initiall set to 1 at declaration to make sure the coordinates arent the same causing the result to be 0.00
		x += 1;
	}
}
double radians(double rad)
{
	return(rad * PI / 180);
}