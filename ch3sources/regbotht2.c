/* regbotht2.c */
/*	regression */
/*	preset points.*/
/*	regression of y on x  and x on y calculated */
/* Test for pmcc of zero */
/* Show appropriate regression lines */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
main()
{
FILE *fp;
	
	/* Preset points for x and y values */
	float xpoints[16]={2.0,2.0,2.0,2.0,2.0,18.0,18.0,18.0,18.0,18.0,6.0,10.0,14.0,6.0,10.0,14.0};
	float ypoints[16]={2.0,6.0,10.0,14.0,18.0,2.0,6.0,10.0,14.0,18.0,2.0,2.0,2.0,18.0,18.0,18.0};
	float sigmax,sigmay,sigmaxy,sigmaxsquared,sigmaysquared,xbar,ybar;
	float fltcnt,sxy,sxx,syy,b,a,c,d, sx, sy, r;
	int i,points; 

	/* Open the output file */
	fp=fopen("regbotht2.dat","w");
	
	points = 16; /* number of points fixed at 16 */
	
	/* Preset storage variables to zero */
	sigmax=0.0;
	sigmay=0.0;
	sigmaxy=0.0;
	sigmaxsquared=0.0;
	sigmaysquared=0.0;

	/*  points from preset arrays */
	/* Calculate sigmax,sigmay,sigmaxy,sigmaxsquared,sigmaysquared */
	for(i=0;i<points;i++)
	{
			
		sigmax=sigmax+xpoints[i];
		sigmay=sigmay+ypoints[i];
		sigmaxy=sigmaxy+xpoints[i]*ypoints[i];
		sigmaxsquared=sigmaxsquared+(float)pow(xpoints[i],2); 
		sigmaysquared=sigmaysquared+pow(ypoints[i],2);
	}
	printf("points are \n");
	for(i=0;i<points;i++)
	{
		printf(" \n");
		printf("%f %f", xpoints[i], ypoints[i]);
		fprintf(fp,"%f\t%f\n",xpoints[i], ypoints[i]);		
	}
	printf(" \n");
	fltcnt=(float)points; /* set float variable to count of points */
		
	/* Calculation of (xbar,ybar)- the mean points*/
	/* and sxy and sxx from the formulas*/
	xbar=sigmax/fltcnt;
	ybar=sigmay/fltcnt;
	sxy=(1/fltcnt)*sigmaxy-xbar*ybar;
	sxx=(1/fltcnt)*sigmaxsquared-xbar*xbar;
	syy=(1/fltcnt)*sigmaysquared-ybar*ybar;

	/* calculate sx and sy from the formulas*/
	sx = sqrt(sxx);
	sy = sqrt(syy);

	/* calculation of b and a from the formulas */
	b=sxy/sxx;
	a=ybar-b*xbar;
	
	/* Print the equations of the regression lines */

	/* Regression line y on x */
	printf("Equation of regression line y on x  is\n ");
	printf(" y=%f + %fx", a,b);
	printf(" \n");

	/* calculation of d and c from the formulas */
	d=sxy/syy;
	c=xbar-d*ybar;


	/* Regression line x on y */
	printf("Equation of regression line x on y  is\n ");
	printf(" x=%f + %fy", c,d);
	
	/* PMCC value calculated */
	r = sxy / (sx*sy);
	printf("\nr is %f", r);
	fclose(fp);	
}
