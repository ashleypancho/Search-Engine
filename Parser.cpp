#include "Parser.h"

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <sstream>

//#include "Index.h"
#include "AvlTree.h"
#include "porter2_stemmer.h"
#include "Word.h"
#include "Document.h"

#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"

using namespace rapidxml;
using namespace std;

// Parser::~Parser()
// {
//     delete docObj;
//     delete wordObj;
// }

void Parser::parse(int indChoice)
{
    clock_t origStart;
    double duration;
    origStart = clock();

    vector<string> documentVectTemp;
    string bufferString;

    vector<string> textHolder;

    //ifstream myfile("enwikibooks-20140502-pages-meta-current.xml");
    ifstream myfile("WikiDumpPart1.xml");
    //ofstream out("output.txt");

    //http://stackoverflow.com/questions/2808022/how-to-parse-the-xml-file-in-rapidxml
    xml_document<> doc;
    xml_node<> *root_node;    //get root node
    /* "Read file into vector<char>"  See linked thread above*/
    vector<char> buffer((istreambuf_iterator<char>(myfile)), istreambuf_iterator<char>( ));

    buffer.push_back('\0');

    doc.parse<0>(&buffer[0]);
    root_node = doc.first_node("mediawiki");

    for(xml_node<> *cNode = root_node -> first_node("page"); cNode; cNode = cNode -> next_sibling("page"))
        {

            cNode = cNode->first_node("title");
            // buffer = cNode->value();
            // documentVectTemp.push_back(buffer);                 //add the title to doc vect
            cNode = cNode->next_sibling("ns");
            cNode = cNode->next_sibling("id");
            bufferString = cNode->value();
            id = bufferString;
            documentVectTemp.push_back(bufferString);                 //add the page number to document vector

            cNode = cNode->next_sibling("revision");
            cNode = cNode->first_node("id");
            if(cNode->next_sibling("parentid"))
                cNode = cNode->next_sibling("parentid");
            cNode = cNode->next_sibling("timestamp");
            cNode = cNode->next_sibling("contributor");

            if(cNode->first_node("username"))                   //case 1: username/id pair
            {
                cNode = cNode->first_node("username");
                cNode = cNode->next_sibling("id");
            }
            else if(!cNode->first_node("username") && cNode->first_node("ip"))      //case 2: ip
            {
                cNode = cNode->first_node("ip");
            }

            cNode = cNode->parent();

            if(cNode->next_sibling("comment"))
                cNode = cNode->next_sibling("comment");
            cNode = cNode->next_sibling("text");
            bufferString = cNode->value();

            documentVectTemp.push_back(bufferString);                 //add the text
            documentVectTemp = removeExtraCharacters(documentVectTemp);

            cNode = cNode->next_sibling("sha1");
            cNode = cNode->next_sibling("model");
            cNode = cNode->next_sibling("format");
            cNode = cNode->parent();
            cNode = cNode->parent();

            Document* docObj = new Document(documentVectTemp);

            //loop through the bufferString of text. parse each word. add to index
            //Word pointer
            textHolder = split(bufferString,' ');

            removeStop(textHolder);
            removeSpace(textHolder);

            // Stem and insert into index
            for(int k = 0; k < textHolder.size(); k++)
            {
            //    Word* wordObj = new Word(noStopText[k],docObj);
               if(isAllAlpha(textHolder[k]))
               {
                   Porter2Stemmer::stem(textHolder[k]);
                   cout << "word inserted: " << textHolder[k] << endl;
                   if(indChoice == 1)
                   {
                       indObj->insert(textHolder[k]);
                   }
                   if(indChoice == 2)
                   {
                       hashObj[textHolder[k]].push_back(id);
                   }
               }
           }

            documentVectTemp.clear();
            textHolder.clear();
        }

        duration = (clock() - origStart) / (double) CLOCKS_PER_SEC;
        // Prints Index
        if(indChoice == 1)
            indObj->print();
        if(indChoice == 2)
        {
            for(auto i : hashObj) {
                cout << i.first << ": ";
                for(int j = 0; j < (i.second).size(); j++) {
                    cout << (i.second).at(j);
                    if(j != ((i.second).size() -1))
                        cout << ", ";
                }
                cout << endl;
            }
        }
        cout << endl << "timer:" << duration << " seconds" << endl;
}

// split via http://www.cplusplus.com/forum/general/125094/
vector<string> Parser::split(string& str, char sep = ' ' )
{
    vector<string> ret;

    istringstream stm(str);
    string token;
    while(getline(stm, token, sep)) ret.push_back(token);

    return ret;
}

vector<string> Parser::removeExtraCharacters(vector<string> &wordList)
{
    string s;
    for(int k = 0; k < wordList.size(); k++)
    {
        s = wordList[k];
        s.erase(std::remove_if(s.begin(), s.end(), [](const unsigned &c){ return isalpha(c);}), s.end());    //removes other characters
        wordList[k] = s;
    }
    return wordList;
}


//modified from http://stackoverflow.com/questions/11302990/c-how-to-check-if-a-string-is-all-lowercase-and-alphanumerics
static inline bool is_not_alphanum_lower(char c)
{
    return (!isalpha(c));
}

bool Parser::isAllAlpha(string str)
{
    return find_if(str.begin(), str.end(), is_not_alphanum_lower) == str.end();
}

bool Parser::isStop(string str)
{
    auto search = stopWords.find(str);
    return search == stopWords.end();
}

void Parser::removeStop(vector<string>& wordList) {
    vector<string> noStop;
    for(int i = 0; i < wordList.size(); i++) {
        auto search = stopWords.find(wordList[i]);
        if(search == stopWords.end()) {
            noStop.push_back(wordList[i]);
        }
   }
   wordList.swap(noStop);
}

void Parser::removeSpace(vector<string> &fullDoc) {
    vector<string> noPunc;
    for (int i = 0; i < fullDoc.size(); i++) {
        string line = fullDoc[i];
        stringstream lineStream(line);
        string word;
        while (1) {
            if (!(lineStream >> word)) break;
            noPunc.push_back(word);
        }
    }
    fullDoc.swap(noPunc);
}
