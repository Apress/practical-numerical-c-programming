/* assetalgorithm.c */
/* Stock Price predictor simulation */
/* tests inverse cumulative */
/* normal distribution function */
/* User enters a probability value */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
	
	double c,c0,c1,c2,d1,d2,d3;
	double q,d,x,y,t;
	
	int i;
	time_t tim;
	
	int  n;
	
	double probvalue;

int main()
{
	
	/* set values for cumulative normal distribution formula */
	c0=2.515517;
	c1=0.802853;
	c2=0.010328;
	d1=1.432788;
	d2=0.189269;
	d3=0.001308;
		
	
	/* User enters the probability used to find the x value */
	printf("Please enter Probability value between 0.0 and 1.0 :\n ");
	scanf("%lf", &probvalue);
	printf("You entered %lf\n", probvalue);

	if(probvalue < 0.0 || probvalue > 1.0)
		return; /* Entered value is out of range */

	y=probvalue; /* Store the entered value */

	/* Use the symmetry of the Cumulative Normal Distribution Graph */
	if(y>=0.5)
		q=1-y; 
	else
		q=y;
	
	/* Calculate the values in the formula */
	t=sqrt(log(1/pow(q,2)));
	c=c0+c1*t+c2*pow(t,2);
	d=1+d1*t+d2*pow(t,2)+d3*pow(t,3);

	x=t-(c/d);

	/* Use the symmetry of the Cumulative Normal Distribution Graph */
	if(y < 0.5)
	{

		y=-1.0*x;

	}
	else if(y == 0.5)
		y=0;
	else
		y=x;

	/* Print the x result for the entered Probability value */
	printf("probvaluevalue  = %lf\n",probvalue);	
	printf("x  = %lf\n",y);	
		
	return ;

}

