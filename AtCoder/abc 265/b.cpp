#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, m, t;
    cin >> n >> m >> t;

    vector<long long> a(n);
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
    }

    vector<long long> b(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int p;
        long long v;
        cin >> p >> v;

        b[p] += v;
    }

    for (int i = 1; i < n; i++)
    {
        if (t > a[i])
        {
            t -= a[i];
        } else {
            cout << "No" << endl;
            return 0;
        }

        t += b[i + 1];
    }

    cout << "Yes" << endl;

    return 0;
}