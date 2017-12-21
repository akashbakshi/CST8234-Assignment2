#include <stdio.h>
#include "types.h"
#include "globals.h"
#include "parse.h"

/*
 * gets the amount of created courses by iterating through the instances of the struct until it encounters a poison pill
 */
int getSizeOfCourses(int index){ /*Finds size of the struct based on the poison pill "ForkC"*/
	int g = 0;
	do{
		g++;
	}while(strcmp(g_courses[g].code,"ForkC") != 0);

	return g;
}
/*
 * gets the amount of registered students per course by iterating through the instances of the struct until it encounters a poison pill
 */
int getSizeOfReg(int index){
	int g = 0;
	do{
		g++;
	}while(strcmp(g_courses[index].registrations[g].studentID,"ScrewC") != 0);  /*Finds size of the struct based on the poison pill "ScrewC"*/

	return g;
}

/*
 * allocates memory and values as needed
 * Spaghetti ala Bakshi ala JD
 */
int storeValuesToStruct(char *courseCode,char *userID,long ts,int newSize){

	int i, j, copy = 0;

	if(newSize == 0){  /* no struct?  make one */
		g_courses = realloc(g_courses,sizeof(Course)*(newSize+2));
		strcpy(g_courses[newSize].code,courseCode);

		g_courses[newSize].registrations = malloc(sizeof(Registration)*2);
		strcpy(g_courses[newSize].registrations[0].studentID,userID);
		g_courses[newSize].registrations[0].timestamp = ts;
		strcpy(g_courses[newSize].registrations[1].studentID,"ScrewC");
		strcpy(g_courses[newSize+1].code,"ForkC");

	}else{
		/*if we already have more than one in the structure*/

		int size = getSizeOfCourses(newSize);  /* gets current size of the courses struct */

		for (j = 0; j < size; j++){ /* look for duplicates and iterate a counter, if the counter is 0 make a new course,
										otherwise add the students to that course
										should be a function but hit time constraints */
			if(strcmp(g_courses[j].code,courseCode)==0){
				copy++;
			}
		}

		if(copy == 0){ /* if there are none of this course, reallocate more memory to courses, allocate memory to the registrations pointer and update poison pills*/
			g_courses = realloc(g_courses,sizeof(Course)*(size+2));
			strcpy(g_courses[size].code,courseCode);

			g_courses[size].registrations = malloc(sizeof(Registration)*2);
			strcpy(g_courses[size].registrations[0].studentID,userID);
			g_courses[size].registrations[0].timestamp = ts;
			strcpy(g_courses[size].registrations[1].studentID,"ScrewC");
			strcpy(g_courses[size+1].code,"ForkC");

		}else if(copy != 0){ /* if struct exists then just increase memory to registrations and add new student */
			for(i =0;i<size;i++){	/* looks for matching course name before writing */
				if(strcmp(g_courses[i].code,courseCode)==0){
					int size = getSizeOfReg(i);
					g_courses[i].registrations = realloc(g_courses[i].registrations,sizeof(Registration)*(size+2));
					strcpy(g_courses[i].registrations[size].studentID,userID);
					g_courses[i].registrations[size].timestamp = ts;
					size++;
					strcpy(g_courses[i].registrations[size].studentID,"ScrewC");
				}
			}
		}
	}	
}

