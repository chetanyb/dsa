#include <iostream>
#include <limits>

#define MAX 1000

class Stack
{
private:
    int top;
    int a[MAX];

public:
    Stack() { top = -1; }

    bool push(int x)
    {
        if (top >= (MAX - 1))
        {
            std::cout << "Stack Overflow\n";
            return false;
        }
        else
        {
            a[++top] = x;
            std::cout << x << " pushed into stack\n";
            return true;
        }
    }

    int pop()
    {
        if (top < 0)
        {
            std::cout << "Stack Underflow\n";
            return 0;
        }
        else
        {
            return a[top--];
        }
    }

    int peek()
    {
        if (top < 0)
        {
            std::cout << "Stack is Empty\n";
            return 0;
        }
        else
        {
            return a[top];
        }
    }

    bool isEmpty()
    {
        return (top < 0);
    }
};

int main()
{
    std::cout << "Welcome to Stack Manager!\n";
    Stack s;
    bool keepGoing = true;
    int choice;

    while (keepGoing)
    {
        std::cout << "What would you like to do?\n";
        std::cout << "1) Push a value\n";
        std::cout << "2) Pop the top value\n";
        std::cout << "3) Peek the top value\n";
        std::cout << "4) Check if stack is empty\n";
        std::cout << "5) Exit\n";
        std::cout << "Enter the number corresponding to your choice: ";
        std::cin >> choice;

        if (!std::cin)
        {
            std::cout << "Invalid input!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            int value;
            std::cout << "Enter the value you want to push: ";
            std::cin >> value;
            if (!std::cin)
            {
                std::cout << "Invalid input!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            s.push(value);
            break;
        }
        case 2:
        {
            int poppedValue = s.pop();
            if (poppedValue != 0)
            {
                std::cout << poppedValue << " popped from stack\n";
            }
            break;
        }
        case 3:
        {
            int topValue = s.peek();
            if (topValue != 0)
            {
                std::cout << "Top element is " << topValue << std::endl;
            }
            break;
        }
        case 4:
        {
            std::cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << std::endl;
            break;
        }
        case 5:
            keepGoing = false;
            break;
        default:
            std::cout << "Invalid input!\n";
        }
    }
    std::cout << "Exiting Stack Manager.\n";
    return 0;
}
