
#include <stdio.h>

int readFile(char *dir){
    FILE *file = fopen(dir,"r");
    if(file == NULL){
        printf("DEBUG: File Not Found");
        return 0;
    }
    else
        printf("DEBUG: File Found");
    fclose(file);
}

int createOutputFile(char *dir){
    FILE *file = fopen(dir,"w");

    if(file == NULL){
        printf("DEBUG: File Not Found Creating one");
        return 0;
    }
    else
        printf("DEBUG: File Found Overwriting");
        
    fclose(file);
}