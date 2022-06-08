#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;

    auto check = [&](int mid)
    {
        int temp = n - mid;
        if (temp % 2 == 1)
        {
            return temp >= 2 && temp / 2 + 1 < mid;
        }
        return temp >= 2 && temp / 2 + 1 < mid;
    };

    int l = 1, r = n;
    while (l < r){
        int mid = l + (r - l) / 2;
        if (check(mid))
        {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << (n - l) / 2 + 1 << ' ' <<  l << ' ' << (n - l + 1) / 2 - 1<< endl;
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