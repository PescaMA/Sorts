#include <iostream>
#include <vector>

double medianThree(double a, double b, double c) {
    if ((a > b) ^ (a > c))
        return a;
    if ((b < a) ^ (b < c))
        return b;
    return c;
}
void insertionSortCopy(std::vector<double>& v){
    for(int unsigned i=1;i<v.size();i++){
        for(int j=i;j > 0 && v[j] <v[j-1];j--)
            std::swap(v[j],v[j-1]);
    }
}
double medianFive(std::vector<double> v){
    insertionSortCopy(v);
    return v[2];
}

double pivotFirst(int const& st, int const& dr,const std::vector<double>& v){
    return v[st];
}
double pivotLast(int const& st, int const& dr,const std::vector<double>& v){
    return v[dr];
}
double pivotRandom(int const& st, int const& dr,const std::vector<double>& v){
    return v[st + rand() % (dr-st+1)];
}
double pivotMedian3Normal(int const& st, int const& dr,const std::vector<double>& v){
    return medianThree(v[st], v[dr], v[(st+dr)/2]);
}
double pivotMedian3Random(int const& st, int const& dr,const std::vector<double>& v){
    return medianThree(pivotRandom(st,dr,v),pivotRandom(st,dr,v),pivotRandom(st,dr,v));
}
double pivotMedian5Normal(int const& st, int const& dr,const std::vector<double>& v){
    std::vector<double> v5;
    for(int i = 0;i <5; i++)
        v5.push_back(v[st + std::min((dr-st+1) * i/4, (dr-st+1)-1)]);
    return medianFive(v5);
}
double pivotMedian5Random(int const& st, int const& dr,const std::vector<double>& v){
    return medianFive({pivotRandom(st,dr,v),pivotRandom(st,dr,v),pivotRandom(st,dr,v),pivotRandom(st,dr,v),pivotRandom(st,dr,v)});
}

void quickSort(std::vector<double>& v, double (*choosePivot)(const int&,const int&,const std::vector<double>&), const int st, const int dr){
    if(st >= dr)
        return;
    double const pivot = choosePivot(st,dr,v);

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
void quickSort(std::vector<double>& v, double (*choosePivot)(const int&,const int&,const std::vector<double>&)){
    quickSort(v,choosePivot,0,v.size() - 1);
}
