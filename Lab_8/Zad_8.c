// Zadanie 8
// Przepisz program execlp3 oraz przeanalizuj jego działanie.
// opisz na podstawie dokumentacji man wartości zwracane przez funkcję fork() oraz funkcję wait().
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    printf("Poczatek\n");

    pid_t pid = fork();

    if (pid == -1) {
        perror("Blad tworzenia procesu potomnego.");

        return 1;
    }

    if (pid == 0) {
        execlp("ls", "ls", "-l", NULL);

        perror("Blad uruchmienia programu.");

        exit(1);
    }

    if (wait(NULL) == -1) 
        perror("Blad w oczekiwaniu na zakonczenie potomka.");

    printf("Koniec\n");

    return 0;
}
/*
Fork: gdy się powiedzie to PID potomka jest zwracany do procesu macierzystego a 0 jest zwracane w procesie potomka. W przypadku niepowodzenia w procesie macierzystym jest zwaracane -1 i nie jest stworzony żaden proces potomny.

Wait: gdy się powiedzie to zwracany jest PID zakończonego potomka, w przypadku niepowodzenia zwraca -1.

*/