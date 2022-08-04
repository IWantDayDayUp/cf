#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long ans = 0;
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == i + 1)
        {
            // cout << "a[i]: " << a[i] << endl;
            cnt += 1;
            continue;
        }

        int num1 = a[i];
        if (a[num1 - 1] == i + 1 && num1 > i + 1)
        {
            // cout << i << ' ' << a[i] << endl;
            ans += 1;
        }
    }

    ans += (cnt - 1) * cnt / 2;

    cout << ans << endl;

    return 0;
}