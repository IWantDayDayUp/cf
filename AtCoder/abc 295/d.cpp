#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    map<vector<int>, long long> mp;
    vector<int> cnt(10, 0);
    mp[cnt] += 1;

    for (auto & c : s)
    {
        cnt[c - '0'] += 1;
        cnt[c - '0'] %= 2;
        mp[cnt] += 1;
    }

    long long ans = 0;
    for (auto & [k, v] : mp)
    {
        ans += (v - 1) * v / 2;
    }

    cout << ans << endl;

    return 0;
}