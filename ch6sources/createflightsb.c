/* createflightsb.c */
/* creates file */
/* prints out the records sequentially */


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h> 

 struct arrivals {
	char posn[3];
	char flight_no[8];
	char sch_arrival_time[6];
	char exp_arrival_time[6];
	char origin[15];
	char remarks[14];
};

struct flightcount {
	int count;
};
int main() 
{
	int i,numread;
	FILE *fparr;
	
	FILE *fltcnt;
	struct arrivals s1;
		
	struct flightcount fc={17};
	struct flightcount fcr;

          
	struct arrivals s10 = {"1","AA1232","07:00","07:00","CHICAGO",""};
	struct arrivals s11 = {"2","BA123","07:05","07:05","LONDON",""};
	struct arrivals s12 = {"3","AA4517","07:08","07:15","BOSTON",""};
	struct arrivals s13 = {"4","AF123","07:10","07:10","PARIS",""};
	struct arrivals s14 = {"5","NH444","07:20","07:20","TOKYO",""};
	struct arrivals s15 = {"6","DJ144","07:22","07:22","MUMBAI",""};
	struct arrivals s16 = {"7","AZ2348","07:23","07:25","WASHINGTON",""};
	struct arrivals s17 = {"8","VS9745","07:25","07:26","TORONTO",""};
	struct arrivals s18 = {"9","DL5816","07:30","07:30","CHICAGO",""};
	struct arrivals s19 = {"10","KL5393","07:33","07:33","MANCHESTER",""};
	struct arrivals s20 = {"11","AZ4627","07:35","07:40","ROME",""};
	struct arrivals s21 = {"12","VS4677","07:40","07:40","NEW ORLEANS",""};
	struct arrivals s22 = {"13","SQ125","07:45","07:45","FRANKFURT",""};
	struct arrivals s23 = {"14","EI5666","07:48","07:48","LONDON",""};
	struct arrivals s24 = {"15","WS2321","07:50","07:50","DULLES",""};
	struct arrivals s25 = {"16","AA197","07:55","08:00","SAN FRANCISCO",""};
	struct arrivals s26 = {"17","B57321","07:58","07:48","SARASOTA",""};
	
	
	/* Create the file flightcnt.dat which will contain */
	/* the current number of flights in arrivals.dat. */
	/* This file can then be updated when flights are */
	/* removed from arrivals.dat to keep a running total */	
	
	fltcnt = fopen("flightcnt.dat","w");
	fwrite(&fc, sizeof(fc), 1, fltcnt);
	fclose(fltcnt);	

	fltcnt = fopen("flightcnt.dat","r");
	fread(&fcr, sizeof(fcr), 1, fltcnt);
	printf(" Number of flights : %d", fcr.count);
	fclose(fltcnt);	
	/* Open the arrivals file */
	
   	fparr = fopen("arrivals.dat", "w");

	/* Write details of each flight to file*/
	/* From the structures defined above */

   	fwrite(&s10, sizeof(s1), 1, fparr);
	fwrite(&s11, sizeof(s1), 1, fparr);
	fwrite(&s12, sizeof(s1), 1, fparr);
	fwrite(&s13, sizeof(s1), 1, fparr);
	fwrite(&s14, sizeof(s1), 1, fparr);
   	fwrite(&s15, sizeof(s1), 1, fparr);
	fwrite(&s16, sizeof(s1), 1, fparr);
	fwrite(&s17, sizeof(s1), 1, fparr);
	fwrite(&s18, sizeof(s1), 1, fparr);
	fwrite(&s19, sizeof(s1), 1, fparr);
   	fwrite(&s20, sizeof(s1), 1, fparr);
   	fwrite(&s21, sizeof(s1), 1, fparr);
	fwrite(&s22, sizeof(s1), 1, fparr);
	fwrite(&s23, sizeof(s1), 1, fparr);
	fwrite(&s24, sizeof(s1), 1, fparr);
 
	fwrite(&s25, sizeof(s1), 1, fparr);
	fwrite(&s26, sizeof(s1), 1, fparr);

	/* Close the file */

   	fclose(fparr);
	/* Reopen the file */

	fopen("arrivals.dat", "r");

	/* Read and print out all of the records on the file */
	printf("\n   	Flight :Sched:  Exp: 	Origin         Remarks");
	for(i=0;i<17;i++)
	{

		numread=fread(&s1, sizeof(s1), 1, fparr);

		if(numread == 1)
		{
			printf("\n :%s\t%s\t%s\t%s\t%s\t%s", s1.posn,s1.flight_no,s1.sch_arrival_time,s1.exp_arrival_time,s1.origin,s1.remarks);			
		}
		else {
			/* If an error occurred on read then print out message */
 
       			if (feof(fparr))

          			printf("Error reading arrivals.dat : unexpected end of file fparr is %p\n",fparr);

       			else if (ferror(fparr))
	 		{
         	 		perror("Error reading arrivals.dat");
      	 		}
		}

	
	}
	/* Close the file */

	fclose(fparr);
   	
	
}