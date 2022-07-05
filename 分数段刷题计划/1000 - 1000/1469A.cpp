#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    string s;
    cin >> s;

    if (s.size() % 2 == 0 and s[0] != ')' and s.back() != '(')
    {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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