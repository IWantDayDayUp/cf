#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, z;
    cin >> n >> z;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        mx = max(mx, max(num, num | z));
    }

    cout << mx << endl;
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