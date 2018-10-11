#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_array(int array[], int arraySize);
void print_array(int array[], int arraySize);
int sumnum(int a[], int n);
void bubbleSort(int numbers[], int arraySize);

int main(){
	srand(time(0));
	int n,i;
	printf("Enter array-size: ");
	scanf("%d",&n);
	if(n<0){
		printf("Array-size cannot be negative!");
		return(1);
	}
	int a[n];
	fill_array(a,n);
	print_array(a,n);
	printf("\n");
	bubbleSort(a,n);
	print_array(a,n);
	printf("\nsum: %d",sumnum(a,n));
}

void print_array(int array[], int arraySize){
	int i;
	for(i=0;i<arraySize;i++){
		printf("%d ",array[i]);
	}
}

int sumnum(int a[], int n){
	int result = 0,i;
	for(i=0;i<n;i++){
		result += a[i];
	}
	return(result);
}

void bubbleSort(int numbers[], int array_size){
	int i,j,temp;
	for(i=(array_size-1);i>=0;i--){
		for(j=1;j<=i;j++){
			if(numbers[j-1]>numbers[j]){
				temp = numbers[j-1];
				numbers[j-1] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

void fill_array(int array[], int arraySize){
	int i;
	for(i=0;i<arraySize;i++){
		array[i] = 0+(rand()%((arraySize*2)+1));
	}
}
