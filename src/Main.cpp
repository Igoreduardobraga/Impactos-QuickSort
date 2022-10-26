#include "QuickSort.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main(int argc, int argv[]) {
    QuickSort I;
    int *A = new int[30];
    srand(time(0));

    for(int i=0 ; i<30 ; i++)
        A[i] = rand()%100;
    
    for(int i=0 ; i<30 ; i++)
        cout << A[i] << " ";

    cout << "\n\n";

    I.Chama_QuickSort(A,30);
    for(int i=0 ; i<30 ; i++)
        cout << A[i] << " ";
    //I.Print();
    delete [] A;
    return 0;
}