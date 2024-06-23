#include <stdio.h>

// Function prototypes
void bubble_sort(int arr[], int n, int ascending);
void selection_sort(int arr[], int n, int ascending);

int main() {
    int n, i, order;
    
    // Get the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Declare an array of size n
    int arr[n];

    // Input array elements from the user
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Prompt the user to choose sorting order
    printf("Choose sorting order:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Enter your choice: ");
    scanf("%d", &order);

    // Sort the array based on the user's choice
    if (order == 1) {
        bubble_sort(arr, n, 1); // Ascending order
    } else if (order == 2) {
        bubble_sort(arr, n, 0); // Descending order
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    // Display the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Bubble sort algorithm
void bubble_sort(int arr[], int n, int ascending) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ascending ? (arr[j] > arr[j + 1]) : (arr[j] < arr[j + 1])) {
                // Swap elements if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection sort algorithm
void selection_sort(int arr[], int n, int ascending) {
    int i, j, min_index, max_index, temp;
    for (i = 0; i < n - 1; i++) {
        if (ascending) {
            min_index = i;
            for (j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            // Swap the minimum element with the current element
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        } else {
            max_index = i;
            for (j = i + 1; j < n; j++) {
                if (arr[j] > arr[max_index]) {
                    max_index = j;
                }
            }
            // Swap the maximum element with the current element
            temp = arr[i];
            arr[i] = arr[max_index];
            arr[max_index] = temp;
        }
    }
}

