#include <stdio.h>
#include <math.h>

#define PI 3.141593

float hour2ang(int hour);
float min2ang(int min);
int clearField();
int drawCircle(int x, int y, int r);
int clearCircle(int x, int y, int r);
int printField();

int field[40][40];

int main(){
	int hour,minute;
	printf("Enter hour:");
	scanf("%d",&hour);
	printf("Enter minute:");
	scanf("%d",&minute);
	
	float ang1 = hour2ang(hour);
	float ang2 = min2ang(minute);
	
	clearField();
	drawCircle(20,20,10);
	clearCircle((int)(20+(sin(ang1)*5)),(int)(20+(cos(ang1)*5)),5);
	drawCircle((int)(20+(sin(ang2)*15)),(int)(20+(cos(ang2)*15)),5);
	printField();
} 

float hour2ang(int hour){ 
	float result; 
	result=2*PI*(hour%12)/12.0 - PI*0.5; 
	return(result);
} 

float min2ang(int min){ 
	float result; 
	result=2*PI*(min%60)/60.0 - PI*0.5; 
	return(result);
}

int clearField(){
	int i,j;
	for(i=0;i<40;i++){
		for(j=0;j<40;j++){
			field[i][j] = 0;
		}
	}
}

int drawCircle(int x, int y, int r){
	int i,j;
	for(i=0;i<40;i++){
		for(j=0;j<40;j++){
			if(r>sqrt(((x-i)*(x-i))+((y-j)*(y-j)))){
				field[i][j] = 1;
			}
		}
	}
}

int clearCircle(int x, int y, int r){
	int i,j;
	for(i=0;i<40;i++){
		for(j=0;j<40;j++){
			if(r>sqrt(((x-i)*(x-i))+((y-j)*(y-j)))){
				field[i][j] = 0;
			}
		}
	}
}

int printField(){
	int i,j;
	for(i=0;i<40;i++){
		for(j=0;j<40;j++){
			if(field[i][j]){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
}