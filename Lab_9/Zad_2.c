// Zadanie 2
// Napisz program misc implementujący i testujący następujące funkcje:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <errno.h>
errno_t err;
// Zadanie 2.1
// Funkcja losuj zwraca wartość losową z przedziału [a, b)
int losuj(int a, int b) {

	return a + rand() % (b - a);

}

// Zadanie 2.2
// Funkcja wariacje1 wylicza metodą kombinatoryczną liczbę ciągów 2-elementowych,
// jakie można utworzyć ze znaków określonych wyrażeniem regularnym [a-zA-Z0-9./]
int wariacje1(){
    int one = ('z' - 'a' + 1) + ('Z' - 'A' + 1) + ( '9' - '0' + 1) + 1 + 1;
    int two = one * one;

    return two;
}

// Zadanie 2.3
// Funkcja wariacje2 wylicza metodą brutalnej siły liczbę ciągów 2-elementowych,
// jakie można utworzyć z wartości określonych wyrażeniem regularnym [a-zA-Z0-9./]
int wariacje2(){
	int i_max = ('z' - 'a' + 1) + ('Z' - 'A' + 1) + ( '9' - '0' + 1) + 1 + 1;

	int i,j;
	int ilosc=0;

	for(i=0;i<i_max;i++){
		for(j=0;j<i_max;j++){
			ilosc++;
		}
	}
	return ilosc;
}

// Zadanie 2.4
// Funkcja set w sposób losowy określa wartość parametru salt dla funkcji crypt_r.
void set(char salt[2]){

	int one = ('z' - 'a' + 1) + ('Z' - 'A' + 1) + ( '9' - '0' + 1) + 1 + 1;

	char tab[one];
	//printf("%d", one);
	int i = 0;

	int j;

	for(j = 'a'; j <= 'z'; j++) {
		tab[i] = j;
		i++;
	}

	for(j = 'A'; j <= 'Z'; j++) {
		tab[i] = j;
		i++;
	}

	for(j = '0'; j <= '9'; j++) {
		tab[i] = j;
		i++;
	}

	tab[i] = '.';
	i++;
	tab[i] = '/';


	salt[0] = tab[losuj(0,one)];
	salt[1] = tab[losuj(0,one)];
}

// Zadanie 2.5
// Funkcja errnoExample ilustruje wypisanie błędu otwarcia pliku przy pomocy zmiennej globalnej errno *
void errnoExample(){

    FILE *plik = fopen("plik.txt","rw");

    if (!plik){
	    _get_errno(&err);

	    if(err == 2){
	    	printf("\nErrno: Nie znaleziono pliku\n");
		}
		else if(err == 1){
			printf("\nErrno:Brak uprawnienien\n");
		}
	}
    else{
    	puts("Plik otwarto pomyslnie!\n");
        fclose(plik);
	}
}

// Zadanie 2.6
// Funkcja perrorExample ilustruje wypisanie błędu otwarcia pliku przy pomocy funkcji perror *
void perrorExample(){

    FILE *plik = fopen( "plik.txt", "rw" );

    if( plik == NULL ){
         perror( "plik.txt" );
	}
    else{
    	puts("Plik otwarto pomyslnie!\n");
        fclose( plik );
	}
}

int main(int argc, char *argv[]) {

	printf("RAND_MAX = %d\n",RAND_MAX);

	srand(time(0));

	int a = 0;
	int b = 20;

    printf("losuj(%d, %d) = %d\n \n", a, b, losuj(a,b));

    printf("wariacje1() = %d\n\n", wariacje1());
	printf("wariacje2() = %d\n\n", wariacje2());

	errnoExample();
	perrorExample();

	char salt[2];

	for (i=0;i<liczbaLosowan;i++){
		set(salt);

		printf("%c%c\n", salt[0], salt[1]);
	}

}
