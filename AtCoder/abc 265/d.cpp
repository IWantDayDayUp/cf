#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long p, q, r;
    cin >> n >> p >> q >> r;

    vector<long long> a(n + 1);
    vector<long long> pre(n + 2, 0);
    map<long long, int> mp; 
    mp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i + 1] += pre[i] + a[i];
        mp[pre[i] + a[i]] = i + 1;
    }

    // for (int i = 1; i <= n + 1; i++)
    // {
    //     cout << pre[i] << " \n"[i == n + 1];
    // }

    for (int i = 1; i <= n; i++)
    {
        if (mp.count(pre[i] + p) && mp.count(pre[i] + p + q) && mp.count(pre[i] + p + q + r))
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}