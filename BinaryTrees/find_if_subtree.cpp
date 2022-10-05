/*
 * =====================================================================================
 *
 *       Filename:  find_if_subtree.cpp
 *
 *    Description:  find if 2nd B Tree is a subtree of first one 
 *
 *        Version:  1.0
 *        Created:  05/10/22 01:58:08 AM IST
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
 
//_____secondary__functions______//

bool isSame(TreeNode* r1, TreeNode* r2) 
{
    bool x =0; 

    if(r1 == r2)
    {
        x=1;
    }

    bool y =  (r1 && r2 && r1->key == r2->key && isSame(r1->left, r2->left) && isSame(r1->right, r2->right));

    return (x || y) ;
}


bool isSubtree(TreeNode* root, TreeNode* subRoot) 
{
    return root && (isSame(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
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

bool same = isSame(root1, root2);

std::cout<<same<<std::endl;  
 
return 0; 
}

