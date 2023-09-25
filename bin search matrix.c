#include <stdio.h>
#include <stdlib.h>

// Binary search on 1D sorted array
int binsearch(int arr[], int s, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == s)
            return mid;
        if (arr[mid] < s)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Element not found
}

// Sort a 1D array using selection sort
void selectionsort(int arr1[], int s) {
    for (int i = 0; i < s - 1; i++) {
        int min = i;
        for (int j = i + 1; j < s; j++) {
            if (arr1[j] < arr1[min]) {
                min = j;
            }
        }
        // Swap min element with the element at index i
        int temp = arr1[i];
        arr1[i] = arr1[min];
        arr1[min] = temp;
    }
}

// Sort a 3x3 matrix in ascending order
void convert(int arr[3][3]) {
    // Convert the 3x3 matrix to a 1D array for sorting
    int arr2[9];
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr2[k++] = arr[i][j];
        }
    }

    // Sort the 1D array
    selectionsort(arr2, 9);
    // Update the matrix with the sorted values
    k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = arr2[k++];
        }
    }
}

int main(void) {
    int arr[3][3];
    printf("Enter elements of a 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Print in the matrix form
    printf("Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int x;
    // Input the element to be searched
    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    // Sort the matrix
    convert(arr);

    // Perform binary search on the sorted matrix
    int res = binsearch(arr[0], x, 0, 8);
    if(res == -1)
        printf("Element not found\n");
    else{
        // Calculate row and column from the index
        int row = res / 3;
        int col = res % 3;
        printf("Element found at column %d and row %d\n",col,row);
    }
    return 0;
}
