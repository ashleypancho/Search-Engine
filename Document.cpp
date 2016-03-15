#include "Document.h"
#include <iostream>

// Document::Document()
// {
//
// }

Document::Document(vector<string>& singleDoc)
{
    if(singleDoc.size() == 3)
    {
        docTitle = singleDoc[0];
        pageNumber = singleDoc[1];
        text = singleDoc[2];
    }
}

// Document::~Document()
// {
//
// }

int Document::search(string word){
    int frequency = 0;
    size_t found = text.find(word);
    while(found != string::npos) {
        frequency++;
        found = text.find(word, found+1);
    }
    return frequency;
}

string Document::getPageNumber() const {
    return pageNumber;
}

string Document::getText() const {
    return text;
}

ostream& operator<<(ostream& output, const Document& d)
{
    output << "Page: " << d.getPageNumber() << endl;
    output << d.getText() << endl;
    return output;
}
