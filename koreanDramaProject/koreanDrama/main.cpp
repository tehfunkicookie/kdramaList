#include <vector>
#include <array>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

#define PI 3.1415

int main(){
    
    double r;
    std::cout << "radius: ";
    std::cin >> r;
    
    std::cout << PI*r*r << std::endl;
    
    return 0;
}