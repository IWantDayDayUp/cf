#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (mp[num].size() < k)
        {
            cnt += 1;
            mp[num].emplace_back(i);
        }
    }

    vector<int> ans(n, 0);
    cnt -= cnt % k;
    int color = 0;
    for (auto & p : mp)
    {
        for (auto & i : p.second)
        {
            ans[i] = ++color;
            color %= k;
            if (--cnt == 0)
            {
                break;
            }
        }
        if (cnt == 0)
        {
            break;
        }
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
        slove();
    }

    return 0;
}