#include <iostream>
#include "SortTestHelper.h"
#include "SortingAdvance.h"
#include "SortingBasic.h"
using namespace std;



int main() {

    int n = 50000;

    cout<<"Test for Random Array, size = "<< n <<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr3, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr1, n);
    quickSort(arr1, n);
    SortTestHelper::printArray(arr1, n);


    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    
    cout<<endl;
    return 0;
}