// Zadanie 1
// Napisz program Files otwierający plik do odczytu oraz implementujący i testujący trzy funkcje:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// Zadanie 1.1
// Funkcja printChars odczytuje zawartość pliku bajt po bajcie.
void printChars(FILE *file){
    
    char c;
    printf("Zawartosc pliku: \n");

    while((c=getc(file))!=EOF){
        printf("%c",c);
    }

}
// Zadanie 1.2
// Funkcja printLines odczytuje zawartość pliku linia po linii.
void printLines(FILE *file){

    int bufferLength = 255;
    char buffer[bufferLength];

    while(fgets(buffer, bufferLength, file)) {
        printf("%s", buffer);
    }
}
// Zadanie 1.3
// Funkcja copy kopiuje pliki analogicznie do komendy cp.
void copy(const char *addr1, const char *addr2){

    FILE *source = fopen(addr1,"r");
    
    if(!source){
        printf("\nNie mozna odczytac pliku 1!\n");
        return;
    }

    FILE *target = fopen(addr2,"w");
    
    if(!source){
        printf("\nNie mozna odczytac pliku 2!\n");
        return;
    }

    char c;

    while((c=getc(source))!=EOF){
        putc(c,target);
    }

    printf("\nPomyslnie skopiowano plik!\n");

    fclose(source);
    fclose(target);
}

void main(){

    FILE *file = fopen("plik.txt", "r");
    
    if(!file){
        printf("Blad otwarcia pliku!\n");
        return;
    }
    //printf("printChars\n");
    //printChars(file);

    //printf("\nprintLines\n");
    //printLines(file);

    fclose(file);

    copy("plik.txt","plik2.txt");

}