/* ch1math.c */
/* demonstrate mathematics functions */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <math.h>
/* Illustration of the common trigonometric functions */
/* also exponent, natural log, log to base 10 */
/* power, square root and find absolute value */

int main()
{
#define PI 3.14159265
	double angle, radianno, answer;

	double  arccos, arcsin, arctan;
double  expno, natlog, lb10;
double  pownum, power, sqroot, fabsno;

/* The cosine function */
	printf("cosine function:\n ");
	printf("Please enter angle in degrees:\n ");
	scanf("%lf", &angle);
	printf("You entered %lf\n", angle);
	radianno = angle * (2 * PI / 360);
	answer = cos(radianno);/* returns cos value to answer */
	printf("cos of %lf is %lf\n", angle, answer);

	/* The sine function */
	printf("sine function:\n ");
	printf("Please enter angle in degrees:\n ");
	scanf("%lf", &angle);
	printf("You entered %lf\n", angle);
	radianno = angle * (2 * PI / 360);
	answer = sin(radianno);/* returns sin value to answer */
	printf("sin of %lf is %lf\n", angle, answer);

	/* The tangent function */
	printf("tangent function:\n ");
	printf("Please enter angle in degrees:\n ");
	scanf("%lf", &angle);
	printf("You entered %lf\n", angle);
	radianno = angle * (2 * PI / 360);
	answer = tan(radianno);/* returns tan value to answer */
	printf("tan of %lf is %lf\n", angle, answer);

/* The arccos function */
	printf("arccos function:\n ");
	printf("Please enter arccos:\n ");
	scanf("%lf", &arccos);
	printf("You entered %lf\n", arccos);
	radianno = acos(arccos);/* returns arccos value to radianno (in radians) */
	answer = radianno * (360 / (2 * PI));
	printf("arccos of %lf in degrees is %lf\n", arccos, answer);

/* The arcsin function */
	printf("arcsin function:\n ");
	printf("Please enter arcsin:\n ");
	scanf("%lf", &arcsin);
	printf("You entered %lf\n", arcsin);
	radianno = asin(arcsin);/* returns arcsin value to radianno (in radians) */

	answer = radianno * (360 / (2 * PI));
	printf("arcsin of %lf in degrees is %lf\n", arcsin, answer);

	/* The arctan function */
	printf("arctan function:\n ");
	printf("Please enter arctan:\n ");
	scanf("%lf", &arctan);
	printf("You entered %lf\n", arctan);
	radianno = atan(arctan);/* returns arctan value to radianno (in radians) */
	answer = radianno * (360 / (2 * PI));
	printf("arctan of %lf in degrees is %lf\n", arctan, answer);


/* showing use of exp, log and log10 functions */
	/* find exponent of entered number */
	printf("exponental function:\n ");
	printf("Please enter number:\n ");
	scanf("%lf", &expno);
	printf("You entered %lf\n", expno);

	answer = exp(expno);/* returns exponent value to answer */
	printf("exponent of %lf is %lf\n", expno, answer);

	/* find natural logarithm of entered number */
	printf("natural logarithm function:\n ");
	printf("Please enter number:\n ");
	scanf("%lf", &natlog);
	printf("You entered %lf\n", natlog);
	answer = log(natlog);/* returns natural log value to answer */
	printf("natural logarithm of %lf is %lf\n", natlog, answer);


	/* find log to base 10 of entered number */
	printf("log to base 10 function:\n ");
	printf("Please enter number:\n ");
	scanf("%lf", &lb10);
	printf("You entered %lf\n", lb10);
	answer = log10(lb10);/* returns log to base 10 value to answer */

	printf("log to base 10 of %lf is %lf\n", lb10, answer);


/* showing use of pow, sqrt and fabs functions */
	/* find x raised to power y number */
	printf("power:\n ");
	printf("Please enter number:\n ");
	scanf("%lf", &pownum);
	printf("You entered %lf\n", pownum);
	printf("Please enter power:\n ");
	scanf("%lf", &power);
	printf("You entered %lf\n", power);

	answer = pow(pownum, power);/* returns power of pownum value to answer */
	printf("%lf raised to power %lf is %lf\n", pownum, power, answer);

	/* find square root of number */

	printf("square root:\n ");
	printf("Please enter number:\n ");
	scanf("%lf", &sqroot);
	printf("You entered %lf\n", sqroot);

	answer = sqrt(sqroot);/* returns square root of sqroot value to answer */
	printf("The square root of %lf is %lf\n", sqroot, answer);

	/* find absolute value of number */
	printf("absolute value:\n ");
	printf("Please enter number:\n ");
	scanf("%lf", &fabsno);
	printf("You entered %lf\n", fabsno);

	answer = fabs(fabsno);/* returns absolute value of fabsno to answer */
	printf("The absolute value of %lf is %lf\n", fabsno, answer);






	return 0;

}




