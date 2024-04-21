#include <iostream>
#include <limits>

#define MAX 1000

class Queue
{
private:
    int front, rear, size;
    int array[MAX];

public:
    Queue()
    {
        front = size = 0;
        rear = MAX - 1;
    } // Initialize front and rear

    bool enqueue(int x)
    {
        if (size >= MAX)
        {
            std::cout << "Queue Overflow\n";
            return false;
        }
        else
        {
            rear = (rear + 1) % MAX;
            array[rear] = x;
            size++;
            std::cout << x << " enqueued into queue\n";
            return true;
        }
    }

    int dequeue()
    {
        if (size == 0)
        {
            std::cout << "Queue Underflow\n";
            return 0;
        }
        else
        {
            int x = array[front];
            front = (front + 1) % MAX;
            size--;
            return x;
        }
    }

    int peek()
    {
        if (size == 0)
        {
            std::cout << "Queue is Empty\n";
            return 0;
        }
        else
        {
            return array[front];
        }
    }

    bool isEmpty()
    {
        return (size == 0);
    }
};

int main()
{
    std::cout << "Welcome to Queue Manager!\n";
    Queue q;
    bool keepGoing = true;
    int choice;

    while (keepGoing)
    {
        std::cout << "What would you like to do?\n";
        std::cout << "1) Enqueue a value\n";
        std::cout << "2) Dequeue the front value\n";
        std::cout << "3) Peek the front value\n";
        std::cout << "4) Check if queue is empty\n";
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
            std::cout << "Enter the value you want to enqueue: ";
            std::cin >> value;
            if (!std::cin)
            {
                std::cout << "Invalid input!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            q.enqueue(value);
            break;
        }
        case 2:
        {
            int dequeuedValue = q.dequeue();
            if (dequeuedValue != 0)
            {
                std::cout << dequeuedValue << " dequeued from queue\n";
            }
            break;
        }
        case 3:
        {
            int frontValue = q.peek();
            if (frontValue != 0)
            {
                std::cout << "Front element is " << frontValue << std::endl;
            }
            break;
        }
        case 4:
        {
            std::cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << std::endl;
            break;
        }
        case 5:
            keepGoing = false;
            break;
        default:
            std::cout << "Invalid input!\n";
        }
    }
    std::cout << "Exiting Queue Manager.\n";
    return 0;
}
