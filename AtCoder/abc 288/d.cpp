#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    vector<long long> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s[i] = a[i];
        if (i >= k) {
            s[i] += s[i - k];
        }
    }
    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        vector<long long> b(k);
        for (int i = r; r - i + 1 <= k; i--)
        {
            b[i % k] += s[i];
        }

        for (int i = l - 1; i >= 0 && l - i <= k; i--)
        {
            b[i % k] -= s[i];
        }

        if (b == vector<long long>(k, b[0]))
        {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}