#include <stdio.h>
/**
* swapping algorithm
*/
void swap (int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
* Start from index 0.
* Compare current element with the next one.
* Swap if current > next.
* Move forward until end of array.
*/
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <size - i - 1; j++){
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

/**
* Treat arr[0..i] as sorted
* Take key = arr[i]
* Shift elements greater than key one position to the right
* Drop key into the hole
*/
void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] > key && j >= 0) {
            swap(&arr[j], &arr[j + 1]);
            j--;
        }
        arr[j+1] = key;
    }
}

/**
* Start from index 0.
* Find the smallest element in the unsorted part.
* Swap it with the element at the current index.
* Move the boundary of sorted part right.
* Repeat until array is sorted.
*/
void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i+ 1; j <size; j++){
            if (arr[j] < arr[min])
            min = j;
        }

        if (min != i) {
            swap(&arr[i], &arr[min]);
        }
    }
}


int main () {
    int arr[] = {3,7,9,5,2,14,7,0,56,43,26,8,3,1};
    int size = sizeof(arr)/ sizeof(arr[0]);

    // bubble_sort(arr, size);
    // insertion_sort(arr, size);
    selection_sort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}