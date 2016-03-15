#include "Word.h"
#include "Document.h"
#include <string.h>

//Word::Word()
//{

//}


//Word::Word()
//{

//}

Word::Word(string pageWord, Document* doc)
{
    theWord = pageWord;
    addDocument(doc);
}

// Word::~Word()
// {
//     for(int i = 0; i < docs.size(); i++)
//     {
//         delete docs[i];
//     }
//     docs.clear();
// }

void Word::addDocument(Document*& doc) {
    docs.push_back(doc);
    occurrences.push_back(doc->search(theWord));
}


bool Word::operator==(const Word& w)
{
    return theWord == w.theWord;
}

// ostream& operator<<(ostream& output, const Word& w)
// {
//     output << "Word: " << w.theWord << endl;
//     for(int i = 0; i < 5; i++) {
//         output << *w.docs[i] << endl;
//     }
//     return output;
// }

void Word::print()
{
    cout << "Word: " << theWord << endl;
    for(int i = 0; i < 5; i++) {
        cout << docs[i] << endl;
    }
}
