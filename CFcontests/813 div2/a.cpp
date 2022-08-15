#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        if (i <= k && a[i] > k)
        {
            ans += 1;
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