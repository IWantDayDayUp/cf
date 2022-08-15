#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    long long ans = 0;
    long long temp = a[0];

    long long mod = 1e7 + 7;

    for (int i = 1; i < n; i++)
    {
        temp += a[i];
        if (temp <= 0)
        {
            break;
        }

        ans += temp;

        ans %= mod;
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