// Zadanie 9
// Przepisz program sierota oraz przeanalizuj jego działanie.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {
        printf("child pid = %d\n", getpid());

        sleep(20);

        exit(0);
    }

    exit(0);
}
/* 
Przodek zakończył  działanie przed zakończeniem swojego potomka stąd wynikiem tego działania jest to, że po zakończeniu programu został wypisany pid na ekranie.
*/