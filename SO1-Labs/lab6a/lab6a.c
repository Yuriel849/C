/*
Author	    : Myungjun Kim
Contents    : Implementation of the seating plan for the Bombardier CRJ-200 aircraft.
Instructions:
	The CRJ-200 has 50 seats and every row, except for the last one, has 4 seats. The last row consists of only 2 seats.
	Every seat is either vacant or reserved.
Requirements:
	Information to be printed to the console:
		Reservation status (vacant or reserved) for each seat
		Overall number of vacant seats and number of reserved seats
	Making reservations:
		Initially all seats are vacant.
		Users are repeatedly prompted to reserve a seat. If vacant, its status is changed to reserved and the console output is updated.
 */

#define _CRT_SECURE_NO_DEPRECATE	// To use scanf() without warnings
#define size 50						// The number of seats in the CRJ-200 aircraft

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void reserveSeat(int *seats);
void printSeatPlan(int *seats);
void clearBuffer(void);

int main(void)
{
	int *seats = (int*)malloc(sizeof(int) * size);
	for (int seat = 0; seat < size; seat++)
		*(seats + seat) = seat + 1;

	reserveSeat(seats);

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

		if (scanf("%d", &toReserve) != 1) // For all non-integer input
		{
			if (getchar() == 'q') // If 'q' was entered, scanf() returns 0 and 'q' remains in the input buffer
				break;
			printf("Please enter a valid seat number.\n");
		}
		else if (!(toReserve > 0 && toReserve <= 50)) // For integers outside the range of 1-50
			printf("Please enter a valid seat number.\n");
		else if (seats[toReserve - 1] > 0 && seats[toReserve - 1] <= 50) // If the value of the desired seat is positive, it is vacant.
		{
			seats[toReserve - 1] *= -1; // Multiply -1 to the value of the desired seat, indicating it is now reserved.
			printSeatPlan(seats);
		}
		else
			printf("Unfortunately, this seat is already reserved, please choose another seat.\n");

		clearBuffer();
	}
}

void printSeatPlan(int *seats)
{
	int flag = 0, counter = 0;

	system("cls");
	printf("Seating plan Bombardier CRJ-200\n   /                \\   \n  /                  \\  \n +                    + \n");
	for (int seat = 0; seat < 50; seat += 4)
	{
		printf(" |  ");
		for (int column = 0; column < 4; column++)
		{
			if (seat + column == 50)
			{
				printf("        ");
				break;
			}
			if (*(seats + seat + column) < 0)
			{
				flag = 1;
				counter++;
			}
			printf("%3d%c", (flag == 1) ? *(seats + seat + column) * -1 : *(seats + seat + column), (flag == 1) ? ' ' : '*');
			flag = 0;
		}

		printf("  | \n");
	}
	printf(" | %2d reserved, %2d vacant*  \n", counter, size - counter);
}

void clearBuffer(void)
{
	while (getchar() != '\n')
		continue;
}