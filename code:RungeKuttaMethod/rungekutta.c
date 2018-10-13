
// Created by Oguz Celikel Oct-14-2018

#include<stdio.h>
#include<math.h>
double func(double x,double y)
{
	return(-(y-4)/x);
}
void runge_kutta(double x0,double y0,double h,double xlast)
{
	double ta,tb,tc,td;
	printf("x		f(x)\n");
	for(;x0<=xlast;x0=x0+h)
	{
		printf("%.3lf		%.3lf\n",x0,y0);
		ta=h*func(x0,y0);
		tb=h*func(x0+h/2.0,y0+ta/2.0);
		tc=h*func(x0+h/2.0,y0+tb/2.0);
		td=h*func(x0+h,y0+tc);
		y0=y0+(ta+2.0*tb+2.0*tc+td)/6.0;
	}
}
int main()
{
	double x0,y0,h,xlast;
	runge_kutta(1.0,0.0,0.1,4.0);
}
