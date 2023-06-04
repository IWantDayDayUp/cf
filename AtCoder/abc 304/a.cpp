#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> a(2 * n);
    int mx = 1e9 + 7, idx = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];

        int cur;
        cin >> cur;

        if (cur < mx)
        {
            idx = i;
            mx = cur;
        }
    }

    // cout << idx << ' ' << mx << endl;

    for (int i = idx; i < idx + n; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}