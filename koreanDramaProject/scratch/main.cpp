#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <iomanip>
#include <queue>
#include <cmath>

template <typename T>
T min(T a, T b){
    return (a<b) ? a: b;
}

template <typename T>
T max (T a, T b){
    return a > b ? a:b;
}

template <typename T1, typename T2>
std::string func(T1 a, T2 b){
    return a>b ? "a is bigger":"b is bigger";
}

template <typename T>
T pythaogrean(T a, T b){
    return pow(pow(a,2)+pow(b,2),0.5);
}

int main(){
    
    std::cout << min(2,3) << std::endl;
    std::cout << min<double>(2.3, 2.1) << std::endl;
    std::cout << max(30,40) << std::endl;
    
    std::cout << func(39.2, 39) << std::endl;
    
    std::cout << pythaogrean(3.0,4.0) << std::endl;
    
    return 0;
}