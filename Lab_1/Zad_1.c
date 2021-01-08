// Zadanie 1
// Napisz program InputOutput odczytujący z terminala i wypisujący na konsoli kolejno wartości typu: całkowitego, zmienno-przecinkowego float i napis.

#include <stdio.h>

// Zadanie 1.1
// Odczytaj i wypisz na konsoli wartość zmienno-przecinkową typu double.

void DoubleInput(){

    double n;

    printf("Podaj liczbe zmienno-przecinkowa (double): ");
    scanf("%lf", &n);
    printf("Wczytano: %f", n);

}

// Zadanie 1.2
// Odczytaj i wypisz na konsoli cały napis "ala ma kota” przy pomocy funkcji scanf.

void ScanfTextInput(){

    char tekst[20];

    printf("Podaj tekst (max 20 znakow): ");
    scanf("%[^\n]", tekst);
    printf("Wczytano: %s", tekst);

}

// Zadanie 1.3
// Odczytaj i wypisz na konsoli cały napis "ala ma kota” przy pomocy funkcji fgets.

void FgetsInput(){

    char tekst[20];

    printf("Podaj tekst (max 20 znakow): ");
    fgets(tekst, sizeof(tekst), stdin);
    printf("Wczytano: %s", tekst);

}


void main(){

    DoubleInput();
    //ScanfTextInput();
    //FgetsInput();
}