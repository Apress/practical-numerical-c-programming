/* peke.c */
/* potential energy Vs kinetic energy */
/* */
/* */	
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

main()
{
	
	int i;
	double m,g,t,h,hn,KE,PE;
	double u,v;

	
	FILE *fptr;

	

	fptr=fopen("peke.dat","w");

	m=10.0;/* preset mass (kg) value */
	g=9.8;/* preset acceleration of gravity (m/s^2) value */
	h=10.0;/* preset height (m) value */
	t=0.1;/* preset time division (s) value */
	u=0.0;/* preset initial velocity (m/s) value */

	for(i=0;i<100;i++)
	{
		v=u+g*t; /* find velocity v from initial velocity,accel. of gravity and time */
		KE=0.5*m*pow(v,2);/* find kinetic energy from mass and velocity */
		hn=u*t+0.5*g*pow(t,2);/* find new height after time t */
		h=h-hn;/* new height after falling hn metres */
		PE=m*g*h;/* find potential energy */
		
		u=v;/* set the inital velocity for the next increment of the loop to the current velocity */
		if(h<=0)
			break;	
		fprintf(fptr,"%lf\t%lf\n",KE,PE);
		
	}
	
	fclose(fptr);


}


