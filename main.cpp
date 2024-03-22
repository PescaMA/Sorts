#include <vector>
#include <iostream>
#include <random>
#include "Headers/insertionSort.h"
#include "Headers/quickSort.h"

#include <chrono>

unsigned long long getTimeMS()
{
    return std::chrono::system_clock::now().time_since_epoch() /
    std::chrono::milliseconds(1);
}

void a(){
std::cout << "a";
}

int main()
{
    srand((unsigned)time(NULL));
    std::vector<int> v = {10,9,8,7,6,5,4,32,1};
    quickSort(v,pivotMedian5Random);
    return 0;
}
