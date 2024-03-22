#include <iostream>
#include <vector>

void insertionSort(std::vector<double>& v){
    for(int unsigned i=1;i<v.size();i++){
        for(int j=i;j > 0 && v[j] <v[j-1];j--)
            std::swap(v[j],v[j-1]);
    }
}
