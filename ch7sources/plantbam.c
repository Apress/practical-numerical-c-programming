/* plantbam.c */
/* industrial plant simulation */
/* power plant temperature and flow rate */
/* Allows amendments to tempflow.bin file */	
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct fplant {
   int ID;
   float temp;
   float flowrate;
   float hightemp;
   float highflow;	
};




int main()
{
	FILE *fp;
	
 	struct fplant s2;
	struct fplant st[17];
	int i;
	int fpid;
	float fnewtemp;
	long int minusone = -1;

	/* Open tempflow.bin file */

	fp = fopen("tempflow.bin", "r");
	for (i = 0;i < 17;i++)
	{
		/* Read each pressure data from file sequentially */
		fread(&s2, sizeof(s2), 1, fp);
		/* Print pressure data each component */

		st[i].ID = s2.ID;
		st[i].temp = s2.temp;
		st[i].flowrate = s2.flowrate;
		st[i].hightemp = s2.hightemp;
		st[i].highflow = s2.highflow;

		printf("\nID : %2d temp : %f flow rate : %f high temp : %f high flow : %f", s2.ID,s2.temp,s2.flowrate,s2.hightemp,s2.highflow);
	}

	fclose(fp);

	/* User asked to enter the ID being minitored */
	
	fp = fopen("tempflow.bin", "r+");
	printf("\nenter ID   \n");
	scanf("%d", &fpid);	

	printf("\n ID is %d",fpid);


				
		for (i = 0;i < 17;i++)
		{
			fread(&s2, sizeof(s2), 1, fp);	
			if(fpid == s2.ID)
			
			{
				/* User asked to enter the new temperature being minitored */

				printf("\nenter new temperature   \n");
				scanf("%f", &fnewtemp);	

				printf("\n new temperature is %f",fnewtemp);
				st[i].temp = s2.temp;
				s2.temp = fnewtemp;

				/* File updated with new temperature */
				fseek(fp,minusone*sizeof(s2),SEEK_CUR);
				fwrite(&s2, sizeof(s2), 1, fp);

				printf("\nID : %d temp : %f flow rate : %f high temp : %f high flow : %f", s2.ID,s2.temp,s2.flowrate,s2.hightemp,s2.highflow);	
				break;		
				
			}
			
		}
		
	fclose(fp);	
			


	
}