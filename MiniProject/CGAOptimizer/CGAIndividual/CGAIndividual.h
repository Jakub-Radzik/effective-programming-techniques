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

    CGAIndividual(int iGenotypeSize, std::string sName);

    CGAIndividual(CGAIndividual &other);

    ~CGAIndividual();

    void v_crossover(CGAIndividual &parent1, CGAIndividual &parent2);

    void v_mutation(double iMutationProbability);

    double v_fitness();

    void v_randomize();

    const std::string &getSName() const;

    void setSName(const std::string &sName);

    std::string s_genotype_to_string();

private:
    std::vector<bool> genotype;
    std::string s_name;
    int i_genotype_size;
};


#endif //MINIPROJECT_CGAINDIVIDUAL_H
