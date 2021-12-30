//
// Created by Jakub Radzik on 22/12/2021.
//

#include "CGAIndividual.h"

CGAIndividual::CGAIndividual(int iGenotypeSize) {
    i_genotype_size = iGenotypeSize;
    s_name = "";
    genotype = std::vector<bool>(iGenotypeSize);
}

CGAIndividual::CGAIndividual(int iGenotypeSize, std::string sName) {
    i_genotype_size = iGenotypeSize;
    s_name = sName;
    genotype = std::vector<bool>(iGenotypeSize);
}

CGAIndividual::CGAIndividual(CGAIndividual &other) {
    i_genotype_size = other.i_genotype_size;
    s_name = other.s_name;
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
        if (((double)(rand() % 100) / 100) < iMutationProbability) {
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

const std::string &CGAIndividual::getSName() const {
    return s_name;
}

void CGAIndividual::setSName(const std::string &sName) {
    s_name = sName;
}

std::string CGAIndividual::s_genotype_to_string() {
    std::string s_genotype = "";
    for (int i = 0; i < i_genotype_size; i++) {
        s_genotype += std::to_string(genotype[i]);
    }
    return s_genotype;
}

