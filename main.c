#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "globals.h"

int main( int argc, char *argv[] ){

    /*testing file io, this will onlybe here temporarily; invalid dir*/
    readFile("gg.txt");
    /*testing file io, valid dir*/
    readFile("reg-20171203.in");


    /*testing file io, outputing to file*/
    createOutputFile("CST8234.out");
}
