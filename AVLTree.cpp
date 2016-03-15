#include "AVLTree.h"


AVLTree::AVLTree()
{
    root = nullptr;
}

void AVLTree::insert(string &val)//, Word*w, Document*doc)
{
    // bool wordFound = false;
    // for(int i = 0; i < words.size(); i++) {
    //     if(w == words[i]){
    //         words[i].addDocument(doc);
    //         wordFound = true;
    //         break;
    //     }
    // }
    // if(!wordFound) {
    //     words.push_back(w);
    // }
    //
    insert(val, root);
}

void AVLTree::insert(string &x, AVLNode *&t)
{
    if(t==nullptr)
    {
        t = new AVLNode(x, nullptr, nullptr);
    }
    else if(x.compare(t->data) < 0)
    {
        insert(x, t->left);
        if(height(t->left)-height(t->right)==2)
        {
            if(x.compare(t ->left->data) < 0)//case I
            {
                rotateWithLC(t);
            }
            else//case II
            {
                doubleWithLC(t);
            }
        }
    }
    else if((t->data).compare(x) < 0)
    {
        insert(x, t->right);
        if(height(t->right)-height(t->left)==2)
        {
            if((t->right->data).compare(x) < 0)
            {
                rotateWithRC(t);
            }//case IV
            else
            {
                doubleWithRC(t);
            }
        }//case III
    }
    else
        {}
    t->height = max(height(t->left), height(t->right))+1;
}

int AVLTree::height(AVLNode *t)
{
    return t==nullptr? -1:
         t->height;
}

void AVLTree::rotateWithLC(AVLNode *&k2)
{
    AVLNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right))+1;
    k1->height = max(height(k1->left), k2->height)+1;
    k2 = k1;
}

void AVLTree::rotateWithRC(AVLNode *&k2)
{
    AVLNode *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->right), height(k2->left))+1;
    k1->height = max(height(k1->right), k2->height)+1;
    k2 = k1;
}

void AVLTree::doubleWithLC(AVLNode *&k3)
{
    rotateWithRC(k3->left);
    rotateWithLC(k3);
}

void AVLTree::doubleWithRC(AVLNode *&k3)
{
    rotateWithLC(k3->right);
    rotateWithRC(k3);
}

void AVLTree::inorder(AVLNode *t)
{
        if (t == nullptr)
            return;
        inorder(t->left);
        cout << t->data << endl;
        inorder(t->right);
}

void AVLTree::print()
{
    inorder(root);
}

// vector<Word*> AVLTree::search(string& word)
// {
//     vector<Word*> results;
//     search(word, results, root);
// }
//
// vector<Word*> AVLTree::search(string& word, vector<Word*> results, AVLNode *t)
// {
//     if (t == nullptr)
//         return results;
//     search(word, results, t->left);
//     if(word == )
//     search(word, results, t->right);
// }
