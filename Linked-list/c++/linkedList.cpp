#include <iostream>
#include <limits>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void display() {
        for (Node* current = head; current != nullptr; current = current->next) {
            std::cout << current->data << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::cout << "Welcome to LinkedList!\n";
    bool keepGoing = true;
    int choice;
    LinkedList list;
    while (keepGoing) {
        std::cout << "What would you like to do?\n1)Append\n2)Display\n3)Exit\nEnter the number corresponding to your choice: ";
        std::cin >> choice;
        if (!std::cin) {
            std::cout << "Invalid input!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        switch(choice) {
            case 1: {
                int value;
                std::cout << "Enter the value you want to append: ";
                std::cin >> value;
                if (!std::cin) {
                    std::cout << "Invalid input!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                list.append(value);
                break;
            }
            case 2:
                list.display();
                break;
            case 3:
                keepGoing = false;
                break;
            default:
                std::cout << "Invalid input!\n";
        }
    }
}
