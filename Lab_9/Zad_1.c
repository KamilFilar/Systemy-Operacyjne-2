// Zadanie 1
// Napisz program regexp ilustrujący wyrażenia regularne POSIX’a.

#include <regex.h>
#include <stdio.h>

int main(){

    regex_t regex;
    int reti;

    // Kompilacja regexu
    reti = regcomp(&regex, "^Ala-kot[[:alnum:]]", 0);
    char matcher[254] = "Ala-kota!@##!@FASa1231fa1X";

    // porownanie wiadomosci z regexem
    reti = regexec(&regex, matcher, 0, NULL, 0);
    if (!reti) {
        puts("Znaleziono lancuch w tekscie");
    }
    else if (reti == REG_NOMATCH) {
        puts("Nie znaleziono lancucha w tekscie");
    }
    else {
        fprintf(stderr, "Program napotkal blad!\n");
        exit(1);
    }

    regfree(&regex); // zwolnienie pamieci zaalokowanej dla regexu
    return 1;
}
