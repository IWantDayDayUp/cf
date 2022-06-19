#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    int cnt = 1;
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        if (i > 1)
        {
            if (nums[i - 1] == nums[i])
            {
                cnt += 1;
            } else{
                if (cnt < 2)
                {
                    ok = false;
                }
                cnt = 1;
            }
        }
    }
    if (!ok || n == 1 || cnt < 2)
    {
        cout << -1 << endl;
        return ;
    }

    vector<int> ans(n + 1, 0);
    int p = 1;
    for (int i = 2; i <= n; i++)
    {
        if (nums[i - 1] == nums[i])
        {
            ans[i - 1] = i;
        } else {
            ans[i - 1] = p;
            p = i;
        }
    }
    ans[n] = p;

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
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