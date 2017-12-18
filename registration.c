#include <stdio.h>
#include "types.h"
#include "globals.h"
#include "parse.h"

int storeValuesToStruct(char *courseCode,char *userID,long ts,int newSize,Course *course){
    	course = realloc(g_courses,sizeof(Course)*1);
		strcpy(course[0].code,courseCode);
}
