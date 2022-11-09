#include "QuickSort.hpp"
//#include "QuickSort_Mediana.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    QuickSort M;
    int *A = new int[30];
    //srand(time(0));

    for(int i=0 ; i<30 ; i++)
        A[i] = rand()%100;
    
    for(int i=0 ; i<30 ; i++)
        cout << A[i] << " ";

    cout << endl;

    int *B = new int[30];

    for(int i=0 ; i<30 ; i++){
        B[i] = A[i];
        cout << B[i] << " ";
    }

    cout << "\n\n";

    M.Chama_QuickSort_Recursivo(0,A,30);
    M.Chama_QuickSort_Mediana(0,B,30);
    for(int i=0 ; i<30 ; i++)
        cout << A[i] << " ";

    cout << "\n";

    for(int i=0 ; i<30 ; i++)
        cout << B[i] << " ";

    delete [] A;
    delete [] B;
    return 0;
}