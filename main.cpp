// Stahl, Daniel

#include "AVLTree.hpp"

int main() {
    AVLTree myAVLTree;
    int userChoice;
    
    do {
        cout << setfill('-') << setw(46) << "\nAVL Tree Implementation\n" << setfill('-') << setw(22) << '\n';
        cout << "1. Insert an element into the tree\n" << "2. Display Balanced AVL Tree\n" << "3. InOrder traversal\n" << "4. PreOrder traversal\n" << "5. PostOrder traversal\n" << "6. Exit\n" << "Enter your Choice: ";
        cin >> userChoice;
        
        switch (userChoice) {
            case 1:
                int num;
                //1. Insert an element into the tree
                cout << "Enter value to be inserted: ";
                cin >> num;
                myAVLTree.Insert(num);
                break;
            case 2:
                //2. Display Balanced AVL Tree
                myAVLTree.DisplayTree();
                break;
                
            case 3:
                //3. InOrder traversal
                myAVLTree.DisplayInOrder();
                break;
                
            case 4:
                //4. PreOrder traversal
                myAVLTree.DisplayPreOrder();
                break;
                
            case 5:
                //5. PostOrder traversal
                myAVLTree.DisplayPostOrder();
                break;
                
            case 6:
                //6. Exit
                cout << "Program closing down";
                break;
        }
        cout << '\n';
    } while(userChoice != 6);
}
