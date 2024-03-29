#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n) : n(n), a(n) {}

    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }

    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> c(n), x(n);
    std::vector<std::vector<int>> f(n);

    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
        c[i]--;
        f[c[i]].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
        x[i]--;
    }
    
    Fenwick<int> fen(n);
    i64 ans = 0;

    for (int i = 0; i < n; i++) {
        ans += fen.rangeSum(x[i] + 1, n);
        fen.add(x[i], 1);
    }
    
    for (int i = 0; i < n; i++) {
        fen.add(x[i], -1);
    }
    
    for (int c = 0; c < n; c++) {
        for (auto i : f[c]) {
            ans -= fen.rangeSum(x[i] + 1, n);
            fen.add(x[i], 1);
        }
        for (auto i : f[c]) {
            fen.add(x[i], -1);
        }
    }
    
    std::cout << ans << "\n";
    
    return 0;
}
