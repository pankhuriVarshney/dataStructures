#include <stdio.h>
void linearSearch(int arr[], int n, int key);
int rec_linearSearch(int arr[], int n, int key);

int main(){
    printf("Enter size of an array: ");
    int n, key;
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements\n");
    for(int i=0; i<n; i++)  
        scanf("%d", &arr[i]);
    printf("Enter the key value to be searched: ");
    scanf("%d", &key);
    linearSearch(arr, n, key);
    printf("USING RECURSION: \n");
    if(rec_linearSearch(arr, n, key)==-1)
        printf("KEY NOT FOUND\n");
    else
        printf("KEY FOUND AT INDEX: %d", rec_linearSearch(arr, n, key));
}
void linearSearch(int arr[], int n, int key){
    int count=0;
    for(int i=0; i<n;i++){
        if(arr[i]==key){
            count++;
            printf("Found at index %d\n", i);
        }
    }
    if(count==0)
        printf("KEY NOT FOUND");
    printf("TOTAL SEARCH COUNT:  %d\n", count);
}

int rec_linearSearch(int arr[], int n, int key){
    if(n-1 < 0)
        return -1;
    if(arr[n-1]==key)
        return n-1;
    else return rec_linearSearch(arr, n-1, key);
}