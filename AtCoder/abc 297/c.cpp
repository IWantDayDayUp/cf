#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (int i = 0; i < h; i++)
    {
        cin >> a[i];

        for (int j = 0; j < w - 1; j++)
        {
            if (a[i][j] == 'T' && a[i][j + 1] == 'T')
            {
                a[i][j] = 'P';
                a[i][j + 1] = 'C';
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}