#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<vector<int>>> src(n, vector<vector<int>>(n, vector<int>()));
    src[0][0].push_back(a[0][0]);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i + j >= n)
            {
                continue;
            }
            if (i > 0)
            {
                for (const int x : src[i - 1][j])
                {
                    src[i][j].push_back(x ^ a[i][j]);
                }
            }
            if (j > 0)
            {
                for (const int x : src[i][j - 1])
                {
                    src[i][j].push_back(x ^ a[i][j]);
                }
            }
        }
    }

    vector<vector<vector<int>>> dst(n, vector<vector<int>>(n, vector<int>()));
    dst[n - 1][n - 1].push_back(a[n - 1][n - 1]);

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            if (i + j < n - 1)
            {
                continue;
            }
            if (i + 1 < n)
            {
                for (const int x : dst[i + 1][j])
                {
                    dst[i][j].push_back(x ^ a[i][j]);
                }
            }
            if (j + 1 < n)
            {
                for (const int x : dst[i][j + 1])
                {
                    dst[i][j].push_back(x ^ a[i][j]);
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        const int j = n - i - 1;
        sort(begin(dst[i][j]), end(dst[i][j]));

        for (const int x : src[i][j])
        {
            const int val = a[i][j] ^ x;
            ans += upper_bound(begin(dst[i][j]), end(dst[i][j]), val) - lower_bound(begin(dst[i][j]), end(dst[i][j]), val);
        }
    }

    cout << ans << '\n';

    return 0;
}