#include <stdio.h>
#include "types.h"
#include "globals.h"
#include "parse.h"

int getSizeOfCourses(int index){
	int g = 0;
	do{
		g++;
	}while(strcmp(g_courses[g].code,"ForkC") != 0);

	return g;
}

int getSizeOfReg(int index){
	int g = 0;
	do{
		g++;
	}while(strcmp(g_courses[index].registrations[g].studentID,"ScrewC") != 0);

	return g;
}
int storeValuesToStruct(char *courseCode,char *userID,long ts,int newSize){

	int i, j, copy = 0;

	if(newSize == 0){
		g_courses = realloc(g_courses,sizeof(Course)*(newSize+2));
		strcpy(g_courses[newSize].code,courseCode);

		g_courses[newSize].registrations = malloc(sizeof(Registration)*2);
		strcpy(g_courses[newSize].registrations[0].studentID,userID);
		g_courses[newSize].registrations[0].timestamp = ts;
		strcpy(g_courses[newSize].registrations[1].studentID,"ScrewC");
		strcpy(g_courses[newSize+1].code,"ForkC");
		printf("should i stay or should i go\n");
	}else{
		/*if we already have more than one in the structure*/

		int size = getSizeOfCourses(newSize);

		for (j = 0; j < size; j++){
			if(strcmp(g_courses[j].code,courseCode)==0){
				copy++;
			}
		}

		printf("gg %d\n",size);
		if(copy == 0){

			printf("struct %s: temp %s\n",g_courses[i].code,courseCode);

			g_courses = realloc(g_courses,sizeof(Course)*(size+2));
			strcpy(g_courses[size].code,courseCode);

			g_courses[size].registrations = malloc(sizeof(Registration)*2);
			strcpy(g_courses[size].registrations[0].studentID,userID);
			g_courses[size].registrations[0].timestamp = ts;
			strcpy(g_courses[size].registrations[1].studentID,"ScrewC");
			strcpy(g_courses[size+1].code,"ForkC");

		}else if(copy != 0){
			for(i =0;i<size;i++){
				if(strcmp(g_courses[i].code,courseCode)==0){
					int size = getSizeOfReg(i);
					printf(" duplicate struct %s: temp %s\n",g_courses[i].code,courseCode);
					g_courses[i].registrations = realloc(g_courses[i].registrations,sizeof(Registration)*(size+2));
					strcpy(g_courses[i].registrations[size].studentID,userID);
					g_courses[i].registrations[size].timestamp = ts;
					size++;
					strcpy(g_courses[i].registrations[size].studentID,"ScrewC");
				}
			}
			printf("\n\n");
		}
	}	
}

int findNumOfDuplicates(Course *course, int size){

	int i;
	int j;

	int offset = 1;
	int numOfDup = 0;
	while(numOfDup == 0 && offset != size){
		for(i =0;i<offset;i++){
			for(j = 0;j<size;j++){
				if(strcmp(course[i].code,course[j].code)==0)
					numOfDup++;
			}
		}
		offset++;
	}
	return numOfDup;
}
int filterOutDuplicates(Course *course,int size){

	int counter = 1;
	int i =0;
	int offset = 0;
	printf("%d",size);

	int duplicates = findNumOfDuplicates(course,size);

	while(duplicates == 0 && offset != size){
		char *courseName = course[offset].code;
		for(i = 0;i<size;i++){
			if(strcmp(course[i].code,courseName)==0){
				counter++;
				course[offset].registrations = realloc(course[offset].registrations,sizeof(Registration)*(counter));
				course[offset].registrations[counter] = course[i].registrations[0];
				strcpy(course[i].code,"");
			}
		}
		offset++;
		counter = 1;
		duplicates = findNumOfDuplicates(course,size);
	}
}
int test(Course *course,int num){
	int i = 0;
	int j = 0;
	for(i = 0;i<num;i++){

		int size = getSizeOfReg(i);
		printf("course code: %s\n",course[i].code);
		for(j = 0;j<size;j++)
			printf("registration sID: %s\n",course[i].registrations[j].studentID);
		printf("registration TS: %ld\n",course[i].registrations[j].timestamp);

	}
	return 1;
}
