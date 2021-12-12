//
// Created by Jakub Radzik on 12/12/2021.
//

#ifndef LISTA5_CREFCOUNTER_H
#define LISTA5_CREFCOUNTER_H

class CRefCounter {
public:
    CRefCounter() { i_count = 0; }

    int iAdd() { return ++i_count; }

    int iDec() { return --i_count; }

    int iGet() const { return i_count; }
private:
    int i_count;
};

#endif //LISTA5_CREFCOUNTER_H
