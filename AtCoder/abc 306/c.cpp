#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> ans;
    map<int, int> mp;
    for (int i = 0; i < 3 * n; i++)
    {
        int cur;
        cin >> cur;

        if (++mp[cur] == 2)
        {
            ans.emplace_back(cur);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}