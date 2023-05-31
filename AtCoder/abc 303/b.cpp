#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> adj(n, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
    {
        int left = -1, right = -1;
        for (int j = 0; j < n; j++)
        {
            left = right;
            cin >> right;
            if (left == -1)
            {
                continue;
            } else {
                adj[left - 1][right - 1] = true;
                adj[right - 1][left - 1] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans += adj[i][j] == false;
        }
    }

    cout << ans << endl;

    return 0;
}