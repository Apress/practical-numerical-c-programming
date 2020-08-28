/* ch1funcans.c */
/* demonstrate function returning an answer */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


/* Function which returns an answer  */
/* finds the pupil in one year of the school with the highest marks */

#include <stdio.h>
double getmarks(double pupils[]);

int main()
{
	double pupil;
	/* Array with marks for class is preset in the main part of the program */
	double marks[] = { 10.6, 23.7, 67.9, 93.0, 64.2, 33.8 ,57.5 ,82.2 ,50.7 ,45.7 };
	/* Call function getmarks. The function returns the max marks which is then stored in pupil */
	pupil = getmarks(marks);
	printf("Max mark is  = %f", pupil);
	return 0;
}

double getmarks(double pupils[])
{
	int i;
	double highest;
	highest = 0;
	/* Go through all the pupils in turn and store the highest mark */
	for (i = 0; i < 6; ++i)
	{
		if (highest < pupils[i])
			highest = pupils[i];

	}
	return highest; /* returns the value in highest to where the function was called */
}









