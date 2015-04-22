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
    unordered_map<string, vector<string>> hashObj;
    unordered_map<string, string> stopWords = {{"a","a"},
        {"about","about"},
        {"above","above"},
        {"after","after"},
        {"again","again"},
        {"against","against"},
        {"all","all"},
        {"am","am"},
        {"an","an"},
        {"and","and"},
        {"any","any"},
        {"are","are"},
        {"as","as"},
        {"at","at"},
        {"be","be"},
        {"because","because"},
        {"been","been"},
        {"before","before"},
        {"being","being"},
        {"below","below"},
        {"between","between"},
        {"both","both"},
        {"but","but"},
        {"by","by"},
        {"cannot","cannot"},
        {"could","could"},
        {"did","did"},
        {"do","do"},
        {"does","does"},
        {"doing","doing"},
        {"down","down"},
        {"during","during"},
        {"each","each"},
        {"few","few"},
        {"for","for"},
        {"from","from"},
        {"further","further"},
        {"had","had"},
        {"has","has"},
        {"have","have"},
        {"having","having"},
        {"he","he"},
        {"her","her"},
        {"here","here"},
        {"hers","hers"},
        {"herself","herself"},
        {"him","him"},
        {"himself","himself"},
        {"his","his"},
        {"how","how"},
        {"i","i"},
        {"if","if"},
        {"in","in"},
        {"into","into"},
        {"is","is"},
        {"it","it"},
        {"its","its"},
        {"itself","itself"},
        {"let's","let's"},
        {"me","me"},
        {"more","more"},
        {"most","most"},
        {"my","my"},
        {"myself","myself"},
        {"no","no"},
        {"nor","nor"},
        {"not","not"},
        {"of","of"},
        {"off","off"},
        {"on","on"},
        {"once","once"},
        {"only","only"},
        {"or","or"},
        {"other","other"},
        {"ought","ought"},
        {"our","our"},
        {"ours","ours"},
        {"ourselves","ourselves"},
        {"out","out"},
        {"over","over"},
        {"own","own"},
        {"same","same"},
        {"she","she"},
        {"should","should"},
        {"so","so"},
        {"some","some"},
        {"such","such"},
        {"than","than"},
        {"that","that"},
        {"the","the"},
        {"their","their"},
        {"theirs","theirs"},
        {"them","them"},
        {"themselves","themselves"},
        {"then","then"},
        {"there","there"},
        {"these","these"},
        {"they","they"},
        {"this","this"},
        {"those","those"},
        {"through","through"},
        {"to","to"},
        {"too","too"},
        {"under","under"},
        {"until","until"},
        {"up","up"},
        {"very","very"},
        {"was","was"},
        {"we","we"},
        {"were","were"},
        {"what","what"},
        {"when","when"},
        {"where","where"},
        {"which","which"},
        {"while","while"},
        {"who","who"},
        {"whom","whom"},
        {"why","why"},
        {"with","with"},
        {"would","would"},
        {"you","you"},
        {"your","your"},
        {"yours","yours"},
        {"yourself","yourself"},
        {"yourselves","yourselves"}};
    vector<string> textHolder;              //hold the split text from the file
    vector<Word*> wordVect;
    Document* docObj;
    Word* wordObj;
    AVLTree* indObj;
    string text;
    string id;

public:
//    Parser();
    // ~Parser();
    vector<string> removeExtraCharacters(vector<string>&);             //remove spaces, puctuation...
    void parse(string fileName);
    // void stemWords();
    // void sendToIndex();
    //
    //
    //      void sendDocsToDocClass();      //send the document vector elements to doc class
    //      vector<string> createSplitVector(string);
    vector<string> split(string& str, char sep);
    //      vector<string> sStreamText(string);
    void removeStop(vector<string> wordList);
    void removeSpace(vector<string> &fullDoc, vector<string> &noPunc);
    bool isAllAlpha(string word);
    bool isStop(string str);
    void processText(string &word);
};

#endif // PARSER_H
