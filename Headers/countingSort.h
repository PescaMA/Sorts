#include<iostream>
#include <vector>
#include <array>
#include <algorithm> // for std::fill

void countingSort(std::vector<double>& v){
    for(auto &elem:v)
        if(elem != (int)elem)
            throw std::invalid_argument("Expected integer values");

    double mn, mx;
    for(auto &elem:v){
        mn = std::min(elem,mn);
        mx = std::max(elem,mx);
    }
    if( mx - mn > 1e7)
        throw std::runtime_error("Size exceeds maximum limit");

    static std::array<int, (int)1e7> cnt;
    std::fill(std::begin(cnt), std::begin(cnt) + (int)(mx - mn + 1), 0);

    for(auto &elem: v)
        cnt[elem - mn] ++;
    int vi = 0;
    for(unsigned int i = 0; i <= mx - mn; i++){
        while(cnt[i] > 0){
            v[vi] = i + mn;
            cnt[i]--;
            vi++;
        }
    }
}
