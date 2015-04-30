#ifndef AVLNODE_H
#define AVLNODE_H
#include <iostream>
#include <string>

using namespace std;

class AVLNode
{
public:
    int height = 0;
    AVLNode *left, *right;
    string data;
    AVLNode(string &elem, AVLNode *LST, AVLNode *RST, int h = 0):data(elem), left(LST),right(RST), height(h) { }


};

#endif // AVLNODE_H
