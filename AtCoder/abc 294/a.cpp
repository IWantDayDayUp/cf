#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        if (a % 2 == 0)
        {
            ans.push_back(a);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }

    return 0;
}