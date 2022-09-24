#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    long long ans = 0;
    for (int k = 1; k <= n; k++)
    {
        for (int i = k; i <= n; i+=k)
        {
            if (s[i - 1] == '1')
            {
                break;
            }
            if (s[i - 1] == '0')
            {
                s[i - 1] = '#';
                ans += k;
            }
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
        solve();
    }

    return 0;
}