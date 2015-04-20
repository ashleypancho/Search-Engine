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

void Parser::parse(string fileName)
{
    clock_t origStart, start;
    double duration, parsing, inserting, clearing, stopTime, stemmer, cleaner;
    origStart = clock();
    start = clock();

    vector<string> documentVectTemp;
    string bufferString;

    vector<string> textHolder;

    ifstream myfile("enwikibooks-20140502-pages-meta-current.xml");
    //ifstream myfile("WikiDumpPart1.xml");
    ofstream out("output.txt");

    //http://stackoverflow.com/questions/2808022/how-to-parse-the-xml-file-in-rapidxml
    xml_document<> doc;
    xml_node<> *root_node;    //get root node
    /* "Read file into vector<char>"  See linked thread above*/
    vector<char> buffer((istreambuf_iterator<char>(myfile)), istreambuf_iterator<char>( ));

    buffer.push_back('\0');

//    cout<<&buffer[0]<<endl; /*test the buffer */

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
//           documentVectTemp = removeExtraCharacters(documentVectTemp);
            cNode = cNode->next_sibling("sha1");
            cNode = cNode->next_sibling("model");
            cNode = cNode->next_sibling("format");
            cNode = cNode->parent();
            cNode = cNode->parent();
//
            Document* docObj = new Document(documentVectTemp);
//
            //loop through the bufferString of text. parse each word. add to index
            //Word pointer
            textHolder = split(bufferString,' ');
            parsing = (clock() - start) / (double) CLOCKS_PER_SEC;
            start = clock();
           cout << "parsing: " << parsing << endl;
            // removeSpace(textHolder,cleanTextHolder);
            cleaner = (clock() - start) / (double) CLOCKS_PER_SEC;
            start = clock();
           cout << "cleaner: " << cleaner << endl;
            // removeStop(textHolder,cleanTextHolder,noStopText);
            stopTime = (clock() - start) / (double) CLOCKS_PER_SEC;
            start = clock();
           cout << "stopTime: " << stopTime << endl;
           for(int k = 0; k < textHolder.size(); k++)
           {
            //    Porter2Stemmer::stem(noStopText[k]);
               stemmer = (clock() - start) / (double) CLOCKS_PER_SEC;
               start = clock();
              out << "stemmer: " << stemmer << endl;

            //    Word* wordObj = new Word(noStopText[k],docObj);
            //    if(k%10000 == 0) {
            //        wordObj->print();
            //        cout << endl;
            //    }
            //   indObj->insert(noStopText[k]);
                cout << "word inserted: " << textHolder[k] << endl;
                hashObj[textHolder[k]].push_back(docObj);
                // cout << hashObj[noStopText[k]];
               inserting = (clock() - start) / (double) CLOCKS_PER_SEC;
               start = clock();
              cout << "inserting: " << inserting << endl;
           }

            documentVectTemp.clear();
            textHolder.clear();
            cleanTextHolder.clear();
            noStopText.clear();
            clearing = (clock() - start) / (double) CLOCKS_PER_SEC;
            cout << "clearing: " << clearing << endl;
        }
        duration = (clock() - origStart) / (double) CLOCKS_PER_SEC;
        cout << "timer:" << duration << " seconds" << endl;
        // indObj->print();
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

void Parser::makeStopWords()
{
    fstream stopFile("stopWords.txt");
    string stopTemp;
    while(!stopFile.eof())          //read in the stop words
    {
        stopFile >> stopTemp;
        stopWords.push_back(stopTemp);
    }

//    stopWords = removeExtraCharacters(stopWords);           //remove non-characters from stop

    for(int k = 0; k < stopWords.size(); k++)
    {
        Porter2Stemmer::stem(stopWords[k]);                 //stems the stopwords
    }
}

vector<string> Parser::removeExtraCharacters(vector<string> &wordList)
{
    string s;
    for(int k = 0; k < wordList.size(); k++)
    {
        s = wordList[k];
        s.erase(std::remove_if(s.begin(), s.end(), [](const unsigned &c){ return !isalpha(c);}), s.end());    //removes other characters
        wordList[k] = s;
    }
    return wordList;
}

void Parser::removeStop(vector<string> &stopWords, vector<string> &noPunct, vector<string> &noStop) {
    for (int i = 0; i < noPunct.size(); i++) {
        string word = noPunct[i];
        int count = 0;
        for (int m = 0; m < stopWords.size(); m++) {
            string stop = stopWords[m];
            if (word == stop)
                count++;
        }
        if (count == 0) {
            noStop.push_back(word);
        }
    }
}

void Parser::removeSpace(vector<string> &fullDoc, vector<string> &noPunc) {
    for (int i = 0; i < fullDoc.size(); i++) {
        string line = fullDoc[i];
        stringstream lineStream(line);
        string word;
        while (1) {
            if (!(lineStream >> word)) break;
            noPunc.push_back(word);
        }
    }
}
