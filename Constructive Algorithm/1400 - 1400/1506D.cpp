#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        mp[num] += 1;
    }
    priority_queue<int, vector<int>, less<int>> q;
    for (auto & p : mp)
    {
        q.emplace(p.second);
    }

    int ans = 0;
    while (q.size() > 1)
    {
        int num1 = q.top();
        q.pop();

        int num2 = q.top();
        q.pop();

        ans += 2;
        if (num1 > 1)
        {
            q.emplace(num1 - 1);
        }
        if (num2 > 1)
        {
            q.emplace(num2 - 1);
        }
    }

    cout << n - ans << endl;
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