#include "QueryProcessor.h"

QueryProcessor::QueryProcessor()
{

}

void QueryProcessor::run()
{
    bool stop = false;
    string query;

    while(!stop)
    {
        cout << "Welcome!" << endl;
        cout << "Please select which data structure you wish to load into." << endl;
        cout << "Type the number of the option to load your choice." << endl;
        cout << "1. AVL Tree" << endl << "2. Hash Table" << endl << "3. Save Index" << endl << "4. Clear Index" << endl;
        cout << "Selection: ";
        cin >> choice;

        if(choice == 1)
        {
            par.parse(choice);
            stop = true;
        }
        else if(choice == 2)
        {
            par.parse(choice);
            stop = true;
        }
        else if(choice == 3)
        {
            //TODO: Save index
        }
        else if(choice == 4)
        {
            //TODO: Clear index
        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    stop = false;

    while(!stop)
    {
        cout << "Please enter query for search or type EXIT to quit." << endl;
        getline(cin, query);
        if(query == "")
        {
        }
        // else if(query == "SAVE")
        // {
        //     handler->save();
        // }
        else if(query == "EXIT")
        {
            cout << "Are you sure? Enter 1 to confirm or 2 to enter another query." << endl;
            cin >> choice;
            if(choice == 1)
                stop = true;
        }
        else
            search(query);
    }

}

void QueryProcessor::search(string& input)
{
    stringstream query;
    string word1;
    vector<Document*> results;

    query << input;
    query >> word1;

    if(word1 == "AND")
    {
        searchAnd(query);
        return;
    }
    else if(word1 == "OR")
    {
        searchOr(query);
        return;
    }

    if(choice == 1) {
        //AVLTree.search(word1);
    }
    else {
        results = par.search(word1);
    }

    cout << "Results: " << endl;
    if(results.size() < 5) {
        for(int i = 0; i < results.size(); i++) {
            cout << (*(results.at(i))) << endl;
        }
    }
    else {
        for(int i = 0; i < 5; i++) {
            cout << (*(results.at(i))) << endl;
        }
    }

}

void QueryProcessor::searchAnd(stringstream& query)
{
    string word1;
    vector<Document*> search1;
    vector<Document*> search2;
    vector<Document*> results;

    query >> word1;

    if(choice == 1) {
        //AVLTree.search(word1);
    }
    else {
        search1 = par.search(word1);
    }

    query >> word1;
    if(choice == 1) {
        //AVLTree.search(word1);
    }
    else {
        search2 = par.search(word1);
    }

    // for(int i = 0; i < search1.size(); i++) {
    //     for(int j = 0; j < search2.size(); j++) {
    //         if((*(search1.at(i))).getPageNumber() == (*(search1.at(j))).getPageNumber()) {
    //             results.push_back(search1.at(i));
    //         }
    //     }
    // }

    for(int i = 0; i < search1.size(); i++) {
        results.push_back(search1.at(i));
    }

    for(int i = 0; i < search2.size(); i++) {
        results.push_back(search2.at(i));
    }

    // query >> word1;
    //
    // if(output.size() == 0)
    // {
    //     cout << "No results for that search." << endl;
    //     return;
    // }

    cout << "Results: " << endl;
    if(results.size() < 5) {
        for(int i = 0; i < results.size(); i++) {
            cout << (*(results.at(i))) << endl;
        }
    }
    else {
        for(int i = 0; i < 5; i++) {
            cout << (*(results.at(i)))<< endl;
        }
    }
}

void QueryProcessor::searchOr(stringstream& query)
{
    string word1;
    string word2;
    vector<Document*> search1;
    vector<Document*> search2;
    vector<Document*> results;

    query >> word1;

    if(choice == 1) {
        //AVLTree.search(word1);
    }
    else {
        search1 = par.search(word1);
    }

    query >> word1;
    if(choice == 1) {
        //TODO: AVL Search
    }
    else {
        search2 = par.search(word1);
    }


    if(search1.size() == 0 || search2.size() == 0)
    {
        if(search1.size() == 0)
            cout << "First term not found." << endl;
        if(search2.size() == 0)
            cout << "Second term not found." << endl;
        return;
    }

    for(int i = 0; i < search1.size(); i++) {
        results.push_back(search1.at(i));
    }

    for(int i = 0; i < search2.size(); i++) {
        results.push_back(search2.at(i));
    }

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

    cout << "Results: " << endl;
    if(results.size() < 5) {
        for(int i = 0; i < results.size(); i++) {
            cout << (*(results.at(i))) << endl;
        }
    }
    else {
        for(int i = 0; i < 5; i++) {
            cout << (*(results.at(i))) << endl;
        }
    }
}

void QueryProcessor::removeNot(vector<Document>& output, stringstream& query)
{
    string word1;
    query >> word1;
    // Check which data structure

    // if(word1 == "NOT")
    // {
            // Read query
    //     query >> word1;
            // Check for matching documents and remove them
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
