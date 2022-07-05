#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string pre = "";
    pre += s[0];

    function<string(string)> get = [&](string temp) -> string
    {
        while ((int)temp.size() < k)
        {
            temp += temp;
        }

        while ((int)temp.size() > k)
        {
            temp.pop_back();
        }

        return temp;
    };

    string mn = get(pre);

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] > s[0]) break;
        pre += s[i];
        mn = min(mn, get(pre));
    }

    cout << mn << endl;

    return 0;
}