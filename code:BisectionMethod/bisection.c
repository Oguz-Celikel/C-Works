
// Created by Oguz Celikel Oct-14-2018

#include <stdio.h>
#include <math.h>
double func(double x);

void equation(int d, double step_size,double x1,double x2)//calculating function
{

	float root=0,y,epsilon=0.01;
	for(x1=-10; x1<=10; x1=x1+step_size)
    {
	    x2=x1+step_size;
		if(func(x1)*func(x2)<0.0)
		{
		    d++;
			printf("interval[%d] -> [%.2lf and %.2lf]\n",d,x1,x2);
			for(y=(x1+x2)/2.0;fabs(x1-y)>epsilon;y=(x1+x2)/2.0)
	{
	
		if(func(x1)*func(y)<=0)
		x2=y;
		else
		x1=y;
		if(x1-y<=0.01)
		{
		   
			root=y;
		}
		printf("%d . %.3f\n",d,root);
    }
	    }
	}
}

int main()
{
    int k=0,x1,x2;
    equation(k, 0.02,x1,x2);
    
}
double func(double x)//the equation
{
    return (x*x*x*x*x + 10.17*x*x*x*x + 11.6063*x*x*x - 84.7171*x*x -12.6063+ 74.5471);
}


