#include <iostream>

int factorialRecursive(int n);
int factorialIterative(int n);

int main()
{
    std::cout << "factorialRecursive of 4 is " << factorialRecursive(4);
    std::cout << "\nfactorialRecursive of 2 is " << factorialRecursive(2);
    std::cout << "\nfactorialRecursive of 5 is " << factorialRecursive(5);
    std::cout << "\nfactorialRecursive of 1 is " << factorialRecursive(1);
    std::cout << "\nfactorialIterative of 4 is " << factorialIterative(4);
    std::cout << "\nfactorialIterative of 2 is " << factorialIterative(2);
    std::cout << "\nfactorialIterative of 5 is " << factorialIterative(5);
    std::cout << "\nfactorialIterative of 1 is " << factorialIterative(1) << "\n";
}

int factorialRecursive(int n)
{
    return (n == 0) ? 1 : (n * factorialRecursive(n - 1));
}

int factorialIterative(int n)
{
    int factorial = 1;
    while (n > 0)
    {
        factorial *= n;
        n -= 1;
    }
    return factorial;
}