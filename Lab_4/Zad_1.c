// Zadanie 1
// Napisz pełną implementację programu Fractions z odczytem danych z terminala i obsługą błędów. 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Zadanie 1.1
// Dodaj funkcję isNumber sprawdzającą, czy napis s przechowuje liczbę całkowitą. Wykorzystaj funkcję isdigit z biblioteki standardowej.
int isNumber(const char *s){

    if(s[0]=='-' || isdigit(s[0])){
        ;
    }
    else{
        return 0;
    }

    int i;
    for(i=1;i<strlen(s);i++){

        if(!isdigit(s[i])){
            return 0;
        }
    }

    return 1;
    
}

// Zadanie 1.2
// Dodaj funkcję trim usuwającą z napisu s początkowe i końcowe znaki białe. Wykorzystaj funkcję isspace z biblioteki standardowej.
char *trim(char *s){

    int i;
    for(i=0;i<strlen(s);i++){
        if(!isspace(s[i]))
            break;
    }

    int j=strlen(s)-1;
    for(j;j>0;j--){
        if(!isspace(s[j]))
            break;
    }

    int newSize = j-i;

    char *result = malloc(newSize+1);

    int index=0;
    for(i=0;i<=j;i++){
        result[index]=s[i];
        index++;
    }

    result[index]='\0';

    return result;

}
// Zadanie 1.3
// Dodaj funkcję getOperator określającą operator z napisu s. Funkcja zwraca prawdę, jeśli napis jest poprawnym operatorem arytmetycznym.

int getOperator(char *op, const char *s){
    
    int i;
    for(i=0;i<strlen(s);i++){
        if(!isdigit(s[i])){
            break;
        }
    }

    if(s[i]=='/' || s[i]=='+' || s[i]=='-' || s[i]==':' || s[i]=='*'){
        op[0] = s[i];
        op[1] = '\0';
        return 1;
    }
    return 0;
}
// Zadanie 1.4
// Dodaj funkcję getFraction określającą strukturę ułamkową z napisu s. Funkcja zwraca prawdę, jeśli napis jest ułamkiem zwykłym lub liczbą całkowitą. 
// Napis może mieć postać: liczba lub liczba / liczba.
struct Fraction {
    int num, den;
};

int getFraction(struct Fraction *x, const char *s){
    
    int i;
    for(i=0;i<strlen(s);i++){
        if(!isdigit(s[i])){
            break;
        }
    }

    if(s[i]=='/'){

        int *licznik = malloc(i+1);
        int *mianownik = malloc(strlen(s)-i+1);
        
        int j;
        for(j=0;j<i;j++){
            licznik[j]=s[j];
        }
        licznik[j]='\0';

        int k=i+1;
        int index=0;
        for(k;k<strlen(s);k++){
            mianownik[index]=s[k];
            index++;
        }
        mianownik[index]='\0';

        x->den = atoi(mianownik);
        x->num = atoi(licznik);

        return 1; // Jest ułamkiem
    }
    else{
        if(i==strlen(s)){
            x->num=atoi(s);
            x->den=1;

            return 1; // Jest liczbą całkowitą
        }
    }

    return 0;
}

// Funkcje potrzebne do zadania 1.5 oraz 1.6

struct Fraction sum(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    
    int c = y.num;
    int d = y.den;
    
    struct Fraction z;
    
    z.num = a*d + c*b;
    z.den = b*d;
    
    return z;
}

struct Fraction subtract(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    
    int c = y.num;
    int d = y.den;
    
    struct Fraction z;
    
    z.num = a*d - c*b;
    z.den = b*d;
    
    return z;
}

struct Fraction multiplicate(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    
    int c = y.num;
    int d = y.den;
    
    struct Fraction z;
    
    z.num = a*c;
    z.den = b*d;
    
    return z;
}

struct Fraction division(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    
    int c = y.num;
    int d = y.den;
    
    struct Fraction z;
    
    z.num = a*d;
    z.den = b*c;
    
    return z;
}

struct Fraction doMagic(struct Fraction x){
    struct Fraction y;
    
    y.num = x.num;
    y.den = x.den;

    int a = y.num;
    int b = y.den;
    //jezeli mianownik < 0 a licznik > 0 to odwroc znaki
    if(a>0)
    {
        if(b<0)
        {
            a=-a;
            b=-b;
        }
    }
    //jezeli mianownik jest podzielny przez licznik podziel
    if(a!=-1)
        if(b%a==0){
            b=b/a;
            a=1;
        }

    if(a%b==0){
        a=a/b;
        b=1;
    }
    y.num=a;
    y.den=b;

    return y;
}

