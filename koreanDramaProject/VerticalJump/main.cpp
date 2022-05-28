#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <iomanip>
#include <queue>
#include <cmath>

#define GRAVITY 9.81

template <typename T>
T potentialEnergy(T height, T mass){
    // remember height has to be in meters and mass has to be in kg
    return (mass*GRAVITY*height);
}

double poundToKg(double pound){
    return pound*0.453592;
}

double kgToPound(double kg){
    return kg*2.20462;
}

double inchesToMeters(double inches){
    return inches*0.0254;
}

double metersToInches(double meters){
    return meters*39.3701;
}

double squat(double PE, double height){
    return (PE / (GRAVITY*height));
}

int main(){
    
    std::cout << potentialEnergy(0.762,72.5748) << " joules" << std::endl;
    std::cout << "Let's say when I squat, the weights travel a total of 17 inches or 0.4318 meters" << std::endl;
    std::cout << "The amount of mass I have to squat such that the energy required is the same as the required energy to jump 30 inches high is: " << kgToPound(squat(potentialEnergy(inchesToMeters(30.0),poundToKg(160.0)),inchesToMeters(17))) << " lbs" <<  std::endl;
    
    return 0;
}

// math logic:
// to jump 30" from the ground...and i'm 160lb...which converted to kg is about 72.5748kg
// 30 inches to meters is 0.762 meters
// E = mgh; 
// 1lb = 0.453592 kg
// 1 inch is 0.0254 m