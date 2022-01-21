//
// Created by Jakub Radzik on 31/12/2021.
//

#include "CGAOptimizer.h"

CGAOptimizer::CGAOptimizer(int populationSize, double mutationProbability, double crossoverProbability,
                           int iGenotypeSize) {
    i_population_size = populationSize;
    d_mutation_probability = mutationProbability;
    d_crossover_probability = crossoverProbability;
    i_genotype_size = iGenotypeSize;
}

CGAOptimizer::~CGAOptimizer() {
    for (int i = 0; i < i_population_size; ++i) {
        delete v_population[i];
    }
}

void CGAOptimizer::vInitialize() {
    std::cout << "Initializing v_population" << std::endl;

    for (int i = 0; i < i_population_size; i++) {
        v_population.push_back(new CGAIndividual(i_genotype_size));
    }

    for (int i = 0; i < i_population_size; i++) {
        v_population[i]->vRandomize();
    }
}

void CGAOptimizer::vRunIteration() {
    std::vector new_population = std::vector<CGAIndividual *>();
    CGAIndividual *cga_parent_1;
    CGAIndividual *cga_parent_2;
    CGAIndividual *cga_child_1;
    CGAIndividual *cga_child_2;

    while (new_population.size() < i_population_size) {
        cga_parent_1 = vSelectParent();
        do {
            cga_parent_2 = vSelectParent();
        } while (cga_parent_1 == cga_parent_2);

        std::tie(cga_child_1, cga_child_2) = tCrossover(*cga_parent_1, *cga_parent_2);
        vMutate(*cga_child_1);
        vMutate(*cga_child_2);

        new_population.push_back(cga_child_1);
        new_population.push_back(cga_child_2);
    }

    for (int i = 0; i < i_population_size; ++i) {
        delete v_population[i];
    }

    v_population = std::move(new_population);


    cga_child_1 = nullptr;
    cga_child_2 = nullptr;
    cga_parent_1 = nullptr;
    cga_parent_2 = nullptr;

    delete cga_child_1;
    delete cga_child_2;
    delete cga_parent_1;
    delete cga_parent_2;
}

CGAIndividual *CGAOptimizer::vSelectParent() {
    CGAIndividual *possible_parent1 = v_population[rand() % i_population_size];
    CGAIndividual *possible_parent2;
    do {
        possible_parent2 = v_population[rand() % i_population_size];
    } while (possible_parent1 == possible_parent2);

    if (possible_parent1->iFitness() >= possible_parent2->iFitness())
        return possible_parent1;
    return possible_parent2;
}

std::tuple<CGAIndividual *, CGAIndividual *>
CGAOptimizer::tCrossover(CGAIndividual &cgaParent1, CGAIndividual &cgaParent2) const {
    if (((double) (rand() % 100) / 100) < d_crossover_probability) {
        CGAIndividual *cga_child1 = new CGAIndividual(i_genotype_size);
        CGAIndividual *cga_child2 = new CGAIndividual(i_genotype_size);

        cga_child1->vCrossover(cgaParent1, cgaParent2);
        cga_child2->vCrossover(cgaParent1, cgaParent2);

        std::tuple<CGAIndividual *, CGAIndividual *> t_children = std::make_tuple(cga_child1, cga_child2);

        cga_child1 = nullptr;
        cga_child2 = nullptr;

        delete cga_child1;
        delete cga_child2;

        return t_children;
    }
    return std::make_tuple(new CGAIndividual(cgaParent1), new CGAIndividual(cgaParent2));
}

void CGAOptimizer::vMutate(CGAIndividual &cgaIndividual) const {
    cgaIndividual.vMutation(d_mutation_probability);
}

const std::vector<CGAIndividual *> &CGAOptimizer::getPopulation() const {
    return v_population;
}
