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
	Making reservations with user input		:
		Initially all seats are vacant.
		Users are repeatedly prompted to reserve a seat. If vacant, its status is changed to reserved and the console output is updated.
		Users are allowed to use capital or small letters when reserving a seat (e. g., "7A" or "7a").
	Exiting the program						:
		Write the console output to a text file (e. g., flightPlan.txt) before exiting the program.
			Implement a function that writes the seat plan either to the console or to a text file.
			Use fprintf() and pass stdout (to write to the console) or the file pointer as argument.
 */

#define _CRT_SECURE_NO_DEPRECATE			// To use scanf() without warnings
#define size 50								// The number of seats in the CRJ-200 aircraft

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
void printSeatPlan(seatInfo *seats, char printMode);
void clearBuffer(void);

int main(void)
{
	seatInfo *seats;
	
	if((seats = (seatInfo*)malloc(sizeof(seatInfo) * size)) == NULL)
		exit(EXIT_FAILURE);

	for (int row = 0; row < size / 4 + 1; row++)		 // row		 == 0 ~ 12
		for (int position = 0; position < 4; position++) // position == 0 ~ 3
			if(4 * row + position < 50) // Because the last row has only two seats 
				*(seats + (4 * row) + position) = (seatInfo) { (row == 12) ? 14 : row + 1, 'A' + position, '*' };

	reserveSeat(seats);

	free(seats);
	getchar();
	return 0;
}

void reserveSeat(seatInfo *seats)
{
	int rowReserve = 0;			// Row number for the desired seat
	char positionReserve = ' '; // Position letter for the desired seat
	int scanReturn = 0;			// Return value of scanf() => How many values were correctly scanned
	char bufferValue = ' ';		// Value of the input buffer (Exit the program if 'q' or 'Q')
	int index = 0;				// Value of the chosen row and position as a number between 0 ~ 49
	
	printSeatPlan(seats, 's');  // Initially print seating plan for user to see.
	printf("\n");
	
	while(1)
	{
		printf("Reserve seat(s) (q to quit):");
		scanReturn = scanf("%d%c", &rowReserve, &positionReserve);
		if (positionReserve >= 'a' && positionReserve <= 'z') // If input is a lowercase letter, change to capital letter
			positionReserve -= 32;							  // 'A' ~ 'Z' == 65 ~ 90, 'a' ~ 'z' == 97 ~ 122
		index = (rowReserve - 1) * 4 + (positionReserve - 'A');

		if ((scanReturn != 2) ||													  // If the row and position are not properly scanned
			!((rowReserve > 0 && rowReserve <= 12) || rowReserve == 14) ||			  // If row is not 0 ~ 12 or 14
			!(positionReserve >= 'A' && positionReserve <= 'D') ||					  // If position is not A ~ D
			(rowReserve == 14 && positionReserve != 'A' && positionReserve != 'B')) // If row == 14 but position is not A or B
		{
			bufferValue = getchar();
			if (bufferValue == 'q' || bufferValue == 'Q')	  // User desires to exit the program
			{
				printf("\nThank you for utilizing our services. Auf Wiedersehen!\n");
				printSeatPlan(seats, 'q');					  // Write to file "flightPlan.txt" before exiting program
				break;
			}
			else
			{
				ungetc(bufferValue, stdin);					  // If not 'q' or 'Q', return to input buffer (for cleanBuffer())
				printf("Please enter a valid seat number.\n");
			}
		}
		else if (rowReserve == 14 && (seats[index - 4].status == '*'))
		{
			seats[index - 4].status = ' ';
			printSeatPlan(seats, 's');
		}
		else if (seats[index].status == '*')
		{
			seats[index].status = ' ';
			printSeatPlan(seats, 's');
		}
		else
			printf("Unfortunately, this seat is already reserved, please choose another seat.\n");

		clearBuffer();
	}
}

void printSeatPlan(seatInfo *seats, char printMode)
{
	int counter = 0, index = 0; // counter is for counting number of reserved seats, index is for using the seatInfo array
	FILE *file = fopen("flightPlan.txt", "w");

	if (printMode == 's')		// stdout, print to console
	{
		system("cls");			// Clear the console before printing
		fprintf(stdout, " Seating plan Bombardier CRJ-200\n    /                   \\   \n   /                     \\  \n  +                       + \n");
		for (int row = 0; row < size / 4 + 1; row++)
		{
			fprintf(stdout, "  | ");
	
			for (int position = 0; position < 4; position++)
			{
				index = 4 * row + position;
				if (index < 50)
				{
					fprintf(stdout, "%3d%c%c", seats[index].rowNumber, seats[index].position, seats[index].status);
					if ((seats[index].status == ' '))
						counter++;
				}
				else // For the 13th row, where there are only two seats
				{
					fprintf(stdout, "          ");
					break;
				}
			}

			fprintf(stdout, "  | \n");
		}
		fprintf(stdout, "  | %2d reserved, %2d vacant*  \n", counter, size - counter);
	}
	else if (file != NULL)		// write to file, prior to exiting program
	{
		fprintf(file, " Seating plan Bombardier CRJ-200\n    /                   \\   \n   /                     \\  \n  +                       + \n");
		for (int row = 0; row < size / 4 + 1; row++)
		{
			fprintf(file, "  | ");
	
			for (int position = 0; position < 4; position++)
			{
				index = 4 * row + position;
				if (index < 50)
				{
					fprintf(file, "%3d%c%c", seats[index].rowNumber, seats[index].position, seats[index].status);
					if ((seats[index].status == ' '))
						counter++;
				}
				else // For the 13th row, where there are only two seats
				{
					fprintf(file, "          ");
					break;
				}
			}

			fprintf(file, "  | \n");
		}
		fprintf(file, "  | %2d reserved, %2d vacant*  \n", counter, size - counter);
	}

	fclose(file);
}

void clearBuffer(void)
{
	while (getchar() != '\n')
		continue;
}