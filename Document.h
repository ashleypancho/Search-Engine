#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <vector>

using namespace std;

class Document
{
private:
    string docTitle;
    int pageNumber;
    string text;
    int frequency = 0;

public:
    //Document();
    Document(vector<string>&);
    int getFrequency();
    int search(string word);
    friend ostream& operator<<(ostream& output, const Document& d);
};

#endif // DOCUMENT_H
