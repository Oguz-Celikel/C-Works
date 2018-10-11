
// Created by Oguz Celikel Oct-12-2018

#include <stdio.h>
#include <math.h>

int main(){
	float a,b,c,d,x1,x2,ex,ey;
	int problem = 0; // if user enters a wrong value, problem's value will be 1
	A:
	printf("\nThis program finds roots of the polynomial y=a*x^2 + b*x + c\n");
	
	printf("Enter a:");
	if(scanf("%f",&a)!=1){
		printf("You entered a wrong value for a!\n");
		problem = 1;
	}
	
	if(a==0){
		printf("a can not be 0\n");
		problem = 1;
	}
	
	if(problem == 0){
		printf("Enter b:");
		if(scanf("%f",&b)!=1){
			printf("You entered a wrong value for b!\n");
			problem = 1;
		}
	}
	
	if(problem == 0){
		printf("Enter c:");
		if(scanf("%f",&c)!=1){
			printf("You entered a wrong value for c!\n");
			problem = 1;
		}
	}
	
	if(problem == 1){
		printf("This is can't calculated.\n");
	}else{
		printf("Here's the result\n");
		d = (b*b) - (4*a*c);
		if(d > 0){
			x1 = ((b*-1) + sqrt(d)) / (2*a);
			x2 = ((b*-1) - sqrt(d)) / (2*a);
			printf("Real Root 1:   %f\n",x1);
			printf("Real Root 2:   %f\n",x2);
		}else if(d == 0){
			x1 = ((b*-1) + sqrt(d)) / (2*a);
			printf("Real Root:   %f\n",x1);
		}else{
			x1 = ((b*-1) / (2*a));
			x2 = sqrt(d*-1) / (2*a);
			printf("Complex Root 1:   %f + %fi\n",x1,x2);
			printf("Complex Root 2:   %f - %fi\n",x1,x2);
		}
		ex = (b*-1) / (2*a);
		ey = (a*ex*ex) + (b*ex) + c;
		if(a>0){
			printf("The function has a minimum at x=%f, y=%f\n",ex,ey);
		}else{
			printf("The function has a maximum at x=%f, y=%f\n",ex,ey);
		}
		goto A;
	}
}