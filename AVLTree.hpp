#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct TreeNode {
    TreeNode(int newNum, TreeNode *newLeft = nullptr, TreeNode *newRight = nullptr, TreeNode *newParent = nullptr) {
        value = newNum;
        left = newLeft;
        right = newRight;
        parent = newParent;
    };
    
private:
    int value;
    TreeNode *left, *right, *parent;
    friend class AVLTree;
};

class AVLTree {
public:
    AVLTree() {root = nullptr;};
    void Insert(int num);
    void Insert(TreeNode* parent, TreeNode* newNode);
    TreeNode* RotateRight(TreeNode* node);
    TreeNode* RotateLeft(TreeNode* node);
    TreeNode* RotateRightLeft(TreeNode* node);
    TreeNode* RotateLeftRight(TreeNode* node);
    void Balance(TreeNode* node);
    void BalanceFactor(TreeNode* node);
    int Height(TreeNode* node);
    void DisplayInOrder(TreeNode* node);
    void DisplayPreOrder(TreeNode* node);
    void DisplayPostOrder(TreeNode* node);
    void EmptyTree(TreeNode* node);
    ~AVLTree();
    
private:
    TreeNode* root;
};






