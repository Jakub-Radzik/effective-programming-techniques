//
// Created by Jakub Radzik on 22/12/2021.
//

#ifndef MINIPROJECT_CGAINDIVIDUAL_H
#define MINIPROJECT_CGAINDIVIDUAL_H

#include <vector>

class CGAIndividual {
public:
    CGAIndividual(int iGenotypeSize);

    CGAIndividual(CGAIndividual &other);

    ~CGAIndividual();

    void v_crossover(CGAIndividual &parent1, CGAIndividual &parent2);

    void v_mutation(int iMutationProbability);

    double v_fitness();

    void v_randomize();

private:
    std::vector<bool> genotype;
    int i_genotype_size;
};


#endif //MINIPROJECT_CGAINDIVIDUAL_H