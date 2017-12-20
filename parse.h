extern int parseArguments( int argc, char *argv[]);

extern int readFile(char *dir,char *type);
extern int createOutputFile(char *type,int num);

extern int storeValuesToStruct(char *courseCode,char *userID,long ts,int newSize);
extern int getSizeOfReg(int index);