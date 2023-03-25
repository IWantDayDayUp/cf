#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<int> A(N), B(N), C(M), D(M);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> C[i] >> D[i];
    }

    auto check = [&](int x, int y)
    {
        vector<long long> a(N), b(M);
        for (int i = 0; i < N; i++)
        {
            a[i] = 1LL * A[i] * y - 1LL * B[i] * x;
        }
        for (int i = 0; i < M; i++)
        {
            b[i] = 1LL * C[i] * y - 1LL * D[i] * x;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long ge = 0, gt = 0;
        for (int i = 0, j = M, k = M; i < N; i++)
        {
            while (j > 0 && a[i] + b[j - 1] >= 0)
            {
                j--;
            }
            while (k > 0 && a[i] + b[k - 1] > 0)
            {
                k--;
            }
            ge += M - j;
            gt += M - k;
        }
        if (ge >= K && gt < K)
        {
            return 0;
        }
        if (ge < K)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    };

    int x1 = 0, y1 = 1, x2 = 1, y2 = 0;
    while (true)
    {
        int res = check(x1 + x2, y1 + y2);
        if (res == 0)
        {
            cout << fixed << setprecision(15);
            cout << 1. * (x1 + x2) / (x1 + x2 + y1 + y2) * 100 << "\n";
            return 0;
        }

        if (res == -1)
        {
            int K = 1;
            while (check(x2 + x1 * K, y2 + y1 * K) == -1)
            {
                K *= 2;
            }
            while (K > 1)
            {
                K /= 2;
                if (check(x2 + x1 * K, y2 + y1 * K) == -1)
                {
                    x2 += x1 * K;
                    y2 += y1 * K;
                }
            }
        }
        else
        {
            int K = 1;
            while (check(x1 + x2 * K, y1 + y2 * K) == 1)
            {
                K *= 2;
            }
            while (K > 1)
            {
                K /= 2;
                if (check(x1 + x2 * K, y1 + y2 * K) == 1)
                {
                    x1 += x2 * K;
                    y1 += y2 * K;
                }
            }
        }
    }

    return 0;
}