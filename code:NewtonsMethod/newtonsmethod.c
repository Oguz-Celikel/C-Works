
// 210206003 Oguz Celikel Homework 4 Newtons Method

#include<stdio.h>
#include<math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int findingdegree(FILE *);
double newton(double (*f)(double , int ), double (*fprime)(double , int ), int , double , double , double , int *);
double func(double , int );
double defunc(double , int );

int main()
{

	FILE *fbo,*fbi;
	double root;
	int flag;
	float dmin,x0,eps,a,b,c,d,e,f;

	fbi=fopen("2016_HW4_210206003_input.txt","r");						//opening an input file

	if( fbi == NULL){
        printf("Error for input file\n");
    }
    else {
	fscanf(fbi,"%f %f %f %f %f %f %f %f %f", &dmin, &x0, &eps, &f, &e, &d, &c, &b, &a);

	printf("dmin:%.30f\t x0:%.2f\t epsilon:%f\t \nf=%.2f  e=%.2f  d=%.2f  c=%.2f  b=%.2f  a=%.2f", dmin, x0, eps, f, e, d, c, b, a);

    int degree = 0; // degree of the polynomial
    degree = findingdegree(fbi);

    root=newton(func, defunc,degree, dmin, x0, eps, &flag);	//root finding

    fbo=fopen("2016_HW4_210206003_results.txt","w");
	}
	if(fbo == NULL){
        printf("Error for output file\n");
    }
    else {
        if (flag == 2){
            printf("Error:Cycling\n");
            fprintf(fbo,"Cycling error\n");
		}
        else if (flag == TRUE ){
            printf("Slope is too close to 0\n");
            fprintf(fbo,"Slope is too close to 0\n");
        }
        else if(flag == FALSE){
        	printf("\nReal root of f(x)= 1.1*x^5+4.5*x^3-2.3*x-3.1 is\t%lf\n", root);
            printf("Results are 2016_HW4_210206003_results.txt file\n");
          	fprintf(fbo,"%f %.2f %f \n%.2f %.2f %.2f %.2f %.2f %.2f \n%f",dmin, x0, eps, f, e, d, c, b, a, root); //writing an output file with root
        }

    }

	fclose(fbi);														//closing txt files
	fclose(fbo);

	return 0;
}

double newton(double (*f)(double, int ),double (*fprime)(double, int), int degree, double dmin, double x0, double epsilon, int *error)
{
	int i;
	double deltax, x1=0, x2=0;
	deltax=2.0*epsilon;
	*error=FALSE;

	while(!(*error)&&fabs(deltax)>epsilon)
		if(fabs(fprime(x0,degree))>dmin)
		{
			deltax=f(x0,degree)/fprime(x0,degree);
		  	x2 = x1;
            x1 = x0;
            x0 = x0 - deltax;
            if(fabs(x0 - x2) < epsilon){
                *error = 2;
                return 0;
            }
		}
		else
		*error=TRUE;

	return(x0);
}

int findingdegree(FILE *fbi)
{
    int degree = 0;
    double r;
    while(!feof(fbi)){
        fscanf(fbi,"%lf",&r);
        degree++;
    }
    rewind(fbi);
    fscanf(fbi,"%lf %lf %lf",&r,&r,&r);

    degree -= 2;
    return degree;
}

double func(double x,int degree)											//function which is given
{
	double f_1;
	f_1=(1.1*x*x*x*x*x)+(0*x*x*x*x)+(4.5*x*x*x)+(0*x*x)-(2.3*x)-(3.1);
	return(f_1);
}

double defunc(double x,int degree)											//derivative of the given function
{
	double df_1;
	df_1=(1.1*5.0*x*x*x*x)+(0*4.0*x*x*x)+(4.5*3.0*x*x)+(0*2.0*x)-(2.3);
	return(df_1);
}
