#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    int h = k / 60;
    int m = k % 60;

    h = (21 + h) % 24;

    string ans = "";
    if (h < 10)
    {
        ans += "0" + to_string(h);
    } else {
        ans += to_string(h);
    }

    ans += ":";

    if (m < 10)
    {
        ans += "0" + to_string(m);
    } else {
        ans += to_string(m);
    }

    cout << ans << endl;

    return 0;
}