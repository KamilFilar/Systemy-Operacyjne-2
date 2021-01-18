// Zadanie 5
// Napisz program dodawanie realizujący dodawanie pisemne.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*Function to return the digit of n-th position of num. Position starts from 0*/
int getdigit(int num, int n){
    
    int r;

    r = num / pow(10, n);
    r = r % 10;

    return r;
}

void main(){

    char aInput[256];
    char bInput[256];

    printf("Podaj pierwsza liczbe: ");
    fgets(aInput, sizeof(aInput), stdin);
    printf("Podaj druga liczbe: ");
    fgets(bInput, sizeof(bInput), stdin);
    printf("\n");

    unsigned int a, b;

    a = (unsigned int)strtol(aInput, NULL, 0);
    b = (unsigned int)strtol(bInput, NULL, 0);

    if (b > a){
        int temp = b;
        b = a;
        a = temp;
    }

    if (a < 0 || b < 0){
        printf("Nie mozna wykonac dodawania na liczbach ujemnych! \n");
        return;
    }
    unsigned int val = a + b;

    int aSize = (int)floor(log10(abs(a))) + 1;
    int bSize = (int)floor(log10(abs(b))) + 1;
    int valSize = (int)floor(log10(abs(val))) + 1;

    int maxSize = valSize < 2 ? 2 : valSize;

    int i = 0;

    char *transferred = malloc(maxSize + 1);

    for (i = 0; i < bSize; i++){

        int v;
        if (i == 0 || transferred[i - 1] == ' '){
            v = getdigit(b, i) + getdigit(a, i);
        }   
        else{
            v = getdigit(b, i) + getdigit(a, i) + transferred[i - 1] - '0';
        }
        if (v >= 10){
            transferred[i] = ((v / 10) + '0');
        }     
        else{
            transferred[i] = ' ';
        }
            
    }
    for (i; i < maxSize; i++){
        transferred[i] = ' ';
    }

    transferred[i] = '\0';

    strrev(transferred);

    printf("%s\n", transferred);

    // print pierwsza liczba
    for (i = 0; i < maxSize - aSize + 1; i++)
        printf(" ");
    printf("%d\n", a);

    // print druga liczba
    printf("+");
    for (i = 0; i < maxSize - bSize; i++)
        printf(" ");
    printf("%d\n", b);

    // print ---------
    for (i = 0; i < maxSize + 1; i++)
        printf("-");
    printf("\n");

    // print wynik
    for (i = 0; i < maxSize - valSize + 1; i++)
        printf(" ");
    printf("%d", val);
}