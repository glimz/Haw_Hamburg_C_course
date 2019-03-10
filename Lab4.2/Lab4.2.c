#include<stdio.h>
#include<math.h>

#define PI 3.14159265359
#define SIZE 7

double distanceKm(double lat1, double lat2, double lon2, double lon1);
double degreeRad(double degree);
void largestDist(double *latLonArray, int rows, int *locA, int *locB, double *distance);

int main(void)
{
	int locA, locB;
	double distance;

	char *name[] = { "Haw Hmaburg", "Eiffel Tower", "Palma de Mallorca", "Las Vegas", "Copacabana", "Waikiki Beach", "Surfer`s paradise" };

	double route[SIZE][2] = {{ 53.557079, 10.023109 }, { 48.858363, 2.294481 }, { 39.562553, 2.661947 }, { 36.156214, -115.148736 }, { -22.971177, -43.182543 }, { 21.281004, -157.837456 }, { -28.002695, 153.431781 }
};
	
	largestDist(route, SIZE, &locA, &locB, &distance);
		
	printf("%s and %s have the largest distance %.11fkm\nYou better not walk. Take a flight, instead.", name[locA], name[locB], distance );
	
	getchar();
	return 0;
}

/*functon to calculate distance of two routes in km*/
double distanceKm(double lat1, double lat2, double lon2, double lon1)
{
	return  6378.388 * acos(sin(degreeRad(lat1)) * sin(degreeRad(lat2)) + cos(degreeRad(lat1)) * cos(degreeRad(lat2)) * cos(degreeRad(lon2 - lon1)));
}

/*function to convert degree to radian*/
double degreeRad(double degree)
{
	double rad = degree * PI / 180;
	return rad;
}

/*largest distance btw two location*/
void largestDist( double *latLonArray, int rows, int *locA, int *locB, double *distance )
{
	double distKm, lat1, lon1, lat2, lon2, radianConv;

	for (int i = 0; i < rows; i++)
	{
		lat1 = latLonArray[i * 2];
		lon2 = latLonArray[i * 2 + 1];

		for (int p = i + 1; p < rows; p++)
		{
			lat2 = latLonArray[p * 2];
			lon2 = latLonArray[p * 2 + 1];


			radianConv = distanceKm(lat1, lat2, lon2, lon1);

			/*check <uncomment to use>*/
			//printf("%20lf %20lf %20lf %20.3lf \n", lat1, lon1, lat2, lon2, distKm );

			/*comparing distances btw 2 point*/
			if (distKm > *distance)
			{
				*distance = distKm;
				*locA = i;
				*locB = p;
			}
		}
		/*check <uncomment to use>*/
		//printf("----------------------------------------------------------------\n");
	}
}