#include <bits/stdc++.h>

using namespace std;

void slove() {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    
    auto check = [&](int n, int m)
    {
        long long cnt = 0;
        bool three = false;
        for (auto & num : a)
        {
            if (num / n >= 2)
            {
                cnt += num / n;
                if (num / n >= 3)
                {
                    three = true;
                }
            }
        }

        if (three)
        {
            return cnt >= m;
        } else {
            return cnt >= m && m % 2 == 0;
        }
    };

    cout << (check(n, m) || check(m, n) ? "Yes" : "No") << endl;

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