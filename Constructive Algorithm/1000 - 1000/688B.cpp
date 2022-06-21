#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    cout << s;
    reverse(s.begin(), s.end());
    cout << s << endl;

    return 0;
}