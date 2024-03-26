#include<iostream>
#include <vector>
#include <map>
void radixSort(std::vector<double>& v, int const& base){
    for(auto &elem:v)
        if(elem != (long long)elem)
            throw std::invalid_argument("Expected integer values");

    std::map<int,std::vector<long long>> buckets;
    long long power = 1;
    while(true){

        bool nonZero = true;
        for(auto &elem:v)
            if((long long)elem / power != 0){
                nonZero = false;
                break;
            }
        if(nonZero)
            break;

        for(auto &elem:v)
            buckets[(long long)elem / power % base].push_back((long long)elem);

        int i = 0;
        for(auto &bucket:buckets){
            for(auto &element:bucket.second){
                v[i] = element;
                i++;
            }
        }
        for(auto &bucket:buckets)
            bucket.second.clear();

        power*=base;
    }
}
