#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int k;
    cin >> k;
    vector<long long> b(k);
    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
    }

    auto get = [&](auto a)
    {
        int n = a.size();
        vector<array<long long, 2>> ans;

        for (int i = 0; i < n; i++)
        {
            long long num = a[i];
            int cnt = 1;
            while (num % m == 0)
            {
                num /= m;
                cnt *= m;
            }

            if (!ans.empty() && ans.back()[0] == num)
            {
                ans.back()[1] += cnt;
            } else {
                ans.push_back({num, cnt});
            }
        }

        return ans;
    };

    cout << (get(a) == get(b) ? "Yes" : "No") << endl;
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