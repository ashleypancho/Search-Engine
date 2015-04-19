#include "Document.h"
#include <iostream>

// Document::Document()
// {
//
// }

Document::Document(vector<string>& singleDoc)
{
    if(singleDoc.size() == 2)
    {
        pageNumber = stoi(singleDoc[0],nullptr,10);
        text = singleDoc[2];
    }
}

Document::~Document()
{

}

int Document::search(string word){
    int frequency;
    size_t found = text.find(word);
    while(found != string::npos) {
        frequency++;
        found = text.find(word, found+1);
    }
    return frequency;
}

int Document::getPageNumber() const {
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
