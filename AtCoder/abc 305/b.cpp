#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    char x, y;
    cin >> x >> y;

    auto calc = [](char c) {
        int dis = 0;
        string s = "0314159";
        for (int i = 'A'; i <= c; i++)
        {
            dis += s[i - 'A'] - '0';
        }
        return dis;
    };

    cout << abs(calc(x) - calc(y)) << endl;

    return 0;
}