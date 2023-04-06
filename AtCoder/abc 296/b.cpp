#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> a(8);
    for (int i = 0; i < 8; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (a[i][j] == '*')
            {
                cout << (char)('a' + j) << (8 - i) << endl;
                return 0;
            }
        }
    }

    return 0;
}