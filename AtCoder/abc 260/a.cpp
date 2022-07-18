#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    map<char, int> mp;
    for (auto & c : s)
    {
        mp[c] += 1;
    }

    for (auto & p : mp)
    {
        if (p.second == 1)
        {
            cout << p.first << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}