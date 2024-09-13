#include <stdio.h>
int main(){
    int n;
    printf("ENTER A NUMBER: ");
    scanf("%d", &n);
    int fact=n;
    for(int i=2; i<n; i++){
        fact*=i;
    }
    printf("FACTORIAL: %d", fact);
}