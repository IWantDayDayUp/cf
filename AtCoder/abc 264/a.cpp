#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s = "atcoder";

    int l, r;
    cin >> l >> r;

    for (int i = l; i <= r; i++)
    {
        cout << s[i - 1];
    }

    cout << endl;

    return 0;
}