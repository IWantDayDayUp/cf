#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int d;
    cin >> d;

    vector<int> p;
    for (int i = d + 1; ; i++)
    {
        int t = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                t = 0;
                break;
            }
        }
        if (t)
        {
            p.emplace_back(i);
            break;
        }
    }

    for (int i = p.back() + d; ; i++)
    {
        int t = 1;
        for (int j = 2; j * j <= i; i++)
        {
            if (i % j == 0)
            {
                t = 0;
                break;
            }
        }
        if (t)
        {
            p.emplace_back(i);
            break;
        }
    }

    cout << min(1ll * p[0] * p[1], 1ll * p[0] * p[0] * p[0]) << endl;
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