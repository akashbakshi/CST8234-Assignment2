
#include <stdio.h>

int readFile(char *dir){
    FILE *file = fopen(dir,"r");
    char buffer[255];
    if(file == NULL){
        printf("DEBUG: File Not Found\n");
        return 0;
    }
    printf("%s", file);

    fgets(buffer, 255, (FILE*)file);
    printf("%s", buffer);

    fgets(buffer, 255, (FILE*)file);
    printf("%s", buffer);

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