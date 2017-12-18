extern int parseArguments( int argc, char *argv[]);

extern int readFile(char *dir);
extern int createOutputFile(char *dir,char *type);

extern int storeValuesToStruct(char *courseCode,char *userID,long ts,int newSize);