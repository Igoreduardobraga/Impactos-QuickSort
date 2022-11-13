#include "MergeSort.hpp"

void MergeSort::merge(int arr[], int p, int q, int r) {
  
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++){
        metricas_MergeSort.Comparacoes++;
        L[i] = arr[p + i];
        metricas_MergeSort.Atribuicoes++;
    }

    for (int j = 0; j < n2; j++){
        metricas_MergeSort.Comparacoes++;
        M[j] = arr[q + 1 + j];
        metricas_MergeSort.Atribuicoes++;
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        metricas_MergeSort.Comparacoes++;
    if (L[i] <= M[j]) {
        metricas_MergeSort.Comparacoes++;
        arr[k] = L[i];
        i++;
    } else {
        arr[k] = M[j];
        metricas_MergeSort.Atribuicoes++;
        j++;
    }
    k++;
    }

    while (i < n1) {
        metricas_MergeSort.Comparacoes++;
        arr[k] = L[i];
        metricas_MergeSort.Atribuicoes++;
        i++;
        k++;
    }

    while (j < n2) {
        metricas_MergeSort.Comparacoes++;
        arr[k] = M[j];
        metricas_MergeSort.Atribuicoes++;
        j++;
        k++;
    }
}

void MergeSort::mergeSort(int arr[], int l, int r) {
    if (l < r) {
        metricas_MergeSort.Comparacoes++;
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void MergeSort::imprimirArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
    cout << endl;
}