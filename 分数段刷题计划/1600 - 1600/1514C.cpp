#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n, 0);
    long long p = 1;
    for (int i = 1; i < n; i++)
    {
        if (std::gcd(n, i) == 1)
        {
            nums[i] = 1;
            p = (p * i) % n;
        }
    }

    if (p != 1)
    {
        nums[p] = 0;
    }

    cout << count(nums.begin(), nums.end(), 1) << endl;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == 1)
        {
            cout << i << ' ';
        }
    }

    return 0;
}