#include <iostream>

#include "Max3Sat/CMax3SatProblem.h"
#include "CGAOptimizer/CGAOptimizer.h"

void Max3Sat() {
    CMax3SatProblem problem("m3s_50_0.txt");
    std::cout << "Result: " << problem.solve() << std::endl;
}

int main() {
//    Max3Sat();

    CGAOptimizer<CGAIndividual> optimizer(100, 0.3, 0.6);


    return 0;
}
