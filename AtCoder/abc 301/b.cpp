#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;

        if (i == 0)
        {
            r = c;
        } else {
            r = c;
            if (l < r)
            {
                for (int j = l; j < r; j++)
                {
                    cout << j << ' ';
                }
            } else {
                for (int j = l; j > r; j--)
                {
                    cout << j << ' ';
                }
            }
        }

        l = r;
    }

    cout << r << endl;

    return 0;
}