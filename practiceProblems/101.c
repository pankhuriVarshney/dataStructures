#include <stdio.h>
void createArray(int arr[], int n){
    printf("Enter the elements: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    } 
}
void displayArray(int arr[], int n){
    printf("The array is:\n");
    for(int i=0; i<n; i++)
        printf("%d\t", arr[i]);
}
int main(){
    printf("ENTER SIZE: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    createArray(arr, n);
    displayArray(arr, n);
}