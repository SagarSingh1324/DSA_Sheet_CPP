/*
 * =====================================================================================
 *
 *       Filename:  find_if_same.cpp
 *
 *    Description:  find if two given trees are same 
 *
 *        Version:  1.0
 *        Created:  05/10/22 03:45:23 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 *   Organization:  
 *
 * =====================================================================================
*/


#include<iostream>
#include<vector>
#include "BinaryTree.h"
 
/*

struct TreeNode 
{
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : key(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : key(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : key(x), left(left), right(right) {}
};

class BinaryTree
{
    public:
        BinaryTree();
        ~BinaryTree();

        void insert(int key);
        TreeNode *search(int key);
        void destroy_tree();

    private:
        void destroy_tree(TreeNode *leaf);
        void insert(int key, TreeNode *leaf);
        TreeNode *search(int key, TreeNode *leaf);
        
        TreeNode *root;
};

*/

//_____secondary__functions______//
 
bool isSameTree(TreeNode* p, TreeNode* q) {
    
    if(p == nullptr && q == nullptr)
    {
        return true;
    }
    else if(p == nullptr && q != nullptr)
    {
        return false;
    }
    else if(p != nullptr && q == nullptr)
    {
        return false;
    }
    else if(p->key == q->key && p->left == nullptr && q->right == nullptr && p->right == nullptr && q->left == nullptr)
    {
        return true;
    }        
    else if(p->key == q->key && p->left != nullptr && q->right == nullptr && p->right == nullptr && q->left != nullptr)
    {
        return isSameTree(p->left, q->left);
    }        
    else if(p->key == q->key && p->left == nullptr && q->right != nullptr && p->right != nullptr && q->left == nullptr)
    {
        return isSameTree(p->right, q->right);
    }        
    else if(p->key == q->key && p->left != nullptr && q->right != nullptr && p->right != nullptr && q->left != nullptr)
    {
        return ( isSameTree(p->left, q->left) && isSameTree(p->right, q->right) );
    }
    
    return false;
}

 
//______main__function_____//
 
int main()
{

TreeNode node1, node2, node3;

node1.key = 5;
node2.key = 2;
node3.key = 7;

TreeNode* root1 = &node1;

node1.left = &node2;
node1.right = &node3;

TreeNode node4, node5, node6;

node4.key = 5;
node5.key = 2;
node6.key = 7;

TreeNode* root2 = &node4;

node4.left = &node5;
node4.right = &node6;

bool same = isSameTree(root1, root2);

std::cout<<same<<std::endl;    
 
return 0; 
}