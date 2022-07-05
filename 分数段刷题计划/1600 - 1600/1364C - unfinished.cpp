#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

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

    vector<int> b(n, n);
    for (int i = 0; i < n; i++)
    {
        
    }

    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " \n"[i == n - 1];
    }

    return 0;
}