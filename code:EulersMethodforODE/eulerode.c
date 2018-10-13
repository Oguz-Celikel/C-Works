
// Created by Oguz Celikel Oct-13-2018

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double func(double , double );
double exact(double );
double m_euler(double , double , double (*)(double,double), double , double );
double p_error( double (*)(double, double, double(*)(double,double), double, double), double (*)(double), double , double );

int main()
{
	float i;
	FILE *fbo;
	fbo=fopen("output.txt","w");																				//Opening output.txt file
	
	fprintf(fbo,"x\tExact Value\tEuler Result(h=0.01)\tEuler Result(h=0.001)\tEuler Result(h=0.0001)\n");
	for( i=0.1 ; i <=0.5 ; i=i+0.1 )             																//Writing exact value and euler's result
	fprintf(fbo,"%.2f\t%.4f\t\t%.4f\t\t\t%.4f\t\t\t%.4f\n", i, exact(i), m_euler(0,-2.5,*func,0.01,i), m_euler(0,-2.5,*func,0.001,i), m_euler(0,-2.5,*func,0.0001,i));
	
	fprintf(fbo,"\nx\tPercentage Error(h=0.01)\tPercentage Error(h=0.001)\tPercentage Error(h=0.0001)\n");
	for( i=0.1 ; i <=0.5 ; i=i+0.1 )																			//Writing percentage error
	fprintf(fbo,"%.2f\t%.4f\t\t\t\t%.4f\t\t\t\t%.4f\n", i, p_error(*m_euler,*exact, i, 0.01), p_error(*m_euler,*exact, i, 0.001), p_error(*m_euler,*exact, i, 0.0001));

	printf("Results are at output.txt file");
	
	fclose(fbo);

	return 0;
}

double func(double x, double y)   																				//Ordinary Differantial Equation
{
	return exp(cos(x))-y*sin(x);
}

double exact(double x)          																				 //General Solution
{
	return -2.5 * exp(cos(x)-1) + x*exp(cos(x));
}

double m_euler(double x0, double y0, double (*g)(double,double), double h, double xlast)  						//Euler's Method
{	 double fx; 
	 for(  ; x0 <= xlast ; x0=x0+h ){
		fx=y0;
	 	y0 = y0 + h*g(x0,y0);
	 }
	 return fx;
}

double p_error ( double (*euler)(double, double, double(*func)(double,double), double, double), double (*exact)(double), double x, double h)   //Percentage Error
{
	double error;
	return error=fabs(( exact(x) - euler(0,-2.5,*func,h,x) ) / exact(x))*100;
}
