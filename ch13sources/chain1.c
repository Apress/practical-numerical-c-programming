/*     chain1.c
	 Chain Reaction Simulation.Cubic Shape
	Predefined values of a & b (varied values
	of a & b) */
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
double randfunc(int N);
int checkin(double x, double y, double z, double a, double b);


main()
{
	FILE *fptr;
	FILE *fptr2;


	/*   Local variables */

	int       K, P, N, Ninp, Q;

	/* x0, y0, z0 is the position of the fission nucleus */
	/* x1, y1, z1,phi1,d1,costheta1 are positions of first neutron */
	/* x2, y2, z2,phi2,d2,costheta2 are positions of second neutron */
	double f, x0, y0, z0, phi1, phi2, d1, d2, costheta1, costheta2;

	double a, b, x1, y1, z1, x2, y2, z2;
	double pi;
	time_t t;
	
	pi = 3.142;
	P = 0;

	/*  Select output file for error messages */
	fptr = fopen("chain1.err", "w");

	/* initialise random number generator */
	srand((unsigned)time(&t));

	/* Ask the user for the number of fissions */
	printf("Enter number of fissions \n");
	scanf("%d", &N);


	/*  Create results file  */
	fptr2 = fopen("chain1.dat", "w");
	if (fptr2 == NULL)
	{
		fprintf(stderr, "Error writing to %s\n", "chain1.dat");
		return(1);
	}


	/* Start values for dimensions of box */
	a = 2.0;
	b = 0.1;

	for (Q = 1;Q <= 20;Q++)
	{
		Ninp = 0;
		for (K = 1;K <= N;K++)
		{
			/* find a random position within the box */
			/* for the nucleus */
			x0 = a * (randfunc(P) - 0.5);
			y0 = a * (randfunc(P) - 0.5);
			z0 = b * (randfunc(P) - 0.5);
			phi1 = 2 * pi*randfunc(P);
			costheta1 = 2 * (randfunc(P) - 0.5);
			phi2 = 2 * pi*randfunc(P);
			costheta2 = 2 * (randfunc(P) - 0.5);
			d1 = randfunc(P);
			d2 = randfunc(P);

			/* calculate the position of first neutron */
			x1 = x0 + d1 * sin(acos(costheta1))*cos(phi1);
			y1 = y0 + d1 * sin(acos(costheta1))*sin(phi1);
			z1 = z0 + d1 * costheta1;

			/* calculate the position of second neutron */
			x2 = x0 + d2 * sin(acos(costheta2))*cos(phi2);
			y2 = y0 + d2 * sin(acos(costheta2))*sin(phi2);
			z2 = z0 + d2 * costheta2;

			/* Find out if first neutron is inside the box */
			if (checkin(x1, y1, z1, a, b) == 1)
				Ninp = Ninp + 1;

			/* Find out if second neutron is inside the box */
			if (checkin(x2, y2, z2, a, b) == 1)
				Ninp = Ninp + 1;



		}

		/*printf("\na is : %d", a);
		printf("\nb is : %d", b);*/

		f = (float)Ninp / (float)N;
		
		fprintf(fptr2, "%lf %lf\n", b / a, f);

		/* make a smaller and b larger */
		/* We will show that a cube (a=b) */
		/* produces the best survival fraction */
		a = a - 0.1;
		b = b + 0.1;

	}
	fclose(fptr2);
}
double randfunc(int N)
{
	/* find a random number between 0 and 1 */
	double TOT;
	
	TOT = rand() % 1000;
	TOT = TOT / 1000;

	return TOT;

}


int checkin(double x, double y, double z, double a, double b)
{

	/* If the coordinates are within the box return 1 */
	/* Otherwise return 0 */	
	int I;
	if (x > -a / 2 && x < a / 2
		&& y > -a / 2 && y < a / 2
		&& z>-b / 2 && z < b / 2)
		I = 1;
	else
		I = 0;

	return I;

}
