/* ch1sw.c */
/* demonstrate switches or characters or numbers */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Example of a switch operation */
int main()
{
	int this_is_a_number; /* store area to hold number entered */
	char this_is_a_character;/* store area to hold character entered */

	printf("\nPlease enter a character a,b,c,d or e:\n ");
	scanf("%c", &this_is_a_character);/* read into this_is_a_character */

	/* switch to the specific "case" for the character entered */
	/* then print which switch case was entered */
	switch (this_is_a_character)
	{

	case 'a':
		printf("Case1: Value is: %c", this_is_a_character);
		break;
	case 'b':
		printf("Case2: Value is: %c", this_is_a_character);
		break;
	case 'c':
		printf("Case3: Value is: %c", this_is_a_character);
		break;
	case 'd':
		printf("Case4: Value is: %c", this_is_a_character);
		break;
	case 'e':
		printf("Case5: Value is: %c", this_is_a_character);
		break;
	default:
		/* The character entered was not between a,b,c,d or e */
		printf("Error Value is: %c", this_is_a_character); 
	}

	printf("Please enter an integer between 1 and 5:\n ");
	scanf("%d", &this_is_a_number);

	/* switch to the specific "case" for the number entered */
	/* then print which switch case was entered */
	switch (this_is_a_number)
	{

	case 1:
		printf("Case1: Value is: %d", this_is_a_number);
		break;
	case 2:
		printf("Case2: Value is: %d", this_is_a_number);
		break;
	case 3:
		printf("Case3: Value is: %d", this_is_a_number);
		break;
	case 4:
		printf("Case4: Value is: %d", this_is_a_number);
		break;
	case 5:
		printf("Case5: Value is: %d", this_is_a_number);
		break;
	default:
		/* The number entered was not between 1 and 5 */
		printf("Error Value is: %d", this_is_a_number); 
	}



	return 0;
}






