#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        cnt += nums[i] == 0;
    }

    if (cnt == n)
    {
        cout << "YES" << endl;
        return ;
    }

    int j = n - 1;
    while (j >= 0 && nums[j] == 0)
    {
        j -= 1;
    }

    long long s = 0;
    for (int i = 0; i < j; i++)
    {
        s += nums[i];
        if (s <= 0)
        {
            cout << "NO" << endl;
            return ;
        }
    }
    s += nums[j];
    cout << (s == 0 ? "YES" : "NO") << endl;
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