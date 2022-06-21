#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int n = a + b + 1;
    vector<int> ans(n);

    if (a == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << n - i << " \n"[i == n - 1];
        }
    } else {
        cout << 1 << ' ';
        for (int i = n - a + 1; i <= n; i++)
        {
            cout << i << ' ';
        }
        for (int i = 1 + b; i > 1; i--)
        {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}