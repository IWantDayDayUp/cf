#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    map<long long, int> mp;
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        mp[num] += 1;
    }

    int one = 0, more = 0;
    for (auto & p : mp)
    {
        one += p.second == 1;
        more += p.second > 1;
    }

    cout << more + (one + 1) / 2 << endl;
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