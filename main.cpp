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

    if(sortedVector == v)
        std::cout << "Correctly sorted\n\n";
    else
        std::cout << "Incorrectly sorted\n\n";
}
std::vector<double> runStlTest(std::string sortName, std::vector<double> v){
    unsigned long long startTime = getTimeMCS();
    std::sort(v.begin(),v.end());
    outPutResult(sortName,v,v,startTime);
    return v;
}
void runTest(std::string sortName, std::vector<double> v,const std::vector<double> &vSorted, void (*namedSort)(std::vector<double>&)){
    unsigned long long startTime = getTimeMCS();
    namedSort(v);
    outPutResult(sortName,v,vSorted,startTime);
}
void runTest(std::string sortName, std::vector<double> v, const std::vector<double>& vSorted,double (*choosePivot)(const int&,const int&,const std::vector<double>&),
             void (*namedSort)(std::vector<double>&, double (*)(const int&,const int&,const std::vector<double>&))){

    try{
        unsigned long long startTime = getTimeMCS();
        namedSort(v,choosePivot);
        outPutResult(sortName,v,vSorted,startTime);
    }catch(const std::runtime_error& e) {
        std::cerr << sortName + "took too long:" << e.what() << "\n\n";}
}
void runTest(std::string sortName, std::vector<double> v,const std::vector<double>& vSorted, const int& base,
             void (*namedSort)(std::vector<double>&, const int&)) {
    unsigned long long startTime = getTimeMCS();
    namedSort(v,base);
    outPutResult(sortName,v,vSorted,startTime);

}

void runAllTests(const std::vector<double>& v){
    std::vector<double> correctSort = runStlTest("STL sort",v);

    try{
        runTest("Counting sort", v,correctSort, countingSort);
    }
    catch(const std::invalid_argument& e) {
        std::cerr << "Invalid Counting sort argument: " << e.what() << "\n\n";
    }
    catch(const std::runtime_error& e) {
        std::cerr << "Invalid Counting sort argument: " << e.what() << "\n\n";
    }

    /*try{
        runTest("Insertion sort", v,correctSort, insertionSort);
    }catch(const std::runtime_error& e) {
        std::cerr << "Insertion sort took too long: " << e.what() << "\n\n";
    }*/


    runTest("Heap sort", v,correctSort, heapSort);



    runTest("Merge sort", v,correctSort, mergeSort);
    runTest("ShellSort sort", v,correctSort, shellSort);

    runTest("Quick sort (pivotFirst)", v,correctSort, pivotFirst, quickSort);
    runTest("Quick sort (pivotLast)", v,correctSort, pivotLast, quickSort);
    runTest("Quick sort (pivotRandom)", v,correctSort, pivotRandom, quickSort);
    runTest("Quick sort (pivotMedian3Normal)", v,correctSort, pivotMedian3Normal, quickSort);
    runTest("Quick sort (pivotMedian5Normal)", v,correctSort, pivotMedian5Normal, quickSort);
    runTest("Quick sort (pivotMedian3Random)", v,correctSort, pivotMedian3Random, quickSort);
    runTest("Quick sort (pivotMedian5Random)", v,correctSort, pivotMedian5Random, quickSort);

    try{
    runTest("Radix sort (base 10)", v,correctSort, 10, radixSort);
    runTest("Radix sort (base 16)", v,correctSort, 16, radixSort);
    runTest("Radix sort (base 2^16)", v,correctSort, (1 << 16), radixSort);
    }
    catch(const std::invalid_argument& e) {
        std::cerr << "Invalid RadixSort argument: " << e.what() << "\n\n";
    }

    /*
    try{
        runTest("Insertion sort", v,correctSort, insertionSort);
    }catch(const std::runtime_error& e) {
        std::cerr << "Insertion sort took too long: " << e.what() << "\n\n";
    }
    try{
        runTest("Bogo sort", v,correctSort, bogoSort);
    }catch(const std::runtime_error& e) {
        std::cerr << "Bogo took too long: " << e.what() << "\n\n";
    }
    */
    std::cout << "\nSuccessfully ran tests.\n\n\n";
}
void runInputs(){
    std::ifstream fin("tests/tests.in");
    int q;
    fin >> q;
    for(int i = 0; i< q; i++){
        std::vector<double> v;
        int n;
        double mx;
        fin >> n >> mx; /// mx is not used (could be a lie)
        while(n--){
            double x;
            fin >> x;
            v.push_back(x);
        }
        std::cout << "----TEST " << i + 1 << " RUNNING:----\n\n";
        runAllTests(v);
    }
}

std::vector<double> GenerateRandomInt(int n){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<double> integers(n);
    for (int i = 0; i < n; ++i) {
        integers[i] = i;
    }
    std::shuffle(integers.begin(), integers.end(), gen);
    return integers;
}

void runInputsGenerated(){
    runAllTests(GenerateRandomInt(1e8));
}

int main()
{
    srand((unsigned)time(NULL));
    //runInputs();
    runInputsGenerated();
    return 0;
}
