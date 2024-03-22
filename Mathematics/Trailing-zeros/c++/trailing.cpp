#include <iostream>

int countTrailingZeros(int n)
{
    int res = 0;
    for (int i = 5; n / i >= 1; i *= 5)
    {
        res = res + (n / i);
    }

    return res;
}

int main()
{

    int number = 50;

    std::cout << countTrailingZeros(number);

    return 0;
}