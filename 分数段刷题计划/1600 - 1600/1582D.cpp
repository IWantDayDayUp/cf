#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> b(n, 0);
    if (n % 2 == 0)
    {
        for (int i = 0; i < n; i += 2)
        {
            b[i] = a[i + 1];
            b[i + 1] = -a[i];
        }
    } else {
        for (int i = 0; i < n - 3; i += 2)
        {
            b[i] = a[i + 1];
            b[i + 1] = -a[i];
        }

        if (a[n - 3] + a[n - 2] != 0)
        {
            b[n - 3] = -a[n - 1];
            b[n - 2] = -a[n - 1];
            b[n - 1] = a[n - 3] + a[n - 2];
        } else if (a[n - 2] + a[n - 1])
        {
            b[n - 3] = a[n - 2] + a[n - 1];
            b[n - 2] = -a[n - 3];
            b[n - 1] = -a[n - 3];
        } else {
            b[n - 3] = -a[n - 2];
            b[n - 2] = a[n - 3] + a[n - 1];
            b[n - 1] = -a[n - 2];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " \n"[i == n - 1];
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