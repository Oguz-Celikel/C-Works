
// Created by Oguz Celikel Oct-14-2018

#include<stdio.h>
#include<math.h>
double func(double x)
{
	return(x*x);
}
double simpson(double a,double b,double n)
{
	double answer,h;
	double x;
	int i;
	answer=func(a);
	h=(b-a)/n;
	
	for(i=1;i<=n;i++){
		x=a+i*h;
		answer=answer+4*func(x-(h/2.0))+2*func(x);
	}
	answer=answer-func(b);
	answer=(h/6.0)*answer;
	printf("%lf",answer);
	return(0);
}
int main()
{
	double a=1.0,b=4.0;
	double n=6.0;
	simpson(a,b,n);
}
