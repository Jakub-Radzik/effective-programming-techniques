//
// Created by Jakub Radzik on 22/12/2021.
//

#include "CGAIndividual.h"

CGAIndividual::CGAIndividual(int iGenotypeSize) {
    i_genotype_size = iGenotypeSize;
    genotype = std::vector<bool>(iGenotypeSize);
}

CGAIndividual::CGAIndividual(CGAIndividual &other) {
    i_genotype_size = other.i_genotype_size;
    genotype = other.genotype;
}


void CGAIndividual::v_crossover(CGAIndividual &parent1, CGAIndividual &parent2) {
    for (int i = 0; i < i_genotype_size; i++) {
        if (rand() % 2 == 0) {
            this->genotype[i] = parent1.genotype[i];
        } else {
            this->genotype[i] = parent2.genotype[i];
        }
    }
}

double CGAIndividual::v_fitness() {
    double i_fitness = 0;
    for (int i = 0; i < i_genotype_size; i++) {
        if (genotype[i]) {
            i_fitness++;
        }
    }
    return (i_fitness / i_genotype_size) * 100;
}

void CGAIndividual::v_mutation(double iMutationProbability) {
    for (int i = 0; i < i_genotype_size; i++) {
        if (rand() % 100 < iMutationProbability) {
            genotype[i] = !genotype[i];
        }
    }
}

void CGAIndividual::v_randomize() {
    for (int i = 0; i < i_genotype_size; i++) {
        genotype[i] = rand() % 2;
    }
}

CGAIndividual::~CGAIndividual() {
    genotype.clear();
}