void printFraction(struct Fraction x){
    
    int a = x.num;
    int b = x.den;
    
    if(b==0){
        printf("(struct Fraction){%d,%d} -> NaN\n",a,b);
        return;
    }

    if(a==0){
        printf("(struct Fraction){%d,%d} -> 0\n",a,b);
        return;
    }

    struct Fraction y = doMagic(x);

    if(y.den==1){
        printf("(struct Fraction){%d,%d} -> %d\n",a,b,y.num);
        return;
    }
    if(abs(y.num)>y.den){
        int whole = y.num/y.den;
        int c=y.num;
        int d=y.den;

        if(c<0){
            c+=abs(whole)*d;
        }
        else{
            c-=abs(whole)*d;
        }
        
        printf("(struct Fraction){%d,%d} -> %d %d/%d\n",a,b,whole,abs(c),abs(d));
        return;
    }
    printf("(struct Fraction){%d,%d} -> %d/%d\n",a,b,y.num,y.den);
    return;
}

int poprawnyOperator(char *op){
    if(op[0]=='+' || op[0]=='-' || op[0]=='*' || op[0]=='/'){
        return 1;
    }  
    return 0;
}

void calculateFraction(struct Fraction x,struct Fraction y, const char op){
    struct Fraction solution;

    if(op == '+'){
        solution = sum(x,y);
    }  
    else if(op == '-'){
        solution = subtract(x,y);
    }  
    else if(op == '*'){
        solution = multiplicate(x,y);
    }  
    else if(op == '/' || op == ':'){
        solution = division(x,y);
    } 
    else{
        printf("%c - nieznane dzialanie",op);
        return;
    }

    printf("%d/%d %c %d/%d = %d/%d\n",x.num,x.den,op,y.num,y.den,solution.num,solution.den);
}

// Zadanie 1.6
// Zaimplementuj bezpieczny odczyt z terminala bez możliwości przepełnienia bufora linii.
char *safeReadFromConsole()
{
    unsigned int len_max = 128;
    unsigned int currentSize = 0;
    char *data = malloc(len_max);
    currentSize = len_max;

    if(data != NULL)
    {
        int c;
        unsigned int i=0;
        //accept user input until hit enter or new line
        while ((c = getchar()) !=  '\n')
        {
            data[i++]=(char)c;
            //if max size realocate
            if (i==currentSize)
            {
                currentSize = i+len_max;
                data = realloc(data,currentSize);
            }
        }
        data[i] = '\0';
        return data;
    }
    return data;
}

// Zadanie 1.5
// Zaimplementuj odczyt z terminala. Jeśli wprowadzony napis ma niepoprawny format, to jego odczyt należy powtórzyć.
void odczytTerminal(){
    
    int MAX_LEN =20;

    printf("Podaj pierwsza liczbe (a/b): ");
    char *ulamek1 = safeReadFromConsole();

    struct Fraction *ul1Pointer,ul1;
    ul1Pointer=&ul1;

    while (getFraction(ul1Pointer,ulamek1)==0){
        printf("Podano nieprawidlowe dane!\n");
        printf("Podaj dane jeszcze raz (a/b): ");
        fgets(ulamek1, MAX_LEN, stdin);
    }

     printf("Podaj druga liczbe (c/d): ");
    char *ulamek2 = safeReadFromConsole();

    struct Fraction *ul2Pointer,ul2;
    ul2Pointer = &ul2;
    
    while (getFraction(ul2Pointer,ulamek2)==0){
        printf("Podano nieprawidlowe dane!\n");
        printf("Podaj dane jeszcze raz (c/d): ");
        fgets(ulamek2, MAX_LEN, stdin);
    }
    
    char *opPointer=malloc(2);

    printf("Podaj operator: ");
    fgets(opPointer, 2, stdin);

    while (poprawnyOperator(opPointer)==0){
        printf("Podano nieprawidlowy operator!\n");
        printf("Podaj operator jeszcze raz: ");
        fgets(opPointer, 1, stdin);
    }
    
    calculateFraction(ul1,ul2,opPointer[0]);
}


void main(){

    printf("isNumber value: %d\n", isNumber("123"));
    printf("isNumber value: %d\n", isNumber("-123"));
    printf("isNumber value: %d\n", isNumber("Napis"));

    printf("trim value: %s", trim("  moj napis  "));

    char *op=malloc(2);
    printf("\n%d - getOperator",getOperator(op,"5&2"));

    struct Fraction *solutionPointer, solution;
    solutionPointer = &solution;
    printf("\n%d - getFraction\n", getFraction(solutionPointer, "5/2"));

    odczytTerminal();

}
