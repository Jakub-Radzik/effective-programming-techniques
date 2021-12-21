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
}

CMax3SatProblem::~CMax3SatProblem() {
    s_file_name = "";

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
    unsigned long long int i_number_of_possible_solutions = pow(2, i_variables_count);
    std::cout << "Start computing... " << std::endl;
    std::cout << "Number of solutions: " << i_number_of_possible_solutions << std::endl;

    int i_global_state = 0;
    int i_temporary_state = 0;

    for (int i = 0;  i < i_number_of_possible_solutions && i_max_number_of_fulfilled_sentences != i_sentences_count; i++) {
        std::cout << "Checking solution: " << i + 1 << "/" << i_number_of_possible_solutions;
        std::cout << " [" << std::bitset<6 * sizeof(i_variables_count)>(i_global_state) << "]";

        for (int j = i_variables_count - 1; j >= 0; j--) {
            vector_of_nodes_variables[j]->setBValue(i_temporary_state & 1);
            i_temporary_state = i_temporary_state >> 1;
        }

        checkSentences();

        //reset variables
        for (int j = 0; j < i_variables_count; j++) {
            vector_of_nodes_variables[j]->setBValue(false);
        }

        //prepare for next iteration
        i_global_state++;
        i_temporary_state = i_global_state;

    }
}

void CMax3SatProblem::checkSentences() {
    int i_temp_number_of_fulfilled_sentences = 0;
    for (int i = 0; i < i_sentences_count; i++) {
        if (vector_of_sentences[i]->resolveSentence()) {
            i_temp_number_of_fulfilled_sentences++;
        }
    }

    std::cout << " - " << i_temp_number_of_fulfilled_sentences << " of " << i_sentences_count
              << " sentences are fulfilled" << std::endl;
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

