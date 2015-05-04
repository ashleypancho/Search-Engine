#include "QueryProcessor.h"

QueryProcessor::QueryProcessor()
{

}

void QueryProcessor::run()
{
    int choice;
    bool stop = false;
    string query;

    while(!stop)
    {
        cout << "Welcome!" << endl;
        cout << "Please select which data structure you wish to load into." << endl;
        cout << "Type the number of the option to load your choice." << endl;
        cout << "1. AVL Tree" << endl << "2. Hash Table" << endl << "3. Clear Index" << endl;
        cout << "Selection: ";
        cin >> choice;

        if(choice == 1)
        {
            //TODO: AVL Tree
            Parser par;
            par.parse(choice);
            stop = true;
        }
        else if(choice == 2)
        {
            //TODO: Hash Table
            Parser par;
            par.parse(choice);
            stop = true;
        }
        else {
            cout << "I'm sorry, you've entered an invalid option. Please try again." << endl;
        }
    }

    // stop = false;
    //
    // while(!stop)
    // {
    //     cout << "Please enter query for search or type EXIT to quit." << endl;
    //     getline(cin, query);
    //     if(query == "")
    //     {
    //     }
    //     // else if(query == "SAVE")
    //     // {
    //     //     handler->save();
    //     // }
    //     else if(query == "EXIT")
    //     {
    //         cout << "Are you sure? Enter 1 to confirm or 2 to enter another query." << endl;
    //         cin >> choice;
    //         if(choice == 1)
    //             stop = true;
    //     }
    //     else
    //         search(query);
    // }

}

void QueryProcessor::search(string& input)
{
    // stringstream query;
    // string word1;
    // IndexEntry* result1;
    //
    // vector<Document> output;
    // vector<float> values;       //TF/IDF values
    //
    // float finalVal;
    // float big = 0;
    // int pos = 0;
    //
    // bool isSame;
    // bool stop = false;
    //
    // query << input;
    //
    // query >> word1;
    //
    // if(word1 == "AND")
    // {
    //     searchAnd(query);
    //     return;
    // }
    // else if(word1 == "OR")
    // {
    //     searchOr(query);
    //     return;
    // }
    //
    // result1 = handler->search(word1);
    // if(result1 == NULL)
    // {
    //     cout << "Word not found." << endl;
    //     return;
    // }
    //
    // for(int i=0; i<result1->docs.size(); i++)
    // {
    //     output.push_back(result1->docs[i]);
    // }
    //
    // for(int i=0; i<output.size(); i++)
    // {
    //     finalVal = handler->tfidf(result1, output[i].docID);
    //     values.push_back(finalVal);
    // }
    //
    // query >> word1;
    //
    // if(word1 == "NOT")
    // {
    //     removeNot(output, query);
    // }
    //
    // if(output.size() == 0)
    // {
    //     cout << "No results for that search." << endl;
    //     return;
    // }
    // else
    // {
    //     cout << "Results:" << endl;
    //     int a = 0;
    //     while(stop == false)
    //     {
    //         if(values.size() != 0)
    //             big = values[0];
    //         for(int i=0; i<output.size(); i++)
    //         {
    //             if(values[i] > big)
    //             {
    //                 big = values[i];
    //                 pos = i;
    //             }
    //         }
    //         cout << output.at(pos).title << " by " << output.at(pos).author << ". Document ID: ";
    //         cout << output.at(pos).docID << ". Published on " << output.at(pos).date << ". TF*IDF value ";
    //         cout << values.at(pos) << endl;
    //         output.erase(output.begin()+pos);
    //         values.erase(values.begin()+pos);
    //         if(values.size() == 0 || a == 15)
    //             stop = true;
    //         a++;
    //     }
    // }
}

void QueryProcessor::searchAnd(stringstream& query)
{
    // string word1;
    // IndexEntry* result1;
    // IndexEntry* result2;
    // vector<IndexEntry*> results;
    // vector<Document> output;
    // vector<float> values;       //TF/IDF values
    // vector<int> order;
    //
    // float value1;
    // float value2;
    // float finalVal;
    // float big = 0;
    // int pos = 0;
    //
    // bool isSame;
    // bool stop = false;
    //
    // query >> word1;
    // result1 = handler->search(word1);
    // query >> word1;
    // result2 = handler->search(word1);
    //
    // if(result1 == NULL || result2 == NULL)
    // {
    //     if(result1 == NULL)
    //         cout << "First term not found." << endl;
    //     if(result2 == NULL)
    //         cout << "Second term not found." << endl;
    //     return;
    // }
    //
    // for(int i=0; i<result1->docs.size(); i++)
    // {
    //     for(int j=0; j<result2->docs.size(); j++)
    //     {
    //         if(result1->docs[i].docID == result2->docs[j].docID)
    //         {
    //             output.push_back(result1->docs[i]);         //check to see if the
    //         }                                               //ID's are the same-
    //     }                                                   //if so, it pushes it
    // }                                                       //into output vector
    //
    // for(int i=0; i<output.size(); i++)
    // {
    //     value1 = handler->tfidf(result1, output[i].docID);
    //     value2 = handler->tfidf(result2, output[i].docID);
    //     finalVal = (value1 + value2)/2;
    //     values.push_back(finalVal);
    // }
    //
    // query >> word1;
    //
    // if(output.size() == 0)
    // {
    //     cout << "No results for that search." << endl;
    //     return;
    // }
    // cout << "Results:" << endl;
    // int a=0;
    // while(stop == false)
    // {
    //     if(values.size() != 0)
    //         big = values[0];
    //     for(int i=0; i<output.size(); i++)
    //     {
    //         if(values[i] > big)
    //         {
    //             big = values[i];
    //             pos = i;
    //         }
    //     }
    //     cout << output.at(pos).title << " by " << output.at(pos).author << ". Document ID: ";
    //     cout << output.at(pos).docID << ". Published on " << output.at(pos).date << ". TF*IDF value ";
    //     cout << values.at(pos) << endl;
    //     output.erase(output.begin()+pos);
    //     values.erase(values.begin()+pos);
    //     if(values.size() == 0 || a >= 15)
    //        stop = true;
    //     a++;
    // }
    //
}

