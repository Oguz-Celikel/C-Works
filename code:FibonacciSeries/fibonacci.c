
// Created by Oguz Celikel Oct-13-2018

#include<stdio.h>
#include<stdlib.h>

int Fibonacci(int);

struct list_even                     				//it stores even number 
{
	int num1;
	struct list_even *next1;
};

struct list_odd          							//it stores odd number 
{
	int num2;
	struct list_odd *next2;
};

typedef struct list_even even;
typedef struct list_odd odd;

int main()
{
    int n, i = 0,k=0,sayi;

    printf("Enter the number of terms of Fibonacci Series\n");
    scanf("%d",&n);

	even *root1;
	odd *root2;

    printf("Fibonacci series\n");
    
    root1=(even *)malloc(sizeof(even));				//starting points for even nodes 
    even *curr1;
    curr1=root1;

	printf("even:");
    for ( i = 1 ; i <= n ; i++ ){
   	sayi=Fibonacci(i);
        if ( 0 == sayi%2 ) {
        	curr1->next1=(even*)malloc(sizeof(even));
            curr1=curr1->next1;
            curr1->num1=Fibonacci(i);
            curr1->next1=NULL;
        printf("\t%d",curr1->num1);
    }
    }

 	root2=(odd *)malloc(sizeof(odd));					//starting points for odd nodes 
    root2->num2=Fibonacci(2);
    odd *curr2;
    curr2=root2;

	printf("\nodd:");
    for ( k = 1 ; k < n ; k++ ) {
   	sayi=Fibonacci(k);
        if ( 0 != sayi%2 ) {
        	curr2->next2=(odd*)malloc(sizeof(odd));
            curr2=curr2->next2;
            curr2->num2=Fibonacci(k);
            curr2->next2=NULL;
        printf("\t%d",curr2->num2);
    }
    }
    return 0;
}

int Fibonacci(int n)   									//it finds fibonacci numbers recursively
{
   if ( n == 0 )
      return 0;
   else if ( n == 1 )
      return 1;
   else
      return ( Fibonacci(n-1) + Fibonacci(n-2) );
}
