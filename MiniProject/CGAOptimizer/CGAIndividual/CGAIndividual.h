//
// Created by Jakub Radzik on 22/12/2021.
//

#ifndef MINIPROJECT_CGAINDIVIDUAL_H
#define MINIPROJECT_CGAINDIVIDUAL_H

#include <vector>
#include <string>

class CGAIndividual {
public:
    CGAIndividual(int iGenotypeSize);

    CGAIndividual(CGAIndividual &other);

    ~CGAIndividual();

    void v_crossover(CGAIndividual &parent1, CGAIndividual &parent2);

    void v_mutation(double iMutationProbability);

    double fitness();

    void v_randomize();

    std::string s_genotype_to_string();

    const std::vector<bool> &getGenotype() const;

    void setDFitness(double dFitness);

private:
    std::vector<bool> genotype;
    double d_fitness;
    int i_genotype_size;
};


#endif //MINIPROJECT_CGAINDIVIDUAL_H
