#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n, k;
    cin >> n >> k;
    k %= 4;
    if (k == 0){
        cout << "NO" << '\n';
        return ;
    }

    set<int> s;
    vector<int> v1, v2;
    for(int i = 1; i <= n; i++) s.insert(i);
    for(int i = 1; i <= n; i++){
        if (i % 4 == 0) v1.push_back(i), s.erase(i);
        else if ((i + k) % 4 == 0)
            v2.push_back(i), s.erase(i);
    }
    cout << "YES" << '\n';
    if (v1.size() + v2.size() < n / 2){
        cout << 1 << ' ' << n << '\n';
        s.erase(1), s.erase(n);
    }
    for(auto x : v1){
        cout << *s.begin() << ' ' << x << '\n';
        s.erase(s.begin());
    }
    for(auto x : v2){
        cout << x << ' ' << *s.begin() << '\n';
        s.erase(s.begin());
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