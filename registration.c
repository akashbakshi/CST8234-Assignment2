#include <stdio.h>
#include "types.h"
#include "globals.h"
#include "parse.h"

int storeValuesToStruct(char *courseCode,char *userID,long ts,int newSize){

	g_courses = realloc(g_courses,sizeof(Course)*(newSize+1));
	strcpy(g_courses[newSize].code,courseCode);

	g_courses[newSize].registrations = malloc(sizeof(Registration)*1);
	strcpy(g_courses[newSize].registrations[0].studentID,userID);
	g_courses[newSize].registrations[0].timestamp = ts;
	test(g_courses,newSize);
}

int prev(char *courseCode,char *userID,long ts,int newSize){
/*
	int i = 0;

		g_courses = realloc(g_courses, sizeof(Course)*(newSize+1));
	strcpy(g_courses[newSize].code,courseCode);
	g_courses[newSize+1].code[0] = '\n';

	if (g_courses[newSize].registrations == NULL){
		g_courses[newSize].registrations = calloc(1, sizeof(Registration)+1);
		g_courses[newSize].registrations[0].studentID[0] = '\n';
		printf("New reg allocated\n");
	}
	g_courses[newSize].registrations = realloc(g_courses[0].registrations, sizeof(Registration)+1);

	do {
		printf("Trying to register\n");
		if (g_courses[newSize].registrations[i].studentID[0] == '\n'){
			printf("Registering\n");
			strcpy(g_courses[newSize].registrations[i].studentID,userID);
			g_courses[newSize].registrations[i].timestamp = ts;
			g_courses[newSize].registrations[i+1].studentID[0] = '\n';
			printf("Added\n");
		}
		i++;
	} while (g_courses[newSize].registrations[i].studentID[0] != '\n');
	*/
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
		printf("course code: %s\n",course[i].code);
		printf("registration sID: %s\n",course[i].registrations[0].studentID);
		printf("registration TS: %ld\n",course[i].registrations[0].timestamp);
	
	}
	return 1;
}
