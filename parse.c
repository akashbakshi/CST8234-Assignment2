
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
				fileName = argv[i+1];
			} else {
			}
		}
		printf("\n%s\n", fileName);
		readFile(fileName,readType);
	   	
}


int readFile(char *dir,char *type){

	char *courseCode[8],*uName[9]; /* temp vars, need to be moved to parse function later */
	long *timeStamp;
	int i = 0;
	
	
    FILE *file = fopen(dir,"r");
    if(file == NULL){
        printf("DEBUG: File Not Found\n");
        return 0;
    }
	
    printf("%s", file);

    while (fscanf(file, "%[^,], %[^,], %ld ", courseCode, uName, &timeStamp) != EOF){
		storeValuesToStruct(courseCode,uName,timeStamp,i);
		
  		/*filterOutDuplicates(g_courses,i);*/
		i++;
  	}
    fclose(file);


	writeToFile(type, g_courses, i);
	
   
	return 0;
}
/*int appendToFile(char *dir,int index){
		FILE *file = fopen(dir,"a");

		if(file == NULL){
			printf("DEBUG: File Not Found Creating one\n");
			return 0;
		}
		else
			{
				printf("hey");
				fprintf(file,"%s:%ld\n",g_courses[index].registrations[0].studentID,g_courses[index].registrations[0].timestamp);
			}
			
		fclose(file);
	
	
}*/
int writeToFile(char *type, Course *dir,int index){

		int i, j;
		FILE *file;

		printf("LOL %s TYPE %s\n", dir[0].code, type);
		int courseNum = getSizeOfCourses(index);
		if(file == NULL){
			printf("DEBUG: File Not Found Creating one\n");
			return 0;
		}
		else
			{
				printf("Ready to append to file");
				for (i = 0; i < courseNum; i++){
					int size = getSizeOfReg(i);
					printf("%d\n", i);
					for (j = 0; j < size; j++){
						file = fopen(dir[i].code, type);
						
						printf("%s:%ld\n",dir[i].registrations[j].studentID, dir[i].registrations[j].timestamp);
					}
				}
			}
		fclose(file);
}

