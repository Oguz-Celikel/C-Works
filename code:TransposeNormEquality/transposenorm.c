
// Created by Oguz Celikel Oct-13-2018

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ftranspose(int,int);
int fnorm(int);
void fequal(int,int,int,int);

int main()
{
    int arr[100],i,nm,comp=0,rw,col,row,column,row2,colm2;
    
	printf("Enter a matrix to find transpose\n");
    
	printf("Enter the row of matrix:");
    	scanf("%d",&rw);
    printf("Enter the column of matrix:");
    	scanf("%d",&col);
    
	ftranspose(rw,col);
    
	printf("\nEnter a vector to find norm\n");
    printf("Enter the N:");
    	scanf("%d",&nm);
   
    fnorm(nm);
   
    printf("\nEnter two matrix to compare them\n");
   
    printf("\nEnter row for 1 st matrix:");
    	scanf("%d",&row);
    printf("Enter column for 1st matrix:");
    	scanf("%d",&column);
    printf("\nEnter row for 2nd matrix:");
    	scanf("%d",&row2);
    printf("Enter column for second matrix:");
    	scanf("%d",&colm2);
    
	fequal(row,column,row2,colm2);

	return 0;
}

int ftranspose (int row,int colm)
{
    double **mat,**trpse;
	int i,j;
   
    mat=(double**)malloc(row*sizeof(double));  //dynamic arrays for rowa
    trpse=(double**)malloc(row*sizeof(double));
    
	for(j=0 ; j<colm ; j++)
    {
        mat[j]=(double*)malloc(colm*sizeof(double)); //dynamiic arrays for columns
        trpse[j]=(double*)malloc(colm*sizeof(double));
    }

    for(i=0 ; i<row ; i++)
        for(j=0 ; j<colm ; j++)
        {
            printf("Enter (%d),(%d):",i+1,j+1);	
            	scanf("%lf",&mat[i][j]);
        }
    
	for(i=0 ; i<row ; i++)   //transpose
        for(j=0 ; j<colm ; j++)
        {
            trpse[j][i]=mat[i][j];
        }
    
	printf("Transpose is:\n");
    for(i=0 ; i<colm ; i++)
    {
        for(j=0 ; j<row ; j++)
        {
            printf("%.3f\t",trpse[i][j]);
        }
        printf("\n");
    }
    
	return 0;
    
	free(mat);
    free(trpse);


}
int fnorm (int dim)

{
    int *arr;
    int i,neww[100];
    double summ=0;
    
	if(dim>10) //if dim is bigger than 10, it warns us
    {
        printf("ERROR:Elements of norm are too much");
        return 0;
    }

	printf("Enter a number:\n");
    
	arr=(int *)malloc(sizeof(int)*dim);   //creating memory amount of dimension
    
	for(i=0 ; i<dim ; i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0 ; i<dim ; i++)
    {
        neww[i]=arr[i]*arr[i];

    }
    
	for(i=0 ; i<dim ; i++)
    {
        summ=summ+neww[i];
    }

    printf("%.3f\n",sqrt(summ));
    
	return 0;

	free(arr);
}

void fequal(int row,int column,int rw,int col)
{
    int i,j,comp,arr1[100][100],arr2[100][100];
    
	if(row!=rw || column!=col)	//checking equality for rows and columns
    {
        printf("They are not equal");
        exit (1);
    }

    for(i=0 ; i<row ; i++)
        for(j=0 ; j<column ; j++)
        {
            printf("\nEnter (%d),(%d) of 1st matrix:",i+1,j+1);
            	scanf("%d",&arr1[i][j]);
        }
    
	for(i=0 ; i<rw ; i++)
        for(j=0 ; j<col ; j++)
        {
            printf("\nEnter (%d),(%d) of 2nd matrix:",i+1,j+1);
            	scanf("%d",&arr2[i][j]);
        }

    for(i=0 ; i<row ; i++) //comparing each elements
        for(j=0 ; j<column ; j++)
        {
            if(arr1[i][j]==arr2[i][j])	
                comp=1;
			else
				comp=0;	
        }
    if(comp==1)
        printf("They are equal");
    else
        printf("They are not equal matrix");
}
