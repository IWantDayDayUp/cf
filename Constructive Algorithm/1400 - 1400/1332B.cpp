#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    map<int, vector<int>> mp;

    auto calc = [&](int num){
        for (int i = 2; i <= num; i++)
        {
            if (num % i == 0)
            {
                return i;
            }
        }
    };

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        mp[calc(num)].emplace_back(i);
    }

    vector<int> ans(n, 0);
    int color = 0;
    for (auto & p : mp)
    {
        color += 1;
        for (auto & i : p.second)
        {
            ans[i] = color;
        }
    }

    cout << color << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " \n"[i == n - 1];
    }
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