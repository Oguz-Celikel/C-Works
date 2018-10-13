
// Created by Oguz Celikel Oct-13-2018

#include<stdio.h>
#include<math.h>


double func1(double );
double func2(double );
double func3(double );
double trapezoidal(double (*)(double ),double ,double ,double ,double );

int main()
{
	FILE *fbo;
	int secim;
	double answer,a=0.0,b=2.0,n=10.0,result;
	

    printf("Functions:\n");
    printf("1. y = cos(x^2) + 2*x^3\n2. y = 2 / (1 + x^2)\n3. y = x - 3");
    
    printf("\nEnter the function number you want to calculate (1,2 or 3)?\n");
    start:
	scanf("%d",&secim);
    
    fbo=fopen("output.txt","w");
    
    switch( secim )                                    				//for choosing the functions
      {
         case 1:
			 	fprintf(fbo,"a\t b\t Trapezoidal\t \n%.2f\t %.2f\t %.4f", a, b, trapezoidal(func1,answer,a,b,n));   break;
		 
		 case 2:
        	 	fprintf(fbo,"a\t b\t Trapezoidal\t \n%.2f\t %.2f\t %.4f", a, b, trapezoidal(func2,answer,a,b,n));   break;
		 
		 case 3: 
        		fprintf(fbo,"a\t b\t Trapezoidal\t \n%.2f\t %.2f\t %.4f", a, b, trapezoidal(func2,answer,a,b,n));   break;
		 
		 default: 
		 		printf("Please enter a valid number...\n1,2 or 3:\n");
		 goto start;                          break;
	  }
		
	fclose(fbo);
}

double func1(double x)                           			     // first function is given
{
	return( cos(x*x)+2*x*x*x );
}

double func2(double x) 											// second function  is given
{
	return( 2 / (1 + x*x) );
}

double func3(double x) 											// third function  is given
{
	return( x-3 );
}

double trapezoidal(double (*func)(double x),double answer,double a,double b,double n)   //a method of numerical integration 
{
	double h;
	int i;     
	
	answer=func(a)/2.0;
	h=(b-a)/n;

	for(i=1;i<=n;i++){
		answer=answer+func(a+i*h);}
	
	answer=answer-func(b)/2.0;
	answer=h*answer;
 	
	printf("Result:%.4f",answer); 
	printf("\nResult was written to the output.txt file");
	
	return answer;
}
