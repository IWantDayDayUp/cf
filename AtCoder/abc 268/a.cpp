#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<int> st;

    for (int i = 0; i < 5; i++)
    {
        int num;
        cin >> num;

        st.insert(num);
    }

    cout << st.size() << endl;

    return 0;
}