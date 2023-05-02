#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int l = 1, r = n;
    while (l < r - 1)
    {
        int mid = l + r >> 1;
        cout << "? " << mid << endl;

        int res;
        cin >> res;

        if (res == 1)
        {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << "! " << l << endl;

    return 0;
}