#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int,int> mp1, mp2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp1[a[i]] += 1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        mp2[b[i]] += 1;
    }

    bool ok = true;
    int ans = 0;
    for (int i = 1; i <= 5; i++)
    {
        if ((mp1[i] + mp2[i]) % 2 == 1)
        {
            ok = false;
            break;
        } else {
            ans += abs((mp1[i] + mp2[i]) / 2 - mp1[i]);
        }
    }

    cout << (ok ? ans / 2 : -1) << endl;

    return 0;
}