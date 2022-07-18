#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n;
    cin >> n;

    vector<long long> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    long long ans = 0;

    // 
    if (n % 2 == 0)
    {
        ans = 1e18;

        long long right = 0;
        for (int i = n - 2; i >= 1; i -= 2)
        {
            if (h[i - 1] < h[i] && h[i] > h[i + 1])
            {
                right += 0;
            } else {
                right += max(h[i - 1] - h[i], h[i + 1] - h[i]) + 1;
            }
        }
        // cout << "right" << right << endl;

        long long left = 0;
        for (int i = 1; i < n - 1; i += 2)
        {
            long long num1 = 0, num2 = 0;
            if (h[i - 1] < h[i] && h[i] > h[i + 1])
            {
                num1 += 0;
            } else {
                num1 += max(h[i - 1] - h[i], h[i + 1] - h[i]) + 1;
            }
            if (h[i] < h[i + 1] && h[i + 1] > h[i + 2])
            {
                num2 += 0;
            } else {
                num2 += max(h[i] - h[i + 1], h[i + 2] - h[i + 1]) + 1;
            }

            right -= num2;

            ans = min(ans, left + min(num1, num2) + right);

            left += num1;
        }

    } else {
        for (int i = 1; i < n; i += 2)
        {
            if (h[i - 1] < h[i] && h[i] > h[i + 1])
            {
                ans += 0;
            } else {
                ans += max(h[i - 1] - h[i], h[i + 1] - h[i]) + 1;
            }
        }
    }

    cout << ans << endl;
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