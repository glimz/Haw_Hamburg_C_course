#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define SEATS 50

/*structure for the seat information*/
typedef struct {
	int rowNum;
	char position;
	int reserved;
}seatInfo;

/* prototype */ 
int printSeating(FILE*, seatInfo[SEATS]);
void reserveSeat(seatInfo[], int);
int smallCapital(int);

int main(void)
{
	FILE *file;
	int emptySeat = 0;
	char position;
	int row, posVar;
	seatInfo seats[SEATS];

	/* seat arrangement*/
	for (int i = 0; i < SEATS; i++) 
	{
		seats[i].rowNum = i / 4 + 1;
		if (seats[i].rowNum == 13)
			seats[i].rowNum = 14;
		seats[i].position = 'A' + i % 4;
		seats[i].reserved = 0;
	}

	/* loop for user input and resvervation of the seats*/ 
	while (1)
	{
		emptySeat = printSeating(stdout, seats);
		fprintf(stdout, "\nVacant: %2d  Reserved: %2d", emptySeat, SEATS - emptySeat);
		printf("\nReserve seat(s). (q to quit):\n");
		while (1)
		{
			printf("Seat: ");
			scanf("%d", &row);
			scanf("%c", &position);
			if (position == 'q')
			{
				/*saving and printing the palne seats in a txt file*/
				file = fopen("C:\\Users\\aci634\\Desktop\\flightPlan.txt", "w");
				printSeating(file, seats);
				fprintf(file, "\nVacant: %2d  Reserved: %2d", emptySeat, SEATS - emptySeat);
				fclose(file);
				return 0;
			}

			/*checking the reservation and making sure the input is valid*/ 
			posVar = smallCapital((int)position);
			if (row < 1 || row > 14 || row == 13 || posVar < 65 || posVar > 68 || (row == 14 && posVar > 66))
			{
				while (getchar() != '\n') 
					continue;
				printf("That isn't a valid seat.\nTry again.\n");
					continue;
			}
			if (row == 14)
				row = 13;
			break;
		}
		reserveSeat(seats, 4 * (row - 1) + posVar - 65);
		while (getchar() != '\n')
			continue;
#ifdef _WIN32
		system("cls");  // clearing the screen 
#endif
	}
	getchar();
	return 0;
}

/* function for printing seating arrangment*/
int printSeating(FILE* file, seatInfo seats[SEATS])
{
	int count = 0;
	fprintf(file, "  /                 \\ \n /                   \\ \n+                     +\n|");
	for (int g = 1; g <= SEATS; g++)
	{
		fprintf(file, " %2d%c", seats[g - 1].rowNum, seats[g - 1].position);
		if (seats[g - 1].reserved == 0)
		{
			fprintf(file, "*");
			count += 1;
		}
		else
			fprintf(file, " ");
		if (g % 4 == 0)
			fprintf(file, " |\n|");
	}
	return count;
}

/*function to convert small letters into capital*/
int smallCapital(int b)
{
	if (b > 96 && b < 101)
		b = b - 32;
	return b;
}

/*function to reserve a seat function*/
void reserveSeat(seatInfo seat[], int place)
{
	if (seat[place].reserved == 0)
		seat[place].reserved = 1;
	else if (seat[place].reserved == 1)
		seat[place].reserved = 0;
}



