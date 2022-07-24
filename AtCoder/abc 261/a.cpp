#include <bits/stdc++.h>

using namespace std;

void slove() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    int ans = 0;
    for (int i = l1; i <= r1; i++)
    {
        if (i >= l2 && i <= r2)
        {
            ans += 1;
        }
    }

    cout << (ans > 0 ? ans - 1 : ans) << endl;

    return 0;
}