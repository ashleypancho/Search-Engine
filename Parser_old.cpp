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

#include "Index.h"
#include "AvlTree.h"
#include "porter2_stemmer.h"
#include "Word.h"
#include "Document.h"

#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"

using namespace rapidxml;
using namespace std;


//Parser::Parser()
//{

//}

void Parser::parse(string fileName)
{
    clock_t start;
    double duration;
    start = clock();

    vector<string> documentVectTemp;
    string buffer;
    xml_document<> doc;

//    file<> benito("enwikibooks-20131101-pages-meta-current.xml");
//    file<> benito("Files_100.xml");
//    file<> benito("WikiDumpPart1.xml");

    //file<> benito(*fileName);


    file<> benito("enwikibooks-20131101-pages-meta-current.xml");
//    file<> benito("Files_10000.xml");
//    file<> benito("WikiDumpPart1.xml");
int counter = 0;

    xml_node<> *root_node;
    doc.parse<0>(benito.data());
    //get root node
    root_node = doc.first_node("mediawiki");
    buffer = root_node->value();
    for(xml_node<> *cNode = root_node -> first_node("page"); cNode; cNode = cNode -> next_sibling("page"))
        {

            cNode = cNode->first_node("title");
            buffer = cNode->value();
            documentVectTemp.push_back(buffer);                 //add the title to doc vect
            cNode = cNode->next_sibling("ns");
            cNode = cNode->next_sibling("id");
            buffer = cNode->value();
            documentVectTemp.push_back(buffer);                 //add the page number to document vector
            cNode = cNode->next_sibling("revision");
            cNode = cNode->first_node("id");
            if(cNode->next_sibling("parentid"))
                cNode = cNode->next_sibling("parentid");
            else if(!cNode->next_sibling("parentid"))
                skipBadNode();
            cNode = cNode->next_sibling("timestamp");
            buffer = cNode->value();
            documentVectTemp.push_back(buffer);                 //add the timestamp
            cNode = cNode->next_sibling("contributor");

            if(cNode->first_node("username"))                   //case 1: username/id pair
            {
                cNode = cNode->first_node("username");
                buffer = cNode->value();
                documentVectTemp.push_back(buffer);             //add the username
                cNode = cNode->next_sibling("id");
                buffer = cNode->value();
                documentVectTemp.push_back(buffer);             //add the id
            }
            else if(!cNode->first_node("username") && cNode->first_node("ip"))      //case 2: ip
            {
                cNode = cNode->first_node("ip");
                buffer = cNode->value();
                documentVectTemp.push_back(buffer);             //add the ip address
            }
            cNode = cNode->parent();
            if(cNode->next_sibling("comment"))
                cNode = cNode->next_sibling("comment");
            else if(!cNode->next_sibling("comment"))
                skipBadNode();
            cNode = cNode->next_sibling("text");
            buffer = cNode->value();
            documentVectTemp.push_back(buffer);                 //add the text
            cNode = cNode->next_sibling("sha1");
            cNode = cNode->next_sibling("model");
            cNode = cNode->next_sibling("format");
            cNode = cNode->parent();
            cNode = cNode->parent();

           // docObj = new Document(documentVectTemp);

            //loop through the buffer of text. parse each word. add to index
            //Word pointer


//            textHolder = createSplitVector(buffer);
            textHolder = split(buffer,' ');


//            for(int k = 0; k < buffer.size(); k++)
//            {
            //textHolder = createSplitVector(buffer);

            //                textHolder = buffer
//            }
//            for(int k = 0; k < textHolder.size(); k++)
//            {
//                wordObj = new Word(textHolder[k],docObj);
//                indObj->insert(wordObj);
//            }

            textHolder = split(buffer,' ');
if(textHolder.empty())
    skipBadNode();
else
{
    for(int k = 0; k < textHolder.size(); k++)
    {
        wordObj = new Word(textHolder[k],docObj,textHolder);
//                indObj->insert(wordObj);
    }
}

            documentVectTemp.clear();
            textHolder.clear();
            //cout << counter << endl;
            counter++;
        }

    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "timer:" << duration << endl;

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

    stopWords = removeExtraCharacters(stopWords);           //remove non-characters from stop

    for(int k = 0; k < stopWords.size(); k++)
    {
        Porter2Stemmer::stem(stopWords[k]);                 //stems the stopwords
    }
    for(int k = 0; k < stopWords.size(); k++)
    {
        cout << stopWords[k] << endl;
    }
}

vector<string> Parser::removeExtraCharacters(vector<string> &wordList)
{
    string s;
    for(int k = 0; k < wordList.size(); k++)
    {
        s = wordList[k];
        s.erase(remove_if(s.begin(),s.end(),[](const char c)
                {return !isalpha(c) && !isdigit((int)c);}),s.end());    //removes other characters
        wordList[k] = s;
    }
    return wordList;
}

void Parser::skipBadNode()
{
    //doesn't actually do anything. just to have something to skip the node
    //if it doesn't exist in one of the xml docs
}

vector<string> Parser::split(string& str, char delim) //found at http://www.cplusplus.com/forum/general/125094/
{
    vector<string> ret;
    istringstream stm(str) ;
    string token ;
    while(getline( stm, token, delim ) ) ret.push_back(token) ;
    return ret ;
}


//vector<string> Parser::createSplitVector(string& textBody)
//{
//    char *cstr = new char[textBody.length() + 1];
//    strcpy(cstr,textBody.c_str());
//    splitstring t(cstr);
//    vector<string> textTemp = t.split(' ');
//    delete [] cstr;
//    return textTemp;
//}

//vector<string> Parser::split(string& str, char delim) //found at http://www.cplusplus.com/forum/general/125094/
//{
//    vector<string> ret;
//    istringstream stm(str) ;
//    string token ;
//    while(getline( stm, token, delim ) ) ret.push_back(token) ;
//    return ret ;
//}


