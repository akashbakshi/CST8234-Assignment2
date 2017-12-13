
#include <stdio.h>

int readFile(char *dir){
    FILE *file = fopen(dir,"r");
    if(file == NULL){
        printf("DEBUG: File Not Found\n");
        return 0;
    }
    else
        printf("DEBUG: File Found\n");
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