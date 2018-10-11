
// Created by Oguz Celikel Oct-12-2018

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main ()
{
    int array[100],array2[100];;
    int i,j,k,min=0,max=0,N=0,fark;

    printf("Enter N Value: ");
    scanf("%d",&N);
    if(N>100){
        printf("It is too long ! Try Again..\n");
        main();
    }
    printf("Enter Min Value: ");
    scanf("%d",&min);
    printf("Enter Max Value: ");
    scanf("%d",&max);
    fark=max-min;

    if(fark>100){
    	printf("This range is too long ! Try Again..\n");
    	main();
	}
    srand(time(NULL));
    printf("Histogram of the N=%d random numbers is as follows\n\n",N);
    for(j=0; j<N; j++)
    {
        array[j] =rand()%(fark+1)+min;
    }
    for(i=min; i<=max; i++)
    {
        printf("%d ",i);
        for(k=0; k<N; k++)
        {
            if(i==array[k]){
                printf("X");
            }
        }
        printf("\n");
    }
    printf("\nExiting Now...");
    return 0;
}
