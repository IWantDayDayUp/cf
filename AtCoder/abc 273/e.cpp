#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    map<int, int> note;
    vector<pair<int, int>> all(1, make_pair(0, -1));

    int at = 0;

    for (int qq = 0; qq < tt; qq++) {
        string op;
        cin >> op;

        if (op == "ADD") {
            int num;
            cin >> num;

            all.emplace_back(at, num);
            at = (int) all.size() - 1;
        }
        if (op == "DELETE") {
            at = all[at].first;
        }
        if (op == "SAVE") {
            int num;
            cin >> num;

            note[num] = at;
        }
        if (op == "LOAD") {
            int num;
            cin >> num;
            
            at = note[num];
        }

        cout << all[at].second << " \n"[qq == tt - 1];
    }

    return 0;
}