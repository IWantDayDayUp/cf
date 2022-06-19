#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << i << endl;
        }
        return ;
    }
    if (n % 2 == 1)
    {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cout << (i + n * j) << ' ';
            }
            cout << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        slove();
    }

    return 0;
}