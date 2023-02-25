#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, q;
    cin >> m >> q;

    set<int> s;
    map<int, int> mp;
    int ans = 0;

    while (q)
    {
        int op, num;
        cin >> op >> num;

        if (op == 1)
        {
            s.insert(num);

            if (1 <= num - 3 && num - 3 <= m)
            {
                mp[num - 3] += 1;
                ans += mp[num - 3] == 1;
            }
            if (1 <= num + 3 && num + 3 <= m)
            {
                mp[num + 3] += 1;
                ans += mp[num + 3] == 1;
            }
        } else {
            s.erase(num);

            if (1 <= num - 3 && num - 3 <= m)
            {
                mp[num - 3] -= 1;
                ans -= mp[num - 3] == 0;
            }
            if (1 <= num + 3 && num + 3 <= m)
            {
                mp[num + 3] -= 1;
                ans -= mp[num + 3] == 0;
            }
        }

        cout << ans << endl;

        q--;
    }

    return 0;
}