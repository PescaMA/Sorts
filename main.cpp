#include <vector>
#include <iostream>
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
void outPutResult(const std::string& sortName, std::vector<int>& v,
                  const std::vector<int>& sortedVector, const unsigned long long& startTime){
    std::cout << sortName << " ran in " << getTimeMCS() - startTime << " microseconds.\n";

    std::sort(v.begin(),v.end());
    if(sortedVector == v)
        std::cout << "Correctly sorted\n";
    else
        std::cout << "Incorrectly sorted\n";
}
void runTest(std::string sortName, std::vector<int> v,void (*namedSort)(std::vector<int>&)){
    std::vector<int> correctSort = v;
    ///unsigned long long startTime = getTimeMCS();
    namedSort(v);
    ///outPutResult(sortName,correctSort,v,startTime);
}
void runTest(std::string sortName, std::vector<int> v, int (*choosePivot)(const std::vector<int>&),
             void (*namedSort)(std::vector<int>&, int (*)(const std::vector<int>&))){
    std::vector<int> correctSort = v;
    ///unsigned long long startTime = getTimeMCS();
    namedSort(v,choosePivot);
    ///outPutResult(sortName,correctSort,v,startTime);
}
void runAllTests(std::vector<int>& v){
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

    runTest("Radix sort (base 10)", v, base10, radixSort);
    runTest("Radix sort (base 16)", v, base16, radixSort);
    runTest("Radix sort (base 2^16)", v, base2power16, radixSort);
}
int main()
{
    srand((unsigned)time(NULL));
    std::vector<int> v = {10,9,8,7,6,5,4,32,1};
    runAllTests(v);
    return 0;
}
