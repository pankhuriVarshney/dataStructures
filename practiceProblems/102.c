#include <stdio.h>
int largestElement(int arr[], int n);
int main(){
    printf("ENTER SIZE OF ARRAY:");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("ENTER ELEMENTS:\n");
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("LARGEST ELEMENT: %d", largestElement(arr, n));
    return 0;
}
int largestElement(int arr[], int n){
    int largest=arr[0];
    for(int i=1; i<n; i++){
        if(largest< arr[i])
            largest= arr[i];
    }
    return largest;
}