// Zadanie 1
// Przepisz program fork oraz przeanalizuj jego działanie.
#include <stdio.h>
#include <unistd.h>

int main(){

    printf("Poczatek\n");

    fork();

    printf("Koniec\n");

    return 0;
}

/* 
 Program jest początkowo wykonywany przez jeden proces. W wyniku wywołania funkcji systemowej fork (linia 10) następuje rozwidlenie i tworzony jest proces potomny, 
 który kontynuuje wykonywanie programu swojego przodka od miejsca utworzenia co daje rezultat:
 Poczatek
 Koniec
 Koniec
 */