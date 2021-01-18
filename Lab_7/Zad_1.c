// Zadanie 1
// Napisz program check sprawdzający na jakim systemie został skompilowany. Wykorzystać kompilację warunkową.
#include <stdio.h>


void main(){

    #ifdef _WIN32 // Includes both 32 bit and 64 bit
	    printf("Program compiled on: Windows");
	#elif __unix__
	    printf("Program compiled on: Unix");
	#endif
}