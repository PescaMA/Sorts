#include <iostream>
#include <vector>

void insertionSort(std::vector<double>& v){
    const long long MAX_TIME = 120 * 1000000; /// seconds * 10^6
    long long startTime = std::chrono::system_clock::now().time_since_epoch() / std::chrono::microseconds(1);

    for(int unsigned i=1;i<v.size();i++){
        for(int j=i;j > 0 && v[j] <v[j-1];j--){
            std::swap(v[j],v[j-1]);
            long long time = std::chrono::system_clock::now().time_since_epoch() / std::chrono::microseconds(1);
            if ( time - startTime > MAX_TIME)
                throw std::runtime_error( std::to_string(time-startTime) + " macroseconds.");
        }

    }
}
