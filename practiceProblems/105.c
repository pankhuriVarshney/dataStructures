#include <stdio.h>
int fact(int n);
int main(){
    int n;
    printf("ENTER A NUMBER: ");
    scanf("%d", &n);
    printf("FACTORIAL: %d", fact(n));
}
int fact(int n){
    if(n<=1)
        return 1;
    return n*fact(n-1);
}