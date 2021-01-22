// Zadanie 10
// Przepisz program zombie oraz przeanalizuj jego działanie.
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {
        printf("child pid = %d\n", getpid());
        exit(0);
    }

    sleep(20);
    
    wait(NULL);

    exit(0);
}

/*
W tym zadaniu proces potomny zakończył swoje działanie i czeka na przekazanie statusu zakończenia przodkowi. Proces zombie jest przerywany dopiero po 20 sekundach uśpienia w momencie gdy jest wywołana funkcja wait.
*/