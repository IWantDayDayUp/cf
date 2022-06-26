#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    int m;
    cin >> m;
    vector<int> p(n, 0);
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        num -= 1;
        p[num] += 1;
    }

    for (int i = 0; i < n / 2; i++)
    {
        // cout << p[i] << " \n"[i == n / 2 - 1];
        if (i > 0)
        {
            p[i] += p[i - 1];
        }

        if (p[i] % 2 == 1)
        {
            swap(s[i], s[n - 1 - i]);
        }
    }

    cout << s << endl;

    return 0;
}