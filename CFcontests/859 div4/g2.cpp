#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    if (a[0] != 1) 
    {
        cout << "NO" << endl;
        return ;
    }

    long long sum = 1;
    for (int i = 1; i < n; i++)
    {
        if (sum < a[i])
        {
            cout << "NO" << endl;
            return ;
        }

        sum += a[i];
    }

    cout << "YES" << endl;
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