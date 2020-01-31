#include <stdio.h>

/*
	main() != main(void)
		() means any or no argument is accepted
		(void) means there is no parameter at all and thus no argument is accepted
 */

 /* To add comments...
	 Add "//"comment --> ctrl + k + c
	 Remove "//" comment --> ctrl + k + u
	 Add & remove comments --> shift + ctrl + /
  */

  /* NOP */ // => comment indicating there is supposed to be nothing here, "No OPeration"

int main(void) // There can only be ONE(1) main() in a project
{
	// all commands within a function are called statements and must end with a semicolon (";")
	printf("So..... the first \'program\' for this course in C :)");
	getchar(); // Defined in stdio.h, forces the program to stop and wait for the user to enter something
	return 0;
}