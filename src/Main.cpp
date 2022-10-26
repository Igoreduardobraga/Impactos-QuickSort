#include "QuickSort.hpp"
//#include "QuickSort_Mediana.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    QuickSort R("QuicksortRecursivo: quicksort");
    QuickSort M("QuicksortMediana");
    //QuickSort_Mediana L;
    int *A = new int[30];
    srand(time(0));

    for(int i=0 ; i<30 ; i++)
        A[i] = rand()%100;
    
    for(int i=0 ; i<30 ; i++)
        cout << A[i] << " ";

    cout << "\n\n";

    //R.Chama_QuickSort(0,A,30);
    M.Chama_QuickSort(0,A,30);
    for(int i=0 ; i<30 ; i++)
        cout << A[i] << " ";

    cout << "\n";
    return 0;
}