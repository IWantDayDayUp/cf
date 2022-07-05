#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<string> ans(n, string(n, 'S'));
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j += 2)
            {
                if (k <= 0) break;
                ans[i][j] = 'L';
                k -= 1;
            }
            if (k <= 0)
            {
                break;
            }
        } else {
            for (int j = 1; j < n; j += 2)
            {
                if (k <= 0) break;
                ans[i][j] = 'L';
                k -= 1;
            }
            if (k <= 0)
            {
                break;
            }
        }
    }

    if (k == 0)
    {
        cout << "YES" << endl;
        for (auto & s : ans)
        {
            cout << s << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}