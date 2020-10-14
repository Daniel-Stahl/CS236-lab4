#include "AVLTree.hpp"

void AVLTree::Insert(int num) {
    TreeNode* tempRoot = root;
    bool nodeEmpty = true;
    
    while (nodeEmpty) {
        if (root == nullptr) {
            root = new TreeNode(num, nullptr, nullptr);
            nodeEmpty = false;
        } else if (num < tempRoot->value) {
            if (tempRoot->left == nullptr) {
                tempRoot->left = new TreeNode(num, nullptr, nullptr);
                nodeEmpty = false;
            } else {
                tempRoot = tempRoot->left;
            }
        } else if (num >= tempRoot->value) {
            if (tempRoot->right == nullptr) {
                tempRoot->right = new TreeNode(num, nullptr, nullptr);
                nodeEmpty = false;
            } else {
                tempRoot = tempRoot->right;
            }
        }
    }
}

TreeNode* AVLTree::RotateRight(TreeNode* node) {
    return root;
};

TreeNode* AVLTree::RotateLeft(TreeNode* node) {
    return root;
};

TreeNode* AVLTree::RotateRightLeft(TreeNode* node) {
    return root;
};

TreeNode* AVLTree::RotateLeftRight(TreeNode* node) {
    return root;
};

TreeNode* AVLTree::Balance(TreeNode* node) {
    return root;
};

int AVLTree::Height(TreeNode* node) const {
    return 0;
};

void AVLTree::DisplayInOrder(TreeNode* node) {

};

void AVLTree::DisplayPreOrder(TreeNode* node) {

};

void AVLTree::DisplayPostOrder(TreeNode* node) {

};

void AVLTree::EmptyTree(TreeNode* node) {
    
}

AVLTree::~AVLTree() {
    
};
