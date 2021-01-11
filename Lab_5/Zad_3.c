// Zadanie 3
// Napisz program DisplayWords odczytujący plik tekstowy oraz wypisujący poszczególne słowa tego pliku przy pomocy funkcji strtok z biblioteki standardowej.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void printWords(FILE *file){

    fseek(file, 0, SEEK_END);
    long int res = ftell(file);

    char *allFile = malloc(sizeof(char)*res+1);
    
    fseek(file, 0, SEEK_SET);//move pointer to start
    
    char ch;
    int index=0;
    
    while((ch = getc(file)) != EOF){
        allFile[index]=ch;
        index++;
    }
    allFile[index]='\0';

    char * schowek;

    schowek = strtok(allFile, " \n" );

    while( schowek != NULL ){
        printf("%s\n", schowek);
        schowek = strtok(NULL, " \n");
    }
}

void main(){

    FILE *file = fopen("plik.txt", "r");
    
    if(!file){
        printf("Blad otwarcia pliku!\n");
        return;
    }

    printWords(file);

    fclose(file);

}