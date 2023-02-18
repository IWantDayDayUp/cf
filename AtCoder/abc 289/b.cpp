#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    iota(a.begin(), a.end(), 0);

    for (int i = 0; i < m; i++)
    {
        int cur;
        cin >> cur;

        a[cur + 1] = a[cur];
    }

    int l = 1, r = 1;
    while (r <= n)
    {
        vector<int> temp;

        while (r <= n && a[r] == a[l])
        {
            temp.emplace_back(r);
            r += 1;
        }
        reverse(temp.begin(), temp.end());

        for (auto & num : temp)
        {
            cout << num << ' ';
        }

        l = r;
        r = l;
    }

    return 0;
}