#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;

    vector<bool> ans(n, false);

    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;

        if (num < 15)
        {
            ans[i] = false;
        } else {
            long long cnt = num / 7;
            long long left = num % 7;

            if (cnt % 2 == 0 and left > 0)
            {
                ans[i] = true;
            } else {
                ans[i] = false;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << (ans[i] ? "YES" : "NO") << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    slove();

    return 0;
}