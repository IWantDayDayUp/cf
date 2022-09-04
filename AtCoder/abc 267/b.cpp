#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    s = '.' + s;

    if (s[1] == '0')
    {
        // a: not knocked down
        // b: knocked down
        set<int> a, b;
        if (s[5] == '0')
        {
            b.insert(4);
        } else {
            a.insert(4);
        }

        if (s[7] == '0')
        {
            b.insert(1);
        } else {
            a.insert(1);
        }

        if (s[4] == '0')
        {
            b.insert(2);
        } else {
            a.insert(2);
        }

        if (s[2] == '0' && s[8] == '0')
        {
            b.insert(3);
        } else {
            a.insert(3);
        }

        if (s[3] == '0' && s[9] == '0')
        {
            b.insert(5);
        } else {
            a.insert(5);
        }

        if (s[6] == '0')
        {
            b.insert(6);
        } else {
            a.insert(6);
        }

        if (s[10] == '0')
        {
            b.insert(7);
        } else {
            a.insert(7);
        }

        int left = 8, right = 0;
        for (auto & num : a)
        {
            left = min(left, num);
            right = max(right, num);
        }

        for (auto & num : b)
        {
            if (left < num && right > num)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }

        cout << "No" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}