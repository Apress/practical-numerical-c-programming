/* regyonx2.c */
/*	regression */
/*	user enters points.*/
/*	regression of y on x  calculated */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
main()
{
	FILE *fp;
	
	/* store areas for points in the formulae */
	float xpoints[12],ypoints[12];
	float sigmax,sigmay,sigmaxy,sigmaxsquared,xbar,ybar;
	float fltcnt,sxy,sxx,b,a;

	int i,points;
 
	fp=fopen("regyonx.dat","w");/* create and open the file */
	
	printf("enter number of points (max 12 ) \n");
	scanf("%d", &points);
	if(points>12)
	{
		printf("error - max of 12 points\n"); /* user entered more than 12 */

	}
	else
	{
		/* Preset store areas to zero */
		sigmax=0;
		sigmay=0;
		sigmaxy=0;
		sigmaxsquared=0;
		

		/* user enters points */
		for(i=0;i<points;i++)
		{
			printf("enter point (x and y separated by space) \n");
			scanf("%f %f", &xpoints[i], &ypoints[i]);
			sigmax=sigmax+xpoints[i];
			sigmay=sigmay+ypoints[i];
			sigmaxy=sigmaxy+xpoints[i]*ypoints[i];
			sigmaxsquared=sigmaxsquared+(float)pow(xpoints[i],2); 
			
		}

		/* print out the points entered */
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
	
		/* calculation of b and a from the formulas */
		b=sxy/sxx;
		a=ybar-b*xbar;
	
		/* Print the equation of the regression line */

		printf("Equation of regression line y on x  is\n ");
		printf(" y=%f + %fx", a,b);
		printf(" \n");

	}
	fclose(fp);	
}
