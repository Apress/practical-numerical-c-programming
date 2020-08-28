/* createmarket.c  */
/* creates supermarket stock file */
/* prints out the records sequentially */
/* Finds specific records and prints them */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
 
struct super {
   int ID;
   char desc[10];
   int limit;
   int numstock;
   char address[30];
};
 
int main() 
{
	int i,numread;
 	FILE *fp;
 	struct super s1;
	struct super s2;
          
	struct super s10 = {1,"10",23,50,"1,Park St"};
	struct super s11 = {2,"11",34,51,"2,Park St"};	
	struct super s12 = {3,"12",44,52,"3,Park St"};
	struct super s13 = {4,"13",25,53,"4,Park St"};
	struct super s14 = {5,"14",34,54,"5,Park St"};
	struct super s15 = {6,"15",51,55,"6,Park St"};
	struct super s16 = {7,"16",23,56,"7,Park St"};	
	struct super s17 = {8,"17",44,57,"8,Park St"};
	struct super s18 = {9,"18",35,58,"9,Park St"};
	struct super s19 = {10,"19",40,59,"10,Park St"}; 
	struct super s20 = {11,"20",40,60,"11,Park St"};
	struct super s21 = {12,"21",42,61,"12,Park St"};	
	struct super s22 = {13,"22",45,62,"13,Park St"};
	struct super s23 = {14,"23",47,63,"14,Park St"};
	struct super s24 = {15,"24",41,63,"15,Park St"};

	struct super s28 = {16,"25",54,68,"16,Park St"};
	struct super s29 = {17,"26",58,69,"17,Park St"};

   	
	/* Open the Patients file */
	
   	fp = fopen("superm.dat", "w");

	/* Write details of each patient to file*/
	/* From the structures defined above */

   	fwrite(&s10, sizeof(s1), 1, fp);
	fwrite(&s11, sizeof(s1), 1, fp);
	fwrite(&s12, sizeof(s1), 1, fp);
	fwrite(&s13, sizeof(s1), 1, fp);
	fwrite(&s14, sizeof(s1), 1, fp);
   	fwrite(&s15, sizeof(s1), 1, fp);
	fwrite(&s16, sizeof(s1), 1, fp);
	fwrite(&s17, sizeof(s1), 1, fp);
	fwrite(&s18, sizeof(s1), 1, fp);
	fwrite(&s19, sizeof(s1), 1, fp);
   	fwrite(&s20, sizeof(s1), 1, fp);
   	fwrite(&s21, sizeof(s1), 1, fp);
	fwrite(&s22, sizeof(s1), 1, fp);
	fwrite(&s23, sizeof(s1), 1, fp);
	fwrite(&s24, sizeof(s1), 1, fp);
 
	fwrite(&s28, sizeof(s1), 1, fp);
	fwrite(&s29, sizeof(s1), 1, fp);

	/* Close the file */

   	fclose(fp);

 	/* Reopen the file */

	fp=fopen("superm.bin", "r");

	/* Read and print out all of the records on the file */

	for(i=0;i<17;i++)
	{

		numread=fread(&s2, sizeof(s2), 1, fp);

		if(numread == 1)
		{
		
			/*printf( "Number of items read = %d ", numread );*/
		
			/*printf("\nlower limit : %d", s2.llimit);
   			printf("\npressure : %d", s2.press);
   			printf("\nupper limit : %d", s2.ulimit);*/
printf("\nID : %d desc : %s limit : %d numstock : %d address : %s", s2.ID,s2.desc,s2.limit,s2.numstock,s2.address);

		}
		else {
			/* If an error occurred on read then print out message */
 
       			if (feof(fp))

          			printf("Error reading patients.bin : unexpected end of file fp is %p\n",fp);

       			else if (ferror(fp))
	 		{
         	 		perror("Error reading patients.bin");
      	 		}
		}



	
	
	}
	/* Close the file */

	fclose(fp);





}