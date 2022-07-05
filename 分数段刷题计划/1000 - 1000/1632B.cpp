#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    int k = 0;
    while ((1 << (k + 1)) <= n - 1)
    {
        k += 1;
    }
    for (int i = (1 << k) - 1; i >= 0; i--)
    {
        cout << i << ' ';
    }
    for (int i = (1 << k); i < n; i++)
    {
        cout << i << ' ';
    }
    cout << endl;
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