void QueryProcessor::searchOr(stringstream& query)
{
    // string word1;
    // string word2;
    // IndexEntry* result1;
    // IndexEntry* result2;
    // vector<Document> output;
    // vector<float> values;
    // vector<int> order;
    //
    // float value1;
    // float value2;
    // float finalVal;
    // float big = 0;
    // int pos = 0;
    //
    // bool isSame;
    // bool stop = false;
    //
    //     query >> word1;
    //     result1 = handler->search(word1);
    //     query >> word1;
    //     result2 = handler->search(word1);
    //
    //     if(result1 == NULL || result2 == NULL)
    //     {
    //         if(result1 == NULL)
    //             cout << "First term not found." << endl;
    //         if(result2 == NULL)
    //             cout << "Second term not found." << endl;
    //         return;
    //     }
    //
    //     for(int i=0; i<result1->docs.size(); i++)
    //     {
    //         output.push_back(result1->docs[i]);
    //     }
    //     for(int i=0; i<result2->docs.size(); i++)
    //     {
    //         output.push_back(result2->docs[i]);
    //     }
    //
    //     for(int i=0; i<result1->docs.size(); i++)
    //     {
    //         for(int j=0; j<result2->docs.size(); j++)
    //         {
    //             for(int k=0; k<output.size(); k++)
    //             {
    //                 if(output[k].docID == result1->docs[i].docID && output[k].docID == result2->docs[j].docID)
    //                 {
    //                     output.erase(output.begin()+k);
    //                     k--;
    //                 }
    //             }
    //         }
    //     }
    //
    //     for(int i=0; i<output.size(); i++)
    //     {
    //         value1 = handler->tfidf(result1, output[i].docID);
    //         value2 = handler->tfidf(result2, output[i].docID);
    //         finalVal = (value1 + value2)/2;
    //         values.push_back(finalVal);
    //     }
    //
    //     if(word1 == "NOT")
    //     {
    //         query >> word1;
    //         result1 = handler->search(word1);
    //         for(int i=0; i<result1->docs.size(); i++)
    //         {
    //             for(int j=0; j<output.size(); j++)
    //             {
    //                 if(result1->docs[i].docID == output[j].docID)
    //                 {
    //                     output.erase(output.begin() + j);
    //                     j--;
    //                 }
    //             }
    //         }
    //     }
    //
    //     if(output.size() == 0)
    //     {
    //         cout << "No results for that search." << endl;
    //         return;
    //     }
    //     cout << "Results:" << endl;
    //     int a = 0;
    //     while(stop == false)
    //     {
    //         if(values.size() != 0)
    //             big = values[0];
    //         for(int i=0; i<output.size(); i++)
    //         {
    //             if(values[i] > big)
    //             {
    //                 big = values[i];
    //                 pos = i;
    //             }
    //         }
    //         cout << output.at(pos).title << " by " << output.at(pos).author << ". Document ID: ";
    //         cout << output.at(pos).docID << ". Published on " << output.at(pos).date << ". TF*IDF value:";
    //         cout << values.at(pos) << endl;
    //
    //         output.erase(output.begin()+pos);
    //         values.erase(values.begin()+pos);
    //         if(values.size() == 0 || a == 15)
    //             stop = true;
    //         a++;
    //     }

}

void QueryProcessor::removeNot(vector<Document>& output, stringstream& query)
{
    // IndexEntry* result1;
    // string word1;
    // query >> word1;
    // if(word1 == "NOT")
    // {
    //     query >> word1;
    //     result1 = handler->search(word1);
    //     for(int i=0; i<result1->docs.size(); i++)
    //     {
    //         for(int j=0; j<output.size(); j++)
    //         {
    //             if(result1->docs[i].docID == output[j].docID)
    //             {
    //                output.erase(output.begin() + j);
    //             }
    //         }
    //     }
    // }
}

QueryProcessor::~QueryProcessor()
{

}
