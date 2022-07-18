#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, k;
    cin >> n >> k;
    vector<int> goods(n);
    int ans = 0;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> goods[i];
        ans += goods[i] / k;
        s.insert(goods[i] % k);
    }

    while (s.size() > 0)
    {
        int l = *s.begin();
        s.erase(s.begin());

        auto it = s.lower_bound(k - l);
        if (it != s.end())
        {
            s.erase(it);
            ans += 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        slove();
    }

    return 0;
}