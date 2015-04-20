#ifndef AVLTREE_H
#define AVLTREE_H
#include "AVLNode.h"

class AVLTree
{
public:
    AVLTree();

    int height(AVLNode *t);
    void insert(string &val)
    {
        insert(val, root);
    }
//    http://www.sanfoundry.com/cpp-program-implement-avl-trees/
    void inorder(AVLNode *t);
    void print();

private:
    AVLNode *root;
    void rotateWithLC(AVLNode* &k2);
    void rotateWithRC(AVLNode* &k2);
    void doubleWithLC(AVLNode* &k3);
    void doubleWithRC(AVLNode* &k3);
    void insert(string &x, AVLNode* &t);
};

#endif // AVLTREE_H
