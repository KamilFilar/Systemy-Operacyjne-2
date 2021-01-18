// Zadanie 2
// Napisz program arguments wypisujący kolejno: wartość zmiennej argc, adres programu, nazwę programu *, przekazane parametry

#include <stdio.h>
#include <windows.h>
  
void main(int argc, char* argv[]){

	char buffer[MAX_PATH];
    
    printf("argc = %d\n", argc);
    GetModuleFileNameA( NULL, buffer, MAX_PATH );
    printf( "addr: %s\n", buffer );
    printf("name: %s\n",argv[0]);

	int i;
	for(i=1;i<argc;i++){
        
		printf("params: %s\n",argv[i]);
	}
}