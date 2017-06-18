#include <iostream>

using namespace std;

int main(void)
{
    int a, b, cnt = 1;
    cin >> a >> b;
    bool flag = true;

    while (a >= 0 && b >= 0)
    {
        if (flag) 
            a -= cnt;
        else
            b -= cnt;
        cnt += 1;
        flag = !flag;
    }
    if (a >= 0)
        cout << "Valera" << '\n';
    if (b >= 0)
        cout << "Vladik" << '\n';
    return 0;
}