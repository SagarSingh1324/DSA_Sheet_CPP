/*
 * =====================================================================================
 *
 *       Filename:  find_height.cpp
 *
 *    Description:  find height of a binary tree given its pointer to its 
 *		    root node 
 *
 *        Version:  1.0
 *        Created:  05/10/22 01:54:49 AM IST
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
#include<algorithm>
#include "BinaryTree.h"

//__________interfaces of methods in BinaryTree class_________//

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
 
int findHeight(TreeNode* root)
{
    if(root == nullptr)
    {
        return 0;
    }
    else if(root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }
    else if(root->left == nullptr)
    {
        return 1 + findHeight(root->right);
    }
    else if(root->right == nullptr)
    {
        return 1 + findHeight(root->left);
    }
    else 
    {
        return (1 + std::max(findHeight(root->left), findHeight(root->right)));
    }
}
 
 
//______main__function_____//
 
int main()
{

TreeNode node1, node2, node3;

node1.key = 5;
node2.key = 2;
node3.key = 7;

TreeNode* root = &node1;

node1.left = &node2;
node1.right = &node3;

std::cout<<findHeight(root)<<std::endl;



return 0; 
}
