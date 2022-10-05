
 
//------------defintion of Node of a tree--------------//
 
#include<iostream>


struct TreeNode 
{
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : key(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : key(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : key(x), left(left), right(right) {}
};


//--------------defintion / interface of binary tree class--------------//


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


//-----------member functions if the binary tree class---------------------//


//________object constructor________//


BinaryTree::BinaryTree()
{
  root = nullptr;
}


//________object destructor_________//


BinaryTree::~BinaryTree()
{
  destroy_tree();
}

//___________tree for destroying the function___________//

void BinaryTree::destroy_tree(TreeNode *leaf)
{
  if(leaf != nullptr)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

//____________funcion for inserting a new TreeNode_________//

void BinaryTree::insert(int key, TreeNode *leaf)
{
  if(key < leaf->key)
  {
    if(leaf->left != nullptr)
    insert(key, leaf->left);
    else
    {
      leaf->left = new TreeNode;
      leaf->left->key = key;
      leaf->left->left = nullptr;    //Sets the left child of the child TreeNode to nullptr
      leaf->left->right = nullptr;   //Sets the right child of the child TreeNode to nullptr
    }  
  }
  else if(key >= leaf->key)
  {
    if(leaf->right != nullptr)
      insert(key, leaf->right);
    else
    {
      leaf->right = new TreeNode;
      leaf->right->key = key;
      leaf->right->left = nullptr;  //Sets the left child of the child TreeNode to nullptr
      leaf->right->right = nullptr; //Sets the right child of the child TreeNode to nullptr
    }
  }
}

//_____________search for a TreeNode in a tree_____________//

TreeNode *BinaryTree::search(int key, TreeNode *leaf)
{
  if(leaf != nullptr)
  {
    if(key == leaf->key)
      return leaf;
    if(key < leaf->key)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return nullptr;
}

// ___________function for intitializing the keyue of root TreeNode_____________//

void BinaryTree::insert(int key)
{
  if(root != nullptr)
    insert(key, root);
  else
  {
    root=new TreeNode;
    root->key = key;
    root->left = nullptr;
    root->right = nullptr;
  }
}

//_________public version of search for a key in a tree________________//

TreeNode *BinaryTree::search(int key)
{
  return search(key, root);
}

//___________public version of function for destroying a tree_________//

void BinaryTree::destroy_tree()
{
  destroy_tree(root);
}





 