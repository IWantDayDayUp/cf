#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    reverse(p.begin(), p.end());

    int ans = 0;
    for (int i = 1; i * k <= n; i++)
    {
        int temp = 0;
        for (int j = 0; j < i; j++)
        {
            temp += p[i * k - 1 - j];
        }
        ans = max(ans, temp);
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