#include <iostream>

#include "Max3Sat/CMax3SatProblem.h"

void Max3Sat() {
    CMax3SatProblem problem("m3s_50_0.txt");
    std::cout << "Result: " << problem.solve() << std::endl;
}

int main() {
    Max3Sat();


    return 0;
}
