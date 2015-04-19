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
//#include "AvlTree.h"
//#include "porter2_stemmer.h"
#include "Word.h"
#include "Document.h"

#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"

using namespace rapidxml;
using namespace std;


// Parser::Parser()
// {
//
// }

void Parser::parse(string fileName)
{
    clock_t start;
    double duration;
    start = clock();

    vector<string> documentVectTemp;
    string bufferString;

    vector<string> textHolder;

    //ifstream myfile("enwikibooks-20140502-pages-meta-current.xml");    //http://stackoverflow.com/questions/2808022/how-to-parse-the-xml-file-in-rapidxml
    ifstream myfile("WikiDumpPart1.xml");
    xml_document<> doc;

    xml_node<> *root_node;
    //doc.parse<0>(WikiDump.data());
    //get root node


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
            else if(!cNode->next_sibling("parentid"))
                ;//    skipBadNode();
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
            else if(!cNode->next_sibling("comment"))
                ;//    skipBadNode();
            cNode = cNode->next_sibling("text");
//            cout << "Text of my first node is: " << cNode->value() << "\n";  /*test the xml_document */

            bufferString = cNode->value();
            documentVectTemp.push_back(bufferString);                 //add the text
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
//            textHolder = createSplitVector(bufferString);
            textHolder = split(bufferString,' ');


//            for(int k = 0; k < bufferString.size(); k++)
//            {
            //textHolder = createSplitVector(bufferString);

            //                textHolder = bufferString
//            }
           for(int k = 0; k < textHolder.size(); k++)
           {
               Word* wordObj = new Word(textHolder[k],docObj);
               if(k%10000 == 0) {
                   wordObj->print();
                   cout << endl;
               }
            //    indObj->insert(wordObj);
           }

            textHolder = split(bufferString,' ');
            if(textHolder.empty())
                ;
            else
            {
                for(int k = 0; k < textHolder.size(); k++)
                {
                   Word* wordObj = new Word(textHolder[k],docObj);
                        //    indObj->insert(wordObj);
                }
            }
//
            documentVectTemp.clear();
            textHolder.clear();
//             //cout << counter << endl;
//             counter++;
        }
        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "timer:" << duration << endl;
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

// void Parser::makeStopWords()
// {
//     fstream stopFile("stopWords.txt");
//     string stopTemp;
//     while(!stopFile.eof())          //read in the stop words
//     {
//         stopFile >> stopTemp;
//         stopWords.push_back(stopTemp);
//     }
//
//     stopWords = removeExtraCharacters(stopWords);           //remove non-characters from stop
//
//     for(int k = 0; k < stopWords.size(); k++)
//     {
//         Porter2Stemmer::stem(stopWords[k]);                 //stems the stopwords
//     }
//     for(int k = 0; k < stopWords.size(); k++)
//     {
//         cout << stopWords[k] << endl;
//     }
// }

// vector<string> Parser::removeExtraCharacters(vector<string> &wordList)
// {
//     string s;
//     for(int k = 0; k < wordList.size(); k++)
//     {
//         s = wordList[k];
//         s.erase(remove_if(s.begin(),s.end(),[](const char c)
//                 {return !isalpha(c) && !isdigit((int)c);}),s.end());    //removes other characters
//         wordList[k] = s;
//     }
//     return wordList;
// }
