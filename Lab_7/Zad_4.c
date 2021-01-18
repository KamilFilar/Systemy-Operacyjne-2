// Zadanie 4
// Napisz program cyfry wyliczający liczbę cyfr danej liczby całkowitej przy pomocy funkcji:

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// - funkcja cyfry1 wykorzystuje funkcję log10. *
int cyfry1(int num){

    int count = (int)floor(log10(abs(num))) + 1;

}

// - funkcja cyfry2 wykorzystuje funkcję snprintf.
int cyfry2(int num){

    return snprintf(NULL, 0, "%d", num) - (num < 0);

}

// - funkcja cyfry3 wykorzystuje dzielenie przez 10. *
int cyfry3(int num){
    
    int count = 0;

    while (num != 0){
        num /= 10;
        ++count;
    }

    return count;
}

void main(){

    printf("cyfry1(-3579) = %d",cyfry1(-3579));
    printf("\ncyfry2(-3579) = %d",cyfry2(-3579));
    printf("\ncyfry3(-3579) = %d",cyfry3(-3579));
    
}
