#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> mp;
    int ans;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        mp[num] += 1;
        if (mp[num] > mx)
        {
            mx = mp[num];
            ans = num;
        }
    }

    cout << ans << endl;

    return 0;
}