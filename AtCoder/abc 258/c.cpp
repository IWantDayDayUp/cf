#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    int p = 0;
    for (int i = 0; i < q; i++)
    {
        int label, x;
        cin >> label >> x;

        if (label == 1)
        {
            p = (p - x + n) % n;
        } else {
            cout << s[(p + x - 1 + n) % n] << endl;
        }
    }

    return 0;
}