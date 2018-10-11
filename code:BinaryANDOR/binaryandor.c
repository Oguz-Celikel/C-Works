
// Created by Oguz Celikel Oct-12-2018

#include <stdio.h>
#include <stdlib.h>

int main(){
	int x,y;
	printf("Enter two integers:");
	scanf("-->%d\n--> %d\n",&x,&y);
	printf("Answer:\n");
	binary(x);
	printf("AND ");
	binary(y);
	printf("= ");
	and(x,y);
	printf("\n");
	binary(x);
	printf("OR ");
	binary(y);
	printf("= ");
	or(x,y);
}

int binary(a){
	int i;
	for(i=7;i>=0;i--){
		printf("%d",(a & (1<<i)) >> i);
	}
	printf(" (%d) ",a);
}

int and(x,y){
	int i,j = 0;
	for(i=7;i>=0;i--){
		int a = ((x & (1<<i)) >>i)&((y & (1<<i)) >>i);
		printf("%d",a);
		int l = 1,k;
		for(k=0;k<i;k++){
			l *= 2;
		}
		j += a*l;
	}
	printf(" (%d) ",j);
}

int or(x,y){
	int i,j = 0;
	for(i=7;i>=0;i--){
		int a = ((x & (1<<i)) >>i)|((y & (1<<i)) >>i);
		printf("%d",a);
		int l = 1,k;
		for(k=0;k<i;k++){
			l *= 2;
		}
		j += a*l;
	}
	printf(" (%d) ",j);
}
