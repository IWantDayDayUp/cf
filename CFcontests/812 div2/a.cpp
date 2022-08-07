#include <bits/stdc++.h>

using namespace std;

void slove() {
    int n;
    cin >> n;

    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        x1 = max(x1, x);
        x2 = min(x2, x);
        y1 = max(y1, y);
        y2 = min(y2, y);
    }

    cout << (abs(x1) + abs(x2) + abs(y1) + abs(y2)) * 2 << endl;
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