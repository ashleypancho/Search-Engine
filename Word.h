#ifndef WORD_H
#define WORD_H

#include <string>
#include <vector>
#include <iostream>

#include "Document.h"

using namespace std;

class Word
{
private:
    string theWord;
    vector<Document*> docs;
    vector<int> occurrences;
public:
//    Word();
    Word(string, Document*);
    // ~Word();
    void addDocument(Document*&);
    bool operator==(const Word& w);
    void print();
    // friend ostream& operator<<(ostream& output, const Word& w);
};

#endif // WORD_H
