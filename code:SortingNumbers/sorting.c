
// Created by Oguz Celikel Oct-11-2018

#include<stdio.h>
int main()
{
		printf("Number Ordering:\n\n");

	int i=0,j,temp,array[20];
		
		printf("PLease enter the numbers\n");
		
		for(i=0;i<20;++i) 
		{
		printf("\n%d.number:",i+1);
			scanf("%d", &array[i]);
		}
	  
	  printf("\nEntered Number:\n"); 
	   for(i=0;i<20;++i)
	    printf("%d\t",array[i]);
		 
		 for(j=0;j<20;++j) 
		 {
			for(i=0;i<19-j;++i)
			{
				if(array[i]>array[i+1]) 
				{
				temp=array[i]; 
				array[i]=array[i+1];
				array[i+1]=temp;
				}
			}
	     }
	 
	 printf("Sorting from Little to Bigger Number \n:\n"); 
	  for(i=0;i<20;++i)
	   printf("%d\t",array[i]);
	   
	   return 0;
}
