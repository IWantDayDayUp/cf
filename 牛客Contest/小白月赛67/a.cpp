#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < 3; i++)
    {
        string ans = "000000";
        for (int j = 0; j < 6; j++)
        {
            if (n-- > 0)
            {
                ans[j] = '1';
            }
        }
        cout << ans << endl;
    }

    return 0;
}