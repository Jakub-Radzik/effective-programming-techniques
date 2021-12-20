#include <iostream>

#include "Max3Sat/CMax3SatProblem.h"


int main() {
    CMax3SatProblem problem("m3s_50_0.txt");
    std::cout<<problem.solve()<<std::endl;


    return 0;
}
