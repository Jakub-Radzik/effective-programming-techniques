//
// Created by Jakub Radzik on 22/12/2021.
//

#include "CGAIndividual.h"

CGAIndividual::CGAIndividual(int iGenotypeSize) {
    i_genotype_size = iGenotypeSize;
    bv_genotype = std::vector<bool>(iGenotypeSize);
}

CGAIndividual::CGAIndividual(CGAIndividual &other) {
    i_genotype_size = other.i_genotype_size;
    bv_genotype = other.bv_genotype;
}


void CGAIndividual::v_crossover(CGAIndividual &parent1, CGAIndividual &parent2) {
    for (int i = 0; i < i_genotype_size; i++) {
        if (rand() % 2 == 0) {
            this->bv_genotype[i] = parent1.bv_genotype[i];
        } else {
            this->bv_genotype[i] = parent2.bv_genotype[i];
        }
    }
}

double CGAIndividual::fitness() {
    return d_fitness;
}

void CGAIndividual::setDFitness(double dFitness) {
    d_fitness = dFitness;
}

void CGAIndividual::v_mutation(double iMutationProbability) {
    for (int i = 0; i < i_genotype_size; i++) {
        if (((double) (rand() % 100) / 100) < iMutationProbability) {
            bv_genotype[i] = !bv_genotype[i];
        }
    }
}

void CGAIndividual::v_randomize() {
    for (int i = 0; i < i_genotype_size; i++) {
        bv_genotype[i] = rand() % 2;
    }
}

CGAIndividual::~CGAIndividual() {
    bv_genotype.clear();
}

const std::vector<bool> &CGAIndividual::getGenotype() const {
    return bv_genotype;
}