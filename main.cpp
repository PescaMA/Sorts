#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <algorithm>

#include "Headers/bogoSort.h"
#include "Headers/countingSort.h"
#include "Headers/heapSort.h"
#include "Headers/insertionSort.h"
#include "Headers/mergeSort.h"
#include "Headers/quickSort.h"
#include "Headers/radixSort.h"
#include "Headers/shellSort.h"


long long getTimeMCS()
{
    return std::chrono::system_clock::now().time_since_epoch() /
    std::chrono::microseconds(1);
}

void outPutResult(const std::string& sortName, std::vector<double>& v,
                  const std::vector<double>& sortedVector, const unsigned long long& startTime){
    std::cout << sortName << " ran in " << getTimeMCS() - startTime << " microseconds.\n";

    std::sort(v.begin(),v.end());
    if(sortedVector == v)
        std::cout << "Correctly sorted\n\n";
    else
        std::cout << "Incorrectly sorted\n\n";
}
void runTest(std::string sortName, std::vector<double> v,void (*namedSort)(std::vector<double>&)){
    std::vector<double> correctSort = v;
    ///unsigned long long startTime = getTimeMCS();
    namedSort(v);
    ///outPutResult(sortName,correctSort,v,startTime);
}
void runTest(std::string sortName, std::vector<double> v, double (*choosePivot)(const int&,const int&,const std::vector<double>&),
             void (*namedSort)(std::vector<double>&, double (*)(const int&,const int&,const std::vector<double>&))){
    std::vector<double> correctSort = v;
    unsigned long long startTime = getTimeMCS();
    namedSort(v,choosePivot);
    outPutResult(sortName,correctSort,v,startTime);
}
void runTest(std::string sortName, std::vector<double> v, const int& base,
             void (*namedSort)(std::vector<double>&, const int&)) {
    std::vector<double> correctSort = v;
    unsigned long long startTime = getTimeMCS();
    namedSort(v,base);
    outPutResult(sortName,correctSort,v,startTime);
}

void runAllTests(const std::vector<double>& v){
    runTest("Bogo sort", v, bogoSort);
    runTest("Counting sort", v, countingSort);
    runTest("Heap sort", v, heapSort);
    runTest("Insertion sort", v, insertionSort);
    runTest("Merge sort", v, mergeSort);
    runTest("ShellSort sort", v, shellSort);

    runTest("Quick sort (pivotFirst)", v, pivotFirst, quickSort);
    runTest("Quick sort (pivotLast)", v, pivotLast, quickSort);
    runTest("Quick sort (pivotRandom)", v, pivotRandom, quickSort);
    runTest("Quick sort (pivotMedian3Normal)", v, pivotMedian3Normal, quickSort);
    runTest("Quick sort (pivotMedian5Normal)", v, pivotMedian5Normal, quickSort);
    runTest("Quick sort (pivotMedian3Random)", v, pivotMedian3Random, quickSort);
    runTest("Quick sort (pivotMedian5Random)", v, pivotMedian5Random, quickSort);

    try{
    runTest("Radix sort (base 10)", v, 10, radixSort);
    runTest("Radix sort (base 16)", v, 16, radixSort);
    runTest("Radix sort (base 2^16)", v, (1 << 16), radixSort);
    }
    catch(const std::invalid_argument& e) {
        std::cerr << "Invalid RadixSort argument: " << e.what() << '\n';
    }
}
void runInputs(){
    std::ifstream fin("tests/tests.in");
    int q;
    fin >> q;
    while(q--){
        std::vector<double> v;
        int n, mx;
        fin >> n >> mx; /// mx is not used (could be a lie)
        while(n--){
            double x;
            fin >> x;
            v.push_back(x);
        }
        runAllTests(v);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    runInputs();
    return 0;
}
