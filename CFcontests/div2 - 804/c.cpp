#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    long long n;
    cin >> n;
    map<long long, long long> mp;
    for (long long i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        mp[num] = i;
    }

    long long l = mp[0], r = mp[0];
    long long mod = 1e9 + 7;
    long long ans = 1;

    for (long long i = 1; i < n; i++)
    {
        if (mp[i] < l)
        {
            l = mp[i];
        } else if (mp[i] > r)
        {
            r = mp[i];
        } else {
            ans = ans * (r - l + 1 - i) % mod;
        }
    }

    cout << ans << endl;
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