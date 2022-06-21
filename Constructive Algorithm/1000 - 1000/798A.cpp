#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int l = 0, r = s.size() - 1;
    int cnt = 0;

    while (l < r)
    {
        cnt += s[l] != s[r];
        l += 1;
        r -= 1;
    }

    if (s.size() % 2 == 0)
    {
        cout << (cnt == 1 ? "YES" : "NO") << endl;
    } else {
        cout << (cnt <= 1 ? "YES" : "NO") << endl;
    }
    
    return 0;
}