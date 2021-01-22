// Zadanie 7
// Przepisz program execlp2 oraz przeanalizuj jego działanie.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Poczatek\n");

    if (fork() == 0) {
       execlp("ls", "ls", "-a", NULL);

       perror("Blad uruchmienia programu.");

       exit(1);
    }

    wait(NULL);

    printf("Koniec\n");

    return 0;
}
