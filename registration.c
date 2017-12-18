#include <stdio.h>
#include "types.h"
#include "globals.h"
#include "parse.h"

int storeValuesToStruct(char *courseCode,char *userID,long ts,int newSize,Course *course){
    	
		course = realloc(g_courses,sizeof(Course)*(newSize+1));
		strcpy(course[newSize].code,courseCode);

		test(course,newSize);
}

int test(Course *course,int num){
	
	printf("out of touch: %s\n",course[num].code);
}
