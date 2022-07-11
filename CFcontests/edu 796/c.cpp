#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove()
{
    int n;
    char c = 0;
    cin >> n;
    n = n * 2 + 1;
    while (n--)
    {
        string s;
        cin >> s;
        for (auto x : s)
            c ^= x;
    }

    cout << c << endl;;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        slove();
    }

    return 0;
}