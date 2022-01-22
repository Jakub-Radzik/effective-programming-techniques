//
// Created by Jakub Radzik on 22/12/2021.
//

#include "CGAIndividual.h"

CGAIndividual::CGAIndividual(int iGenotypeSize) {
    i_genotype_size = iGenotypeSize;
    v_genotype = std::vector<bool>(iGenotypeSize);
    i_fitness = 0;
}

CGAIndividual::CGAIndividual(CGAIndividual &other) {
    i_genotype_size = other.i_genotype_size;
    v_genotype = other.v_genotype;
    i_fitness = other.i_fitness;
}

CGAIndividual::~CGAIndividual() {
    v_genotype.clear();
}

void CGAIndividual::vCrossover(CGAIndividual &parent1, CGAIndividual &parent2) {
    for (int i = 0; i < i_genotype_size; i++) {
        if (rand() % 2 == 0) {
            this->v_genotype[i] = parent1.v_genotype[i];
        } else {
            this->v_genotype[i] = parent2.v_genotype[i];
        }
    }
}

int CGAIndividual::iFitness() const {
    return i_fitness;
}

void CGAIndividual::vSetFitness(int iFitness) {
    i_fitness = iFitness;
}

void CGAIndividual::vMutation(double iMutationProbability) {
    for (int i = 0; i < i_genotype_size; i++) {
        if (((double) (rand() % 100) / 100) < iMutationProbability) {
            v_genotype[i] = !v_genotype[i];
        }
    }
}

void CGAIndividual::vRandomize() {
    for (int i = 0; i < i_genotype_size; i++) {
        v_genotype[i] = rand() % 2;
    }
}


const std::vector<bool> &CGAIndividual::getGenotype() const {
    return v_genotype;
}

Sentence *CGAIndividual::getSRandomSentence() const {
    return s_random_sentence;
}

void CGAIndividual::setSRandomSentence(Sentence *sRandomSentence) {
    s_random_sentence = sRandomSentence;
}

void CGAIndividual::vOptimizeGenotype() {
    bool isSentenceTrue = s_random_sentence->bResolveSentence();

    int i_index;
    if(!isSentenceTrue) {
        for (int i = 0; i < s_random_sentence->getIVariablesCount(); ++i) {
            i_index = s_random_sentence->iGetIndex(i);
            v_genotype[i_index] = !v_genotype[i_index];
        }
    }
}
