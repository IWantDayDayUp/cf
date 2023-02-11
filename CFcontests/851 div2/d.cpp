#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long mod = 1e9 + 7;

    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> num(n + 1);
    num[0] = 1; 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        num[i + 1] = num[i] * 2 % mod;
    }


    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int cur = a[j] - a[i];

            long long l = lower_bound(a.begin(), a.end(), a[i] - cur) - a.begin();
            long long r = a.end() - lower_bound(a.begin(), a.end(), a[j] + cur);

            // cout << a[i] << ' ' << a[j] << ' ' << cur << ' ' << l << ' ' << r << endl;

            ans += num[l + r];
            ans %= mod;
        }
    }

    cout << ans << endl;

    return 0;
}