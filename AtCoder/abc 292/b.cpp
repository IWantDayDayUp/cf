#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> cnt(n, 0);

    for (int i = 0; i < q; i++)
    {
        int p, x;
        cin >> p >> x;
        x--;

        if (p == 1)
        {
            cnt[x] += 1;
        } else if (p == 2)
        {
            cnt[x] += 2;
        } else {
            if (cnt[x] >= 2)
            {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}