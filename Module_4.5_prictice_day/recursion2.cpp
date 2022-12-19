#include <bits/stdc++.h>
using namespace std;

int digitSum(int n)
{
    static int sum = 0;
    if (n == 0)
    {
        return 0;
    }

    digitSum(n / 10);

    return sum += n % 10;
}
int main()
{

    int result = digitSum(123);

    cout << result;

    return 0;
}