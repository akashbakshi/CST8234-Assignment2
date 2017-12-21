
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

/*
 * parses command line arguments
 */
int parseArguments( int argc, char *argv[]){

	int i, j;

	char *readType = "w";
	char *fileName;

	char *courseCode[8],*uName[9];
	long *timeStamp;
	if (argc == 1){  /*If nothing is entered, print help and smokebomb out of here*/
		printHelp();
		exit(0);
	}

	for (i = 0; i < argc; i++){
		if (strcmp(argv[i], "--help") == 0){
			printHelp();
			exit(1);
		} else if (strcmp(argv[i], "--append") == 0){
			readType = "a";
			break;
		}
	}
	for (j = i+1; j < argc; j++){  /*Iterates through remaining variables (if any)*/
		fileName = argv[j];
		readFile(fileName,readType);
	}

}

/*
 * Reads data from file and passes to struct handler function
 */
int readFile(char *dir,char *type){

	char *courseCode[8],*uName[9];
	long *timeStamp;
	int i = 0;

	FILE *file = fopen(dir,"r");
	if(file == NULL){
		printf("DEBUG: File Not Found\n");
		return 0;
	}

	printf("%s", file);

	while (fscanf(file, "%7[^,], %8[^,], %13ld ", courseCode, uName, &timeStamp) == 3){
		storeValuesToStruct(courseCode,uName,timeStamp,i);
		i++;
	}
	fclose(file);

	writeToFile(type, g_courses, i);

	return 0;
}

/*
 * Writes data data to file using a copy of the g_courses struct, the type of file operation it will be using, and an int to help find how many total courses there are
 */
int writeToFile(char *type, Course *dir,int index){

	int i, j;
	FILE *file;

	int courseNum = getSizeOfCourses(index);  /*Finds size of the final courses struct for printing purposes*/
	if(file == NULL){
		printf("DEBUG: File Not Found Creating one\n");
		return 0;
	}
	else{
		for (i = 0; i < courseNum; i++){
			file = fopen(dir[i].code, type);
			int size = getSizeOfReg(i);  /*Finds size of the final registration struct per courses struct*/
			for (j = 0; j < size; j++){
				fprintf(file,"%s:%ld\n",dir[i].registrations[j].studentID, dir[i].registrations[j].timestamp);
			}
		}
	}
	fclose(file);
}

