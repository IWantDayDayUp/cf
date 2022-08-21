#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k, b, s;
    cin >> n >> k >> b >> s;

    // if ((s - b * k) > (n - 1) * (k - 1) || k * b > s)
    // {
    //     cout << -1 << endl;
    //     return ;
    // }
    
    vector<long long> ans(n);
    ans[0] = b * k;
    long long left = s - b * k;
    if (left < 0)
    {
        cout << -1 << endl;
        return ;
    }
    for (int i = 1; i < n; i++)
    {
        if (left >= k - 1)
        {
            ans[i] = k - 1;
            left -= (k - 1);
        } else {
            ans[i] = left;
            left = 0;
        }
    }
    if (left >= k)
    {
        cout << -1 << endl;
        return ;
    } else {
        ans[0] += left;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " \n"[i == n - 1];
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