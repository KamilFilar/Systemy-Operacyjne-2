/* Zadanie 1
Napisz program Sequence wyliczający wartości ciągu {an} przy pomocy trzech funkcji. Ciąg zdefiniowany jest rekurencyjnie:

a(0) = 1
a(1) = 4
a(n) = 2*a(n-1) + 0.5*a(n-2) */

#include <stdio.h>

// Zadanie 1.1
// Funkcja a1 - metoda dziel i zwyciężaj. 

float a1(int n){

    if(n==0){
        return 1;
    }
    if(n==1){
        return 4;
    }

    return 2*a1(n-1) + 0.5*a1(n-2);
}

// Zadanie 1.2
// Funkcja a2 - metoda programowania dynamicznego z ramką trójzębną.

float a2(int n){

    float r0 = 1;
    float r1 = 4;
    float r2 = 2*r1 + 0.5*r0;

    int i;
    for(i=1;i<=n;i++){
        r0 = r1;
        r1 = r2;
        r2 = 2*r1 + 0.5*r0;
    }

    return r0;
}
/*
Analiza wywołania a2(4)  - przeanalizowanie krok po kroku powyższej funkcji (jak będzie taka potrzeba to napiszę wynik analizy tutaj).
Graf a2(4):
		                 a2(4)
		                   |
                    2*a2(3)+0.5*a2(2)
                       |          |
        2*a2(2)+0.5*a2(1)          X                 W miejsce X jest podstawiana zapisana wartość 2*a2(1)+0.5*a2(0)
		    |                      ^
	 	2*a2(1)+0.5*a2(0) ---------|

*/

// Zadanie 1.3
// Funkcja a3 - metoda programowania dynamicznego z ramką dwuzębną.
float a3(int n){

    float r0 = 1;
    float r1 = 4;

    int i;
    for(i=1;i<=n;i++){
        float pom = r0;
        r0 = r1;
        r1 = 2*r0 + 0.5*pom;
    }

    return r0;
}
/*
Analiza wywołania a3(4)  - przeanalizowanie krok po kroku powyższej funkcji (jak będzie taka potrzeba to napiszę wynik analizy tutaj).
Różnica pomiędzy funkcją a3, a funkcją a2 polega na tym, że w funkcji a3 występuje zmienna pomocnicza zastępująca jeden ząb z ramki z funkcji a2.
Graf a3(4):
		                 a3(4)
		                   |
                    2*a3(3)+0.5*a3(2)
                       |          |
        2*a3(2)+0.5*a3(1)          X                 W miejsce X jest podstawiana zapisana wartość 2*a3(1)+0.5*a3(0)
		    |                      ^
	 	2*a3(1)+0.5*a3(0) ---------|

*/


void main(){

    int n;
    printf("Podaj wyraz ciagu, ktory chcesz obliczyc: ");
    scanf("%d", &n);

    printf("Wynik a1(%d) = %f \n", n, a1(n));
    printf("Wynik a2(%d) = %f \n", n, a2(n));
    printf("Wynik a3(%d) = %f \n", n, a3(n)); 
    
}