// Zadanie 2
// Napisz program CountWords odczytujący plik tekstowy oraz obliczający liczbę słów w tym pliku przy pomocy funkcji:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// Zadanie 2.1
// Funkcja countWords1 oblicza liczbę słów przy pomocy zmiennej stanu inside, gdzie wartość 0 oznacza, że zamierzamy odczytać znak poza słowem, 
// a wartość 1 oznacza, że zamierzamy odczytać znak w słowie.
int countWords1(FILE *file){

    char ch = getc(file);
    int word_count = 0;
    int inside = 0;

    if(ch != ' ' || ch != '\t' || ch != '\0' || ch != '\n'){
        word_count++;
    }

    while ((ch = getc(file)) != EOF){

        if(ch == ' ' || ch == '\t' || ch == '\n'){
            
            if(inside){
                inside = 0;
                word_count++;
            }
        }
        else{
            inside++;
        }
    }
    return word_count;
}

// Zadanie 2.2
// Funkcja countWords2 oblicza liczbę słów bez pomocy zmiennej stanu.
int countWords2(FILE *file){

    char ch;
    int word_count = 0;

    while ((ch = getc(file)) != EOF)
    {
        if(ch == ' ' || ch == '\t' || ch == '\n')
        {
            word_count++;
        }
    }
    
    return word_count;
}

void main(){

    FILE *file = fopen("plik.txt", "r");
    
    if(!file){
        printf("Blad otwarcia pliku!\n");
        return;
    }

    printf("Liczba slow: %d \n", countWords1(file));
    fseek(file, 0, SEEK_SET); //move pointer to start
    printf("Liczba slow: %d \n", countWords2(file));
    
    //printf("%d - amount of words 2\n",countWords2(file));

    fclose(file);
}