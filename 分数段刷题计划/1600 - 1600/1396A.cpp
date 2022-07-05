#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    if (n == 1)
    {
        cout << 1 << ' ' << 1 << endl;
        cout << 0 << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << 0 << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << -nums[0] << endl;
    } else {
        cout << 1 << ' ' << 1 << endl;
        cout << -nums[0] << endl;
        cout << 1 << ' ' << n << endl;
        for (int i = 0; i < n; i++)
        {
            cout << (i == 0 ? 0 : - n * nums[i]) << " \n"[i == n - 1];
        }
        cout << 2 << ' ' << n << endl;
        for (int i = 1; i < n; i++)
        {
            cout << (n - 1) * nums[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}