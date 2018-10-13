
// Created by Oguz Celikel Oct-13-2018 

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAXSTACK 45
 
void init_stack();             													//functions that used 
int give_count();
void push();
struct students pop();
void students_list();
void  stats_on_gpa();
void  performance_list();

double minimum,ave,maximum;     												 //external variables 

struct students                           
{
    int stdID,yearofbirth;
    double gpa;
    char name[30];
}stack;

struct stack_students
{
    int count;
    struct students entries[MAXSTACK];
}s;

int main()
{
	int sayi;
	
	int flag=!EOF;

    init_stack();

    FILE *cfPtr;

    cfPtr = fopen("students.txt", "r");                                         	//opening the file 
    
	if(cfPtr == NULL)   															//to control the file 
    printf("File cannot opened");

    while (!feof(cfPtr))
    {
    	flag=fscanf( cfPtr, "%d %s %d %lf", &stack.stdID, stack.name, &stack.yearofbirth, &stack.gpa);
    	
    	
    	if(flag != EOF)         													//to push if is not end of file 
            push();																
    }

    while(give_count() > 45 )                           							//to pop if count bigger than stack 
    {
        stack=pop();                                       
        printf("Students %s is bumped",stack.name);
    }
    
	fclose(cfPtr);																	//closing the file
	
    printf("Enter 1 for  Students List\n");
    printf("Enter 2 for  The Minimum, Maximum and Average of GPA Values\n");
    printf("Enter 3 for  Performence Results\n");
    
    ilk:
    printf("\nEnter a number:");
    scanf("%d",&sayi);
    
    switch(sayi)
	{
		case 1: 																	//that gives us student list 
		students_list();    									goto ilk;      	 
    
		case 2:																		//that gives us some calculated values of GPA
		stats_on_gpa();  															
		printf("Minimum GPA of Students:%lf\n",minimum); 
		printf("Average GPA of Students:%lf\n",ave);
		printf("Maximum GPA of Students:%lf\n",maximum); 	    goto ilk;
   	
		case 3: 																	//that gives us performance list of students
		stats_on_gpa();
		performance_list(); 									goto ilk;
    
		default:  printf("\nEnter only 1,2 or 3:"); 	    	goto ilk;
	}
    
    return 0;
}

void init_stack()																//initialize the stack
{
    s.count=0;
}

int give_count()																//that gives count of stack entries
{
    return s.count;
}

struct students pop()															//that pops from stack
{
    if(s.count > 0){
        s.count--;
        return s.entries[s.count];
    }
    else{
        printf("Error-Attempt to pop empty stack\n");
        exit(-1);
    }
}

void push()																		//that pushes on stack
{
    if(s.count < MAXSTACK){
        s.entries[s.count] = stack;
        s.count++;
    }
    else{
        printf("Error-Attempt to push on full stack\n");
        exit(-2);
    }
}

void students_list()															 //function shows students on the file 
{
		int i;
    	
    	printf("Student ID\tStudent Name\t\tYear of Birth\tGPA\t\n");
    	for(i=0 ; i<s.count ; i++)
    	printf( "%d\t\t%s\t\t%d\t\t%.2f\n", s.entries[i].stdID, s.entries[i].name, s.entries[i].yearofbirth, s.entries[i].gpa);        
}

void  stats_on_gpa()											//function calculates minimum, maximum and average value of GPA
{
	int i;
	double sum=0.0;
        
	minimum=s.entries[0].gpa;
	for (i=0 ; i<s.count ; i++){
		if(s.entries[i].gpa<minimum)
		minimum=s.entries[i].gpa;
	}
	
	for (i=0 ; i<s.count ;i++)
	sum =sum+s.entries[i].gpa;
	
	ave=sum/s.count;
	
	maximum=s.entries[0].gpa;
	for (i=0 ; i<s.count ; i++){
		if(s.entries[i].gpa>maximum)
		maximum=s.entries[i].gpa;
	}	
}

void performance_list()											//function shows results as Successful or Failed
{
 	int i;
 	for (i=0 ; i<s.count ; i++){
 		if(s.entries[i].gpa==maximum)
 		printf("%s->Best\n",s.entries[i].name);
 		if(s.entries[i].gpa==minimum)
 		printf("%s->Worst\n",s.entries[i].name);
		if(s.entries[i].gpa>ave && s.entries[i].gpa!=maximum)
		printf("%s->Successful\n",s.entries[i].name);
		else if(s.entries[i].gpa<ave  &&  s.entries[i].gpa!=minimum )
		printf("%s->Failed\n",s.entries[i].name);
	}
}


