/* 
Napisz program Add_User.c tworzący użytkowników na podstawie bazy w pliku baza.txt zawierającej:

jan;kowalski;haslo1
piotr;nowak;haslo2
grzegorz;adamski;haslo3

Użytkowników tworzymy analogicznie jak w zadaniu 13. Program ma działać poprawnie dla pliku baza.txt zapisanego zarówno w formacie Linux, jak i Windows.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

char *login(const char *name, const char *surname){
    int size = strlen(surname);

    if (size > 32);{
        size = 32;
    }

    char *result = malloc(size + 1);

    result[0] = name[0];

    int i = 1;
    int index = 0;
    for (i; i < size; i++){
        result[i] = surname[index];
        index++;
    }

    result[size] = '\0';

    return result;
}

void createUser(char *name, char *surname, char *password)
{
    char *logi = login(name, surname);

    char *polecenie="useradd -p ";
    char *all= malloc(128);

    sprintf(all,"useradd -p \"%s\" %s",password,logi);

    printf("\n%s - polecenie %d\n",all,strlen(all));

    free(all);

    int m=system(all);

    if(m==0){
        printf("User was created. His Login data\n");
        printf("Login : %s\n",logi);
        printf("Password : %s\n\n",password);
    }
    else if(m==2304){
        printf("konto juz istnieje z loginem: %s\n",logi);
    }
    else{
        printf("wystapil konkretny blad");
    }
        
    free(name);
    free(surname);
    free(password);

    name = malloc(128);
    surname = malloc(128);
    password = malloc(128);
}

void main()
{
    FILE *in_file = fopen("dane.txt", "r");
    if (!in_file){
        printf("Couldn't read file\n");
        return;
    }

    int c;

    char *name = malloc(128);
    int nameI = 0;
    char *surname = malloc(128);
    int surnameI = 0;
    char *password = malloc(128);
    int passwordI = 0;

    int kolejnosc = 0;
    int i = 0;

    while ((c = getc(in_file))){
        if (kolejnosc == 0){

            if (c != ';'){
                name[nameI] = c;
                nameI++;
            }

            else{
                kolejnosc++;
                name[nameI] = '\0';
            }
        }
        else if (kolejnosc == 1){

            if (c != ';'){
                surname[surnameI] = c;
                surnameI++;
            }
            else{
                kolejnosc++;
                surname[surnameI] = '\0';
            }
        }
        else if (kolejnosc == 2){

            if (c != '\n'){
                password[passwordI] = c;
                passwordI++;
            }

            else{
                password[passwordI] = '\0';
                kolejnosc = 0;

                createUser(name, surname, password);
                surnameI = 0;
                passwordI = 0;
                nameI = 0;
                //dodanie do uzytkownikow
                //wyczyszczeinei wszystkich zmiennych
            }
        }

        if (c == EOF){
            break;
        }
    }

    fclose(in_file);
}