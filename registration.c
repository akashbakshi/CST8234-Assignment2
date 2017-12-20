#include <stdio.h>
#include "types.h"
#include "globals.h"
#include "parse.h"



int storeValuesToStruct(char *courseCode,char *userID,long ts,int newSize){
	/* if it's the first element create it normally */
	g_courses = malloc(sizeof(Course)*(newSize+1));
	strcpy(g_courses[newSize].code,courseCode);
					
	g_courses[newSize].registrations = malloc(sizeof(Registration));
	strcpy(g_courses[newSize].registrations[0].studentID,userID);
	g_courses[newSize].registrations[0].timestamp = ts;
		
	test(g_courses,newSize);
}
int findNumOfDuplicates(Course *course, int size){
	/* Used to get the number of duplicates */
	int offset = 1;
	int numOfDup = 0;
	while(numOfDup == 0 && offset != size){
		for(int i =0;i<offset;i++){
			for(int j = 0;j<size;j++){
				if(strcmp(course[i].code,course[j].code)==0)
					numOfDup++;
			}
		}
		offset++;
	}
	return numOfDup;
}
int filterOutDuplicates(Course *course,int size){
	/* Used to remove all duplicates */
	int counter = 1;
	int i =0;
	int offset = 0;
	printf("%d",size);

	int duplicates = findNumOfDuplicates(course,size);
	
	while(duplicates != 0 && offset != size){
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
	

	printf("course code: %s\n",course[num].code);
	printf("registration sID: %s\n",course[num].registrations[0].studentID);
	printf("registration TS: %ld\n",course[num].registrations[0].timestamp);
	
}
