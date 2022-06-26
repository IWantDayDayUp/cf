#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num > 0)
        {
            q.push(make_pair(num, i + 1));
        }
    }

    vector<pair<int, int>> ans;
    while (q.size() > 1)
    {
        int a = q.top().second, num1 = q.top().first;
        q.pop();
        int b = q.top().second, num2 = q.top().first;
        q.pop();

        ans.emplace_back(make_pair(a, b));
        if (num1 > 1)
        {
            q.emplace(make_pair(num1 - 1, a));
        }
        if (num2 > 1)
        {
            q.emplace(make_pair(num2 - 1, b));
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << ' ' << ans[i].second << endl;
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