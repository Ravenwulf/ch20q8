#include <iostream>
#include "EmployeeTree.h"

//**************************************************
// This version of insert inserts a number into    *
// a given subtree of the main binary search tree. *
//**************************************************
void EmployeeTree::insert(TreeNode*& tree, EmployeeInfo e)
{
    // If the tree is empty, make a new node and make it 
    // the root of the tree.
    if (!tree)
    {
        tree = new TreeNode(e);
        return;
    }

    // If num is already in tree: return.
    if (tree->employee.id == e.id)
        return;

    // The tree is not empty: insert the new node into the
    // left or right subtree.
    if (e.id < tree->employee.id)
        insert(tree->left, e);
    else
        insert(tree->right, e);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************
void EmployeeTree::destroySubtree(TreeNode* tree)
{
    if (!tree) return;
    destroySubtree(tree->left);
    destroySubtree(tree->right);
    // Delete the node at the root.
    delete tree;
}

//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************
void EmployeeTree::search(int id) const
{
    TreeNode* tree = root;

    while (tree)
    {
        if (tree->employee.id == id) {
            std::cout << "Employee Found: " << "\u001b[36;1m" << tree->employee.name << "\u001b[0m\n";
            return;
        }
        else if (id < tree->employee.id)
            tree = tree->left;
        else
            tree = tree->right;
    }
    throw EmployeeNotFound();
}

//********************************************
// remove deletes the node in the given tree *
// that has a value member the same as num.  *
//********************************************
void EmployeeTree::remove(TreeNode*& tree, int id)
{
    if (tree == nullptr) return;
    if (id < tree->employee.id)
        remove(tree->left, id);
    else if (id > tree->employee.id)
        remove(tree->right, id);
    else
        // We have found the node to delete.
        makeDeletion(tree);
}

//***********************************************************
// makeDeletion takes a reference to a tree whose root      *
// is to be deleted. If the tree has a single child, the    *
// the tree is replaced by the single child after the       *    
// removal of its root node. If the tree has two children   *
// the left subtree of the deleted node is attached at      *
// an appropriate point in the right subtree, and then      *
// the right subtree replaces the original tree.            *
//***********************************************************
void EmployeeTree::makeDeletion(TreeNode*& tree)
{
    // Used to hold node that will be deleted.
    TreeNode* nodeToDelete = tree;

    // Used to locate the  point where the 
    // left subtree is attached.
    TreeNode* attachPoint;

    if (tree->right == nullptr)
    {
        // Replace tree with its left subtree. 
        tree = tree->left;
    }
    else if (tree->left == nullptr)
    {
        // Replace tree with its right subtree.
        tree = tree->right;
    }
    else
        //The node has two children
    {
        // Move to right subtree.
        attachPoint = tree->right;

        // Locate the smallest node in the right subtree
        // by moving as far to the left as possible.
        while (attachPoint->left != nullptr)
            attachPoint = attachPoint->left;

        // Attach the left subtree of the original tree
        // as the left subtree of the smallest node 
        // in the right subtree.
        attachPoint->left = tree->left;

        // Replace the original tree with its right subtree.
        tree = tree->right;
    }

    // Delete root of original tree
    delete nodeToDelete;
}

//*********************************************************
// This function displays the values  stored in a tree    *  
// in inorder.                                            *
//*********************************************************
void EmployeeTree::displayInOrder(TreeNode* tree) const
{
    if (tree)
    {
        displayInOrder(tree->left);
        cout << tree->employee.name << "  ";
        displayInOrder(tree->right);
    }
}

void EmployeeTree::displayInColor(TreeNode* tree, std::string color) const
{
    if (tree)
    {
        displayInColor(tree->left, "\u001b[32;1m");
        cout << color << tree->employee.name << "  ";
        displayInColor(tree->right, "\u001b[31;1m");
        cout << "\u001b[0m";
    }
}

//*********************************************************
// This function displays the values stored in a tree     *
// in inorder.                                            *
//*********************************************************
void EmployeeTree::displayPreOrder(TreeNode* tree) const
{
    if (tree)
    {
        cout << tree->employee.name << "  ";
        displayPreOrder(tree->left);
        displayPreOrder(tree->right);
    }
}

//*********************************************************
// This function displays the values  stored  in a tree   *
// in postorder.                                          * 
//*********************************************************
void EmployeeTree::displayPostOrder(TreeNode* tree) const
{
    if (tree)
    {
        displayPostOrder(tree->left);
        displayPostOrder(tree->right);
        cout << tree->employee.name << "  ";
    }
}

void EmployeeTree::invertTree(TreeNode* tree) const {
    if (tree) {
        invertTree(tree->left);
        TreeNode* tempTree = tree->left;
        tree->left = tree->right;
        tree->right = tempTree;
        invertTree(tree->left);
    }

}

void EmployeeTree::countNodes(TreeNode* tree, int& count) const {
    if (tree)
    {
        count++;
        countNodes(tree->left, count);
        countNodes(tree->right, count);
    }
}