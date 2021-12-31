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

double CGAIndividual::fitness() {
    return d_fitness;
}

void CGAIndividual::setDFitness(double dFitness) {
    d_fitness = dFitness;
}

void CGAIndividual::v_mutation(double iMutationProbability) {
    for (int i = 0; i < i_genotype_size; i++) {
        if (((double) (rand() % 100) / 100) < iMutationProbability) {
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

std::string CGAIndividual::s_genotype_to_string() {
    std::string s_genotype = "";
    for (int i = 0; i < i_genotype_size; i++) {
        s_genotype += std::to_string(genotype[i]);
    }
    return s_genotype;
}

const std::vector<bool> &CGAIndividual::getGenotype() const {
    return genotype;
}