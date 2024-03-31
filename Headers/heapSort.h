#include<iostream>
#include <vector>
#include <queue>

template <class t>
class Heap{
    std::vector<t> v;
public:
    void push(t x){
        v.push_back(x);
        long long i = v.size();

        while( i > 1 && v[i - 1] < v[i/2 - 1]){
            std::swap(v[i - 1], v[i/2 - 1]);
            i/=2;
        }
    }
    t top(){
        return v[0];
    }
    bool empty(){
        return v.empty();
    }
    void pop(){
        if (v.empty()) return;
        long long i = 0;
        std::swap(v[i], v[v.size()-1]);
        v.pop_back();
        while(i < v.size() ){
            unsigned int c1 = (1+i) * 2 - 1;
            unsigned int c2 = (1+i) * 2;
            if(c1 >= v.size())
                break;
            if(c2 == v.size()){
                if(v[c1] < v[i])
                     std::swap(v[i], v[c1]);
                break;
            }
            if(v[i] < std::min (v[c1],v[c2]))
                break;
            if(v[c1] < v[c2]){
                std::swap(v[i], v[c1]);
                i = c1;
            }
            else{
                std::swap(v[i], v[c2]);
                i = c2;
            }
        }
    }
    friend std::ostream& operator<<(std::ostream& out, const Heap pq){
        for(auto el:pq.v)
            out << el << ' ';
        return out;
    }
};

void heapSort(std::vector<double>& v){
    Heap<double> pq;
    for(double el:v)
        pq.push(el);
    int i = 0;
    while(!pq.empty()){
        v[i] = pq.top();
        pq.pop();
        i++;
    }
}
