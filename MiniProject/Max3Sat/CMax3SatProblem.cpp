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
    i_vector_of_sentences = std::vector<std::string *>();
}

CMax3SatProblem::~CMax3SatProblem() {
    s_file_name = "";
    i_vector_of_sentences.clear();
}

int CMax3SatProblem::solve() {
    this->load();
    this->compute();
    return i_max_number_of_fulfilled_sentences;
}

void CMax3SatProblem::load() {
    std::string myText;
    std::ifstream MyReadFile(s_file_name);
    while (getline(MyReadFile, myText)) {
        i_vector_of_sentences.push_back(parseSentenceIntoTable(myText));
        i_sentences_count++;
    }
    MyReadFile.close();

    std::cout << "Loaded " << i_sentences_count << " sentences" << std::endl;

    //init map with false
    std::string variable;
    for (int i = 0; i < i_sentences_count; i++) {
        for (int j = 0; j < i_number_of_variables_in_sentence; j++) {

            if (i_vector_of_sentences[i][j].starts_with("-")) {
                variable = i_vector_of_sentences[i][j].substr(1);
            } else {
                variable = i_vector_of_sentences[i][j];
            }

            if (!isVectorContainsVariable(variable)) {
                n_vector_of_variables.push_back(new Node(variable, false));
                i_variables_count++;
            }
        }
    }

    std::cout << "Contains " << i_variables_count << " variables" << std::endl;

}

bool CMax3SatProblem::isVectorContainsVariable(const std::string &iVariable) {
    for (int i = 0; i < i_variables_count; i++) {
        if (n_vector_of_variables[i]->getIVariable() == iVariable) {
            return true;
        }
    }
    return false;
}

void CMax3SatProblem::compute() {
    int i_number_of_possible_solutions = pow(2, i_variables_count);
    std::cout << "Number of possible solutions: " << i_number_of_possible_solutions << std::endl;
    std::cout << "Start computing..." << std::endl;

    int i_global_state = 0;
    int i_temporary_state = 0;

    for (int i = 0; i < i_variables_count; i++) {

        //set variables to global state
        for (int j = i_variables_count - 1; j >= 0; j--) {
            n_vector_of_variables[j]->setBValue(i_temporary_state & 1);
            i_temporary_state = i_temporary_state >> 1;
        }

        checkSentences();

        //reset variables
        for (int j = 0; j < i_variables_count; j++) {
            n_vector_of_variables[j]->setBValue(false);
        }

        //prepare for next iteration
        i_global_state++;
        i_temporary_state = i_global_state;
    }
}

void CMax3SatProblem::checkSentences() {
}

std::string *CMax3SatProblem::parseSentenceIntoTable(std::string sentence) {
    sentence = sentence.substr(2, sentence.length() - 3);// remove parentheses

    std::string *table = new std::string[3];
    int i = 0;
    std::string word = "";

    for (auto x: sentence) {
        if (x == ' ') {
            if (word != "") {
                table[i++] = word;
            }
            word = "";
        } else {
            word = word + x;
        }
    }
    return table;
}

void CMax3SatProblem::printTable() {
    for (auto x: i_vector_of_sentences) {
        for (int i = 0; i < 3; i++) {
            std::cout << x[i] << " ";
        }
        std::cout << std::endl;
    }
}



