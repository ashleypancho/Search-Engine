#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Document
{
private:
    string docTitle;
    string pageNumber;
    string text;

public:
    //Document();
    Document(vector<string>&);
    // ~Document();
    int search(string word);
    string getPageNumber() const;
    string getText() const;
    friend ostream& operator<<(ostream& output, const Document& d);
};

#endif // DOCUMENT_H
