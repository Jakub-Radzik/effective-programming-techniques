//
// Created by Jakub Radzik on 20/12/2021.
//

#include "CMax3SatProblem.h"

CMax3SatProblem::CMax3SatProblem(std::string fileName) {
    s_file_name = fileName;
    i_sentences_count = 0;
    i_number_of_variables_in_sentence = 3;
    i_variables_count = 0;
    i_max_number_of_fulfilled_sentences = 0;
    vector_of_sentences = std::vector<Sentence *>();
    vector_of_nodes_variables = std::vector<Node *>();
    i_number_of_population = 100;
}

CMax3SatProblem::~CMax3SatProblem() {
    s_file_name = "";

    delete cgaOptimizer;

    for (int i = 0; i < i_variables_count; ++i) {
        delete vector_of_nodes_variables[i];
    }
    for (int i = 0; i < i_sentences_count; i++) {
        delete vector_of_sentences[i];
    }
}

int CMax3SatProblem::solve() {
    this->load();
    this->compute();
    return i_max_number_of_fulfilled_sentences;
}

void CMax3SatProblem::load() {
    std::cout << "Loading... " << std::endl;

    std::string myText;
    std::ifstream MyReadFile(s_file_name);
    while (getline(MyReadFile, myText)) {
        vector_of_sentences.push_back(parseSentenceIntoTable(myText));
        i_sentences_count++;
    }
    MyReadFile.close();

    std::cout << "Loaded " << i_sentences_count << " sentences" << std::endl;

    //init map with false
    int variable;
    int position;
    std::cout << "Removing repeats..." << std::endl;
    for (int i = 0; i < i_sentences_count; i++) {
        for (int j = 0; j < i_number_of_variables_in_sentence; j++) {

            variable = vector_of_sentences[i]->getVariable(j);
            position = isVectorContainsVariable(variable);

            if (position == -1) {
                vector_of_nodes_variables.push_back(vector_of_sentences[i]->getNodeAt(j));
                i_variables_count++;
            } else {
                vector_of_sentences[i]->replaceNodeAt(j, vector_of_nodes_variables[position]);
            }
        }
    }

    std::cout << "Contains " << i_variables_count << " variables" << std::endl;
    cgaOptimizer = new CGAOptimizer(100, 0.3, 0.5, i_variables_count);

}

int CMax3SatProblem::isVectorContainsVariable(const int &iVariable) {
    for (int i = 0; i < i_variables_count; i++) {
        if (vector_of_nodes_variables[i]->getIVariable() == iVariable) {
            return i;
        }
    }
    return -1;
}

void CMax3SatProblem::compute() {
    CGAIndividual *individual;

    int i1 = 50; //TODO: make this a const - number of generated populations

    cgaOptimizer->v_initialize();

    for (int k = 0; k < i1; k++) {
        //iterate over k number of populations

        //iterate over population
        for (int i = 0; i < i_number_of_population; i++) {
            individual = cgaOptimizer->getPopulation()[i];

            //iterate over member genotype
            for (int j = 0; j < i_variables_count; ++j) {
                vector_of_nodes_variables[j]->setBValue(individual->getGenotype()[j]);
            }

            checkSentences(*individual);
        }
        cgaOptimizer->v_run_iteration();
    }

    individual = nullptr;
    delete individual;
}

void CMax3SatProblem::checkSentences(CGAIndividual &individual) {
    int i_temp_number_of_fulfilled_sentences = 0;
    for (int i = 0; i < i_sentences_count; i++) {
        if (vector_of_sentences[i]->resolveSentence()) {
            i_temp_number_of_fulfilled_sentences++;
        }
    }


    individual.setDFitness(i_temp_number_of_fulfilled_sentences);

    //TODO: consider storing best individual object (std::copy)

    if (i_temp_number_of_fulfilled_sentences > i_max_number_of_fulfilled_sentences) {
        i_max_number_of_fulfilled_sentences = i_temp_number_of_fulfilled_sentences;
    }
}

Sentence *CMax3SatProblem::parseSentenceIntoTable(std::string sSentence) {
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
                s_sentence->addVariable(new Node(i_variable, false), bWordIsNegative);
            }
            word = "";
        } else {
            word = word + x;
        }
    }
    return s_sentence;
}

