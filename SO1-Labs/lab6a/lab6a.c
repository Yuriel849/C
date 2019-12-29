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
	
	do
	{
		printf("Reserve seat(s) (q to quit):");
		scanf("%d", &toReserve);

		if (seats[toReserve - 1] > 0)   // If the value of the desired seat is positive, it is vacant.
		{
			seats[toReserve - 1] *= -1; // Multiply -1 to the value of the desired seat, indicating it is now reserved.
			printSeatPlan(seats);
		}
		else
		{
			printf("Unfortunately, this seat is already reserved, please choose another seat.\n");
			continue;
		}
	} while (getchar() != 'q'); // Infinite loop unless 'q' is entered.
}

void printSeatPlan(int *seats)
{
	system("cls");
	for (int seat = 0; seat < size; seat++)
		printf("Seat %d : pointer %d\n", seat + 1, *(seats + seat));
}