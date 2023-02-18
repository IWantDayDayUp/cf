#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;

        for (int j = 0; j < c; j++)
        {
            int t;
            cin >> t;
            t--;

            a[i] |= 1 << t;
        }
    }

    int ans = 0;

    for (int i = 1; i < (1 << m); i++)
    {
        int cur = 0;

        for (int j = 0; j < m; j++)
        {
            if ((i >> j) & 1)
            {
                cur |= a[j];
            }
        }

        if (cur == (1 << n) - 1)
        {
            ans += 1;
        }
    }

    cout << ans << endl;

    return 0;
}