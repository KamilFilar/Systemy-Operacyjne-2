// Zadanie 16
// Napisz program którego rezultatem będzie wydruk zawartości bieżącego katalogu poprzedzony napisem Poczatek a zakończony napisem Koniec.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Poczatek\n");

    system("ls -la");

    printf("Koniec\n");

    return 0;
}