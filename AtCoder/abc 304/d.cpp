#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long w, h;
    cin >> w >> h;

    long long n;
    cin >> n;
    vector<array<long long, 2>> pos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pos[i][0] >> pos[i][1];
    }

    long long A;
    cin >> A;
    vector<long long> a(A + 1, 0ll);
    for (long long i = 0; i < A; i++)
    {
        cin >> a[i];
    }
    a[A] = w;

    long long B;
    cin >> B;
    vector<long long> b(B + 1, 0ll);
    for (long long i = 0; i < B; i++)
    {
        cin >> b[i];
    }
    b[B] = h;

    map<pair<long long, long long>, long long> mp;
    for (int i = 0; i < n; i++)
    {
        long long x = *lower_bound(a.begin(), a.end(), pos[i][0]);
        long long y = *lower_bound(b.begin(), b.end(), pos[i][1]);

        mp[make_pair(x, y)] += 1;
    }

    long long mx = -1, mn = 1e9 + 7;
    for (auto & p : mp)
    {
        mx = max(mx, p.second);
    }

    if (mp.size() == (A + 1) * (B + 1))
    {
        for (auto & p : mp)
        {
            mn = min(mn, p.second);
        }
    } else {
        mn = 0;
    }

    cout << mn << ' ' << mx << endl;

    return 0;
}