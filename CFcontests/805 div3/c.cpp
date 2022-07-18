#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, k;
    cin >> n >> k;

    map<long long, vector<int>> mp;
    // vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;

        // nums[i] = num;

        mp[num].emplace_back(i);
    }

    // cout << n << ' ' << k << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << nums[i] << " \n"[i == n - 1];
    // }

    for (int i = 0; i < k; i++)
    {
        long long a, b;
        cin >> a >> b;

        // cout << a << ' ' << b << endl;

        if (!mp.count(a) || !mp.count(b))
        {
            cout << "NO" << endl;
        } else {
            bool ok = false;
            for (auto & p : mp[a])
            {
                for (auto & idx : mp[b])
                {
                    if (p < idx)
                    {
                        ok = true;
                    }
                }
            }

            cout << (ok ? "YES" : "NO") << endl;
        }
    }
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