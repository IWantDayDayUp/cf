#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    cin >> num;

    vector<int> a;
    while (num > 0)
    {
        a.emplace_back(num % 10);
        num /= 10;
    }
    reverse(a.begin(), a.end());

    int ans = 0;
    vector<int> nums;
    while (true)
    {
        int cur = 0;
        int n = a.size();

        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {
                a[i] -= 1;
                cur = cur * 10 + 1;
            } else {
                cur = cur * 10 + 0;
            }
        }

        if (cur == 0)
        {
            break;
        } else {
            ans += 1;
            nums.emplace_back(cur);
        }
    }

    cout << ans << endl;
    for (int i = 0; i < ans; i++)
    {
        cout << nums[i] << " \n"[i == ans - 1];
    }

    return 0;
}