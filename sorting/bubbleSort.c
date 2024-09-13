#include <stdio.h>
void bubbleSort(int arr[], int n);
void bubbleSortOPTIMIZED(int arr[], int n);
int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n], arr2[n];
    printf("Enter the elements: \n");
    for(int i=0; i<n; i++){
        int temp;
        scanf("%d", &temp);
        arr[i]=temp;
        arr2[i]=temp;
    }
    bubbleSort(arr, n);
    bubbleSortOPTIMIZED(arr2, n);
    printf("SORTED ARRAY 1: \n");
    for(int i=0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    printf("SORTED ARRAY 2: \n");
    for(int i=0; i<n; i++)
        printf("%d\t", arr2[i]);
    printf("\n");
}
void bubbleSort(int arr[], int n){
    int steps=0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<(n-1-i); j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            steps++;
        }
        steps++;
    }
    printf("NUMBER OF ITERATIONS NORMAL: %d\n", steps);
}
void bubbleSortOPTIMIZED(int arr[], int n){
    int flag=0;
    int steps=0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<(n-1-i); j++){
            if(arr[j]>arr[j+1]){
                flag++;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            steps++;
        }
        steps++;
        if(flag==0){break;}
       
    }
    printf("NUMBER OF ITERATIONS OPTIMIZED: %d\n", steps);
}