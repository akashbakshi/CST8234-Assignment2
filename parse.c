
#include <stdio.h>
#include "types.h"
#include "globals.h"
#include "parse.h"

void printHelp(){
	printf("\t--help\n");
	printf("\t\tDisplays this guide and exits.\n");
	printf("\t--append NUM\n");
	printf("\t\tFlags the file to be added to.\n");
	printf("\tFILENAME\n");
	printf("\t\tFile name(s) to be read.\n");
}

int parseArguments( int argc, char *argv[]){ /* function breaks if a file is specified */

	int i;
	
		
	char *readType = "r";
	char *fileName;

	char *courseCode[8],*uName[9]; /* temp vars, may need to be moved to parse function later */
	long *timeStamp;
		if (argc == 1){
			printHelp();
			exit(0);
		}

		for (i = 0; i < argc; i++){
			if (strcmp(argv[i], "--help") == 0){
				printHelp();
				exit(1);
			} else if (strcmp(argv[i], "--append") == 0){
				readType = "a";
				
			} else {
				fileName = argv[1];
			}
		}
		printf("\n%s\n", fileName);
		readFile(fileName);
	   
}

int doesCourseExists(char *name){
	int exists = 0;

	if(strcmp(g_courses->code,name) == 0)
		exists ++;

	return exists;
}
int storeValuesToStruct(char *courseCode,char *userID,long ts,int newSize){
    	printf("geyy:%s ",courseCode);
	
}

int readFile(char *dir){

	char *courseCode[8],*uName[9]; /* temp vars, need to be moved to parse function later */
	long *timeStamp;
	int i = 0;
	
	Course *g_courses = malloc(sizeof(Course));
	g_courses->registrations = malloc(sizeof(Registration));
	
    FILE *file = fopen(dir,"r");
    if(file == NULL){
        printf("DEBUG: File Not Found\n");
        return 0;
    }
	
    printf("%s", file);

    while (fscanf(file, "%[^,], %[^,], %ld ", courseCode, uName, &timeStamp) != EOF){
		printf("hiii:%s ",courseCode);
		
		strcpy(g_courses->code,courseCode);
		storeValuesToStruct(&courseCode,uName,timeStamp,i);
		i++;
  }

    fclose(file);
	printf("out of touch: %s",g_courses[0].code);

	return 0;
}
int printCourses(int num){
	for(int i =0;i<num;i++){
	}
}
int createOutputFile(char *dir,char *type){
    FILE *file = fopen(dir,type);

    if(file == NULL){
        printf("DEBUG: File Not Found Creating one\n");
        return 0;
    }
    else
        printf("DEBUG: File Found Overwriting\n");
        
    fclose(file);
}

