#include <iostream>
#include <stdlib.h>

void change(int& max, int& min) {
    min = min + max;
    max = min - max;
    min = min - max;
}

void QuickSort(int arr[], int left, int right) { // Рекурсивная ф-ия 
        int l_hold = left;
        int r_hold = right; 
        int pivot = arr[left];

        while (left < right){

            while ((arr[right] >= pivot) && (left < right)) right--; 

            if (left != right) 
            {
                change(arr[left], arr[right]); 
                left++; 
            }

            while ((arr[left] <= pivot) && (left < right)) left++; 

            if (left != right) 
            {
                change(arr[right], arr[left]);
                right--; 
            }
        }

        arr[right] = pivot;  // можно и arr[left] = pivot
        if (l_hold < right) QuickSort(arr, l_hold, right  - 1); // можно и l_hold < left
        if (r_hold > right) QuickSort(arr, right + 1, r_hold);
}

void print(int a[], const int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
}

int main() {
    int Rand_M, Rand_L, N;
    std:: cin >> Rand_M >> Rand_L;
    Rand_M -= Rand_L;

    std::cin >> N;

    int* array = new int[N];

    for (int i = 0; i < N; ++i) {
        array[i] = rand() % Rand_M + Rand_L;
        std::cout << array[i] << ' ';
    }
    std::cout <<'\n';
    int left = 0;
    int right = N - 1;

    QuickSort(array,left,right);
    print(array, N);
    delete[] array;
    return 0;
}