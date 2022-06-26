#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        mp[num] = i;
    }

    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;

        int target = mp[cur];

        int l = 0;
        if (target <= i)
        {
            l = i - target;
        } else {
            l = n - (target - i);
        }
        int r = 0;
        if (i <= target)
        {
            r = target - i;
        } else {
            r = n - (i - target);
        }

        left[l]++;
        right[r]++;
    }

    int ans = 0;
    ans = *max_element(left.begin(), left.end());
    ans = max(ans, *max_element(right.begin(), right.end()));

    cout << ans << endl;

    return 0;
}