#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, k;
    cin >> n >> k;
    vector<long long> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    long long l = h[0], r = h[0];

    for (int i = 1; i < n; i++)
    {
        l = max(l - (k - 1), h[i]);
        r = min(r + (k - 1), h[i] + (k - 1));

        if (l > r)
        {
            cout << "NO" << endl;
            return ;
        }
    }

    if (h[n - 1] < l || h[n - 1] > r)
    {
        cout << "NO" << endl;
    } else {
        cout << "YES" <<endl;
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