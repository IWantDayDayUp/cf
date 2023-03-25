#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long t, p;
    cin >> n >> t >> p;

    vector<long long> a(n), b(n), c(n), x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> x[i] >> y[i];
    }

    string s = "";
    for (int i = 0; i < n; i++)
    {
        s = s + to_string(i);
    }

    long long ans = 0;
    do {

        // cout << s << endl;

        int tt = 0;
        long long cur = 0;

        for (int i = 0; i < n; i++)
        {
            int j = s[i] - '0';
            tt += x[j];

            if (tt > t)
            {
                break;
            }

            cur += max(c[j], a[j] - tt * b[j] - y[j] * p);
        }

        // cout << cur << endl;
        ans = max(ans, cur);
    } while (next_permutation(s.begin(), s.end()));

    cout << ans << endl;

    return 0;
}