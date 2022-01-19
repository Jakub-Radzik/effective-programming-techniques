#include <iostream>

#include "Max3Sat/CMax3SatProblem.h"

// KONWENCJA NAZEWNICTWA:
// Pola klas i tymczasowe zmienne: type_name_of_variable;
// Metody: typeNameOfMethod(params)
// Parametry metod: typeNameOfVariable

void Max3Sat() {
    CMax3SatProblem problem("m3s_50_1.txt");
    problem.vSetCrossOverProbability(0.5);
    problem.vSetMutationProbability(0.5);
    problem.vSetMaxNumberOfGenerations(1000);
    problem.vSetPopulationSize(100);
    problem.iSolve();
}

int main() {
    std::cout<<"Max3Sat"<<std::endl;
    Max3Sat();


    return 0;
}
