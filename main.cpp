// Stahl, Daniel

#include "AVLTree.hpp"

int main() {
    AVLTree myAVLTree;
    int userChoice;
    
    cout << setfill('-') << setw(46) << "\nAVL Tree Implementation\n" << setfill('-') << setw(22) << '\n';
    
    cout << "1. Insert an element into the tree\n" << "2. Display Balanced AVL Tree\n" << "3. InOrder traversal\n" << "4. PreOrder traversal\n" << "5. PostOrder traversal\n" << "6. Exit\n" << "Enter your Choice: ";
    cin >> userChoice;
    
    switch (userChoice) {
        case 1:
            //1. Insert an element into the tree
            myAVLTree.Insert(1);
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

