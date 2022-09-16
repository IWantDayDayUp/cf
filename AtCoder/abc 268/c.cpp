#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++)
    {
        int d = a[i] - i;

        if (d < 0)
        {
            d += n;
        }

        cnt[d] += 1;
        cnt[(d + 1 + n) % n] += 1;
        cnt[(d - 1 + n) % n] += 1;
    }

    cout << *max_element(cnt.begin(), cnt.end()) << endl;

    return 0;
}