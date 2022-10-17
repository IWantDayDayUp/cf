#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    long long s = 0, even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        long long cur;
        cin >> cur;

        s += cur;
        even += (cur % 2 == 0);
        odd += (cur % 2 == 1);
    }

    for (int i = 0; i < q; i++)
    {
        long long t, x;
        cin >> t >> x;

        if (t == 0)
        {
            s += even * x;

            if (x & 1)
            {
                odd += even;
                even = 0;
            }
        } else {

            s += odd * x;

            if (x & 1)
            {
                even += odd;
                odd = 0;
            }
        }

        cout << s << endl;
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