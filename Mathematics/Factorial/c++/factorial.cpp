#include <iostream>

int factorial(int n);

int main()
{
    std::cout << "Factorial of 4 is " << factorial(4);
    std::cout << "\nFactorial of 2 is " << factorial(2);
    std::cout << "\nFactorial of 5 is " << factorial(5);
    std::cout << "\nFactorial of 1 is " << factorial(1);
}

int factorial(int n)
{
    return (n == 0) ? 1 : (n * factorial(n - 1));
}