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
    ///unsigned long long startTime = getTimeMCS();
    namedSort(v,choosePivot);
    ///outPutResult(sortName,correctSort,v,startTime);
}
void runTest(std::string sortName, std::vector<double> v, const int& base,
             void (*namedSort)(std::vector<double>&, const int&)) {
    std::vector<double> correctSort = v;
    unsigned long long startTime = getTimeMCS();
    namedSort(v,base);
    outPutResult(sortName,correctSort,v,startTime);
}

void runAllTests(std::vector<double>& v){
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
int main()
{
    srand((unsigned)time(NULL));
    std::vector<double> v = {10,9,8,7,6,5,4,32,1};
    std::vector<double> v100 = {5344,4987,223,2040,557,8178,3016,6922,3000,1401,832,9940,1957,8532,6954,8148,7046,6285,3604,4991,8351,1267,5480,5907,9246,590,8728,4930,6992,434,5405,4206,1980,4070,8444,7774,1232,3661,5008,7702,8223,7960,9665,9147,6568,4556,8374,511,936,1503,6307,9782,5194,91,6252,6216,7347,9989,7211,7701,5827,9435,5899,8525,3928,8083,9086,1985,9474,2000,298,7870,963,8552,2054,413,8337,3833,8948,9988,5245,157,6582,6122,2695,4322,704,2394,2334,5463,3135,4615,3039,5977,1312,927,8805,7727,1968,9653};
    ///runAllTests(v);
    runAllTests(v100);
    return 0;
}
