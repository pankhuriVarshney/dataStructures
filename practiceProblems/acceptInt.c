#include <stdio.h>
#include <stdlib.h>
int func();
int main(){
    func();
    
}
int func(){
    int *arr=(int *)malloc(sizeof(int));
    int count=0, lowestEven=0;
    int flag=0;
    while(1){
        int n;
        scanf("%d", &n);
        if(n<0){
            break;
        }
        count++;
        arr=(int *)realloc(arr, sizeof(int)*count);
        arr[count-1]=n;
        if(arr[count-1]%2==0&&flag==0){
            lowestEven=arr[count-1];
            flag=1;
        }
        else if(arr[count-1]%2==0&&lowestEven>arr[count-1]){
            lowestEven=arr[count-1];
        }
    }
    if(flag==0){
        return 0;
    }
    else{
        printf("%d", lowestEven);
    }
}