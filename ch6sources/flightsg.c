/* flightsg.c */

/* Airport display boards updates*/	
/* arrivals only */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

main()
{
	char fltno[8];
	char ch;
	int ret;
	int opt2;
	int eofcheck;

	/* Structure definition for arrivals file */
	/* This contains the flight number, scheduled */
	/* arrival time, expected arrival time, airport */
	/* from where the flight left and remarks, which */
	/* contains current information eg "landed" etc */

	struct arrivals {
		char posn[3];
		char flight_no[8];
		char sch_arrival_time[6];
		char exp_arrival_time[6];
		char origin[15];
		char remarks[14];
	};
	/* Structure for flightcnt.dat file */
	/* which contains the current number */
	/* of flights */
		struct flightcount {
		int count;
	};

	FILE *source, *target;
	FILE *fparr;
	FILE *fparr2;
	FILE *fltcnt; 
	struct arrivals s1;
	
	    
	struct arrivals st[17];    
	struct flightcount fc;

	char new_sch_arrival_time[6];
	char new_exp_arrival_time[6];
	char new_origin[15];
	char new_remarks[14];

	int  i,opt;
	int lim;
	long int minusone = -1;
	char rollup;

	char oldname[] = "arrivals2.dat";
  	char newname[] = "arrivals.dat";

	fltcnt = fopen("flightcnt.dat","r");
	fread(&fc, sizeof(fc), 1, fltcnt);
	printf(" Number of flights : %d", fc.count);
	opt2 = fc.count;
	fclose(fltcnt);	

	/* Open arrivals file */

	fparr = fopen("arrivals.dat", "r");
	printf("\n        Flight\t:Sched:\tExp:\tOrigin:\t        Remarks");




	for (i = 0;i < 17;i++)
	{
		/* Read each flight data from file sequentially */
		/* and display them */
		if(fread(&s1, sizeof(s1), 1, fparr) == 1)
		{
			/* Print flight no, sched and expected time and flight originfor each flight */

		
			strcpy(st[i].posn,s1.posn);
			strcpy(st[i].flight_no,s1.flight_no);
			strcpy(st[i].sch_arrival_time,s1.sch_arrival_time);
			strcpy(st[i].exp_arrival_time,s1.exp_arrival_time);
			strcpy(st[i].origin,s1.origin);
			strcpy(st[i].remarks,s1.remarks);

			/* Only print the first 12 flights on the "display board" */
			if(opt2 < 12)
				lim = opt2;
			else
				lim = 12;

			if(i<lim)
				printf("\n : %s\t%s\t%s\t%s\t%s\t\t%s", s1.posn,s1.flight_no,s1.sch_arrival_time,s1.exp_arrival_time,s1.origin,s1.remarks);
		}

	}
	

	fclose(fparr);

	/* The flights can be rolled up (when a flight had landed) */
	/* or amendments made to the display */
	
	printf("\nroll up ? y or n \n");
	scanf("%c", &rollup);		
	if(rollup == 'n')
	{
		/* Amendments can be made to the scheduled arrival time, */
		/* the expected arrival time, the airport of origin */
		/* or remarks for the flight */

		/* The flight number is asked for */
		printf("\nenter flight number  (max 10 ) \n");
		scanf("%s", fltno);	

		printf("\n Flight number is %s",fltno);

		printf("\nenter the field you want to change \n");
		printf("\nsched = 1,Exp = 2 Origin = 3 Remarks = 4\n");
		scanf("%d", &opt);
		/* A switch command uses the number entered */
		switch(opt)
		{
		case 1:
			/* Change Scheduled Arrival Time */
			printf("\nenter the new sched \n");
			scanf("%s", new_sch_arrival_time);
			printf("\nnew sched is %s",new_sch_arrival_time);
		
			/*for (i = 0;i < 11;i++)*/
for (i = 0;i < 17;i++)
			{
			
				ret=strcmp(fltno,st[i].flight_no);
				if(ret == 0)
				{
					strcpy(st[i].sch_arrival_time,new_sch_arrival_time);
					printf("\nstored sched is %s",st[i].sch_arrival_time);
					printf("\n Flight number is %s",&fltno);
					printf("\n struct Flight number is %s",st[i].flight_no);
				}
			}
			break;
		case 2:
			/* Change expected Arrival Time */
			printf("\nenter the new exp \n");
			scanf("%s", new_exp_arrival_time);
			printf("\nnew exp is %s",new_exp_arrival_time);
			/*for (i = 0;i < 11;i++)*/
for (i = 0;i < 17;i++)
			{
		/*	printf("\n Flight number is %s",&fltno);
			printf("\n struct Flight number is %s",st[i].flight_no);*/
				ret=strcmp(fltno,st[i].flight_no);
				if(ret == 0)
				{
					strcpy(st[i].exp_arrival_time,new_exp_arrival_time);
					printf("\nstored exp is %s",st[i].exp_arrival_time);
					printf("\n Flight number is %s",&fltno);
					printf("\n struct Flight number is %s",st[i].flight_no);
				}
			}
			break;
		case 3:
			/* Change Airport of origin */
			printf("\nenter the new origin \n");
			scanf("%s", new_origin);
			printf("\nnew origin is %s",new_origin);
			for (i = 0;i < 17;i++)
			{
			
				ret=strcmp(fltno,st[i].flight_no);
				if(ret == 0)
				{
					strcpy(st[i].origin,new_origin);
					printf("\nstored origin is %s",st[i].origin);
					printf("\n Flight number is %s",&fltno);
					printf("\n struct Flight number is %s",st[i].flight_no);
				}
			}
			break;
		case 4:
			/* Add remarks */
			printf("\nenter the new remarks \n");
			scanf("%s", new_remarks);
			printf("\nnew remarks is %s",new_remarks);
			for (i = 0;i < 17;i++)
			{
			
				ret=strcmp(fltno,st[i].flight_no);
				if(ret == 0)
				{
					strcpy(st[i].remarks,new_remarks);
					printf("\nstored remarks is %s",st[i].remarks);
					printf("\n Flight number is %s",&fltno);
					printf("\n struct Flight number is %s",st[i].flight_no);
				}
			}
			break;
		default:
			printf("\nerror \n");
		}/* end of switch */

		/* Output updated arrivals data */

		fparr = fopen("arrivals.dat", "w");

		if(opt2 < 12)
			lim = opt2;
		else
			lim = 12;
		printf("\n        Flight\t:Sched:\tExp:\tOrigin:\t        Remarks");
		
		for (i = 0;i < 17;i++)
		{
			strcpy(s1.posn,st[i].posn);	
			strcpy(s1.flight_no,st[i].flight_no);
			strcpy(s1.sch_arrival_time,st[i].sch_arrival_time);
			strcpy(s1.exp_arrival_time,st[i].exp_arrival_time);
			strcpy(s1.origin,st[i].origin);
			strcpy(s1.remarks,st[i].remarks);
			fwrite(&s1 ,sizeof(s1),1 , fparr );

			if(i<lim)
				printf("\n : %s\t%s\t%s\t%s\t%s\t\t%s",st[i].posn, st[i].flight_no,st[i].sch_arrival_time,st[i].exp_arrival_time,st[i].origin,st[i].remarks);
		}
		fclose(fparr);

	}/* end of not rollup */
	if(rollup == 'y')
	{
		/* Flight to be rolled off the display */
		/* eg if it has landed */
		printf("\nenter flight number  \n");
		scanf("%s", fltno);	

		/* Write to a temporary file arrivals2.dat */
		/* which will then overwrite arrivals.dat */

		fparr = fopen("arrivals.dat", "r");
		fparr2 = fopen("arrivals2.dat", "w");

		if(opt2 < 12)
			lim = opt2;
		else
			lim = 12;

		for (i = 0;i < 17;i++)
		{

			eofcheck = fread(&s1, sizeof(s1), 1, fparr);
			if(eofcheck == 0)
			{
				goto exit;
			} 
			
			if(strcmp(s1.flight_no,fltno) != 0)
			{
				fwrite(&s1 ,sizeof(s1),1 , fparr2 );
			}
			else
			{
				/* update the flight count file */

				fltcnt = fopen("flightcnt.dat","r");
				fread(&fc, sizeof(fc), 1, fltcnt);
				fclose(fltcnt);
				fc.count = fc.count-1;
				opt2 = fc.count;
				fltcnt = fopen("flightcnt.dat","w");
				fwrite(&fc, sizeof(fc), 1, fltcnt);
				fclose(fltcnt);	

				fltcnt = fopen("flightcnt.dat","r");
				fread(&fc, sizeof(fc), 1, fltcnt);
				fclose(fltcnt);

			}
	
		}
exit:
		fclose(fparr);
		fclose(fparr2);	

		/* Copy arrivals2.dat to new arrivals.dat */

		remove("arrivals.dat");

		source = fopen("arrivals2.dat", "r");
   		target = fopen("arrivals.dat", "w");

     		while ((ch = fgetc(source)) != EOF)
      			fputc(ch, target);
  
   		fclose(source);
   		fclose(target);
	
		/* Display updated data */

		fparr = fopen("arrivals.dat", "r");
		if(opt2 < 12)
			lim = opt2;
		else
			lim = 12;
		printf("\n        Flight\t:Sched:\tExp:\tOrigin:\t        Remarks");
		for (i = 0;i < lim;i++)
		{
			fread(&s1, sizeof(s1), 1, fparr);

			strcpy(st[i].posn,s1.posn);
			strcpy(st[i].flight_no,s1.flight_no);
			strcpy(st[i].sch_arrival_time,s1.sch_arrival_time);
			strcpy(st[i].exp_arrival_time,s1.exp_arrival_time);
			strcpy(st[i].origin,s1.origin);
			strcpy(st[i].remarks,s1.remarks);

			printf("\n : %s\t%s\t%s\t%s\t%s\t\t%s",st[i].posn, st[i].flight_no,st[i].sch_arrival_time,st[i].exp_arrival_time,st[i].origin,st[i].remarks);

		}
	fclose(fparr);	
	}/* end of rollup = y */
	
}