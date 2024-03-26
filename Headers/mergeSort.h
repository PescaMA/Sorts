#include<iostream>
#include <vector>

void merge_arrays(std::vector<double> &v, int const left, int const mid, int const right){
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

    for(auto i = 0; i < subArrayOne; i++) leftArray[i] = v[left+i];
    for(auto j = 0; j < subArrayTwo; j++) rightArray[j] = v[mid+1+j];

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while(indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo){
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]){
            v[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else{
            v[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while(indexOfSubArrayOne < subArrayOne){
        v[indexOfMergedArray] =
        leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while(indexOfSubArrayTwo < subArrayTwo){
        v[indexOfMergedArray] =
        rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(std::vector<double>& v, int const left, int const right){
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(v, left, mid);
    mergeSort(v, mid+1, right);
    merge_arrays(v, left, mid, right);
}

void mergeSort(std::vector<double>& v){
    mergeSort(v, 0, v.size()-1);
}
