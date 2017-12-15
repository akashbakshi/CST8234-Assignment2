
#include <stdio.h>
#include "parse.h"

extern int parseArguments( int argc, char *argv[], char *courseCode, char *uName, long *timeStamp){

}


int readFile(char *dir){

	char *courseCode[8],*uName[9]; /* temp vars, need to be moved to parse function later */
	long *timeStamp;

    FILE *file = fopen(dir,"r");
    char buffer[255];
    if(file == NULL){
        printf("DEBUG: File Not Found\n");
        return 0;
    }
    printf("%s", file);

/*    while (file != EOF){
    	fscanf(file, "%8[^,]", courseCode);
    	fscanf(file, "%9[^,]", uName);
    	fscanf(file, "%ld", &timeStamp);
    	printf("Course code: %s, Username: %s, Timestamp: %ld\n", courseCode, uName, timeStamp);
    }*/


    while (fscanf(file, "%[^,], %[^,], %ld", courseCode, uName, &timeStamp) != EOF){
    	printf("Course code: %s, Username: %s, Timestamp: %ld\n", courseCode, uName, timeStamp);
    }

    fclose(file);
}

int createOutputFile(char *dir){
    FILE *file = fopen(dir,"w");

    if(file == NULL){
        printf("DEBUG: File Not Found Creating one\n");
        return 0;
    }
    else
        printf("DEBUG: File Found Overwriting\n");
        
    fclose(file);
}
