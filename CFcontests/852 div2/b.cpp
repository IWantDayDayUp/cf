#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x, y;
    cin >> x >> y;


    if (x > y)
    {
        swap(x, y);
    }
    cout << (y - x) * 2 << endl;

    for (int i = x; i <= y; i++)
    {
        cout << i << ' ';
    }
    for (int i = y - 1; i > x; i--)
    {
        cout << i << ' ';
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}