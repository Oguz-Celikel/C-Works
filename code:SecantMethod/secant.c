
// Created by Oguz Celikel Oct-14-2018

#include<stdio.h>
#include<math.h>
#define TRUE 1
#define FALSE 0

double func(double x)
{
    return (x*x*x*x + 3.5*x*x*x - 3*x*x - 3.5*x + 2);
}
double secant(double x1,double x2,double epsilon,int max_tries)
{
	int count = 0;
	double root = x1;
	
	
	while(fabs(x2-x1)>epsilon && count<max_tries)
	{
		root = x1 -func(x1)*(x2-x1)/(func(x2)-func(x1));
		x1=x2;
		x2=root;
		count=count+1;
	}
	printf("%d iteration %lf\n",count, root);
	
	//if(fabs(x2-x1)>epsilon)
	return(root);
}
int main()
{
	double x1=-10,x2=10,epsilon=0.01;
	int max_tries=1000;
	secant(x1,x2,epsilon,max_tries);
}
