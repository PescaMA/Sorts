#include<iostream>
#include <vector>

void shellSort(std::vector<double> &v){
    int n = v.size();
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i += 1){
            double temp = v[i]; int j;
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap)
                v[j] = v[j - gap];
            v[j] = temp;
        }
    }
}
