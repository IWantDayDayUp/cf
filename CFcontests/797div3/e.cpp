#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove()
{
    int n, k;
    cin >> n >> k;

    i64 ans = 0;
    vector<int> a(n);
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        ans += a[i] / k;
        a[i] %= k;
        s.insert(a[i]);
    }

    while (!s.empty())
    {
        int x = *s.begin();
        s.erase(s.begin());

        auto it = s.lower_bound(k - x);
        if (it != s.end())
        {
            s.erase(it);
            ans++;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        slove();
    }

    return 0;
}