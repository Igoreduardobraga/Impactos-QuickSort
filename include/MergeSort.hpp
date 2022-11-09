#ifndef MERGESORT_H
#define MERGESORT_H

class MergeSort{
    private:

    public:
        MergeSort();
        void merge(int arr[], int p, int q, int r);
        void mergeSort(int arr[], int l, int r);
        void imprimirArray(int arr[], int size);
};

#endif