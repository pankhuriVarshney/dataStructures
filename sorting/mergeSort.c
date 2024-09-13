#include <stdio.h>
void mergeSort(int arr[], int leftIndex, int rightIndex);
void merge(int arr[], int leftIndex, int mid, int rightIndex);

void mergeSort(int arr[], int leftIndex, int rightIndex){
    if(leftIndex>=rightIndex)
        return;
    int mid=(leftIndex+rightIndex)/2;
    mergeSort(arr, leftIndex, mid);
    mergeSort(arr, mid+1, rightIndex);

    merge(arr, leftIndex, mid, rightIndex);
}
void merge(int arr[], int leftIndex, int mid, int rightIndex){
    int left=mid-leftIndex+1;
    int right=rightIndex-mid;
    int L[left], R[right];
    for(int i=0; i<left; i++){
        L[i]=arr[leftIndex+i];
    }
    for(int j=0; j<right; j++){
        R[j]=arr[mid+1+j];
    }
    int i,j,k;
    for(i=0, j=0, k=leftIndex; i<left&&j<right; k++){
        if(L[i]<R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
    }
    while (i<left) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j<right) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}
int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: \n");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, n-1);
    printf("SORTED ARRAY: \n");
    for(int i=0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}