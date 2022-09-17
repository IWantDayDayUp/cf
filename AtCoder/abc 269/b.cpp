#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> words(10);
    int a = 11, b = 0, c = 11, d = 0;
    for (int i = 1; i < 11; i++)
    {
        string s;
        cin >> s;

        if (s.find("#") != -1)
        {
            a = min(a, i);
            b = max(b, i);

            for (int j = 0; j < 10; j++)
            {
                if (s[j] == '#')
                {
                    c = min(c, j + 1);
                    d = max(d, j + 1);
                }
            }
        }
    }

    cout << a << ' ' << b << endl;
    cout << c << ' ' << d << endl;

    return 0;
}