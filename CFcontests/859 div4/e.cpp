#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }
    
    int lo = 0, hi = n;
    while (lo + 1 < hi) {
        int x = (lo + hi) / 2;
        std::cout << "? " << x;
        for (int i = 1; i <= x; i++) {
            std::cout << " " << i;
        }
        std::cout << std::endl;
        int res;
        std::cin >> res;
        if (s[x] == res) {
            lo = x;
        } else {
            hi = x;
        }
    }
    std::cout << "! " << hi << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}