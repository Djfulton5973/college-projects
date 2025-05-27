#include <iostream>

enum MenuItem {

    Append = 1,
    Print,
    Exit

};

struct Node {

    int value;
    Node *next;

};

MenuItem getMenuItem();
Node* append(Node *pRoot);
void print(Node *pRoot);
Node* cleanup(Node *pRoot);

int main() {

    Node *root = nullptr;

    MenuItem menu;

    do {

        menu = getMenuItem();

        switch (menu) {

            case Append:

                root = append(root);
                break;
            case Print:

                print(root);
                break;
            case Exit:

                root = cleanup(root);

                std::cout << "Exit" << std::endl;

        }

    } while (menu != Exit);


    return 0;
}
MenuItem getMenuItem() {

    std::cout << "\nEnter one of the following choices:\n";
    std::cout << "\tAppend... " << MenuItem::Append << "\n";
    std::cout << "\tPrint.... " << MenuItem::Print << "\n";
    std::cout << "\tExit..... " << MenuItem::Exit << "\n";
    std::cout << "\t> ";

    int input;
    std::cin >> input;

    return static_cast<MenuItem>(input);

}
Node* append(Node *pRoot) {

    Node *newNode = new Node;


    std::cout << "\nEnter and integer: ";
    std::cin >> newNode->value;

    newNode->next = nullptr;

    if (!pRoot) {

        pRoot = newNode;

    }
    else {

        Node *lastNode = pRoot;

        while (lastNode->next) {

            lastNode = lastNode->next;

        }

    }

    return pRoot;

}

void print(Node *pRoot) {

    std::cout << "\nList {";

    while(pRoot) {

        std::cout << pRoot->value;

        if (pRoot->next)

            std::cout << ", ";

        pRoot = pRoot->next;

    }

    std::cout << "}" << std::endl;

}

Node* cleanup(Node *pRoot) {

    while (pRoot->next) {

        Node* pNext = pRoot->next;
        delete pRoot;
        pRoot = pNext;

    }

    return nullptr;

}
