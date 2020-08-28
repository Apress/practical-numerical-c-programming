/* createplantb.c  */
/* industrial plant simulation */
/* Creates file */
/* reads from file */
/* prints out the records sequentially */

/* power plant temperature and flow rate */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
 
struct fplant {
   int ID;
   float temp;
   float flowrate;
   float hightemp;
   float highflow;	
};
 
int main() 
{
	int i,numread;
 	FILE *fp;
 	struct fplant s1;
	struct fplant s2;
          
	struct fplant s10 = {1,10,23,50,50};
	struct fplant s11 = {2,11,34,51,50};	
	struct fplant s12 = {3,12,44,52,50};
	struct fplant s13 = {4,13,25,53,50};
	struct fplant s14 = {5,14,34,54,50};
	struct fplant s15 = {6,15,51,55,50};
	struct fplant s16 = {7,16,23,56,50};	
	struct fplant s17 = {8,17,44,57,50};
	struct fplant s18 = {9,18,35,58,50};
	struct fplant s19 = {10,19,40,59,50}; 
	struct fplant s20 = {11,20,40,60,50};
	struct fplant s21 = {12,21,42,61,50};	
	struct fplant s22 = {13,22,45,62,50};
	struct fplant s23 = {14,23,47,63,50};
	struct fplant s24 = {15,24,41,63,50};

	struct fplant s28 = {16,28,54,68,50};
	struct fplant s29 = {17,29,58,69,50};

   	
	/* Open the file */
	
   	fp = fopen("tempflow.bin", "w");

	/* Write details of each ID to file*/
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

	fp=fopen("tempflow.bin", "r");

	/* Read and print out all of the records on the file */

	for(i=0;i<17;i++)
	{

		numread=fread(&s2, sizeof(s2), 1, fp);

		if(numread == 1)
		{
		
			printf("\nID : %d temp : %f flow rate : %f high temp : %f high flow : %f", s2.ID,s2.temp,s2.flowrate,s2.hightemp,s2.highflow);

		}
		else {
			/* If an error occurred on read then print out message */
 
       			if (feof(fp))

          			printf("Error reading tempflow.bin : unexpected end of file fp is %p\n",fp);

       			else if (ferror(fp))
	 		{
         	 		perror("Error reading tempflow.bin");
      	 		}
		}

	
	}
	/* Close the file */

	fclose(fp);





}