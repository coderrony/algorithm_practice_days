#include <bits/stdc++.h>
using namespace std;

void reverse(string str)
{
    static int i = 0;
    if (i == str.size())
    {
        return;
    }
    i += 1;
    reverse(str);
    cout << str[i -= 1] << " ";
}

int main()
{
    string str = "phitron";
    reverse(str);
    return 0;
}
