
#include <stdio.h>
#include "parse.h"

extern int parseArguments( int argc, char *argv[]){ /* function breaks if a file is specified */
	int i;
	char readType = 'r';
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
				readType = 'a';
			} else {
				printf("%s", argv[i]);
				fileName = argv[i];
				printf("%s", fileName);
			}
		}
		FILE *file = fopen(fileName,readType);
	    while (fscanf(file, "%[^,], %[^,], %ld ", courseCode, uName, &timeStamp) != EOF){
	    	printf("Course code: %s, Username: %s, Timestamp: %ld", courseCode, uName, timeStamp);
	    	printf("\n");
	    }
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

    while (fscanf(file, "%[^,], %[^,], %ld ", courseCode, uName, &timeStamp) != EOF){
    	printf("Course code: %s, Username: %s, Timestamp: %ld", courseCode, uName, timeStamp);
    	printf("\n");
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

void printHelp(){
	printf("\t--help\n");
	printf("\t\tDisplays this guide and exits.\n");
	printf("\t--append NUM\n");
	printf("\t\tFlags the file to be added to.\n");
	printf("\tFILENAME\n");
	printf("\t\tFile name(s) to be read.\n");
}
