#include<iostream>
#include <vector>

bool isSorted(std::vector<double>& v, int n){
    while (--n > 0)
        if (v[n] < v[n - 1])
            return false;
    return true;
}

// To generate permutation of the array
void shuffle(std::vector<double>& v, int n){
    for (int i = 0; i < n; i++) std::swap(v[i], v[rand() % n]);
}

// Sorts array a[0..n-1] using Bogo sort
void bogoSort(std::vector<double>& v){

    const long long MAX_TIME = 5 * 1000000; /// seconds * 10^6
    long long startTime = std::chrono::system_clock::now().time_since_epoch() / std::chrono::microseconds(1);
    while(!isSorted(v, v.size())){
        shuffle(v, v.size());
        long long time = std::chrono::system_clock::now().time_since_epoch() / std::chrono::microseconds(1);
        if ( time - startTime > MAX_TIME)
            throw std::runtime_error( std::to_string(time-startTime) + " Destroying Universe...");
    }
}
