#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    long long cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        long long num;
        cin >> num;

        cnt += num - i;
    }

    if (cnt % 2 == 1)
    {
        cout << "ZZZ" << endl;
    } else {
        cout << "SSZ" << endl;
    }

    return 0;
}