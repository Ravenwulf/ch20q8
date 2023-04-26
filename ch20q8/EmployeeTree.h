#include <string>
#include "EmployeeInfo.h"

class EmployeeTree
{
private:
    // The TreeNode struct is used to build the tree.
    struct TreeNode
    {
        EmployeeInfo employee;
        TreeNode* left;
        TreeNode* right;
        TreeNode(EmployeeInfo value1,
            TreeNode* left1 = nullptr,
            TreeNode* right1 = nullptr)
        {
            employee = value1;
            left = left1;
            right = right1;
        }
    };

    TreeNode* root;     // Pointer to the root of the tree

    // Various helper member functions.
    void insert(TreeNode*&, EmployeeInfo);
    void destroySubtree(TreeNode*);
    void remove(TreeNode*&, int);
    void makeDeletion(TreeNode*&);
    void displayInOrder(TreeNode*) const;
    void displayPreOrder(TreeNode*) const;
    void displayPostOrder(TreeNode*) const;
    void displayInColor(TreeNode*, std::string c) const;
    void invertTree(TreeNode*) const;
    void countNodes(TreeNode*, int& c) const;

public:
    // These member functions are the public interface.
    EmployeeTree()		// Constructor
    {
        root = nullptr;
    }
    ~EmployeeTree()		// Destructor
    {
        destroySubtree(root);
    }
    void insert(EmployeeInfo e)
    {
        insert(root, e);
    }
    bool search(int) const;
    void remove(int num)
    {
        remove(root, num);
    }
    void showInOrder(void) const
    {
        displayInOrder(root);
    }
    void showPreOrder() const
    {
        displayPreOrder(root);
    }
    void showPostOrder() const
    {
        displayPostOrder(root);
    }
    void invertTree() const {
        invertTree(root);
    }
    void showInColor(void) const
    {
        displayInColor(root, "\u001b[32;1m");
    }
    //int countNodes() const { return countNodes(root); }
    bool isBalanced() const {
        int count = 0;
        countNodes(root->left, count);
        int left = count;

        count = 0;
        countNodes(root->right, count);
        int right = count;

        std::cout << "\nLeft: " << left << " Right: " << right << std::endl;
        return (left == right);
    }
};

