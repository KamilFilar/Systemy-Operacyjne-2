// Zadanie 13
// Przepisz program redirect oraz przeanalizuj jego działanie.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    close(1);

    creat("ls.txt", 0600);

    execvp("ls", argv);
}
/*
Program stworzył plik ls.txt i zapisał w nim wynik działania polecenia ls.
creat(const char *pathname, mode_t mode);
pathname – nazwa pliku lub sciezka do pliku wraz z nazwą
mode – parametr związany z uprawnieniami (w tym przypadku zapis i odczyt)
*/