/*
Author	    : Myungjun Kim
Contents    : Implementation of the seating plan for the Bombardier CRJ-200 aircraft.
Instructions:
	The CRJ-200 has 50 seats and every row, except for the last one, has 4 seats. The last row consists of only 2 seats.
	Every seat is either vacant or reserved.
Requirements:
	Information to be printed to the console:
		Each seat should show its row number, position A to D within the row, and reservation status (vacant or reserved).
		Overall number of vacant seats and number of reserved seats.
		Skip row number 13 (i. e., row 12 is succeeded by row 14).
	Making reservations						:
		Initially all seats are vacant.
		Users are repeatedly prompted to reserve a seat. If vacant, its status is changed to reserved and the console output is updated.
		Users are allowed to use capital or small letters when reserving a seat (e. g., "7A" or "7a").
	Exiting the program						:
		Write the console output to a text file (e. g., flightPlan.txt) before exiting the program.
			Implement a function that writes the seat plan either to the console or to a text file.
			Use fprintf() and pass stdout (to write to the console) or the file pointer as argument.
 */

#define _CRT_SECURE_NO_DEPRECATE	// To use scanf() without warnings
#define size 50						// The number of seats in the CRJ-200 aircraft

#include <stdio.h>
#include <stdlib.h>

// Structure
typedef struct {
	int rowNumber; // Row number
	char position; // Position A to D in a row
	char status;	   // Reservation status
} seatInfo;

// Function prototypes
void reserveSeat(seatInfo *seats);
void printSeatPlan(seatInfo *seats);
void clearBuffer(void);

int main(void)
{
	seatInfo *seats;
	
	if((seatInfo*)malloc(sizeof(seatInfo) * size) == NULL)
		exit(EXIT_FAILURE);

	for (int row = 0; row < size / 4 + 1; row++)		 // row		 == 0 ~ 12
		for (int position = 0; position < 4; position++) // position == 0 ~ 3
			if(4 * row + position < 50) // Because the last row has only two seats 
				*(seats + (4 * row) + position) = (seatInfo) { (row == 12) ? 14 : row + 1, 'A' + position, '*' };

	printSeatPlan(seats);
	//reserveSeat(seats);

	free(seats);
	getchar();
	return 0;
}

void reserveSeat(int *seats)
{
	int toReserve = 0;
	
	printSeatPlan(seats); // Initially print seating plan for user to see.
	printf("\n");

	while(1)
	{
		printf("Reserve seat(s) (q to quit):");

		if (scanf("%d", &toReserve) != 1)				// For all non-integer input
		{
			if (getchar() == 'q')
				break;
			printf("Please enter a valid seat number.\n");
		}
		else if (!(toReserve > 0 && toReserve <= 50))	// For integers outside the range of 1-50
			printf("Please enter a valid seat number.\n");
		else if (seats[toReserve - 1] > 0 && seats[toReserve - 1] <= 50) // If the value of the desired seat is positive, it is vacant.
		{
			seats[toReserve - 1] *= -1; // Negative integer indicates reserved seat.
			printSeatPlan(seats);
		}
		else
			printf("Unfortunately, this seat is already reserved, please choose another seat.\n");

		clearBuffer();
	}
}

void printSeatPlan(seatInfo *seats)
{
	int counter = 0;

	system("cls");
	printf(" Seating plan Bombardier CRJ-200\n    /                   \\   \n   /                     \\  \n  +                       + \n");
	for (int row = 0; row < size / 4 + 1; row++)
	{
		printf("  | ");
	
		for (int position = 0; position < 4; position++)
		{
			if (4 * row + position < 50)
			{
				printf("%3d%c%c", seats[(4 * row) + position].rowNumber, seats[(4 * row) + position].position, seats[(4 * row) + position].status);
				if ((seats[(4 * row) + position].status == ' '))
					counter++;
			}
			else
			{
				printf("          ");
				break;
			}
		}

		printf("  | \n");
	}
	printf("  | %2d reserved, %2d vacant*  \n", counter, size - counter);
}

void clearBuffer(void)
{
	while (getchar() != '\n')
		continue;
}