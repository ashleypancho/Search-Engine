#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <sstream>
#include <unordered_map>

// #include "Index.h"
#include "AvlTree.h"
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
    unordered_map<string, vector<Document*>> hashObj;
    vector<string> stopWords = {"a","about","above","after","again","against","all","am","an","and","any","are","aren't","as","at","be","because","been","before","being","below","between","both","but","by","can't","cannot","could","couldn't","did","didn't","do","does","doesn't","doing","don't","down","during","each","few","for","from","further","had","hadn't","has","hasn't","have","haven't","having","he","he'd","he'll","he's","her","here","here's","hers","herself","him","himself","his","how","how's",
    "i","i'd","i'll","i'm","i've","if","in","into","is","isn't","it","it's","its","itself","let's","me","more","most","mustn't","my","myself","no","nor","not","of","off","on","once","only","or","other","ought","our","ours","ourselves","out","over","own","same","shan't","she","she'd","she'll","she's","should","shouldn't","so","some","such","than","that","that's","the","their","theirs","them","themselves","then","there",
    "there's","these","they","they'd","they'll","they're","they've","this","those","through","to","too","under","until","up","very","was","wasn't","we","we'd","we'll","we're","we've","were","weren't","what","what's","when","when's","where","where's","which","while","who","who's","whom","why","why's","with","won't","would","wouldn't","you","you'd","you'll","you're","you've","your","yours","yourself","yourselves"};               //move to the .h file so it is in whole class
    vector<string> textHolder;              //hold the split text from the file
    vector<string> cleanTextHolder;         //textHolder with removed spaces and stuff
    vector<string> noStopText;              //completely free of stop words
    vector<Word*> wordVect;
    Document* docObj;
    Word* wordObj;
    AVLTree* indObj;

public:
//    Parser();
    // ~Parser();
    void makeStopWords();                   //make stop word vector
    vector<string> removeExtraCharacters(vector<string>&);             //remove spaces, puctuation...
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
    void removeStop(vector<string> &stopWords, vector<string> &noPunct, vector<string> &noStop);
    void removeSpace(vector<string> &fullDoc, vector<string> &noPunc);

};

#endif // PARSER_H
