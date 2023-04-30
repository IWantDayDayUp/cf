#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    map<int, multiset<int>> mp;

    for (int qq = 0; qq < q; qq++)
    {
        int num;
        cin >> num;

        if (num == 1)
        {
            int i, j;
            cin >> i >> j;

            mp[j].insert(i);
        } else if (num == 2)
        {
            int i;
            cin >> i;

            int s = mp[i].size();
            // cout << "size: " << s << endl;
            for (auto & c : mp[i])
            {
                cout << c << ' ';
            }
            cout << endl;
        } else {
            int i;
            cin >> i;

            for (int j = 1; j <= n; j++)
            {
                if (mp[j].find(i) != mp[j].end())
                {
                    cout << j << ' ';
                }
            }
            cout << endl;
        }
    }

    return 0;
}