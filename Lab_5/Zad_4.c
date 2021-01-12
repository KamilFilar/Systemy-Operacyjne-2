// Zadanie 4
// Napisz program NewLine testujący jakie znaki określają koniec linii w pliku tekstowym na systemie Windows i Linux. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// Zadanie 4.1
// Funkcja printHex wypisuje plik w postaci dwucyfrowych liczb szesnastkowych.
void printHex(FILE *file){
    
    char ch;
    while((ch = getc(file)) != EOF){
        printf("%.2x ",ch);
    }
}

// Zadanie 4.3
// Funkcja printLinesHex wypisuje plik linia po linii analogicznie do printHex.
void printLinesHex(FILE *file){

    char c;

    while((c=getc(file))!=EOF){
        if(c=='\n'){
            printf("%.2x \n", c);
        }
        else{
            printf("%.2x ", c);
        }
    }
}

// Zadanie 4.2
// Funkcja printChar wypisuje plik w postaci znaków umieszczonych w apostrofach.
void printChar(FILE *file){

    char ch;
    while((ch = getc(file)) != EOF){
        
        if(ch == '\n'){
            printf("'\\n'");
        }

        else{
            printf("'%c' ",ch);
        }
    }
}

// Zadanie 4.4
// Funkcja printLinesChar wypisuje plik linia po linii analogicznie do printChar.
void printLinesChar(FILE *file){
    
    char ch;
    while((ch = getc(file)) != EOF){

        if(ch == '\n'){
            printf("'\\n'\n");
        }
        else{
            printf("'%c' ",ch);
        }
    }
}


void main()
{
    FILE *file = fopen("windows.txt", "r");
    
    if(!file){
        printf("Blad otwarcia pliku!\n");
        return;
    }

    printf("\n\n");

    printHex(file);
    fseek(file, 0, SEEK_SET);//move pointer to start

    printf("\n\n");

    printChar(file);
    fseek(file, 0, SEEK_SET);//move pointer to start

    printf("\n\n");

    printLinesHex(file);
    fseek(file, 0, SEEK_SET);//move pointer to start

    printf("\n\n");

    printLinesChar(file);

    printf("\n\n");
    
    fclose(file);

}