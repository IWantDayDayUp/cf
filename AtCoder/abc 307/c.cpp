#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H1, W1;
    cin >> H1 >> W1;

    vector<string> S1(H1);
    rep(i, H1) cin >> S1[i];

    int H2, W2;
    cin >> H2 >> W2;

    vector<string> S2(H2);
    rep(i, H2) cin >> S2[i];

    int H3, W3;
    cin >> H3 >> W3;

    vector<string> S3(H3);
    rep(i, H3) cin >> S3[i];

    rep(i1, 20 + H3 - H1 + 1) rep(j1, 20 + W3 - W1 + 1)
    {
        rep(i2, 20 + H3 - H2 + 1) rep(j2, 20 + W3 - W2 + 1)
        {
            vector<string> S(20 + H3, string(20 + W3, '.'));
            rep(i, H1) rep(j, W1)
            {
                if (S1[i][j] == '#')
                    S[i1 + i][j1 + j] = '#';
            }
            rep(i, H2) rep(j, W2)
            {
                if (S2[i][j] == '#')
                    S[i2 + i][j2 + j] = '#';
            }
            bool flag = true;
            rep(i, H3) rep(j, W3)
            {
                if (S3[i][j] != S[10 + i][10 + j])
                    flag = false;
            }
            rep(i, 20 + H3) rep(j, 20 + W3)
            {
                if (10 <= i && i < 10 + H3 && 10 <= j && j < 10 + W3)
                    continue;
                if (S[i][j] == '#')
                    flag = false;
            }
            if (flag)
            {
                cout << "Yes\n";
                return 0;
            }
        }
    }

    cout << "No\n";

    return 0;
}