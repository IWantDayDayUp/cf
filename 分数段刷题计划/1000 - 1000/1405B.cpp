#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    long long ans = 0;
    long long temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += nums[i];
        if (temp < 0)
        {
            ans += temp;
            temp = 0;
        }
    }

    cout << -ans << endl;
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