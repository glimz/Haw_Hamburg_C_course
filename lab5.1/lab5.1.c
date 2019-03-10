/*Travel planning using double arrays

#define _CRT_SECURE_NO_DEPRECATE
#define PI 3.14159265359
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double degreeRad(double);
double distanceKm(double *, double *, double *, int);

int main(void)
{

	char* latitude[200];
	char* longtitude[200];
	int wayPoint = 0;
	double totalDist = 0;

	printf("Enter the number of waypoints: ");
	while (1)
	{
		if (scanf("%d", &wayPoint) == 1)
			break;
		else if (getchar() != '\n')

			printf("Try again (expected number >= 0): ");
	}
	getchar();
	/*Reserving array for longitude and latitude using malloc
	double *longitude = (double *)malloc(wayPoint * sizeof(double));
	double *latitude = (double *)malloc(wayPoint * sizeof(double));

	printf("Enter waypoints as \"<latitude> <longitude>\": ");

	for (int i = 0; i < wayPoint; i++)
	{
		while (1)
		{
			printf("\n Waypoint %d: ", i + 1);
			scanf("%s", latitude);
			scanf("%s", longtitude);

			int lat_success = sscanf(latitude, "%lf", &latitude[i]);
			int lon_success = sscanf(longtitude, "%lf", &longitude[i]);

			if (!lat_success || !lon_success)
			{

				printf("Invalid input (expected \"<latitude> <longitude>\"):  ");

				if (!lat_success)
					printf("%s", latitude);
				if (!lon_success)
					printf("%s", longtitude);
				else
					break;

			}
			while (getchar() != '\n')
				continue;
		}
	}
	getchar();

	distanceKm(latitude, longitude, &totalDist, wayPoint);
	printf("\nBy taking this route you will travel %.1lf Km.", totalDist);
	//Clear memory
	free(longitude);
	free(latitude);

	getchar();
	return 0;
}
function to go through and add up all the way points
double distanceKm(double *latitude, double *longitude, double *totalDistance, int arraySize)
{
	double deltaX, deltaY, DistKm;
	double latA, lonA, latB, lonB;
	int x = 1;
	/*increasmental for loop
	for (int y = 0; y < arraySize - 1; y++)
	{
		latA = latitude[y];
		lonA = longitude[y];
		lonB = longitude[x];
		latB = latitude[x];
		/*calculating the local distance KM
		deltaY = 111.3 * fabs((degreeRad(latA - latB)));
		deltaX = 111.3 * cos((degreeRad(latA + latB)) / 2) * fabs(degreeRad(lonA - lonB));
		DistKm = sqrt(deltaX * deltaX + deltaY * deltaY) * (180 / PI);
		*totalDistance += DistKm;
		x += 1;
	}
}
/*converting from degree radian
double degreeRad(double rad)
{
	return(rad * PI / 180);
}*/

/*Travel planning using double arrays*/

#define _CRT_SECURE_NO_DEPRECATE
#define PI 3.14159265359
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double degreeRad(double);
double distanceKm(double *, double *, double *, int);

int main(void)
{

	char* latitude[200];
	char* longtitude[200];
	int wayPoint = 0;
	double totalDist = 0;

	printf("Enter the number of waypoints: ");
	while (1)
	{
		if (scanf("%d", &wayPoint) == 1)
			break;
		else if (getchar() != '\n')

			printf("Try again (expected number >= 0): ");
	}
	getchar();
	/*Reserving array for longitude and latitude using malloc*/
	double *longitude = (double *)malloc(wayPoint * sizeof(double));
	double *latitude = (double *)malloc(wayPoint * sizeof(double));

	printf("Enter waypoints as \"<latitude> <longitude>\": ");

	for (int i = 0; i < wayPoint; i++)
	{
		while (1)
		{
			printf("\n Waypoint %d: ", i + 1);
			scanf("%s", latitude);
			scanf("%s", longtitude);

			int lat_success = sscanf(latitude, "%lf", &latitude[i]);
			int lon_success = sscanf(longtitude, "%lf", &longitude[i]);

			if (!lat_success || !lon_success)
			{

				printf("Invalid input (expected \"<latitude> <longitude>\"):  ");

				if (!lat_success)
					printf("%s", latitude);
				if (!lon_success)
					printf("%s", longtitude);
				else
					break;

			}
			while (getchar() != '\n')
				continue;
		}
	}
	getchar();

	distanceKm(latitude, longitude, &totalDist, wayPoint);
	printf("\nBy taking this route you will travel %.1lf Km.", totalDist);
	//Clear memory
	free(longitude);
	free(latitude);

	getchar();
	return 0;
}
/*function to go through and add up all the way points*/
double distanceKm(double *latitude, double *longitude, double *totalDistance, int arraySize)
{
	double deltaX, deltaY, DistKm;
	double latA, lonA, latB, lonB;
	int x = 1;
	/*increasmental for loop*/
	for (int y = 0; y < arraySize - 1; y++)
	{
		latA = latitude[y];
		lonA = longitude[y];
		lonB = longitude[x];
		latB = latitude[x];
		/*calculating the local distance KM*/
		deltaY = 111.3 * fabs((degreeRad(latA - latB)));
		deltaX = 111.3 * cos((degreeRad(latA + latB)) / 2) * fabs(degreeRad(lonA - lonB));
		DistKm = sqrt(deltaX * deltaX + deltaY * deltaY) * (180 / PI);
		*totalDistance += DistKm;
		x += 1;
	}
}
/*converting from degree radian*/
double degreeRad(double rad)
{
	return(rad * PI / 180);
}