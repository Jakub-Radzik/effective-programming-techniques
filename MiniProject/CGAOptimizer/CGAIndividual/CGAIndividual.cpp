//
// Created by Jakub Radzik on 22/12/2021.
//

#include "CGAIndividual.h"

CGAIndividual::CGAIndividual(int iGenotypeSize) {
    i_genotype_size = iGenotypeSize;
    v_genotype = std::vector<bool>(iGenotypeSize);
}

CGAIndividual::CGAIndividual(CGAIndividual &other) {
    i_genotype_size = other.i_genotype_size;
    v_genotype = other.v_genotype;
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

double CGAIndividual::dFitness() {
    return d_fitness;
}

void CGAIndividual::vSetFitness(double dFitness) {
    d_fitness = dFitness;
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