/*
 * =====================================================================================
 *
 *       Filename:  DownUp_LeftRight_Traversal.cpp
 *
 *    Description:  traverse the tree from Bottom to Up and Left to Right (enhanced bfs)
 *                  
 *                  also can be used for left and right view 
 *                  for left view: in get_values function, get front element then clear the queue
 *                  for right view: use a stack in get_values, get top element then clear the stack
 *
 *        Version:  1.0
 *        Created:  05/10/22 01:59:12 AM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include<queue>
#include "BinaryTree.h"

//________interfaces of methods in binary tree header____________//

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

std::queue<TreeNode*> level_change(std::queue<TreeNode*> level_first)
{

    std::queue<TreeNode*> level_second;

    while(!level_first.empty())
    {

        if(level_first.front()->left != nullptr)
        {
        level_second.push(level_first.front()->left);
        }

        if(level_first.front()->right != nullptr)
        {
        level_second.push(level_first.front()->right);
        }

        level_first.pop();
    }

    return level_second;
}

std::vector<int> get_values(std::queue<TreeNode*> level_first)
{
    std::vector<int> values;

    while(!level_first.empty())
    {
        values.push_back(level_first.front()->key);
        level_first.pop();
    }

    return values;
}

std::vector<std::vector<int> > traverse(TreeNode* &root)
{
    std::vector<std::vector<int> > result;

    if(root = nullptr)
    {
        return result;
    }

    std::vector<int> values;

    std::queue<TreeNode*> temp;
    temp.push(root);

    int level=1;

    while(!temp.empty())
    {
        std::vector<int>  values = get_values(temp);
        result.push_back(values);

        temp = level_change(temp);
    }    


    return result;
}

//______main__function_____//

int main()
{
    /*
                        1
                2               3
            4      5        6       7

    */

    TreeNode node1(1), node2(2), node3(3), node4(4), node5(5), node6(6), node7(7);

    node1.left   = &node2;
    node1.right  = &node3;
    node2.left   = &node4;
    node2.right  = &node5;
    node3.left   = &node6;
    node3.right  = &node7;

    TreeNode* root = &node1;

    // result should be [[1],[2,3],[4,5,6,7]]

    std::vector<std::vector<int> > result;

    result = traverse(root);

    std::cout<<result[0][0]<<std::endl<<result[1][0]<<std::endl<<result[1][1]<<std::endl<<result[2][0]<<std::endl<<result[2][1]<<std::endl<<result[2][2]<<std::endl<<result[2][3]<<std::endl;

    return 0;
}
