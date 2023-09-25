#include <stdio.h>
#include <stdlib.h>
//sort a 1D array using selection sort
void selectionsort(int arr1[], int s){
    for (int i=0;i<s-1;i++){
        int min=i;
        for (int j=i+1;j<s;j++){
            if (arr1[j]<arr1[min]){
                min = j;
            }
        }
        // Swap min element with the element at index i
        int temp=arr1[i];
        arr1[i]=arr1[min];
        arr1[min]=temp;
    }
}
// sort a 3x3 matrix
void sortmatrix(int arr[3][3]){
    // Convert the 3x3 matrix to a 1D array for sorting
    int arr2[9];
    int k=0;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            arr2[k++]=arr[i][j];
        }
    }
    // Sort the 1D array
    selectionsort(arr2,9);
    // Update the matrix with the sorted values
    k=0;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            arr[i][j]=arr2[k++];
        }
    }
}

// print matrix
void printmatrix(int arr[3][3]){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int arr[3][3];
    printf("Enter elements of a 3x3 matrix:\n");
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            printf("matrix[%d][%d] = ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    // Sort the matrix
    sortmatrix(arr);
    // Print
    printf("Sorted matrix:\n");
    printmatrix(arr);
    return 0;
}