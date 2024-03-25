#include<iostream>
#include <vector>
#include <queue>

void heapSort(std::vector<double>& v){
    std::priority_queue<double> pq;
    for( int el:v)
        pq.push(-el);
    int i = 0;
    while(!pq.empty()){
        v[i] = -pq.top();
        pq.pop();
        i++;
    }
}
