#include "Word.h"
#include "Document.h"
#include <string.h>

//Word::Word()
//{

//}


//Word::Word()
//{

//}

Word::Word(string& pageWord, Document*& doc)
{
    theWord = pageWord;
    addDocument(doc);
}

void Word::addDocument(Document*& doc) {
    docs.push_back(doc);
    occurrences.push_back(doc.getFrequency());
}


bool Word::operator==(const Word& w, const Word &w2)
{
    return w.theWord.compare(s2) == 0;
}
