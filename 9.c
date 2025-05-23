#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (max - min + 1) + min;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        int t = arr[i]; arr[i] = arr[min_idx]; arr[min_idx] = t;
    }
}

int main() {
    FILE *fp = fopen("sorting_times.csv", "w");
    if (!fp) return printf("Error opening file.\n"), 1;

    fprintf(fp, "n,Time taken (ms)\n");
    srand(time(NULL));

    for (int n = 1000; n <= 10000; n += 1000) {
        int arr[n];
        generateRandomArray(arr, n, 1, 10000);
        clock_t start = clock();
        selectionSort(arr, n);
        double time_ms = (double)(clock() - start) / CLOCKS_PER_SEC * 1000;
        printf("Time taken to sort %d elements: %.2f ms\n", n, time_ms);
        fprintf(fp, "%d,%.2f\n", n, time_ms);
    }

    fclose(fp);
    printf("Data saved to sorting_times.csv\n");
    return 0;
}
