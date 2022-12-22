#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ',')
        {
            if ((cnt & 1) == 0)
            {
                s[i] = '.';
            }
        } else if (s[i] == '"')
        {
            cnt += 1;
        }
    }

    cout << s << endl;

    return 0;
}