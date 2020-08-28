/*     cofm5c.c
     Centre of Mass Calculation.
	Calculates c of m for 
	circle centre = (0,0) radius = 2
*/
#define _CRT_SECURE_NO_WARNINGS	
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
double randfunc();
main()
{

	int  I,outcount;
	float area,total,count;
	FILE *fptr;
	time_t t;
	/*  Local Arrays */
      double x, y,xout[3500],yout[3500],xcofm,ycofm;

	fptr=fopen("cofmc.dat","w");


   
   /* Intializes random number generator */
   srand((unsigned) time(&t));

	/* clears arrays to zero */
         for( I = 0; I<3500;I++)
	{
		xout[I] = 0.0;
		yout[I] = 0.0;
		
	}
	/* set x and y cofm accumulators to zero */
	xcofm=0.0;
	ycofm=0.0;
	

	total = 0.0;
	count = 0.0;
	outcount = 0;
        for( I = 1;I<= 3500;I++)
	{
	/* get x values between -2 and +2 */
	/* get y values between -2 and +2 */
            x = randfunc()*4.0-2.0;
            y = randfunc()*4.0-2.0;
       
	/* If the generated x and y values are above */
	/* the curve y=x^2 then add 1 to count */   
	/* and update the x and y cofm values */
  	   
 	    if(y>-sqrt(4-pow(x,2)) && y<sqrt(4-pow(x,2)))
	    {
		xcofm=xcofm+x;
		ycofm=ycofm+y;
		
		total = total+1;
		outcount = outcount +1;
		xout[outcount] = x;
		yout[outcount] = y;
	    }
	    count = count+1;
		
   	}	
	
	area=(total/count)*16;/* area is part of the square which is 4x4 or 16 sq units */
	printf("total is %f count is %f\n",total,count);

	xcofm=xcofm/total;
	ycofm=ycofm/total;
	
	printf("area is %lf\n",area);
	printf("cofm is %lf,%lf",xcofm,ycofm);
	

	/*  Plot the data */
	
	if(outcount >= 2700)
		outcount = 2700;
	
 		
         for(I = 1; I<=outcount-1;I++)
		fprintf(fptr,"%lf %lf\n",xout[I],yout[I]);
 	fclose(fptr);

}

double randfunc()
{
	/* get a random number 0 to 1 */
	double ans;
	

	ans=rand()%1000;
	ans=ans/1000;

 	return ans;
      
}


      

