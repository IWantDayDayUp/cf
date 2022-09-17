#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k, a, b;
    cin >> n >> k >> a >> b;

    if (abs(a - b) > k)
    {
        cout << "YES" << endl;
    } else {

        if (a > b)
        {
            swap(a, b);
        }

        if (a - 1 > k)
        {
            cout << "YES" << endl;
        } else if (n - b > k)
        {
            cout << "YES" << endl;
        } else if (n - a > k && b - 1 > k)
        {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
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