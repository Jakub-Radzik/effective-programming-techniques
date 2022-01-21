//
// Created by Jakub Radzik on 20/12/2021.
//

#include "CMax3SatProblem.h"

#include <utility>

CMax3SatProblem::CMax3SatProblem(std::string sFileName) {
    s_file_name = std::move(sFileName);
    i_sentences_count = 0;
    i_variables_count = 0;
    i_max_number_of_fulfilled_sentences = 0;
    i_number_of_variables_in_sentence = I_NUMBER_OF_VARIABLES_IN_SENTENCE;
    vector_of_sentences = std::vector<Sentence *>();
    vector_of_nodes_variables = std::vector<Node *>();
    cgaIndividual_best_solution = nullptr;

    d_cross_over_probability = D_CROSS_OVER_PROBABILITY;
    d_mutation_probability = D_MUTATION_PROBABILITY;
    i_population_size = I_POPULATION_SIZE;
    i_max_number_of_generations = I_MAX_NUMBER_OF_GENERATIONS;
}

CMax3SatProblem::~CMax3SatProblem() {
    s_file_name = "";

    delete cga_optimizer;

    for (int i = 0; i < i_variables_count; ++i) {
        delete vector_of_nodes_variables[i];
    }

    for (int i = 0; i < i_sentences_count; i++) {
        delete vector_of_sentences[i];
    }

    delete cgaIndividual_best_solution;
}


void CMax3SatProblem::vLoad() {
    std::cout << "Loading... " << std::endl;

    // read file line by line
    std::string s_line_in_file;
    std::ifstream ifstream_file(s_file_name);
    while (getline(ifstream_file, s_line_in_file)) {
        // process single string line into Sentence Object
        vector_of_sentences.push_back(parseStringSentenceIntoObjectSentence(s_line_in_file));
        i_sentences_count++;
    }
    ifstream_file.close();

    std::cout << "Loaded " << i_sentences_count << " sentences" << std::endl;

    int i_variable_in_sentence;
    int i_position_of_variable;
    std::cout << "Removing repeats..." << std::endl;

    // iterate over sentences
    for (int i = 0; i < i_sentences_count; i++) {

        // iterate over variables of sentence (we don't care about sign for now)
        for (int j = 0; j < i_number_of_variables_in_sentence; j++) {

            // get variable and check whether it exist in vector of variables (sign is not important here)
            i_variable_in_sentence = vector_of_sentences[i]->iGetVariable(j);
            i_position_of_variable = iPositionOfVariableInVector(i_variable_in_sentence);

            // if variable is not present in vector
            if (i_position_of_variable == -1) {
                vector_of_nodes_variables.push_back(vector_of_sentences[i]->nGetNodeAt(j));
                i_variables_count++;
            } else {
                // flagged variables with the same value should point at the same node
                vector_of_sentences[i]->vReplaceNodeAt(j, vector_of_nodes_variables[i_position_of_variable]);
            }
        }
    }

    std::cout << "Contains " << i_variables_count << " variables" << std::endl;
    cga_optimizer = new CGAOptimizer(i_population_size, d_mutation_probability, d_cross_over_probability,
                                     i_variables_count);
}

int CMax3SatProblem::iPositionOfVariableInVector(const int &iVariable) {
    for (int i = 0; i < i_variables_count; i++) {
        if (vector_of_nodes_variables[i]->getIVariable() == iVariable) {
            return i;
        }
    }
    // return -1 if variable does not exist in vector
    return -1;
}

int CMax3SatProblem::iSolve() {
    vLoad();

    CGAIndividual *individual;
    cga_optimizer->vInitialize();

    // iterate over k number of populations
    for (int k = 0; k < i_max_number_of_generations; k++) {

        // iterate over v_population
        for (int i = 0; i < i_population_size; i++) {
            individual = cga_optimizer->getPopulation()[i];

            // iterate over member v_genotype
            for (int j = 0; j < i_variables_count; ++j) {
                // set genotype to variables
                vector_of_nodes_variables[j]->setBValue(individual->getGenotype()[j]);
            }

            // compute fitness of current setting and set it to individual
            individual->vSetFitness(iCompute(*individual));

            // find max fitness and save copy of best individual
            if (individual->iFitness() > i_max_number_of_fulfilled_sentences) {
                i_max_number_of_fulfilled_sentences = individual->iFitness();

                if(cgaIndividual_best_solution != nullptr) {
                    delete cgaIndividual_best_solution;
                }

                cgaIndividual_best_solution = new CGAIndividual(*individual);
            }
        }
        cga_optimizer->vRunIteration();
    }

    individual = nullptr;
    delete individual;

    std::cout << "Spełniono sentencji: " << i_max_number_of_fulfilled_sentences<< " z "<< i_sentences_count << std::endl;
    std::cout << "Jakość: " << 100 * ((float) i_max_number_of_fulfilled_sentences / (float) i_sentences_count) << " %"
              << std::endl;
    for (int i = 0; i < i_variables_count; ++i) {
        std::cout << "[" << vector_of_nodes_variables[i]->getIVariable() << "=" << cgaIndividual_best_solution->getGenotype()[i] << "] ";
    }
    std::cout<<std::endl;

    return i_max_number_of_fulfilled_sentences;
}

int CMax3SatProblem::iCompute(CGAIndividual &cgaIndividual) {
    int i_temp_number_of_fulfilled_sentences = 0;
    for (int i = 0; i < i_sentences_count; i++) {
        if (vector_of_sentences[i]->bResolveSentence()) {
            i_temp_number_of_fulfilled_sentences++;
        }
    }

    return i_temp_number_of_fulfilled_sentences;
}

Sentence *CMax3SatProblem::parseStringSentenceIntoObjectSentence(std::string sSentence) const {
    sSentence = sSentence.substr(2, sSentence.length() - 3);// remove parentheses

    Sentence *s_sentence = new Sentence(i_number_of_variables_in_sentence);

    std::string word;
    bool bWordIsNegative;
    std::string value;
    int i_variable;

    for (auto x: sSentence) {
        if (x == ' ') {
            if (word != "") {
                bWordIsNegative = word.starts_with("-");
                value = bWordIsNegative ? word.substr(1, word.length()) : word;
                std::istringstream(value) >> i_variable;
                s_sentence->vAddVariable(new Node(i_variable, false), bWordIsNegative);
            }
            word = "";
        } else {
            word = word + x;
        }
    }
    return s_sentence;
}


void CMax3SatProblem::vSetPopulationSize(int iPopulationSize) {
    i_population_size = iPopulationSize;
}

void CMax3SatProblem::vSetCrossOverProbability(double dCrossOverProbability) {
    d_cross_over_probability = dCrossOverProbability;
}

void CMax3SatProblem::vSetMutationProbability(double dMutationProbability) {
    d_mutation_probability = dMutationProbability;
}

void CMax3SatProblem::vSetMaxNumberOfGenerations(int iMaxNumberOfGenerations) {
    i_max_number_of_generations = iMaxNumberOfGenerations;
}

