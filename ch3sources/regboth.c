/* regboth.c */
/*	regression */
/*	user enters points.*/
/*	regression of y on x  and x on y calculated */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
main()
{
FILE *fp;
	
	float xpoints[16]={2,2,2,2,2,18,18,18,18,18,6,10,14,6,10,14};
	float ypoints[16]={2,6,10,14,18,2,6,10,14,18,2,2,2,18,18,18};
	float sigmax,sigmay,sigmaxy,sigmaxsquared,sigmaysquared,xbar,ybar;
	float fltcnt,sxy,sxx,syy,b,a,c,d, sx, sy, r;
	int i,points; 
fp=fopen("regbotht.dat","w");
	
	printf("enter number of points (max 16 ) \n");
	scanf("%d", &points);
	if(points>16)
	{
		printf("error - max of 16 points\n");

	}
	else
	{
		sigmax=0;
		sigmay=0;
		sigmaxy=0;
		sigmaxsquared=0;
		sigmaysquared=0;

		/* user enters points from scatter graph */
		for(i=0;i<points;i++)
		{
			/*printf("enter point (x and y separated by space) \n");
			scanf("%f %f", &xpoints[i], &ypoints[i]);*/
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
	fprintf(fp,"%lf\t%lf\n",xpoints[i], ypoints[i]);		
		}
		printf(" \n");
		fltcnt=(float)points; 
		
		/* Calculation of (xbar,ybar)- the mean points*/
		/* and sxy and sxx from the formulas*/
		xbar=sigmax/fltcnt;
		ybar=sigmay/fltcnt;
		sxy=(1/fltcnt)*sigmaxy-xbar*ybar;
		sxx=(1/fltcnt)*sigmaxsquared-xbar*xbar;
	syy=(1/fltcnt)*sigmaysquared-ybar*ybar;

	sx = sqrt(sxx);
		sy = sqrt(syy);

		/* calculation of b and a from the formulas */
		b=sxy/sxx;
		a=ybar-b*xbar;
	
		/* Print the equation of the regression line */

		printf("Equation of regression line y on x  is\n ");
		printf(" y=%f + %fx", a,b);
		printf(" \n");

/* calculation of d and c from the formulas */
d=sxy/syy;
	c=xbar-d*ybar;


	/* Regression line */
	printf("Equation of regression line x on y  is\n ");
	printf(" x=%f + %fy", c,d);
	}
/* PMCC value calculated */
		r = sxy / (sx*sy);
		printf("\nr is %lf", r);
fclose(fp);	
}
