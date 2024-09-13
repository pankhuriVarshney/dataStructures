#include <stdio.h>
void binarySearch(int arr[], int n, int key);
int rec_binarySearch(int arr[], int n, int key, int low, int high);

int main(){
     printf("Enter size of an array: ");
    int n, key, count=0;
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements\n");
    for(int i=0; i<n; i++)  
        scanf("%d", &arr[i]);
    printf("Enter the key value to be searched: ");
    scanf("%d", &key);
    
    printf("Enter 1: To implement binary search with Iteration\nEnter 2: To implement binary search with Recursion\nEnter your choice:");
    int ch;
    scanf("%d", &ch);
    switch(ch){
        case 1: {
            printf("USING ITERATION: \n");
            binarySearch(arr, n, key);
            break;
        }
        case 2: {
            printf("USING RECURSION: \n");
            if(rec_binarySearch(arr, n, key, 0, n-1)==-1)
                printf("KEY NOT FOUND\n");
            else
                printf("KEY FOUND AT INDEX: %d", rec_binarySearch(arr, n, key, 0, n-1));
        }

    }
   
}

void binarySearch(int arr[], int n, int key){
    int low=0, high=n-1, mid;
    int count=0;
    while(low<=high){
        mid=(low+high)/2;
        if(key==arr[mid]){
            printf("Key found at index %d\n", mid);
            return;
            // count++;
            // if(arr[mid]==arr[mid+1]){
            //     int temp=mid;
            //     while(arr[temp]==arr[temp+1]){
            //         printf("Key found at index %d\n", ++temp);
            //         count++;
            //     }
            // }
            // if(arr[mid]==arr[mid-1]){
            //     int temp=mid;
            //     while(arr[temp]==arr[temp-1]){
            //         printf("Key found at index %d\n", --temp);
            //         count++;
            //     }
            // }
        //    goto end;
        }
        else if(key>arr[mid])
            low=mid+1;
        else
            high=mid-1;
    }
    printf("KEY NOT FOUND\n");
    // // printf("TOTAL SEARCH COUNT: %d\n", count);

}

int rec_binarySearch(int arr[], int n, int key, int low, int high){
    if(low>high){
        return -1;
    }
    int mid=(low+high)/2;
    if(arr[mid]==key)
        return mid;
    else if(key>arr[mid])
        return rec_binarySearch(arr, n, key, mid+1, high);
    else 
        return rec_binarySearch(arr, n, key, low, mid-1);
}