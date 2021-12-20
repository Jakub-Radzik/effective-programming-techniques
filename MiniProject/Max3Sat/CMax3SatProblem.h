//
// Created by Jakub Radzik on 20/12/2021.
//

#ifndef MINIPROJECT_CMAX3SATPROBLEM_H
#define MINIPROJECT_CMAX3SATPROBLEM_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <math.h>
#include "Node.h"

class CMax3SatProblem {
public:
    CMax3SatProblem(std::string fileName);

    int solve();

    ~CMax3SatProblem();

private:
    void load();
    void compute();
//    bool isSatisfiable();
    bool isVectorContainsVariable(const std::string& iVariable);
    void checkSentences();

    std::string *parseSentenceIntoTable(std::string sentence);
    void printTable();

    std::string s_file_name;
    //TODO: sentences should be a vector of objects
    //TODO: each object should have a reference to nodes
    std::vector<std::string *> i_vector_of_sentences;

    std::vector<Node*> n_vector_of_variables;

    int i_sentences_count;
    int i_variables_count;
    int i_number_of_variables_in_sentence;
    int i_max_number_of_fulfilled_sentences;
};


#endif //MINIPROJECT_CMAX3SATPROBLEM_H
