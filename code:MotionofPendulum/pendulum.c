
// Created by Oguz Celikel Oct-14-2018

#include<stdio.h>
#include<math.h>
#define GRAVITY -9.8
int main()
{
	double h,s0,tlast,length,s,z,t;
	double sa,sb,sc,sd;
	double za,zb,zc,zd;
	printf("enter the initial value of s:");
	scanf("%lf",&s0);
	printf("enter the last value of t:");
	scanf("%lf",&tlast);
	printf("enter value of increments:");
	scanf("%lf",&h);
	printf("enter length of pendulum:");
	scanf("%lf",&length);
	printf("t	s(t)	x(t)	y(t)\n");
	s=s0;
	z=0;
	for(t=0;t<=tlast;t=t+h)
	{
		printf("%.3lf	%.3lf	%.3lf	%.3lf\n",t,s,length*sin(s/length),-length*cos(s/length));
		
		za=h*GRAVITY*sin(s/length);
		sa=h*z;
		zb=h*GRAVITY*sin((s+sa/2)/length);
		sb=h*(z+za/2);
		zc=h*GRAVITY*sin((s+sb/2)/length);
		sc=h*(z+zb/2);
		zd=h*GRAVITY*sin((s+sc)/length);
		sd=h*(z+zc);
		z=z+za/6+zb/3+zc/3+zd/6;
		s=s+sa/6+sb/3+sc/3+sd/6;
	}
	
}
