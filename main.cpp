// Stahl, Daniel

#include "AVLTree.hpp"

int main() {
    AVLTree myAVLTree;
    //TreeNode* root;
    int userChoice;
    
    cout << setfill('-') << setw(46) << "\nAVL Tree Implementation\n" << setfill('-') << setw(22) << '\n';
    
    cout << "1. Insert an element into the tree\n" << "2. Display Balanced AVL Tree\n" << "3. InOrder traversal\n" << "4. PreOrder traversal\n" << "5. PostOrder traversal\n" << "6. Exit\n" << "Enter your Choice: ";
    cin >> userChoice;
    
    switch (userChoice) {
        case 1:
            //1. Insert an element into the tree
            myAVLTree.Insert(15);
            myAVLTree.Insert(18);
            myAVLTree.Insert(10);
            myAVLTree.Insert(7);
            myAVLTree.Insert(57);
            myAVLTree.Insert(6);
            myAVLTree.Insert(13);
            myAVLTree.Insert(12);
            myAVLTree.Insert(9);
            myAVLTree.Insert(65);
            myAVLTree.Insert(19);
            myAVLTree.Insert(16);
            myAVLTree.Insert(23);
            break;
    
        case 2:
            //2. Display Balanced AVL Tree
            break;
            
        case 3:
            //3. InOrder traversal
            break;
            
        case 4:
            //4. PreOrder traversal
            break;
            
        case 5:
            //5. PostOrder traversal
            break;
            
        case 6:
            //6. Exit
            break;
    }
    
    
    
}

