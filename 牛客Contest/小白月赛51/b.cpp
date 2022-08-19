#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    long long sum = 0;
    int pre = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != 0)
        {
            if (pre >= a[i])
            {
                cout << -1 << endl;
                return 0;
            }

            pre = a[i];
        } else {
            a[i] = pre + 1;
            pre = a[i];
        }

        sum += a[i];
    }

    cout << sum << endl;

    return 0;
}