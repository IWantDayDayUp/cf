#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];
        }
    }

    int cnt = 0;
    while (cnt < 4)
    {
        bool ok = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 0)
                {
                    continue;
                }

                if (cnt == 0)
                {
                    if (b[i][j] != 1)
                    {
                        ok = false;
                        break;
                    }
                } else if (cnt == 1)
                {
                    if (b[i][n - 1 - j] != 1)
                    {
                        ok = false;
                        break;
                    }
                } else if (cnt == 2)
                {
                    if (b[n - 1 - i][n - 1 - j] != 1)
                    {
                        ok = false;
                        break;
                    }
                } else if (cnt == 3)
                {
                    if (b[n - 1 - i][j] != 1)
                    {
                        ok = false;
                        break;
                    }
                }
            }

            if (!ok)
            {
                break;
            }
        }

        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }

        cnt += 1;
    }

    cout << "No" << endl;

    return 0;
}