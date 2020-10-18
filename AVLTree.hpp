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
    TreeNode* Insert(TreeNode* node, int num);
    TreeNode* RotateRight(TreeNode* node);
    TreeNode* RotateLeft(TreeNode* node);
    TreeNode* RotateRightLeft(TreeNode* node);
    TreeNode* RotateLeftRight(TreeNode* node);
    TreeNode* Balance(TreeNode* node);
    int Difference(TreeNode* node);
    int Height(TreeNode* node);
    void DisplayTree();
    void DisplayTree(TreeNode* node, int level);
    void DisplayInOrder();
    void DisplayInOrder(TreeNode* node);
    void DisplayPreOrder();
    void DisplayPreOrder(TreeNode* node);
    void DisplayPostOrder();
    void DisplayPostOrder(TreeNode* node);
    void EmptyTree(TreeNode* node);
    ~AVLTree();
    
private:
    TreeNode* root;
};






