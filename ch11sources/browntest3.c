/* Brownian motion (2D) Simulation (Monte Carlo)*/
/* */
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


#define PI 3.141592654


main()
{
	FILE *fptr;
	time_t  t;


int i;
	int collisions;
	double anglerand;
	double xvals[5950],yvals[5950];
	double cosval,sinval;

	fptr=fopen("browntest3.dat","w");
	srand((unsigned) time(&t));/* set the random number seed */
			
	collisions=1000;
	xvals[0]=00.0;
	yvals[0]=00.0;

	for(i=0;i<1000;i++)
	{
	
		anglerand=rand()%1000;
		anglerand=anglerand/1000;

		/* Get a random angle between 0 and PI radians */

		anglerand=2*PI*anglerand;

		/* length of jump is 1 */
		/* So the cos and sin of the angle */
		/* will be the distance moved in */
		/* that direction (+ or -) */	
	
		xvals[i+1]=xvals[i]+cos(anglerand);
		cosval = cos(anglerand);


		yvals[i+1]=yvals[i]+sin(anglerand);
		sinval = sin(anglerand);

		
		fprintf(fptr,"%lf %lf\n", xvals[i], yvals[i]);	
		/*printf("cosval = %lf sinval = %lf\n",cosval,sinval);*/
	
	
	}



}
