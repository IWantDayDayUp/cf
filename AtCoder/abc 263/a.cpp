#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int, int> mp;
    set<int> st;
    for (int i = 0; i < 5; i++)
    {
        int num;
        cin >> num;

        mp[num] += 1;
        st.insert(num);
    }

    if (st.size() != 2)
    {
        cout << "No" << endl;
    } else {
        int num = *st.begin();

        cout << (mp[num] == 2 || mp[num] == 3 ? "Yes" : "No") << endl;
    }

    return 0;
}