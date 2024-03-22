#include <iostream>
#include <vector>

int medianThree(int a, int b, int c) {
    if ((a > b) ^ (a > c))
        return a;
    if ((b < a) ^ (b < c))
        return b;
    return c;
}
void insertionSortCopy(std::vector<int>& v){
    for(int unsigned i=1;i<v.size();i++){
        for(int j=i;j > 0 && v[j] <v[j-1];j--)
            std::swap(v[j],v[j-1]);
    }
}
int medianFive(std::vector<int> v){
    insertionSortCopy(v);
    return v[2];
}

int pivotFirst(const std::vector<int>& v){
    return v[0];
}
int pivotLast(const std::vector<int>& v){
    return v[v.size() - 1];
}
int pivotRandom(const std::vector<int>& v){
    return v[rand() % v.size()];
}
int pivotMedian3Normal(const std::vector<int>& v){
    return medianThree(v[0], v[v.size()- 1], v[v.size()/2]);
}
int pivotMedian3Random(const std::vector<int>& v){
    return medianThree(pivotRandom(v),pivotRandom(v),pivotRandom(v));
}
int pivotMedian5Normal(const std::vector<int>& v){
    std::vector<int> v5;
    for(int i = 0;i <5; i++)
        v5.push_back(v[std::min(v.size() * i/4, v.size()-1)]);
    return medianFive(v5);
}
int pivotMedian5Random(const std::vector<int>& v){
    return medianFive({pivotRandom(v),pivotRandom(v),pivotRandom(v),pivotRandom(v),pivotRandom(v)});
}



void quickSort(std::vector<int>& v, int (*choosePivot)(const std::vector<int>&)){
    std::cout << choosePivot(v) << '\n';
}
