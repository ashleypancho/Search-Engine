/* This class controls the query statements for
 * the search engine
 */
#ifndef QUERYPROCESSOR_H
#define QUERYPROCESSOR_H

#include <sstream>
#include "Parser.h"
#include "Document.h"
#include "Word.h"

using namespace std;

class QueryProcessor {
public:
    //default constructor
    QueryProcessor();

    //allows user to input and search for items
    void run();

/*  accepts the entire query
 *  calls additional search functions if necessary
 *  searches the index
 */
    void search(string&);

/*  searches for documents containing all the
 *  terms after AND (not including NOT, if applicable
 */
    void searchAnd(stringstream&);

/*  searches for one of the terms in the query, or
 *  the other, or both
 */
    void searchOr(stringstream&);

/*  removes documents containing terms specified after
 *  the NOT statement
 */
    void removeNot(vector<Document>&, stringstream&);

    virtual ~QueryProcessor();
private:
    Parser par;
    int totalDocs;
    int choice;
};

#endif  /* QUERYPROCESSOR_H */
