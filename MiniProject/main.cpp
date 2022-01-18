#include <iostream>

#include "Max3Sat/CMax3SatProblem.h"

void Max3Sat() {
    CMax3SatProblem problem("m3s_50_1.txt");
    problem.setDCrossOverProbability(0.5);
    problem.setDMutationProbability(0.5);
    problem.setIMaxNumberOfGenerations(1000);
    problem.setIPopulationSize(200);
    problem.solve();
}

int main() {
    std::cout<<"Max3Sat"<<std::endl;
    Max3Sat();


    return 0;
}
