#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    if (n == 1)
    {
        if (s == 1)
        {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << s << endl;
            cout << s / 2 << endl;
        }
    } else {
        int left = s - n;
        int mx = 1 + left;

        if (mx - 1 > n - 1)
        {
            cout << "YES" << endl;
            cout << mx << ' ';
            for (int i = 0; i < n - 1; i++)
            {
                cout << 1 << " \n"[i == n - 2];
            }
            cout << mx - 1 << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}