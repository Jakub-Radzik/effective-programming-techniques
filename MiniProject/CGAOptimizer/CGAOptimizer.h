//
// Created by Jakub Radzik on 22/12/2021.
//

#ifndef MINIPROJECT_CGAOPTIMIZER_H
#define MINIPROJECT_CGAOPTIMIZER_H


#include <vector>
#include "CGAIndividual/CGAIndividual.h"

template<typename T>
class CGAOptimizer {
public:
    CGAOptimizer(int populationSize, double mutationProbability, double crossoverProbability);

    ~CGAOptimizer();

    void v_initialize();

    void v_run_iteration();

    T v_select_parent();

    std::tuple<T, T> v_crossover(T &parent1, T &parent2);

    void v_mutate(T &individual);

private:

    int i_population_size;
    int i_crossover_probability;
    int i_mutation_probability;
    int i_genotype_size;
    std::vector<T*> population;
};

#endif //MINIPROJECT_CGAOPTIMIZER_H

template<typename T>
CGAOptimizer<T>::CGAOptimizer(int populationSize, double mutationProbability, double crossoverProbability) {
    i_population_size = populationSize;
    i_mutation_probability = mutationProbability;
    i_crossover_probability = crossoverProbability;
    population = std::vector<CGAIndividual*>();
}

template<typename T>
CGAOptimizer<T>::~CGAOptimizer() {
    for (int i = 0; i < i_population_size; i++) {
        delete population[i];
    }
}

template<typename T>
void CGAOptimizer<T>::v_initialize() {
    for (int i = 0; i < i_population_size; i++) {
        population.push_back(new T(i_genotype_size));
    }

    for (int i = 0; i < i_population_size; i++) {
        population[i]->randomize();
    }
}

template<typename T>
void CGAOptimizer<T>::v_run_iteration() {
    std::vector<T> new_population = std::vector<T>();
    T parent1;
    T parent2;
    T child1;
    T child2;

    while (new_population.size() < i_population_size) {
        parent1 = v_select_parent();
        while (parent1 == parent2) {
            parent2 = v_select_parent();
        }
        std::tie(child1, child2) = v_crossover(parent1, parent2);
        v_mutate(child1);
        v_mutate(child2);
        new_population.push_back(child1);
        new_population.push_back(child2);
    }
    population = std::move(new_population);
}

template<typename T>
T CGAOptimizer<T>::v_select_parent() {
    return population[rand() % i_population_size];
}

template<typename T>
std::tuple<T, T>
CGAOptimizer<T>::v_crossover(T &parent1, T &parent2) {

}

template<>
std::tuple<CGAIndividual, CGAIndividual>
CGAOptimizer<CGAIndividual>::v_crossover(CGAIndividual &parent1, CGAIndividual &parent2) {
    if (rand() % 100 < i_crossover_probability) {
        CGAIndividual child1(i_genotype_size);
        CGAIndividual child2(i_genotype_size);

        child1.v_crossover(parent1, parent2);
        child2.v_crossover(parent1, parent2);
        return std::make_tuple(child1, child2);
    } else {
        CGAIndividual child1(parent1);
        CGAIndividual child2(parent2);
        return std::make_tuple(child1, child2);
    }
}

template<typename T>
void CGAOptimizer<T>::v_mutate(T &individual) {
    individual.v_mutation(i_mutation_probability);
}
