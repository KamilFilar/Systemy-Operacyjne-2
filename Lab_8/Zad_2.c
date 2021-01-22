// Zadanie 2
// Przepisz program fork2 oraz przeanalizuj jego działanie.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    
    printf("Poczatek\n");

    pid_t pid = fork();

    if (pid == 0)
        printf("Proces dziecko, zmienna pid = %d\n", pid);

    if (pid != 0)
        printf("Proces rodzic, zmienna pid = %d\n", pid);

    printf("Koniec procesu:%d\n", pid);

    return 0;
}

/* Zmiennej pid (linia 9) jest przypisywane utworzenie nowego procesu (fork())
Jeżeli pid == 0 to zwracana na ekran jest wartosc procesu potomnego.
Jeżeli pid != 0 to zwracana na ekran jest wartosc procesu macierzystego.
Na końcu zwracana jest na ekran informacja o końcu procesu (linia 17).

*/