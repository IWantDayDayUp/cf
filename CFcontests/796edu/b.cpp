#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<i64> nums(n);
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (nums[i] % 2 == 0)
        {
            even += 1;
        } else {
            odd += 1;
        }
    }

    if (odd) 
    {
        cout << even << endl;
    } else {
        int ans = 30;
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            while (nums[i] % 2 == 0)
            {
                nums[i] /= 2;
                temp += 1;
            }
            ans = min(ans, temp);
        }
        
        cout << ans + n - 1 << endl;
    }
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