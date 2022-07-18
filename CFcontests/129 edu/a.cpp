#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, m;
    cin >> n;

    int mx1 = -1, mx2 = -1;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        mx1 = max(mx1, temp);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        mx2 = max(mx2, temp);
    }

    // cout << mx1 << ' ' << mx2 << endl;

    if (mx1 > mx2)
    {
        cout << "Alice" << endl;
        cout << "Alice" << endl;
        return;
    } else if (mx1 < mx2) {
        cout << "Bob" << endl;
        cout << "Bob" << endl;
        return;
    }
    cout << "Alice" << endl;
    cout << "Bob" << endl;
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