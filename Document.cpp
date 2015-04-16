#include "Document.h"

Document::Document()
{

}

Document::Document(vector<string>& singleDoc)
{
    if(singleDoc.size() == 5)
    {
        docTitle = singleDoc[0];
        pageNumber = stoi(singleDoc[1],nullptr,10);
        text = singleDoc[4];
    }
    else if(singleDoc.size() == 6)
    {
        docTitle = singleDoc[0];
        pageNumber = stoi(singleDoc[1],nullptr,10);
        text = singleDoc[5];
    }

}

int getFrequency()
{
    return frequency;
}

int Document::search(string word){
    size_t found = text.find(word);
    while(found != string::npos) {
        frequency++;
        found = text.find(word, found+1);
    }
    return frequency;
}

ostream& operator<<(ostream& output, const Document& d)
{
    output << d.text << endl;
    return output;
}
