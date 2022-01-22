//
// Created by Jakub Radzik on 22/12/2021.
//

#ifndef MINIPROJECT_CGAINDIVIDUAL_H
#define MINIPROJECT_CGAINDIVIDUAL_H

#include <vector>
#include <string>
#include <iostream>
#include "../../Max3Sat/Sentence.h"

class CGAIndividual {
public:
    CGAIndividual(int iGenotypeSize);

    CGAIndividual(CGAIndividual &other);

    ~CGAIndividual();

    void vCrossover(CGAIndividual &parent1, CGAIndividual &parent2);

    void vMutation(double iMutationProbability);

    int iFitness() const;

    void vRandomize();

    const std::vector<bool> &getGenotype() const;

    void vSetFitness(int iFitness);

    // modyfikacja
    Sentence *getSRandomSentence() const;

    void setSRandomSentence(Sentence *sRandomSentence);

    void vOptimizeGenotype();

private:
    std::vector<bool> v_genotype;
    int i_fitness;
    int i_genotype_size;
    Sentence *s_random_sentence;
};


#endif //MINIPROJECT_CGAINDIVIDUAL_H
