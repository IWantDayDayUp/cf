#include <bits/stdc++.h>

using namespace std;

void solve() {
    int q;
    cin >> q;

    long long a = 1, b = 1;
    char mn = 'a', mx = 'a';

    for (int i = 0; i < q; i++)
    {
        long long d, k;
        string x;
        cin >> d >> k >> x;

        sort(x.begin(), x.end());

        if (d == 1)
        {
            a += x.size() * k;
            mn = max(mn, x[x.size() - 1]);
        } else {
            b += x.size() * k;
            mx = max(mx, x[x.size() - 1]);
        }

        // cout << a << ' ' << b << ' ' << mx << ' ' << x <<  endl;
        
        if (mx == 'a')
        {
            if (mn == 'a')
            {
                cout << (a < b ? "YES" : "NO") << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "YES" << endl;
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