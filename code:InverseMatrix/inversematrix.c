

//OGUZ CELÝKEL 210206003 HOMEWORK 1 EE204

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int N=10;

int determinant(float a[N][2*N],int N)
{
    float det=0,i;

    if(N==1)
    {
        return a[0][0];
    }
    else if(N==2)
    {
        det=(a[0][0]*a[1][1]-a[0][1]*a[1][0]);
        return det;
    }
    /*else if(N>2)      //KOD EKSÝK!!
    {
    for(i=0 ;i<N ; i++)
        det= det + pow(-1,i)*a[N][2*N]*determinant(a,N);
        return det;
    }*/
}

void main()
{
    float ratio;
    int i,j,k,dim;

    printf("Enter the dimension of the matrix\n");
    scanf("%d" , &dim);
    N=dim;

    float augmatrix[dim][2*dim];

    printf("Enter the elements of the matrix\n");
    for(i=0 ; i<dim ; i++)
        for(j=0 ; j<dim ; j++)
        {
            printf( "Enter the element ( %d , %d )\n" , i+1 , j+1 );
            scanf( "%f" , &augmatrix[i][j] );
        }

    if(determinant(augmatrix, dim) == 0)
    {
        printf("Matrix is not inversible!");
        exit(1);
    }

    for(i=0 ; i<dim ; i++)
        for(j=dim; j<2*dim ; j++)
        {
            if(i==j%dim)
                augmatrix[i][j]=1;
            else
                augmatrix[i][j]=0;
        }

    for(i=0 ; i<dim ; i++)
        for(j=0; j<dim ; j++)
        {
            if(i!=j)
            {
                ratio=augmatrix[j][i]/augmatrix[i][i];
                for(k=i ; k<2*dim ; k++)
                    augmatrix[j][k]-=augmatrix[i][k]*ratio;
            }
        }

    printf("\nInverse of the matrix is:\n");
    for(i=0 ; i<dim ; i++)
    {
        for(j=dim ; j<2*dim ; j++)
        {
            printf("%.3f\t" , augmatrix[i][j]/augmatrix[i][i] );
        }
        printf("\n");
    }
}


