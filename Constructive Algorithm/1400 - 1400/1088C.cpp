#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << n + 1 << endl;
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int add = (i - (nums[i] + sum) % n + n) % n;
        cout << 1 << ' ' << i + 1 << ' ' << add << endl;
        sum += add;
    }
    cout << 2 << ' ' << n << ' ' << n << endl;

    return 0;
}