#include<iostream>
#include <vector>
#include <unordered_map>
void radixSort(std::vector<int>& v, int const& base){
    std::unordered_map<int,std::vector<int>> buckets(base);
    int power = 1;
    while(true){

        bool nonZero = true;
        for(auto &elem:v)
            if(elem / power % base != 0){
                nonZero = false;
                break;
            }
        if(nonZero)
            break;

        for(auto &elem:v)
            buckets[elem / power % base].push_back(elem);
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
