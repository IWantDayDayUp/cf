#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    string ans = "";
    for (int i = 0; i < k; i++)
    {
        ans += ('A' + i);
    }

    cout << ans << endl;

    return 0;
}