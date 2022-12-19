#include <bits/stdc++.h>
using namespace std;

char getCapital(string str)
{
    static int i = 0;
    static char res;
    if (str.size() == i)
    {
        // cout << "HI";
        res = '0';
        return res;
    }
    if (isupper(str[i]))
    {
        res = str[i];
        return res;
    }
    i += 1;

    getCapital(str);
    return res;
}
int main()
{
    char c = getCapital("thisMyJob");
    cout << c;

    return 0;
}