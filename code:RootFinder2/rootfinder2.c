
// Created by Oguz Celikel Oct-13-2018

#include<stdio.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

double myfunc(double r);
int find_interval(double (*f)(double), double, double, double, double *, double *);

int main()
{

	double x1=-6.0,x2=6.0,a1,a2;
	int i;

	printf("Function is x^4 + 7/2x.x^3 - 3.x^2 - 7/2.x + 2\n\n");
	printf("Interval of Roots with 0.03 stepsize:\n\n");

	if( find_interval(myfunc, x1, x2, 0.03, &a1, &a2) )       					
		printf("1.interval is [%.2f, %.2f]\n", a1, a2);							//printing first interval
	else
		printf("There is no interval\n");
	
	for( i=a2 ; i<=6 ; i=i+0.03 ){													//checking other intervals
		if( find_interval(myfunc, a2, x2, 0.03, &a1 ,&a2) )
			printf("%d.interval is [%.2f, %.2f]\n", i+5, a1, a2);				//printing other interval
	}
	
}

double myfunc(double r)     													//function whose root to find
{
	return ( r*r*r*r + 7.0/2.0*r*r*r - 3.0*r*r - 7.0/2.0*r + 2 );
}

int find_interval(double (*f)(double), double start_point, double end_point, double stepsize, double *left_int, double *right_int)
{
	int found_root = TRUE; 														//initial value of indicator
	
	*left_int=start_point;        												//intialize interval
	*right_int=*left_int+stepsize;
	
	while( *left_int < end_point && f(*left_int)*f(*right_int)>0.0 ){			//searching intervals
		*left_int=*right_int;
		*right_int+=stepsize;
		if(*right_int>end_point)
		*right_int=end_point;
	}
	
	if(f(*left_int)*f(*right_int)>0.0)	
	found_root = FALSE;
	
	return(found_root);
}
