#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<vector<int>> p(6, vector<int>(n + 1));
    string t = "abc";
    int cnt = 0;
    while (cnt == 0 || next_permutation(t.begin(), t.end()))
    {
        for (int i = 0; i < n; i++)
        {
            p[cnt][i + 1] = p[cnt][i] + (s[i] != t[i % 3]);
        }
        cnt += 1;
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int cost = r - l + 1;

        // aolution
        for (int i = 0; i < 6; i++)
        {
            cost = min(cost, p[i][r + 1] - p[i][l]);
        }

        cout << cost << endl;
    }

    return 0;
}