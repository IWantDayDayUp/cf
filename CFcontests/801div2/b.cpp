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

    if (n % 2 == 1)
    {
        cout << "Mike" << endl;
    } else {
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < nums[p])
            {
                p = i;
            }
        }

        if (p % 2 == 0)
        {
            cout << "Joe" << endl;
        } else {
            cout << "Mike" << endl;
        }
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