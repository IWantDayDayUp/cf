#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    if (s == string(n, '1'))
    {
        cout << 0 << endl;
    } else if (s[0] == '1') {
        cout << 1 << endl;
    } else if (s[n - 1] == '1')
    {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }

    return 0;
}