// Zadanie 2
// Napisz program Strings implementujący i testujący następujące funkcje:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Zadanie 2.1
// Funkcja indexOf działająca analogicznie do tej samej funkcji z klasy String w języku Java. 

int indexOf(const char *str, int c){

    int i;
    for(i=0;i<strlen(str);i++){

        if(str[i]==c){
            return i;
        }
    }

    return -1;
}

// Zadanie 2.2
// Funkcja identity zwracająca imię i nazwisko oddzielone spacją. 

char *identity(const char *name, const char *surname){

    char *result = malloc(strlen(name)+strlen(surname)+2);

    strcpy(result, name);
    strcat(result, " ");
    strcat(result, surname);
    strcat(result, "\0");

    return result;
}

// Zadanie 2.3
// Funkcja login tworząca login użytkownika na podstawie pierwszej litery imienia i całego nazwiska. 
// Należy pamiętać, że login na systemie Linux składa się z maksymalnie 32 znaków.

char *login(const char *name, const char *surname){

    int  size = strlen(surname);
    if(size>32);{
        size = 32;
    }

    char *result = malloc(size+1);

    result[0] = name[0];

    int i, index = 0;

    for(i=1;i<size;i++){
        result[i] = surname[index];
        index++;
    }

    result[index] = '\0';

    return result;

}

void main(){

    printf("\nIndeks: %d", indexOf("Przykladowy tekst 123.", 'r'));
    
    printf("\nImie i nazwisko: %s", identity("Kamil","Filar"));

    printf("\nMoj login: %s", login("Kamil", "Filar"));

}