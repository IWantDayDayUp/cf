#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    map<char, int> mp1, mp2;
    for (auto & c : s)
    {
        mp1[c] += 1;
    }
    for (auto & c : t)
    {
        mp2[c] += 1;
    }

    set<char> st = {'a', 't', 'c', 'o', 'd', 'e', 'r'};

    int cnt = 0;
    for (int c = 'a'; c <= 'z'; c++)
    {
        if (mp1[c] != mp2[c])
        {
            if (st.count(c) == 0)
            {
                cout << "No" << endl;
                return 0;
            }

            if (mp1[c] < mp2[c])
            {
                cnt += mp1[c] - mp2[c];
            }
        }
    }

    cout << (cnt <= mp1['@'] ? "Yes" : "No") << endl;

    return 0;
}