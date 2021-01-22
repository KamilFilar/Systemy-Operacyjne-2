// Zadanie 6
// Przepisz program execlp oraz przeanalizuj jego działanie.
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Poczatek\n");

    execlp("ls", "ls", "-l", NULL);

    printf("Koniec\n");

    return 0;
}
/* Funkcji systemowa execlp powoduje zmiane wykonywanego programu. 
Sterowanie nie wraca już do poprzedniego programu i napis Konie nie pojawia się na ekranie. */
