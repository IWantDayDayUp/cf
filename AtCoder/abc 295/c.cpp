#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;

        mp[c] += 1;
    }

    long long ans = 0;
    for (auto & [k, v] : mp)
    {
        ans += v / 2;
    }

    cout << ans << endl;

    return 0;
}