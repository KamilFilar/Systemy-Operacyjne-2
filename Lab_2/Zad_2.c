// Zadanie 2
// Napisz program SequenceTree wypisujący, jak wyglądają kolejne wywołania funkcji a1 razem z wartościami przez nie zwracanymi.

#include <stdio.h>

float SequenceTree(int n){

    if(n==0){
        printf("SequenceTree(%d)= 1 \n", n);
        return 1;
    }
    if(n==1){
        printf("SequenceTree(%d)= 4 \n", n);
        return 4;
    }

    float result = 2*SequenceTree(n-1) + 0.5*SequenceTree(n-2);
    printf("SequenceTree(%d) = %f \n", n, result);
    return result;
}

void main(){

    int n;
    printf("Podaj numer wyrazu, ktory chcesz obliczyc: ");
    scanf("%d", &n);

    SequenceTree(n);
}