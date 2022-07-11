#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    long long m;
    cin >> m;

    int p = 9;
    for (int i = 0; i < 10; i++)
    {
        long long num = pow(10, i);
        if (num > m)
        {
            p = i - 1;
            break;
        } else if (num == m)
        {
            p = i;
            break;
        }
    }

    cout << m - (long long)pow(10, p) << endl;
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