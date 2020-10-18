#include "AVLTree.hpp"

void AVLTree::Insert(int num) {
    root = Insert(root, num);
    root = Balance(root);
}

TreeNode* AVLTree::Insert(TreeNode* node, int num) {
    if (node == NULL) {
        node = new TreeNode(num, NULL, NULL);
    } else if(num < node->value) {
        node->left = Insert(node->left, num);
        node->left = Balance(node->left);
    } else {
        node->right = Insert(node->right, num);
        node->right = Balance(node->right);
    }
    
    return node;
}

TreeNode* AVLTree::RotateRight(TreeNode* node) {
    TreeNode* tempNode = node->left;
    TreeNode* B = tempNode->right;
    tempNode->right = node;
    node->left = B;
    cout << "Rotate right" << endl;
    return tempNode;
}

TreeNode* AVLTree::RotateLeft(TreeNode* node) {
    TreeNode* tempNode = node->right;
    TreeNode* B = tempNode->left;
    tempNode->left = node;
    node->right = B;
    cout << "Rotate left" << endl;
    return tempNode;
}

TreeNode* AVLTree::RotateRightLeft(TreeNode* node) {
    TreeNode* tempNode = node->right;
    node->right = RotateRight(tempNode);
    cout << "Rotate right left" << endl;
    return RotateLeft(node);
}

TreeNode* AVLTree::RotateLeftRight(TreeNode* node) {
    TreeNode* tempNode = node->left;
    node->left = RotateLeft(tempNode);
    cout << "Rotate left right" << endl;
    return RotateRight(node);
}

TreeNode* AVLTree::Balance(TreeNode* node) {
    int balanceFactor = Height(node->left) - Height(node->right);
    if (balanceFactor > 1) {
        if (Height(node->left->left) - Height(node->left->right) >= 1) {
            node = RotateRight(node);
        } else {
            node = RotateLeftRight(node);
        }
    } else if(balanceFactor < -1){
        if (Height(node->right->left) - Height(node->right->right) < 0) {
            node = RotateLeft(node);
        } else {
            node = RotateRightLeft(node);
        }
    }
    
    return node;
}

int AVLTree::Height(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    } else {
        int heightLeft = Height(node->left);
        int heightRight = Height(node->right);
        
        if(heightLeft > heightRight) {
            return heightLeft + 1;
        } else {
            return heightRight + 1;
        }
    }
}

void AVLTree::Difference(TreeNode* node) {

}

void AVLTree::DisplayInOrder(TreeNode* node) {

}

void AVLTree::DisplayPreOrder(TreeNode* node) {

}

void AVLTree::DisplayPostOrder(TreeNode* node) {

}

void AVLTree::EmptyTree(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    
    EmptyTree(node->left);
    EmptyTree(node->right);
    delete node;
}

AVLTree::~AVLTree() {
    EmptyTree(root);
    root = NULL;
}
