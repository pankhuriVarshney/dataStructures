#include <stdio.h>
int main(){
    int n; 
    printf("ENTER THE NUMBER OF TERMS OF FIB SERIES: ");
    scanf("%d", &n);
    int a=0, b=1, c=0;
    for(int i=0; i<n; i++){ 
        c=a;
        a=b;
        b+=c;
        printf("%d\t", c);
    }
}