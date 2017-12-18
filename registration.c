#include <stdio.h>
#include "types.h"
#include "globals.h"
#include "parse.h"




int storeValuesToStruct(char *courseCode,char *userID,long ts,int newSize){
    	int i;
		if(newSize == 0){
			/* if it's the first element create it normally */
				g_courses = realloc(g_courses,sizeof(Course)*(newSize+1));
				strcpy(g_courses[newSize].code,courseCode);
					
				g_courses[newSize].registrations = malloc(sizeof(Registration));
				strcpy(g_courses[newSize].registrations[0].studentID,userID);
				g_courses[newSize].registrations[0].timestamp = ts;
		}
		else{
			/* if it's not iterate through all the previous elements to check for duplicates */
			for(i = 0;i<newSize;i++){
				if(strcmp(g_courses[i].code,courseCode) == 0){
					/* if we found a duplicate, realloc registration +1 */
					size_t size = (sizeof(g_courses[i].registrations)/sizeof(g_courses[i].registrations[0]))+1;
					printf("size: %d",size);
					g_courses[i].registrations = realloc(g_courses[i].registrations,size);
					strcpy(g_courses[i].registrations[size].studentID,userID);
					g_courses[i].registrations[size].timestamp = ts;
				}
				else{
					/* if we didn't find duplicates then continue creating it normalling */
					g_courses = realloc(g_courses,sizeof(Course)*(newSize+1));
					strcpy(g_courses[newSize].code,courseCode);
						
					g_courses[newSize].registrations = malloc(sizeof(Registration));
					strcpy(g_courses[newSize].registrations[0].studentID,userID);
					g_courses[newSize].registrations[0].timestamp = ts;
				}
			}
		}
}

int test(Course *course,int num){
	
	int size = (sizeof(g_courses[num].registrations)/sizeof(Registration));
	
	if(size == 1){

	printf("course code: %s\n",course[num].code);
	printf("registration sID: %s\n",course[num].registrations[0].studentID);
	printf("registration TS: %ld\n",course[num].registrations[0].timestamp);
	}else{
	printf("course code: %s\n",course[num].code);
		for(int i =0;i<size;i++){
		printf("registration sID: %s\n",course[num].registrations[i].studentID);
		printf("registration TS: %ld\n",course[num].registrations[i].timestamp);
		}
	}
}
