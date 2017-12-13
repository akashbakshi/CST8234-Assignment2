/**
 * YOU MAY NOT EDIT THIS FILE
 */

typedef struct
{
    char studentID[12];
    long timestamp;
} Registration;

typedef struct
{
    char code[12];
    Registration *registrations;
} Course;
