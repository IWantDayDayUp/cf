#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> mat_mul(vector<vector<long long>> a, vector<vector<long long>> b, long long mod)
{
    int n = a.size();
    vector<vector<long long>> res(n, vector<long long>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }

    return res;
}

vector<vector<long long>> mat_pow(vector<vector<long long>> a, long long b, long long mod)
{
    int n = a.size();
    vector<vector<long long>> res(n, vector<long long>(n));

    for (int i = 0; i < n; i++)
    {
        res[i][i] = 1;
    }

    while (b)
    {
        if (b & 1)
        {
            res = mat_mul(res, a, mod);
        }
        a = mat_mul(a, a, mod);
        b >>= 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, x, m;
    cin >> a >> x >> m;

    vector<vector<long long>> f = {{a, 1}, {0, 1}}, g = mat_pow(f, x, m);

    cout << g[0][1] << endl;

    return 0;
}