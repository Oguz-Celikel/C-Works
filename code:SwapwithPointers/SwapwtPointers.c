
// Created by Oguz Celikel Oct-12-2018

#include <stdio.h>

void swap_nums(int *x, int *y){
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void swap_pointers(char *x, char *y){
	char tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int main(){
	int a,b;
	char *s1,*s2;
	
	a = 3; b = 4;
	printf("a is %d\n",a);
	printf("b is %d\n",b);
	swap_nums(&a,&b);
	printf("After swap\n");
	printf("a is %d\n",a);
	printf("b is %d\n",b);
	
	s1 = "I should print second";
	s2 = "I should print first";
	printf("s1 is %s\n",s1);
	printf("s2 is %s\n",s2);
	swap_pointers(&s1,&s2);
	printf("After swap\n");
	printf("s1 is %s\n",s1);
	printf("s2 is %s\n",s2);
	
	return 0;
}
