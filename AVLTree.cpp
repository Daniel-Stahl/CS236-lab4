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
    TreeNode* tempNodeA = node->left;
    TreeNode* tempNodeB = tempNodeA->right;
    tempNodeA->right = node;
    node->left = tempNodeB;
    return tempNodeA;
}

TreeNode* AVLTree::RotateLeft(TreeNode* node) {
    TreeNode* tempNodeA = node->right;
    TreeNode* tempNodeB = tempNodeA->left;
    tempNodeA->left = node;
    node->right = tempNodeB;
    return tempNodeA;
}

TreeNode* AVLTree::RotateRightLeft(TreeNode* node) {
    TreeNode* tempNode = node->right;
    node->right = RotateRight(tempNode);
    return RotateLeft(node);
}

TreeNode* AVLTree::RotateLeftRight(TreeNode* node) {
    TreeNode* tempNode = node->left;
    node->left = RotateLeft(tempNode);
    return RotateRight(node);
}

TreeNode* AVLTree::Balance(TreeNode* node) {
    int balanceFactor = Height(node->left) - Height(node->right);
    if (balanceFactor > 1) {
        if (Difference(node->left) >= 1) {
            node = RotateRight(node);
        } else {
            node = RotateLeftRight(node);
        }
    } else if(balanceFactor < -1){
        if (Difference(node->right) < 0) {
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

int AVLTree::Difference(TreeNode* node) {
    return Height(node->left) - Height(node->right);
}

void AVLTree::DisplayTree() {
    TreeNode* tempNode = root;
    DisplayTree(tempNode, 0);
}

void AVLTree::DisplayTree(TreeNode* node, int level) {
    if (node == NULL) {
        return;
    }
    
    level += 15;
    
    DisplayTree(node->right, level);
    
    cout << endl;
    
    if (node == root) {
        cout << "Root -> ";
    }
    
    for (int x = 15; x < level; x++) {
        cout << " ";
    }
    
    cout << node->value << "\n";
    
    DisplayTree(node->left, level);
    
}

void AVLTree::DisplayInOrder() {
    TreeNode* node = root;
    DisplayInOrder(node);
}

void AVLTree::DisplayInOrder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    
    DisplayInOrder(node->left);
    cout << node->value << "\t";
    DisplayInOrder(node->right);
}

void AVLTree::DisplayPreOrder() {
    TreeNode* node = root;
    DisplayPreOrder(node);
}

void AVLTree::DisplayPreOrder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    
    cout << node->value << "\t";
    DisplayPreOrder(node->left);
    DisplayPreOrder(node->right);
}

void AVLTree::DisplayPostOrder() {
    TreeNode* node = root;
    DisplayPostOrder(node);
}

void AVLTree::DisplayPostOrder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    
    DisplayPostOrder(node->left);
    DisplayPostOrder(node->right);
    
    cout << node->value << "\t";
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
