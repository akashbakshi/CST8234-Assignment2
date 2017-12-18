#include <stdio.h>
#include "types.h"
#include "globals.h"
#include "parse.h"

int storeValuesToStruct(char *courseCode,char *userID,long ts,int newSize,Course *course){
    	
		course = realloc(g_courses,sizeof(Course)*(newSize+1));
		strcpy(course[newSize].code,courseCode);
		course[newSize].registrations = malloc(sizeof(Registration));
		strcpy(course[newSize].registrations[0].studentID,userID);
		course[newSize].registrations[0].timestamp = ts;
		if(doesCourseExists(course,courseCode,newSize)>0){
			printf("exists");
		}
		test(course,newSize);
}

int doesCourseExist(Course *course,char *codeToCheck,int num){
	int exists = 0;

	for(int i =0;i<num;i++){
		if(strcmp(course[num].code,codeToCheck) == 0)
			exists = 1;
	}
	return exists;
}

int test(Course *course,int num){
	
	printf("course code: %s\n",course[num].code);
	printf("registration sID: %s\n",course[num].registrations[0].studentID);
	printf("registration TS: %ld\n",course[num].registrations[0].timestamp);
}
