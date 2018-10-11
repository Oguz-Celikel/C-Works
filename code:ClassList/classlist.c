
// Created by Oguz Celikel Oct-12-2018

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
	char firstname[16];
	char lastname[32];
	int grade;
	int id_num;
};

char filename[128];

int main(){
	int choice=0,i,j,k,max=0,N=0,temp;
	char fname[16],lname[32];
	FILE *fpi;
	while(1){
		printf("\nEnter file name:");
		scanf("%s",filename);
		fpi = fopen(filename,"r");
		if(fpi == NULL){
			printf("The file cannot open!");
		}else{
			break;
		}
	}
	for(i=0;;i++){
		char c;
		int d;
		if(fscanf(fpi,"%s %s %d %d",&c,&c,&d,&d)==EOF){
			break;
		}
		N++;
	}
	struct student class[N];
	fclose(fpi);
	fopen(filename,"r");
	for(i=0;i<N;i++){
		if(fscanf(fpi,"%s %s %d %d",&class[i].firstname,&class[i].lastname,&class[i].id_num,&class[i].grade)==EOF){
			break;
		}
		if(max<class[i].grade){
			max = class[i].grade;
		}
	}
	fclose(fpi);
	for(i=0;i<N;i++){
		if(max==class[i].grade){
			printf("%s %s received the maximum grade:%d\n",class[i].firstname,class[i].lastname,class[i].grade);
		}
	}
	while(7!=choice){
		printf("\nEnter your choice:");
		printf("\n1.First name based search");
		printf("\n2.Last name based search");
		printf("\n3.Sort list based on grades");
		printf("\n4.Sort list based on first names");
		printf("\n5.Sort list based on last names");
		printf("\n6.Sort list based on students ID's");
		printf("\n7.End\n");
		printf("\nWhich one -->>");
		scanf("%d",&choice);
		if(1==choice){
			printf("Enter a first name:");
			scanf("%s",&fname[0]);
			for(i=0;i<N;i++){
				if(0==strcmp(fname,class[i].firstname)){
					printf("%s %s, grade:%d\n",class[i].firstname,class[i].lastname,class[i].grade);
				}
			}
		}
		if(2==choice){
			printf("Enter a last name:");
			scanf("%s",&lname[0]);
			for(i=0;i<N;i++){
				if(0==strcmp(lname,class[i].lastname)){
					printf("%s %s, grade:%d\n",class[i].firstname,class[i].lastname,class[i].grade);
				}
			}
		}
		if(3==choice){
			for(i=0;i<N-1;i++){
				for(j=N-1;i<j;j--){
					if(class[j-1].grade<class[j].grade){
						struct student temp = class[j-1];
						class[j-1] = class[j];
						class[j] = temp;
					}
				}
			}
			fpi = fopen("output.txt","w");
			for(i=0;i<N;i++){
				printf("%s %s %d %d\n",class[i].firstname,class[i].lastname,class[i].id_num,class[i].grade);
				fprintf(fpi,"%s %s %d %d\r\n",class[i].firstname,class[i].lastname,class[i].id_num,class[i].grade);
			}
			fclose(fpi);
		}
		if(4==choice){
			for(i=0;i<N-1;i++){
				for(j=N-1;i<j;j--){
					if(strcmp(class[j-1].firstname,class[j].firstname)>0){
						struct student temp = class[j-1];
						class[j-1] = class[j];
						class[j] = temp;
					}
				}
			}
			fpi = fopen("output.txt","w");
			for(i=0;i<N;i++){
				printf("%s %s %d %d\n",class[i].firstname,class[i].lastname,class[i].id_num,class[i].grade);
				fprintf(fpi,"%s %s %d %d\r\n",class[i].firstname,class[i].lastname,class[i].id_num,class[i].grade);
			}
			fclose(fpi);
		}
		if(5==choice){
			for(i=0;i<N-1;i++){
				for(j=N-1;i<j;j--){
					if(strcmp(class[j-1].lastname,class[j].lastname)>0){
						struct student temp = class[j-1];
						class[j-1] = class[j];
						class[j] = temp;
					}
				}
			}
			fpi = fopen("output.txt","w");
			for(i=0;i<N;i++){
				printf("%s %s %d %d\n",class[i].firstname,class[i].lastname,class[i].id_num,class[i].grade);
				fprintf(fpi,"%s %s %d %d\r\n",class[i].firstname,class[i].lastname,class[i].id_num,class[i].grade);
			}
			fclose(fpi);
		}
		if(6==choice){
			for(i=0;i<N-1;i++){
				for(j=N-1;i<j;j--){
					if(class[j-1].id_num>class[j].id_num){
						struct student temp = class[j-1];
						class[j-1] = class[j];
						class[j] = temp;
					}
				}
			}
			fpi = fopen("output.txt","w");
			for(i=0;i<N;i++){
				printf("%s %s %d %d\n",class[i].firstname,class[i].lastname,class[i].id_num,class[i].grade);
				fprintf(fpi,"%s %s %d %d\r\n",class[i].firstname,class[i].lastname,class[i].id_num,class[i].grade);
			}
			fclose(fpi);
		}
	}
}