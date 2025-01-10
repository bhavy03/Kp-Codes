#include <stdio.h>

void binarySearch(int arr[], int start, int end, int target, int row) {
    if (start > end) {
        return; 
    }

    int mid = (start + end) / 2;
    if (arr[mid] == target) {
        printf("Element found at row %d and column %d\n", row, mid);
        return;
    } else if (arr[mid] > target) {
        binarySearch(arr, start, mid - 1, target, row);
    } else {
        binarySearch(arr, mid + 1, end, target, row);
    }
}

int main() {
    int rows, cols, target, found = 0;
    printf("Enter number of rows and columns:\n");
    scanf("%d %d", &rows, &cols);

    printf("Enter the matrix:\n");
    int arr[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter the target:\n");
    scanf("%d", &target);

    for (int i = 0; i < rows; i++) {
        if (arr[i][0] <= target && arr[i][cols - 1] >= target) {
            binarySearch(arr[i], 0, cols - 1, target, i); 
            found = 1;
            break; 
        }
    }

    if (!found) {
        printf("Element not found in the matrix\n");
    }

    return 0;
}
