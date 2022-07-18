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
    for (int i = 0; i < n; i++)
    {
        int cnt;
        cin >> cnt;
        cnt;

        string s;
        cin >> s;

        for (auto & c : s)
        {
            if (c == 'U')
            {
                nums[i] -= 1;
                if (nums[i] == -1)
                {
                    nums[i] = 9;
                }
            } else {
                nums[i] += 1;
                if (nums[i] == 10)
                {
                    nums[i] = 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " \n"[i == n - 1];
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