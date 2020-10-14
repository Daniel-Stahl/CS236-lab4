#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct TreeNode {
    TreeNode(int newNum, TreeNode *newLeft = nullptr, TreeNode *newRight = nullptr) {
        value = newNum;
        left = newLeft;
        right = newRight;
    };
    
private:
    int value;
    TreeNode *left, *right;
    friend class AVLTree;
};

class AVLTree {
public:
    AVLTree() {root = nullptr;};
    void Insert(int num);
    TreeNode* RotateRight(TreeNode* node);
    TreeNode* RotateLeft(TreeNode* node);
    TreeNode* RotateRightLeft(TreeNode* node);
    TreeNode* RotateLeftRight(TreeNode* node);
    TreeNode* Balance(TreeNode* node); //Balance is called by insert
    int Height(TreeNode* node) const;
    void DisplayInOrder(TreeNode* node);
    void DisplayPreOrder(TreeNode* node);
    void DisplayPostOrder(TreeNode* node);
    void EmptyTree(TreeNode* node);
    ~AVLTree();
    
private:
    TreeNode* root;
};






