
#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    int steps=0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            steps++;
        }
        arr[j + 1] = key;
        steps++;
    }
    printf("NUMBER OF ITERATIONS: %d\n", steps);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    return 0;
}
