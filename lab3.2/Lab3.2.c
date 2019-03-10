#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>

#define PI 3.14159265359

double localDistanceKm(double lat1, double lat2, double lon1, double lon2);
double distanceKm(double lat1, double lat2, double lon2, double lon1);
double degreeRad(double degree);

int main(void)
{
	double lat1, lat2, lon1, lon2;

	printf("Enter corrdinates to determine the distance between them:\n lat1, lon1\n");
	scanf("%lf %lf", &lat1, &lon1);
	getchar();

	printf("Enter second corrdinates:\n lat2, lon2\n");
	scanf("%lf %lf", &lat2, &lon2);
	getchar();

	printf("The local distance betwwen the two locations is %f\n", localDistanceKm(lat1, lat2, lon1, lon2));
	printf("The accurate distance betwwen the two locations is %f\n", distanceKm(lat1, lat2, lon1, lon2));

	getchar();
	return 0;
}

double localDistanceKm( double lat1, double lat2, double lon1, double lon2)
{
	double deltay = 111.3 * (lat1 - lat2);
	double deltax = 111.3 * cos(degreeRad(((lat1 + lat2) / 2))) * (lon1 - lon2);
		
	return sqrt(deltax * deltax + deltay * deltay);
}

double distanceKm( double lat1, double lat2, double lon2, double lon1)
{
	return  6378.388 * acos(sin(degreeRad(lat1)) * sin(degreeRad(lat2)) + cos(degreeRad(lat1)) * cos(degreeRad(lat2)) * cos(degreeRad(lon2 - lon1)));
}

double degreeRad(double degree)
{
	double rad = degree * PI / 180;
	return rad;
}