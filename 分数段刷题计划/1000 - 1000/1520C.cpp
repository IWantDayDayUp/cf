#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    
    if (n == 1)
    {
        cout << 1 << endl;
    } else if (n == 2)
    {
        cout << -1 << endl;
    } else {
        vector<vector<int>> nums(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                nums[i][j] = i * n + j + 1;
            }
        }

        for (int j = 0; j < n; j++)
        {
            if (j % 2 == 0) continue;
            for (int i = 1; i < n; i++)
            {
                swap(nums[i - 1][j], nums[i][j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << nums[i][j] << " \n"[j == n - 1];
            }
        }
        cout << endl;
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