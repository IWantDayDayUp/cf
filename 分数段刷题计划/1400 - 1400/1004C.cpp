#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        mp[nums[i]] += 1;
    }

    set<int> st;
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (--mp[nums[i]] == 0)
        {
            ans += st.size();
        }

        st.insert(nums[i]);
    }

    cout << ans << endl;

    return 0;
}