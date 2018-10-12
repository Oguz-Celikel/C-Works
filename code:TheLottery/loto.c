
// Created by Oguz Celikel Oct-12-2018

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void cekilis(int sayi)
{
	int i,j,k, loto[5];
	
	
	for (k=0; k<sayi; k++)
	{
	
	 srand(time(NULL));

	 rand:
		
		for(i=0 ; i<6 ; i++)
		{
		
			loto[i]=1+rand()%49;   
		}
	
		for(i=0 ; i<6 ; i++)
		{
	  		for(j=i ; j<5 ; j++)
	  		{
	  			if(loto[i]==loto[j+1])      
	  			goto rand;
	  		}
   		}
   	
		printf("\nNumbers:\n");
		
		for(i=0 ; i<6 ; i++)
		{
			printf("%d\t",loto[i]);
  		}
  	
  			
    }
  	
  	return sayi;
}

int main()
{
  int i,sayi;
  
  printf("Enter the number of columns:");
  scanf("%d",&sayi);
  
  cekilis(sayi);
 
   return 0;
}
