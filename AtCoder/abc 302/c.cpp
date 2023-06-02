#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    do {
        bool ok = true;

        for (int i = 0; i < n - 1; i++)
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                cnt += a[i][j] != a[i + 1][j];
            }
            if (cnt != 1)
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << "No" << endl;

    return 0;
}