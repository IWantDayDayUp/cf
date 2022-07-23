#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    vector<long long> prefix(n + 1);
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = nums[i] + prefix[i];
    }

    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;

        cout << prefix[n - x + y] - prefix[n - x] <<endl;
    }

    return 0;
}