// Napisz program FiboTree wypisujący, jak wyglądają kolejne wywołania funkcji fibo1 razem z wartościami przez nie zwracanymi.
#include <stdio.h>

int FiboTree(int n){

    if(n==0){
        printf("FiboTree(%d)= 1\n", n);
        return 1;
    }
    if(n==1){
        printf("FiboTree(%d)= 1\n", n);
        return 1;
    }
    int result = FiboTree(n-1)+FiboTree(n-2);
    printf("FiboTree(%d)= %d\n", n, result);
    return result;
}

void main(){

    int n;
    
    printf("Podaj wyraz ciagu, ktory chcesz obliczyc: ");
    scanf("%d",&n);

    FiboTree(n);
}