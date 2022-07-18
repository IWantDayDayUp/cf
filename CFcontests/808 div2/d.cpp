#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n;
    cin >> n;
    
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    
    while (n - (cnt.count(0) ? cnt[0] : 0) > 1) {
        map<int, int> nc;
        int last = -1;
        n--;
        for (auto [x, c] : cnt) {
            if (c > 1) {
                nc[0] += c - 1;
            }
            if (last != -1) {
                nc[x - last]++;
            }
            last = x;
        }
        cnt = nc;
    }
    
    cnt.erase(0);
    cout << (cnt.empty() ? 0 : cnt.begin()->first) << "\n";
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