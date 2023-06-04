#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int num = to_string(n).size();
    if (num > 3)
    {
        num -= 3;
        // cout << num << endl;
        n -= n % (int)pow(10, num);
    }

    cout << n << endl;

    return 0;
}