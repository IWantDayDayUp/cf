#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

map<int, vector<int>> mp;
const int N = 200000 + 5;
long long l[N], r[N];
int ans = 0;

int dfs(int u)
{
    long long res = 0;
    for (int & v : mp[u])
    {
        res += dfs(v);
    }
    if (res < l[u])
    {
        ans += 1;
        res = r[u];
    }

    return min(res, r[u]);
}

void slove() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        mp[i].clear();
    }

    for (int i = 2; i <= n; i++)
    {
        int fa;
        cin >> fa;
        mp[fa].emplace_back(i);
    }
    
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }

    ans = 0;
    dfs(1);

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