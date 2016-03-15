#ifndef AVLTREE_H
#define AVLTREE_H
#include "AVLNode.h"
#include "Word.h"
#include <vector>

class AVLTree
{
public:
    AVLTree();
    int height(AVLNode *t);
    void insert(string &val);//, Word*w, Document*doc);
    // vector<Word*> search(string& word);
//    http://www.sanfoundry.com/cpp-program-implement-avl-trees/
    void inorder(AVLNode *t);
    void print();

private:
    AVLNode *root;
    vector<Word*> words;
    void rotateWithLC(AVLNode* &k2);
    void rotateWithRC(AVLNode* &k2);
    void doubleWithLC(AVLNode* &k3);
    void doubleWithRC(AVLNode* &k3);
    void insert(string &x, AVLNode* &t);
    // vector<Word*> search(string& word, vector<Word*> results, AVLNode *t)
};

#endif // AVLTREE_H
