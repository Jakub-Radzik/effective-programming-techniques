//
// Created by Jakub Radzik on 20/12/2021.
//

#ifndef MINIPROJECT_CMAX3SATPROBLEM_H
#define MINIPROJECT_CMAX3SATPROBLEM_H

#define D_CROSS_OVER_PROBABILITY 0.3
#define D_MUTATION_PROBABILITY 0.5
#define I_POPULATION_SIZE 100
#define I_MAX_NUMBER_OF_GENERATIONS 100
#define I_NUMBER_OF_VARIABLES_IN_SENTENCE 3

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Node.h"
#include "Sentence.h"
#include "../CGAOptimizer/CGAOptimizer.h"

class CMax3SatProblem {
public:
    explicit CMax3SatProblem(std::string sFileName);

    ~CMax3SatProblem();

    int iSolve();

    // setters
    void vSetPopulationSize(int iPopulationSize);

    void vSetMaxNumberOfGenerations(int iMaxNumberOfGenerations);

    void vSetCrossOverProbability(double dCrossOverProbability);

    void vSetMutationProbability(double dMutationProbability);


private:
    void vLoad();

    int iCompute(CGAIndividual &cgaIndividual);

    int iPositionOfVariableInVector(const int &iVariable);

    Sentence *sGetRandomSentence();

    Sentence *parseStringSentenceIntoObjectSentence(std::string sSentence) const;

    CGAOptimizer *cga_optimizer;

    std::vector<Sentence *> vector_of_sentences;
    std::vector<Node *> vector_of_nodes_variables;

    std::string s_file_name;
    int i_sentences_count;
    int i_variables_count;
    int i_number_of_variables_in_sentence;
    int i_max_number_of_fulfilled_sentences;
    CGAIndividual* cgaIndividual_best_solution;

    int i_population_size;
    double d_cross_over_probability;
    double d_mutation_probability;
    int i_max_number_of_generations;
};


#endif //MINIPROJECT_CMAX3SATPROBLEM_H

