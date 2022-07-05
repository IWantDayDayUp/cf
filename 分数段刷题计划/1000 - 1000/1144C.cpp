#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, int> mp;
    bool ok = true;
    vector<int> up, down;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (ok)
        {
            if (mp[num] == 0)
            {
                mp[num] += 1;
                up.emplace_back(num);
            } else if (mp[num] == 1) {
                mp[num] += 1;
                down.emplace_back(num);
            } else {
                ok = false;
            }
        }
    }

    if (!ok)
    {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << up.size() << endl;
        sort(up.begin(), up.end());
        for (int i = 0; i < up.size(); i++)
        {
            cout << up[i] << " \n"[i == up.size() - 1];
        }
        if (down.size() == 0)
        {
            cout << 0 << endl;
            cout << endl;
        } else {
            cout << down.size() << endl;
            sort(down.begin(), down.end(), [&](int a, int b)
            {
                return a > b;
            });
            for (int i = 0; i < down.size(); i++)
            {
                cout << down[i] << " \n"[i == down.size() - 1];
            }
        }
    }






    return 0;
}