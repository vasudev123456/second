#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void fillRandom(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) arr[i] = rand() % (max - min + 1) + min;
}

int main() {
    FILE *fp = fopen("sorting_times.csv", "w");
    if (!fp) return 1;

    fprintf(fp, "n,Time (ms)\n");
    srand(time(NULL));

    for (int n = 5000; n <= 10000; n += 500) {
        int arr[n];
        fillRandom(arr, n, 1, 10000);
        clock_t start = clock();
        mergeSort(arr, 0, n - 1);
        double time_ms = (double)(clock() - start) / CLOCKS_PER_SEC * 1000;
        printf("Sorted %d elements in %.2f ms\n", n, time_ms);
        fprintf(fp, "%d,%.2f\n", n, time_ms);
    }

    fclose(fp);
    return 0;
}
