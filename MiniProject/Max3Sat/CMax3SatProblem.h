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
#include "Sentence.h"

class CMax3SatProblem {
public:
    CMax3SatProblem(std::string fileName);
    int solve();
    ~CMax3SatProblem();

private:
    void load();
    void compute();
    int isVectorContainsVariable(const int& iVariable);
    void checkSentences();
    Sentence *parseSentenceIntoTable(std::string sSentence);

    std::vector<Sentence *> vector_of_sentences;
    std::vector<Node*> vector_of_nodes_variables;

    std::string s_file_name;
    int i_sentences_count;
    int i_variables_count;
    int i_number_of_variables_in_sentence;
    int i_max_number_of_fulfilled_sentences;
};


#endif //MINIPROJECT_CMAX3SATPROBLEM_H

