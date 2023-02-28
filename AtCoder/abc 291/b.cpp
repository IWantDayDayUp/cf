#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;
    vector<long long> a(5 * k);
    for (int i = 0; i < 5 * k; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    long long ans = 0;
    for (int i = k; i < 4 * k; i++)
    {
        ans += a[i];
    }

    // cout << ans << endl;

    cout << fixed << setprecision(15) << ((double)ans / (3.0 * k)) << endl;

    return 0;
}