/*      PROGRAM vaca.c
C	VACANCY DIFFUSION MODEL.
C       TRACES  ALL ATOMS   (2D VERSION)
C	NB - FOR MORE THAN 1 ATOM IN LATTICE, THE TRACE ATOM
C	MAY MOVE MORE THAN ONCE IN ONE MONTE CARLO CYCLE.*/
#include <stdio.h>
#include <math.h>
#include <time.h>
int IRND();
int IFOURRND();
main()
{
	int test;
	float FT,XMSD,TEMP,MOVES;
     	 int N,I,N1,N2,ATOM,FILLEDSITES;
    	 int FOURRNDTEST[4],N1N,N2N,J,K,L,MCC,M;
    	 int LATTICE2[20][20];
     	int FIRSTTIME,MCCMAX;
     	int N1R,N2R,IX,IY,Q,P,NOTFOUND,INC,IXY;
	FILE *fptr;
	
	time_t t;

 	 /* Intializes random number generator */
 	  srand((unsigned) time(&t));
	fptr=fopen("vaca.dat","w");
	
	/*MCCMAX = 500;*/
	/*MCCMAX = 100000;*/
	/*MCCMAX = 10000; this value fills the whole lattice */
	/*MCCMAX = 50; this value demonstrates partially filled lattice */
	MCCMAX = 50;/* this demonstrates msd */
	MCCMAX = 1000;
	MCCMAX = 50;
	MCCMAX = 1000;
      	MCCMAX = 10000;
 	MOVES = 0.0;
 MCCMAX = 50;/* test 13/2/20 */	
	XMSD = 0.0;
	ATOM = 0;
	

	for(P=0;P<20;P++)
	{
		for(Q=0;Q<20;Q++)
		{
		/*C	FILL THE ARRAY*/
			
			LATTICE2[P][Q] = 0;
			
		}
	}
	FILLEDSITES = 399;


	/*C	SELECT ANY SITE AS THE INITIAL VACANCY SITE*/
      /*N1N = IRND();
      N2N = IRND();*/
	N1N=1;/* Start x value */
	N2N=10;/* Start y value */
	/*N1N=1;
	N2N=1;*/

	LATTICE2[N1N][N2N] = 1;

	


   
	for(MCC=1;MCC<=MCCMAX;MCC++)
	{
		



			N1=N1N;
			N2=N2N;

			if(LATTICE2[N1][N2] == 1)
			{
			/*C	VACANCY SITE (= 1 RANDOM NUMBER SELECTION)
			C	*/

				INC = IFOURRND();
				
				N1R = 0;
				N2R = 0;
				FOURRNDTEST[INC] = FOURRNDTEST[INC] + 1;
	/* test mechanism- instead of going from 19 to 1 etc you bounce off the boundary. Go from 19 to	18 etc */	
				if(INC == 1)/* UP */
				{
  					if(N1 == 19)
						N1N = 18;
					else
						N1N = N1+1;
	
					N1R = -1;
				}else if(INC == 2)/* RIGHT */
				{
  					if(N2 == 19)
						N2N = 18;
					else
						N2N = N2+1;
	
					N2R = -1;
				}else if(INC == 3)/* DOWN */
				{
  					if(N1 == 1)
						N1N = 2;
					else
						N1N = N1-1;
	
					N1R = 1;
				}else if(INC == 4)/* LEFT */
				{
  					if(N2 == 1)
						N2N = 2;
					else
						N2N = N2-1;
	
					N2R = 1;
				}
printf("INC %d N1N %d N2N %d N1R %d N2R %d\n",INC,N1N,N2N,N1R,N2R);

				test=0;
				
				
				if(LATTICE2[N1N][N2N] == 0)
				{
					LATTICE2[N1N][N2N] = 1;
						
					
				}
				else
				printf("not found\n");
			}	
		
	
	}
 
	for(P=0;P<20;P++)
	{
		for(Q=0;Q<20;Q++)
		{
		

			
			if(LATTICE2[P][Q] == 1)
				fprintf(fptr," %d\t%d\n",P,Q);

			
			
    
		}
	}
	
	fclose(fptr);

}


  int IRND()
{
	float TOT,DIV,X;
	int ANS,I;

	TOT=rand()%1000;
	TOT=TOT/1000;
	DIV = 20.0;
	X = 1.0;
	for(I=0;I<20;I++)
		if(TOT < X/DIV)
			ANS = I;
			
		else	
			X = X+1.0;

     
	return ANS;
}

 

int IFOURRND()
{
	float TOT;
	int ANS,I;


	TOT=rand()%1000;
	TOT=TOT/1000;
	
	
	if(TOT < 0.25)
		ANS = 1;
	else if(TOT < 0.5)
		ANS = 2;
	else if(TOT < 0.75)
		ANS = 3;
	else
		ANS = 4;
	
	return ANS;
	
}




