#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> p;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '2')
        {
            p.emplace_back(i);
        }
    }

    if (p.size() == 1 || p.size() == 2)
    {
        cout << "NO" << endl;
        return ;
    }

    vector<string> ans(n, string(n, '='));
    for (int i = 0; i < n; i++)
    {
        ans[i][i] = 'X';
    }
    for (int i = 0; i < p.size(); i++)
    {
        int b = (i + 1) % p.size();
        ans[p[i]][p[b]] = '+';
        ans[p[b]][p[i]] = '-';
    }

    cout << "YES" << endl;
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