#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    if (p[0] != n && p[n - 1] != n)
    {
        cout << -1 << endl;
    } else {
        for (int i = n - 1; i >= 0; i--)
        {
            cout << p[i] << " \n"[i == 0];
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