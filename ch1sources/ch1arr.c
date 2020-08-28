/* ch1arr.c */
/* Array use and nested forloops */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* program to show array use */

int main()

{
	int arr1[8];/* define an array of 8 integers */
	
	int arr2[7][8];/* 2D array of integers 7 rows and 8 columns*/


	int i, j, k, l;



	printf("enter 8 integer numbers\n");

	for (i = 0;i < 8;i++)
	{
		scanf("%d", &arr1[i]);/* read into arr1[i] */
	}
	printf("Your 8 numbers are \n");

	for (i = 0;i < 8;i++)
	{
		printf("%d ", arr1[i]);/* write contents of arr1 to command line */
	}
	printf("\n");


	printf("enter number of rows and columns (max 7 rows max 8 columns) \n");
	scanf("%d %d", &k, &l);
	if (k > 7 || l > 8)
	{
		/* User tried to enter more than 7 rows or 8 columns */
		printf("error - max of 8 for rows or columns\n");

	}

	else
	{
		printf("enter array\n");
		/* read i rows and j columns using nested forloop */
		for (i = 0;i < k;i++)
		{
			for (j = 0;j < l;j++)
			{
				scanf("%d", &arr2[i][j]);
			}
		}
		printf("Your array is \n");
		/* print entered 2D array using nested forloop */
		for (i = 0;i < k;i++)
		{
			for (j = 0;j < l;j++)
			{
				printf("%d ", arr2[i][j]);
			}
			printf("\n");

		}
	}
	




}







