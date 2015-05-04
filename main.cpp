#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <vector>

#include "QueryProcessor.h"
// #include "Word.h"

#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"

using namespace rapidxml;
using namespace std;



int main()
{
    QueryProcessor search;
    search.run();

    return 0;
}
