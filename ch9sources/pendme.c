/* pendme.c */
/*
 Simple Euler method
 */
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>




main()
{
	FILE *fptr;
	FILE *fptr2;
	int i,npoints;

	double length,g,dt,omega[250],theta[250],time[250];

	
	fptr=fopen("pendout.dat","w");
	fptr2=fopen("pendoutb.dat","w");
	length=1.0;/* preset length of pendulum (l) */
	g=9.8;/* preset acceleration of gravity (m/s^2) */
	npoints=250;/* Preset number of points in loop */
	dt=0.04;/* preset time interval (s) */

	/* Clear storage arrays to zero */
	for(i=0;i<npoints;i++)
	{
		omega[i]=0;
		theta[i]=0;
		time[i]=0;
	}

	/* preset theta and omega values */
	theta[0]=0.2;
	omega[0]=0.0;

	/* Euler Method */
	for(i=0;i<npoints;i++)
	{
		omega[i+1]=omega[i]-(g/length)*theta[i]*dt;
		theta[i+1]=theta[i]+omega[i]*dt;
		time[i+1]=time[i]+dt;

		fprintf(fptr,"%lf\t%lf\n",time[i+1],theta[i+1]);
		fprintf(fptr2,"%lf\t%lf\n",time[i+1],omega[i+1]);
	}
	fclose(fptr);
	fclose(fptr2);  
}


	