#include <iostream>

bool isPalindrome(int n)
{
    int reverse = 0;
    int initial = n;
    while (n > 0)
    {
        reverse = ((reverse * 10) + (n % 10));
        n /= 10;
    }
    return (initial == reverse);
}

int main()
{
    bool result;
    std::cout << "Checking 3733 for palindrome:";
    result = isPalindrome(3733);
    std::cout << result << std::endl;
    return 0;
}