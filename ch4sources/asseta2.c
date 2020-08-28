/* asseta2.c */
/* Stock Price predictor simulation */
/* from Day values */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double calcrand();
void avstdvar(double dayvals[]);


FILE *fp;
	
	double c,c0,c1,c2,d1,d2,d3;
	double q,d,F,y,t;
	
	int ns,np,ss;
	double x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;
	int i,j;
	time_t tim;
	

	
	int  n;
	double average, variance, std_deviation, sum = 0, sum1 = 0;
	double PDRaverage,PDRvariance,PDRstd_deviation,pdrsum,nextval,lastval,drift,epsilon,exptest,nitest;
	double pdr[50];

main()
{
	FILE *fp;
	/* Array containing day stck prices starting with yesterday and moving backwards */
	double dayvals[50]={22.82,22.51,22.47,22.05,22.96,21.43,20.97,20.46,20.25,20.46,20.45,20.7,20.31,20.94,20.85,20.59,20.65,21.12,20.78};
	
	double value,testval;
	int j;


	fp=fopen("asseta2.dat","w");
	srand((unsigned) time(&tim));/* set up random number function */

	for(i=0;i<50;i++)
	{
		/* clear predicted rate array */
		pdr[i]=0.0;
	}
	for(i=19;i<50;i++)
	{
		/* Clear the end part of our values array for our predicted vales */
		dayvals[i]=0.0;
		
	}
	
	n=19; /* number of predicted daily rates (PDR) )*/
	



	j=0;
	/* write historical rates to output file */

	for(i=18;i>-1;i--)
	{
		fprintf(fp,"%d\t%lf\n",j,dayvals[i]);
		j++;
	}




	/* Calc PDRs - if you enter 20 days there will be 19 PDRs */

	for(j=0;j<n-1;j++)
	{
		pdr[j]=log(dayvals[j]/dayvals[j+1]);
		printf("pdr[j] = %lf\n",pdr[j]);
			
	}
	/* Compute the sum of all elements */
	pdrsum=0.0;
	for (i = 0; i < n-1; i++)
	{

		pdrsum = pdrsum + pdr[i];

	}
	PDRaverage = pdrsum / (double)(n-1);
	
	/* Call function to calculate statistical values */
	avstdvar(dayvals);	

	
	drift=PDRaverage-(PDRvariance/2);
	printf("drift is %lf\n",drift);
	printf("PDRaverage is %lf\n",PDRaverage);
	lastval=dayvals[0];

	/* Calculate values using formula */
	/* nextval=lastval*exp(drift+PDRstd_deviation*calcrand()) */
	for (i = 19; i < 38; i++)
	{
		
		nitest=calcrand();
		exptest=exp(drift+PDRstd_deviation*nitest);
		nextval=lastval*exptest;
		printf("exptest is %lf\n",exptest);
		printf("nitest is %lf\n",nitest);


		printf("nextval is %lf\n",nextval);
		fprintf(fp,"%d\t%lf\n",i,nextval);

		lastval=nextval;

	}

	fclose(fp);

}
double calcrand()
{
	/* set values for cumulative normal distribution formula */
	c0=2.515517;
	c1=0.802853;
	c2=0.010328;
	d1=1.432788;
	d2=0.189269;
	d3=0.001308;
		
	

	y=rand()%1000;/* Generate random number between 0 and 1 */
	y=y/1000;

	if(y>=0.5)
		q=1-y; 
	else
		q=y;

	t=sqrt(log(1/pow(q,2)));
	c=c0+c1*t+c2*pow(t,2);
	d=1+d1*t+d2*pow(t,2)+d3*pow(t,3);

	F=t-(c/d);

	/* Use the symmetry of the Cumulative Normal Distribution Graph */
	if(y < 0.5)
	{

		y=-1.0*F;

	}
	else if(y == 0.5)
		y=0;
	else

		y=F;


	printf("y  = %lf\n",y);	
	
	
	return y;

}

void avstdvar(double dayvals[])
{
	/* Average,Standard Deviation,Variance processing */
	sum = 0.0;
	sum1 = 0.0;

	

	/* Compute the sum of all elements */
	for (i = 0; i < n; i++)
	{

		sum = sum + dayvals[i];
	}
	average = sum / (double)n;

	/* Compute variance and standard deviation */
	for (i = 0; i < n; i++)
	{
		sum1 = sum1 + pow((dayvals[i] - average), 2);
	}
	variance = sum1 / (double)n;

	/* Compute PDRvariance and PDRstandard deviation */
	sum1=0.0;
	for (i = 0; i < n-1; i++)
	{
		sum1 = sum1 + pow((pdr[i] - PDRaverage), 2);
	}
	PDRvariance = sum1 / (double)(n-1);

	std_deviation = sqrt(variance);
	PDRstd_deviation = sqrt(PDRvariance);
	printf("Average of all elements = %lf\n", average);
	printf("variance of all elements = %lf\n", variance);
	printf("Standard deviation = %lf\n", std_deviation);
	printf("PDRvariance of all elements = %lf\n", PDRvariance);
	printf("PDRStandard deviation = %lf\n", PDRstd_deviation);
	
}