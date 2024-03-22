#include<iostream>
#include <vector>
#include <map>
void radixSort(std::vector<double>& v, int const& base){
    for(auto &elem:v)
        if(elem != (int)elem)
            throw std::invalid_argument("Expected integer values");

    std::map<int,std::vector<int>> buckets;
    int power = 1;
    while(true){

        bool nonZero = true;
        for(auto &elem:v)
            if((int)elem / power % base != 0){
                nonZero = false;
                break;
            }
        if(nonZero)
            break;

        for(auto &elem:v)
            buckets[(int)elem / power % base].push_back((int)elem);

        int i = 0;
        for(auto &bucket:buckets){
            for(int &element:bucket.second){
                v[i] = element;
                i++;
            }
        }
        for(auto &bucket:buckets)
            bucket.second.clear();

        power*=base;
    }
}
