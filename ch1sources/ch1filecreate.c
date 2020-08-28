/* ch1filecreate.c */
/* filecreate */
/* Creates a file freom data preset */
/* into the 2D array of the program. */
/* Then prints the data to the user */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
int main()
{
	struct record
	{
		double matrix[3][5];
	};
	int /*counter,*/ i, j;
	FILE *ptr;
	struct record data_record;
	size_t r1;

	double inmat[3][5] = {
		{2.6,3.1,7.4,0.6,9.3},
		{4.9,9.3,0.6,7.4,3.1},
		{8.3,8.8,5.2,2.7,0.8}
		
	};
	/* Copy preset array to output array */
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 5;j++)
		{
			data_record.matrix[i][j] = inmat[i][j];
		}
	}
	/* Open output file (write/binary) */
	ptr = fopen("testaug.bin", "wb");
	if (!ptr)
	{
		/* Error when trying to open file */
		printf("Can not open file");
		return 1; /* quit the program */
	}
	/* Write output matrix to output file */
	r1 = fwrite(data_record.matrix, sizeof(data_record.matrix), 1, ptr);
	printf("wrote %d elements \n", r1);
	printf("size of data_record.matrix is %d \n", sizeof(data_record.
		matrix));
	/* Print matrix written to file */
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 5;j++)
		{
			data_record.matrix[i][j] = inmat[i][j];
			printf("data_record.matrix[%d][%d] = %lf \n", i, j,
			data_record.matrix[i][j]);
		}
	}

	fclose(ptr); /* Close the file */
	return 0;
}
















