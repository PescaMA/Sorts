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

int pivotFirst(int const& st, int const& dr,const std::vector<int>& v){
    return v[st];
}
int pivotLast(int const& st, int const& dr,const std::vector<int>& v){
    return v[dr];
}
int pivotRandom(int const& st, int const& dr,const std::vector<int>& v){
    return v[st + rand() % (dr-st+1)];
}
int pivotMedian3Normal(int const& st, int const& dr,const std::vector<int>& v){
    return medianThree(v[st], v[dr], v[(st+dr)/2]);
}
int pivotMedian3Random(int const& st, int const& dr,const std::vector<int>& v){
    return medianThree(pivotRandom(st,dr,v),pivotRandom(st,dr,v),pivotRandom(st,dr,v));
}
int pivotMedian5Normal(int const& st, int const& dr,const std::vector<int>& v){
    std::vector<int> v5;
    for(int i = 0;i <5; i++)
        v5.push_back(v[st + std::min((dr-st+1) * i/4, (dr-st+1)-1)]);
    return medianFive(v5);
}
int pivotMedian5Random(int const& st, int const& dr,const std::vector<int>& v){
    return medianFive({pivotRandom(st,dr,v),pivotRandom(st,dr,v),pivotRandom(st,dr,v),pivotRandom(st,dr,v),pivotRandom(st,dr,v)});
}

void quickSort(std::vector<int>& v, int (*choosePivot)(const int&,const int&,const std::vector<int>&), const int st, const int dr){
    if(st >= dr)
        return;
    int const pivot = choosePivot(st,dr,v);

    int i , pivotIndex;
    int j = dr;
    for(i = st; i <= j; i++){
        if(v[i] > pivot){
            std::swap(v[i], v[j]);
            j--;
            i--;
        }
        if(v[i] == pivot)
            pivotIndex = i;
    }
    std::swap(v[pivotIndex], v[j]);
    quickSort(v,choosePivot,st,j - 1);
    quickSort(v,choosePivot,j + 1,dr);
}
void quickSort(std::vector<int>& v, int (*choosePivot)(const int&,const int&,const std::vector<int>&)){
    quickSort(v,choosePivot,0,v.size() - 1);
}
