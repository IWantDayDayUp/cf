#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> p(n + 1);
    for (int i = 0; i < n; i++)
    {
        p[nums[i]].emplace_back(i);
    }

    vector<int> ans;
    for (int i = 0; i < n; )
    {
        int j = i + 1;
        int x = 0;

        while (true)
        {
            auto it = lower_bound(p[x].begin(), p[x].end(), i);
            if (it == p[x].end())
            {
                break;
            }
            j = max(j, *it + 1);
            x += 1;
        }

        i = j;
        ans.emplace_back(x);
    }
    
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " \n"[i == ans.size() - 1];
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