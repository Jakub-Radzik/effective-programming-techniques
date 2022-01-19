//
// Created by Jakub Radzik on 22/12/2021.
//

#ifndef MINIPROJECT_CGAOPTIMIZER_H
#define MINIPROJECT_CGAOPTIMIZER_H

#include <iostream>
#include <vector>
#include <unistd.h>
#include "CGAIndividual/CGAIndividual.h"

class CGAOptimizer {
public:
    CGAOptimizer(int populationSize, double mutationProbability, double crossoverProbability, int iGenotypeSize);

    ~CGAOptimizer();

    void vInitialize();

    void vRunIteration();

    CGAIndividual *vSelectParent();

    std::tuple<CGAIndividual *, CGAIndividual *> vCrossover(CGAIndividual &parent1, CGAIndividual &parent2);

    void vMutate(CGAIndividual &individual);

    const std::vector<CGAIndividual *> &getPopulation() const;

private:
    int i_population_size;
    double d_crossover_probability;
    double d_mutation_probability;
    int i_genotype_size;
    std::vector<CGAIndividual *> v_population;
};

#endif //MINIPROJECT_CGAOPTIMIZER_H

