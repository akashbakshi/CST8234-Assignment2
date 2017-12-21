/* PROGRAM: CST8234
   AUTHOR: Justin De Vries, Akash Bakshi
   DATE: 2017-12-20
   PURPOSE: Assignment 2: Registration of students to their classes, read from files and output to files.
   LEVEL OF DIFFICULTY: 4/5
   CHALLENGES: Working with the memory allocation
   HOURS SPENT: 20 total
   EFFICIENCY O((n^n)*n)
*/
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
