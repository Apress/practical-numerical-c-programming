/* plantb.c */
/* industrial plant simulation */
/* Finds specific records and prints them */
/* Checking power plant temperature and flow rate */	
/* against acceptable levels */
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
	float fptemp,fpflow;
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

	printf("\nenter ID   \n");
	scanf("%d", &fpid);	

	printf("\n ID is %d",fpid);

	/* User asked to enter the Current temperature being minitored */

	printf("\nenter current temperature   \n");

	scanf("%f", &fptemp);	

	printf("\n current temperature is %f",fptemp);

	/* Current temperature checked against range of temperature */
	/* An Alert is displayed if the temperature is outside the range */
				
		for (i = 0;i < 17;i++)
		{
			
			if(fpid == st[i].ID)
			
			{
				
				printf("\n high temp is %f",st[i].hightemp);
				/*printf("\n struct upper press is %d",st[i].ulimit);*/
				/*if(fppress < st[i].llimit)
					printf("\n ALERT! Pressure is below lower limit");*/
				if(fptemp > st[i].hightemp)
					printf("\n ALERT! Temperature is above upper limit");
			}

		}
	
	/* User asked to enter the Flow Rate being minitored */	

	printf("\nenter current flow rate   \n");
	scanf("%f", &fpflow);	

	printf("\n current flow rate is %f",fpflow);

	/* Flow Rate checked against limits */
	/* An Alert is displayed if the flow rate is outside the range */
				
		for (i = 0;i < 17;i++)
		{
			
			if(fpid == st[i].ID)
			
			{
				
				printf("\n high flow rate is %f",st[i].highflow);
				
				if(fpflow > st[i].highflow)
					printf("\n ALERT! Flow rate is above upper limit");
			}

		}
		
		
}