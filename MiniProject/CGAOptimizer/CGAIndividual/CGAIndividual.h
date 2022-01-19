//
// Created by Jakub Radzik on 22/12/2021.
//

#ifndef MINIPROJECT_CGAINDIVIDUAL_H
#define MINIPROJECT_CGAINDIVIDUAL_H

#include <vector>
#include <string>
#include <iostream>

class CGAIndividual {
public:
    CGAIndividual(int iGenotypeSize);

    CGAIndividual(CGAIndividual &other);

    ~CGAIndividual();

    void vCrossover(CGAIndividual &parent1, CGAIndividual &parent2);

    void vMutation(double iMutationProbability);

    double dFitness();

    void vRandomize();

    const std::vector<bool> &getGenotype() const;

    void vSetFitness(double dFitness);

private:
    std::vector<bool> v_genotype;
    double d_fitness;
    int i_genotype_size;
};


#endif //MINIPROJECT_CGAINDIVIDUAL_H
