#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h1, w1;
    cin >> h1 >> w1;
    vector<vector<long long>> a(h1, vector<long long>(w1, 0));
    for (int i = 0; i < h1; i++)
    {
        for (int j = 0; j < w1; j++)
        {
            cin >> a[i][j];
        }
    }

    int h2, w2;
    cin >> h2 >> w2;
    vector<vector<long long>> b(h2, vector<long long>(w2, 0));
    for (int i = 0; i < h2; i++)
    {
        for (int j = 0; j < w2; j++)
        {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < (1 << h1); i++)
    {
        for (int j = 0; j < (1 << w1); j++)
        {
            vector<int> r, c;
            for (int k = 0; k < h1; k++)
            {
                if (i & (1 << k))
                {
                    r.emplace_back(k);
                }
            }
            
            for (int k = 0; k < w1; k++)
            {
                if (j & (1 << k))
                {
                    c.emplace_back(k);
                }
            }
            if (r.size() != h2 || c.size() != w2)
            {
                continue;
            }

            // cout << r.size() << ' ' << c.size() << endl;

            bool ok = true;
            for (int n = 0; n < h2; n++)
            {
                for (int m = 0; m < w2; m++)
                {
                    if (a[r[n]][c[m]] != b[n][m])
                    {
                        ok = false;
                        break;
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
        }
    }

    cout << "No" << endl;

    return 0;
}