#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n + 1);
    map<long long, int> mp;
    long long sum = 0;
    mp[sum] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        mp[sum] = i;
    }

    int ans = n;
    long long pre = 0;
    for (int i = 1; i <= n; i++)
    {
        pre += a[i];
        if (sum % pre != 0)
        {
            continue;
        }

        long long cur = pre;
        bool ok = true;
        
        vector<int> p = {0};
        while (cur <= sum)
        {
            if (mp[cur] == 0)
            {
                ok = false;
                break;
            }
            p.emplace_back(mp[cur]);
            cur += pre;
        }

        if (ok) 
        {
            // cout << i << ' ' << temp << endl;
            int temp = 0;
            for (int j = 1; j < p.size(); j++)
            {
                temp = max(temp, p[j] - p[j - 1]);
            }
            ans = min(ans, temp);
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
        solve();
    }

    return 0;
}