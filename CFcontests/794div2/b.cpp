#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> nums(n);
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (st.empty())
        {
            st.emplace(nums[i]);
        } else if (st.top() < nums[i])
        {
            st.emplace(nums[i]);
        } else {
            ans += 1;
            st.emplace(0);
        }
    }

    cout << ans << endl;
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