#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<vector<int>> pre(n + 1, vector<int>(3, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            pre[i + 1][0] = pre[i][0] + 1;
            pre[i + 1][1] = pre[i][1];
            pre[i + 1][2] = pre[i][2];
        }
        else if (s[i] == '1')
        {
            pre[i + 1][0] = pre[i][0];
            pre[i + 1][1] = pre[i][1] + 1;
            pre[i + 1][2] = pre[i][2];
            cnt += 1;
        }
        else
        {
            pre[i + 1][0] = pre[i][0];
            pre[i + 1][1] = pre[i][1];
            pre[i + 1][2] = pre[i][2] + 1;
        }
    }
    // cout << cnt << endl;

    vector<int> ans;
    for (int i = 0; i + k - 1 < n; i++)
    {
        int a = pre[i + k][0] - pre[i][0];
        int b = pre[i + k][1] - pre[i][1];
        int c = pre[i + k][2] - pre[i][2];
        // cout << a << ' ' << b << ' ' << c << endl;

        if (a > 0 || cnt != b)
        {
            continue;
        }

        ans.emplace_back(i);
    }

    if (ans.size() == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}