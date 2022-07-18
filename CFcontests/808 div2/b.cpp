#include <bits/stdc++.h>

using namespace std;

void slove() {
    long long n, l, r;
    cin >> n >> l >> r;

    vector<long long> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = ((l - 1) / (i + 1) + 1) * (i + 1);

        if (ans[i] > r)
        {
            cout << "NO" << endl;
            return ;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " \n"[i == n - 1];
    }
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