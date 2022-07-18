#include <bits/stdc++.h>

using namespace std;

void slove() {
    long long n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    auto check = [&](long long mid)
    {
        int temp = q;
        for (int i = mid; i < n; i++)
        {
            if (a[i] > temp)
            {
                temp -= 1;
            }
        }
        
        return temp >= 0;
    };

    long long l = 0, r = n - 1;
    while (l < r)
    {
        long long mid = l + r >> 1;

        if (check(mid))
        {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    string ans = string(n, '0');
    for (int i = 0; i < n; i++)
    {
        if (i < l)
        {
            if (a[i] <= q)
            {
                ans[i] = '1';
            }
        } else {
            ans[i] = '1';
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