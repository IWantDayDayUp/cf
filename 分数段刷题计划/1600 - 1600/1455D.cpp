#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = n + 1;
    if (is_sorted(a.begin(), a.end()))
    {
        ans = 0;
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> b(a);
        b[i] = x;
        sort(b.begin(), b.end());

        int cnt = 0;
        bool ok = true;
        int cur = x;

        for (int j = 0; j < n; j++)
        {
            if (a[j] != b[j])
            {
                cnt += 1;
                if (b[j] == cur && b[j] < a[j])
                {
                    cur = a[j];
                } else {
                    ok = false;
                    break;
                }
            }
        }

        if (ok)
        {
            ans = min(ans, cnt);
        }
    }

    cout << (ans == n + 1 ? -1 : ans) << endl;
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