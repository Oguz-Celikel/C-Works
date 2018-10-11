
// Created by Oguz Celikel. Oct-11-2018
// Basic Calculator

#include <stdio.h>
#include <math.h>

int main()
{
    int choose,num1,num2;
   A:
    printf("\n*** CALCULATOR ***\n");
    printf("Choose one of the operations below:\n[1]Addition\n[2]Subtraction\n[3]Multiplication\n[4]Division\n-->");
    scanf("%d",&choose);
    
    switch(choose)
    {
        case 1:
            printf("Enter two numbers: \n");
            scanf("%d %d",&num1,&num2);
            printf("Result:%d\n",num1+num2);
            goto A; break;
         case 2:
            printf("Enter two numbers: \n");
            scanf("%d %d",&num1,&num2);
            printf("Result:%d\n",num1-num2);
            goto A; break;
        case 3:
            printf("Enter two numbers: \n");
            scanf("%d %d",&num1,&num2);
            printf("Result:%d\n",num1*num2);
            goto A; break;
        case 4:
            {
            float num1,num2;
            printf("Enter two numbers: \n");
            scanf("%f %f",&num1,&num2);
            printf("Result:%2.2f\n",num1/num2);
            goto A; break;
            }
        default:
            printf("Please enter a valid command\n");
            goto A;
    }

}
