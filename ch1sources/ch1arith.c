/* ch1arith.c */
/* Read, display and arithmetics */
/* Input data from the command line */
/* and read it into the program. */
/* Also write the data back to the */
/* command line. Basic arithmetic */
/* done on input data. */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main ()
{
	char c;	/* store for character entered */
	int this_is_a_number1, this_is_a_number2, total;	/* store for two integers entered */
	float float_number1, float_number2,float_total;		/* store for two decimals entered */


/* read and display a character */

	printf("Enter character: "); /* tell the user to enter a character */
	c = getchar(); /* read the character in */
 
	printf("Character entered: ");/* tell the user what was entered */
	putchar(c); /* write the character */

   


/* Read in two integers , add  them  and display the answer */


	printf("\nPlease enter an integer number:\n ");
	scanf("%d", &this_is_a_number1); /* read number into this_is_a_number1 */
	printf("You entered %d\n", this_is_a_number1);

	printf("Please enter another integer number: \n");
	scanf("%d", &this_is_a_number2); /* read number into this_is_a_number2 */
	printf("You entered %d\n", this_is_a_number2);

	total = this_is_a_number1 + this_is_a_number2;/* add two numbers */
	printf("sum of your two integer numbers is %d\n", total); /* write result to command line */

	


/*  Add two floating point numbers */

	
	printf("Please enter a decimal number:\n ");
	scanf("%f", &float_number1); /* read decimal number into float_number1  */
	printf("You entered %f\n", float_number1);

	printf("Please enter another decimal number: \n");
	scanf("%f", & float_number2); /* read decimal number into float_number2 */
	printf("You entered %f\n", float_number2);

	float_total = float_number1+float_number2;/* add the numbers */
	printf("sum of your two decimal numbers is %f\n", float_total);/* write result to command line */

	



/*  multiply two floating point numbers */


	

	float_total = float_number1 * float_number2;/* multiply the numbers */
	printf("product of your two decimal numbers is %f\n", float_total);/* write result to command line */

	

/*  divide two floating point numbers */

	
	float_total = float_number1 / float_number2;/* divide the numbers */ 
	printf("quotient of your two decimal numbers is %f\n", float_total);/* write result to command line */

	return 0;
}

