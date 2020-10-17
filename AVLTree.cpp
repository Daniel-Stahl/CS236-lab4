#include "AVLTree.hpp"

void AVLTree::Insert(int num) {
    TreeNode* newNode = new TreeNode(num, nullptr, nullptr, nullptr);
    
    if (root == nullptr) {
        root = newNode;
        return;
    }

    Insert(root, newNode);
    //BalanceFactor(newNode);
}

void AVLTree::Insert(TreeNode* parent, TreeNode* newNode) {
    if (newNode->value > parent->value) {
        if (parent->right == nullptr) {
            parent->right = newNode;
            newNode->parent = parent;
        } else {
            Insert(parent->right, newNode);
        }
    } else {
        if (parent->left == nullptr) {
            parent->left = newNode;
            newNode->parent = parent;
        } else {
            Insert(parent->left, newNode);
        }
    }
    
    BalanceFactor(newNode);
};

TreeNode* AVLTree::RotateRight(TreeNode* node) {
    TreeNode* tempNode = node->left;
    TreeNode* B = tempNode->right;
    tempNode->right = node;
    node->left = B;
    node->parent->left = tempNode;
    tempNode->parent = node->parent;
    node->parent = tempNode;
    cout << "Rotate right" << endl;
    return tempNode;
    
};

TreeNode* AVLTree::RotateLeft(TreeNode* node) {
    TreeNode* tempNode = node->right;
    TreeNode* B = tempNode->left;
    tempNode->left = node;
    node->right = B;
    node->parent->right = tempNode;
    tempNode->parent = node->parent;
    node->parent = tempNode;
    cout << "Rotate left" << endl;
    return tempNode;
};

TreeNode* AVLTree::RotateRightLeft(TreeNode* node) {
    TreeNode* tempNode = node->right;
    node->right = RotateRight(tempNode);
    cout << "Rotate right left" << endl;
    return RotateLeft(node);
};

TreeNode* AVLTree::RotateLeftRight(TreeNode* node) {
    TreeNode* tempNode = node->left;
    node->left = RotateLeft(tempNode);
    cout << "Rotate left right" << endl;
    return RotateRight(node);
};

void AVLTree::Balance(TreeNode* node) {
    if (Height(node->left) - Height(node->right) > 1) {
        if (Height(node->left->left) > Height(node->left->right)) {
            node = RotateRight(node);
        } else {
            node = RotateLeftRight(node);
        }
    } else {
        if (Height(node->right->right) > Height(node->right->left)) {
            node = RotateLeft(node);
        } else {
            node = RotateRightLeft(node);
        }
    }
    
    if (node->parent == nullptr) {
        root = node;
    }
        
};

int AVLTree::Height(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    } else {
        int heightLeft = Height(node->left);
        int heightRight = Height(node->right);
        return max(heightLeft, heightRight) + 1;
    }
};

void AVLTree::BalanceFactor(TreeNode* node) {
    if (Height(node->left) - Height(node->right) > 1 || Height(node->left) - Height(node->right) < -1) {
        Balance(node);
    }
    
    if (node->parent == nullptr) {
        return;
    } else {
        BalanceFactor(node->parent);
    }
}

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
