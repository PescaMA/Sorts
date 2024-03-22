#include <iostream>
#include <chrono>

unsigned long long getTimeMS()
{
    return std::chrono::system_clock::now().time_since_epoch() /
    std::chrono::milliseconds(1);
}

void a(){
std::cout << "a";
}

int main()
{
    std::cout << getTimeMS();
    return 0;
}
