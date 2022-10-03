#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n + 1);
    vector<int> d(n + 1), p(n + 1);
    d[1] = 0;
    int mx = 0;
    for (int i = 2; i <= n; i++)
    {
        int pa;
        cin >> pa;
        p[i] = pa;
        adj[pa].emplace_back(i);
        d[i] = d[pa] + 1;

        mx = max(mx, d[i]);
    }

    int ans;

    function<int(int, int)> dfs = [&](int u, int mid)
    {
        int temp = 0;
        for (auto & v : adj[u])
        {
            temp = max(temp, dfs(v, mid));
        }
        // 根节点或直连, 不用调整
        if (u == 1 || p[u] == 1) 
        {
            return 0;
        }

        if (temp + 1 < mid) 
        {
            return temp + 1;
        }

        ans += 1;

        return 0;
    };

    auto check = [&](int mid)
    {
        ans = 0;
        dfs(1, mid);
        
        return ans <= k;
    };

    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;
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