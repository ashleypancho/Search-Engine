#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <vector>

#include "Parser.h"
#include "Word.h"

#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"

using namespace rapidxml;
using namespace std;



int main()
{
    string fileName;
    //fileName = "enwikibooks-20131101-pages-meta-current.xml";
    //fileName = "WikiDumpPart1.xml";
    Parser par;//= new Parser();
    par.parse(fileName);
    // par -> makeStopWords();
    // par -> stemWords();


    return 0;
}
