#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    vector<long long> cnt(w, 0);

    for (int i = 0; i < h; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < w; j++)
        {
            cnt[j] += s[j] == '#';
        }
    }

    for (int i = 0; i < w; i++)
    {
        cout << cnt[i] << " \n"[i == w - 1];
    }

    return 0;
}