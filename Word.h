#ifndef WORD_H
#define WORD_H

#include <string>
#include <vector>

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
    Word(string&, Document*&);
    void addDocument(Document*&);
    bool operator==(const Word& w, const Word &w2);
};

#endif // WORD_H
