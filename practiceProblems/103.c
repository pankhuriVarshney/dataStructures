#include <stdio.h>
int secondLargestElement(int arr[], int n);
int main(){
    printf("ENTER SIZE OF ARRAY:");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("ENTER ELEMENTS:\n");
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("SECOND LARGEST ELEMENT: %d", secondLargestElement(arr, n));
    return 0;
}
int secondLargestElement(int arr[], int n){
    int largest=arr[0], second;
    for(int i=1; i<n; i++)
        if(largest<arr[i]){
            second=largest;
            largest=arr[i];
        }
    return second;
}