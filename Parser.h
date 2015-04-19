#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <sstream>

// #include "Index.h"
// #include "AvlTree.h"
#include "Word.h"
#include "Document.h"
//#include "splitstring.h"

#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"

using namespace rapidxml;
using namespace std;

class Parser
{
private:
    string title;
    string author;
    string timeStamp;
    string textToken;
    int pageIDNumber;

    vector<string> stopWords;               //move to the .h file so it is in whole class
    vector<string> textHolder;              //hold the split text from the file
    vector<Word*> wordVect;
    Document* docObj;
    Word* wordObj;
//    Index* indObj;

public:
//    Parser();
   // void makeStopWords();                   //make stop word vector
    // vector<string> removeExtraCharacters(vector<string>&);             //remove spaces, puctuation...
    void parse(string fileName);
    // void stemWords();
    // void sendToIndex();
    // void skipBadNode();             //used to 'skip' a node if it is missing in a doc
    //
    //
    //      void sendDocsToDocClass();      //send the document vector elements to doc class
    //      vector<string> createSplitVector(string);
         vector<string> split(string& str, char sep);
    //      vector<string> sStreamText(string);




};

#endif // PARSER_H
