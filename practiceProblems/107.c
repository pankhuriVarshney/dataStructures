#include <stdio.h>
void fib(int n, int a, int b);
int main(){
    int n; 
    printf("ENTER THE NUMBER OF TERMS OF FIB SERIES: ");
    scanf("%d", &n);
    fib(n, 0, 1);
}
void fib(int n, int a, int b){
    if(n==0)
        return;
    printf("%d\t", a);
    fib(n-1, b, a+b);
}