// Zadanie 1
// Napisz program Fractions wedle poniższego schematu i przetestuj jego działanie. 
// Rozbuduj go o pozostałe działania na ułamkach. Przed każdą dodaną funkcją należy podać wyprowadzenie dla działania.

#include <stdio.h>
#include <stdlib.h>

struct Fraction {
    int num, den;
};

/*
a/b + c/d = (a*d)/(b*d) + (c*b)/(d*b) = (a*d + c*b) / (b*d)
*/
struct Fraction suma(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    
    int c = y.num;
    int d = y.den;
    
    struct Fraction z;
    
    z.num = a*d + c*b;
    z.den = b*d;
    
    return z;
}
// a/b - c/d = (a*d)/(b*d) - (c*b)/(d*b) = (a*d - c*d) / (b*d)
struct Fraction roznica(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    int c = y.num;
    int d = y.den;
    
    struct Fraction z;
    z.num = a*d - c*b;
    z.den = b*d;
    
    return z;
}
// (a/b) * (c/d) = (a*c) / (b*d)
struct Fraction iloczyn(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    int c = y.num;
    int d = y.den;
    
    struct Fraction z;
    z.num = a*c;
    z.den = b*d;
    
    return z;
}
// (a/b) : (c/d) = (a/b) * (d/c) = (a*d)/(b*c)
struct Fraction iloraz(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    int c = y.num;
    int d = y.den;
    
    struct Fraction z;
    z.num = a*d;
    z.den = b*c;
    
    return z;
}

void main() {
    struct Fraction x = {2, 3};
    struct Fraction y = {1, 4};
    
    struct Fraction zs = suma(x, y);
    struct Fraction zr = roznica(x, y);
    struct Fraction zm = iloczyn(x, y);
    struct Fraction zd = iloraz(x, y);
    
    printf("Suma: %d/%d + %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, zs.num, zs.den);
    printf("Roznica: %d/%d - %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, zr.num, zr.den);
    printf("Iloczyn: %d/%d * %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, zm.num, zm.den);
    printf("Iloraz: %d/%d : %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, zd.num, zd.den);

    const char op;
    printf("Podaj symbol dzialania: ");
    scanf("%c",&op);
    print(x,y,op);

//    struct Fraction U = {2,0};
//    struct Fraction U = {0,2};
//    struct Fraction U = {2,4};
//    struct Fraction U = {-1,2};
//    struct Fraction U = {1,-2};
//    struct Fraction U = {4,-2};
    struct Fraction U = {5,-2};

    printFraction(U); 
}

// Zadanie 1.1
// Dodaj do programu funkcję print wypisującą działanie dla podanych ułamków i operatora.

void print(struct Fraction x, struct Fraction y, const char op){
    
    int a = x.num;
    int b = x.den;
    int c = y.num;
    int d = y.den;  
    struct Fraction z;

    if(op=='+'){
    	z.num = a*d + c*b;
    	z.den = b*d;
    	printf("Suma: %d/%d + %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, z.num, z.den);
	}
	if(op=='-'){
		z.num = a*d - c*b;
    	z.den = b*d;
		printf("Roznica: %d/%d - %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, z.num, z.den);
	}
	if(op=='*'){
		z.num = a*c;
    	z.den = b*d;
		printf("Iloczyn: %d/%d * %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, z.num, z.den);
	}
	if(op=='/'){
		z.num = a*d;
    	z.den = b*c;
		printf("Iloraz: %d/%d / %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, z.num, z.den);
	}
	if(op==':'){
		z.num = a*d;
    	z.den = b*c;
		printf("Iloraz: %d/%d : %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, z.num, z.den);
	}
	if((op!='+')&&(op!='-')&&(op!='*')&&(op!='/')&&(op!=':')){
		printf("%c - nieznane dzialanie",op);
	}
}

// Zadanie 1.2
// Dodaj do programu funkcję printFraction wypisującą skrócony ułamek.

void printFraction(struct Fraction U){
	int a = U.num;
	int b = U.den;
		
	// 1 i 2
	if(b==0){
		printf("(struct Fraction){%d,%d} -> NaN \n", a, b);
	}
	if(a==0){
		printf("(struct Fraction){%d,%d} -> 0 \n", a, b);
	}
	if((a!=0)&&(b!=0)){
	div_t wynAB = div(a,b);		
//	printf( "wynik = div(%d,%d)\n", a, b );
//	printf( "Iloraz liczb wynosi: %d. Reszta z dzielenia wynosi: %d\n\n", wynAB.quot, wynAB.rem ); 
	//3
	if((wynAB.quot==0)&&(wynAB.rem>0)){
		printf("(struct Fraction){%d,%d} -> ", a, b);
		a /= wynAB.rem;
		b /= wynAB.rem;
		if(b<0){
			a *=(-1);
			b *=(-1);
		}
		printf(" %d/%d",a,b);
	}
	//4
	if((wynAB.quot==0)&&(wynAB.rem<0)){
		printf("(struct Fraction){%d,%d} -> %d/%d", a, b, a, b);
	}
	//5
	if((wynAB.quot==0)&&(wynAB.rem==0)){
		printf("(struct Fraction){%d,%d} -> ", a, b);
		if(b<0){
			a *= (-1);
			b *= (-1);
		}
		printf(" %d/%d", a, b);
	}
	//6
	if((wynAB.quot!=0)&&(wynAB.rem==0)){
		printf("(struct Fraction){%d,%d} -> %d", a, b, wynAB.quot);
	}
	//7
	if((wynAB.quot!=0)&&(wynAB.rem!=0)){
		printf("(struct Fraction){%d,%d} ->", a, b);
		if(b<0){
			b *=(-1);
		}
		printf(" %d %d/%d \n", wynAB.quot, wynAB.rem, b);		
	}	
 }	
}