#include <iostream>

#include "Max3Sat/CMax3SatProblem.h"
#include "CGAOptimizer/CGAOptimizer.h"

void Max3Sat() {
    CMax3SatProblem problem("m3s_50_0.txt");
    std::cout << "Result: " << problem.solve() << std::endl;
}

int main() {
//    Max3Sat();

    CGAOptimizer optimizer(100, 0.3, 0.5);
    optimizer.v_initialize();
    optimizer.v_run_iteration();


    return 0;
}
