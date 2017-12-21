#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "globals.h"
#include "parse.h"

int main( int argc, char *argv[] ){

    if ( ! parseArguments( argc, argv) )
        exit(0);



    return 0;
}
