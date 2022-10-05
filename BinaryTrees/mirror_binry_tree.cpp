/*
 * =====================================================================================
 *
 *       Filename:  mirror_binry_tree.cpp
 *
 *    Description:  turn a binary tree into its mirror image 
 *
 *        Version:  1.0
 *        Created:  05/10/22 01:56:47 AM IST
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

TreeNode* invertTree(TreeNode* root) 
{
    
    if(root == nullptr)
    {
        return nullptr;
    }
    else if(root->left == nullptr && root->right == nullptr)
    {
        return root;
    }
    else if(root->left != nullptr && root->right == nullptr)
    {
        invertTree(root->left);
        
        root->right = root->left;
        root->left = nullptr;
        
        return root;
        
    }
    else if(root->left == nullptr && root->right != nullptr)
    {
        invertTree(root->right);
        
        root->left = root->right;
        root->right = nullptr;
        
        return root;
    }
    else if(root->left != nullptr && root->right != nullptr)
    {
        invertTree(root->left);
        invertTree(root->right);
        
        TreeNode* swap;

        swap = root->left;
        root->left = root->right;
        root->right = swap;
        
        return root;
    }
    return root;
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

invertTree(root);

std::cout<<node1.left->key<<std::endl;
 
return 0; 
}
