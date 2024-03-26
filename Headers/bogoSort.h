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
    while(!isSorted(v, v.size())) shuffle(v, v.size());
}
