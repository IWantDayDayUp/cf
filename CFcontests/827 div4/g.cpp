#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b;
    vector<bool> vis(n);
    
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int mx = 0, k = -1;
        for (int j = 0; j < n; j++) {
            int x = a[j] & ~cur;
            if (!vis[j] && x > mx) {
                mx = x;
                k = j;
            }
        }

        if (k < 0) {
            break;
        }

        vis[k] = true;
        b.push_back(a[k]);
        cur |= a[k];
    }
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            b.push_back(a[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << " \n"[i == n - 1];
    }
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