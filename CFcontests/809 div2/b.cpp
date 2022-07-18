#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;

        mp[c].emplace_back(i);
    }

    vector<int> ans(n, 0);
    for (auto & p : mp)
    {
        int cur = p.first;
        set<int> st;

        ans[cur - 1] = 1;

        if (p.second.size() == 1)
        {
            continue;
        }

        vector<int> nums;
        for (int i = 1; i < p.second.size(); i++)
        {
            int diff = p.second[i] - p.second[i - 1];
            if (diff % 2 == 0)
            {
                if (nums.size() > 0)
                {
                    nums.end() += diff;
                }
                continue;
            } else {
                nums.emplace_back(diff);
            }

            ans[cur - 1] = max(ans[cur - 1], (int)nums.size() + 1);
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