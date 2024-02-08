#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;

    for (i=0; i<n-1; i++) {
        minIdx = i;
        for (j= +1; j<n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx=j;
        }

        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[10] = {29, 10, 14, 37, 13, 25, 99, 88, 65, 75};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
