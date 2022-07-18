#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n * 2);
    for (int i = 0; i < n * 2; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());


    for (int i = 0; i < n; i++)
    {
        if (a[i] + x > a[i + n])
        {
            // cout << a[i] << ' ' << a[i + n] << endl;
            cout << "NO" << endl;
            return ;
        }
    }

    cout << "YES" << endl;
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