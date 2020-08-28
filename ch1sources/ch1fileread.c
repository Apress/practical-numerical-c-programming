/* ch1fileread.c */
/* fileread */
/* read the data from a file and write it to command line */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
	struct record
	{
		double matrix[3][5];
	};
int main()
{
	int counter, i;
	FILE *ptr;
	struct record data_record;
	size_t r1;
	/* Open input file (read/binary) */
	ptr = fopen("testaug.bin", "rb");
	if (!ptr)
	{
		/* error trying to open the file */
		printf("Can not open file");
		return 1;
	}
	/* Read input matrix from input file */
	r1 = fread(data_record.matrix, sizeof(data_record.matrix), 1, ptr);
	printf("read %d elements \n", r1);
	printf("size of struct record is %d \n", sizeof(struct record));
	/* Print matrix read from file */
	/* using nested forloop */
	for (counter = 0; counter < 3; counter++)
	{
		for (i = 0; i < 5; i++)
		{
			printf("matrix[%d][%d] = %lf \n", counter, i, data_record.matrix[counter][i]);
			
		}
	}
	fclose(ptr); /* close the file */
	return 0;
}



















