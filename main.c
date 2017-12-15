#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "globals.h"
#include "parse.h"

int main( int argc, char *argv[] ){


    printf("\nTesting Parser\n%d",argc);
    /*testing file io, valid dir*/
    



    if ( ! parseArguments( argc, argv) )
        exit(0);


    return 0;
}
