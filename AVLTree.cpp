#include "AVLTree.h"


AVLTree::AVLTree()
{
    root = nullptr;
}

void AVLTree::insert(string &val)
{
    insert(val, root);
}

void AVLTree::insert(string &x, AVLNode *&t)
{
    if(t==nullptr)
        t = new AVLNode(x, nullptr, nullptr);
    else if(x < t ->SampleData)
    {
        insert(x, t->left);
        if(height(t->left)-height(t->right)==2)
            if(x < t ->left->SampleData)//case I
                rotateWithLC(t);
            else//case II
                doubleWithLC(t);
    }
    else if(t->SampleData < x)
    {
        insert(x, t->right);
        if(height(t->right)-height(t->left)==2)
            if(t->right->SampleData < x)
                rotateWithRC(t);//case IV
            else
                doubleWithRC(t);//case III
    }
    else
        ;
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
        cout<<t->SampleData<<endl;
        inorder(t->right);
}

void AVLTree::print()
{
    cout << "root: " << root->SampleData << endl;
    cout << "root->left: " << root->left->SampleData << endl;
}
