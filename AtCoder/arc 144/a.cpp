#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cout << 2 * n << '\n';
    if (n % 4 > 0)
    {
        cout << n % 4;
    }
    for (int i = 0; i < n / 4; i++)
    {
        cout << 4;
    }
    cout << '\n';

    return 0;
}