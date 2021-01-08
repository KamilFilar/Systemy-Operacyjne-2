/* Zadanie 2
Napisz program Fibo wyliczający wartości ciągu Fibonacciego przy pomocy trzech funkcji. Definicja ciągu:
0   1   2   3   4   5   6    indeksy
1   1   2   3   5   8   13   wartości   */

#include <stdio.h>

// Zadanie 2.1
// Funkcja fibo1 - metodą dziel i zwyciężaj.

int fibo1(int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    if(n>1){
        return fibo1(n-1)+fibo1(n-2);
    }
}
/* Drzewo wywołań dla n = 4 
                    
                       fibo1(4)
                    /            \
                fibo1(3)   +       fibo1(2)
                /      \           /       \
            fibo1(2) + fibo1(1)   fibo1(1)+fibo1(0)
            /      \
        fibo1(1) + fibo1(0)


    Analiza wywołań dla n = 4: 

    Na początku funkcja otrzymuje paramter n = 4.
    Wywołanie fibo1(5):
        Sprawdza czy fibo1(4) == 0 [false]
        Sprawdzamy czy fibo1(4) == 1 [false]
        Zwraca sumę wartości z wywołań [fibo1(3)+fibo1(2)] [5]
    Wywołanie fibo1(4): 
        Sprawdza czy fibo1(3) == 0 [false]
        Sprawdza czy fibo1(3) == 1 [false]
        Zwraca sumę wartości z wywołań [fibo1(2)+fibo1(1)] [3]
    Wywołanie fibo1(2): 
        Sprawdza czy fibo1(2) == 0 [false]
        Sprawdza czy fibo1(2) == 1 [false]
        Zwraca sumę wartości z wywołań [fibo1(1)+fibo1(0)] [2]
    Wywołanie fibo1(1):
        Sprawdza czy fibo1(1) == 0 [false]
        Sprawdza czy fibo1(1) == 1 [true]
        Zwraca [1]
    Wywołanie fibo1(0):
        Sprawdza czy fibo1(1) == 0 [true]
        Sprawdza czy fibo1(1) == 1 [false]
        Zwraca [1] 
*/

int fibo2(int n){

    int r0 = 1;
    int r1 = 1;
    int r2 = r1 + r0;

    int i;
    for (i=0; i<n; i++){
        r0 = r1;
        r1 = r2;
        r2 = r1 + r0;
    }

    return r0;

}
/*
Ile razy należy przesunąć ramkę w prawo, aby wyznaczyć wartość n-tego wyrazu ciągu Fibonacciego w funkcji fibo2 dla n >= 3?     1 raz w prawo
Dla n-tego wyrazu należy przesunąć ramkę n-2 razy w prawo.

Analiza - wystarczy przeanalizować powyższy algorytm krok po kroku.

Graf fibo2(4):
	                                   _____________
                                      |             |
				fibo2(4)              |       5     |
				/     \               |      / \    |
		    fibo2(3)  fibo2(2)        |     3   2 <-|
			/	  \                   |    / \   
	 	fibo2(2)  fibo2(1)            |__ 2   1  
	    /      \                         / \   ^
	fibo2(1) fibo2(0)                   1   1  |
                                        |______|
*/

int fibo3(int n){

    int r0 = 1;
    int r1 = 1;
    
    int i;
    for(i=0;i<n;i++){
        int pom = r0;
        r0 = r1;
        r1 = r0 + pom;
    }

    return r0;
}

/*
Ile razy należy przesunąć ramkę w prawo, aby wyznaczyć wartość n-tego wyrazu ciągu Fibonacciego w funkcji fibo2 dla n >= 3?     1 raz w prawo
Dla n-tego wyrazu należy przesunąć ramkę n-1 razy w prawo.

Analiza - wystarczy przeanalizować powyższy algorytm krok po kroku.

Graf fibo3(4):
  		                               _____________ 
				fibo3(4)              |       5     |
				/     \               |      / \    |
		    fibo3(3)  fibo3(2)        |     3   2 <-|
			/	  \                   |    / \   
	 	fibo3(2)  fibo3(1)            |__ 2   1  
	    /      \                         / \   ^
	fibo3(1) fibo3(0)                   1   1  |
                                        |______|


Która funkcja ma mniejszą złożoność obliczeniową fibo2 czy fibo3? Funkcja fibo2(n) ma złożoność mniejszą, obie mają złożoność liniową O(n)
fibo2(n) = 1+1+2+1 + n(1+1+2) + 1 = 6 + 4n
fibo3(n) = 1+1+1 + n(1+1+2) + 1 = 5 + 4n
*/
void main(){

    int n;
    
    printf("Podaj wyraz ciagu, ktory chcesz obliczyc: ");
    scanf("%d",&n);
    
    printf("\n\nWynik fibo1(%d) = %d \n", n, fibo1(n));
    printf("Wynik fibo2(%d) = %d \n", n, fibo2(n));
    printf("Wynik fibo3(%d) = %d \n", n, fibo3(n));
}