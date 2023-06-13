#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int x = n % 5;

    cout << (x <= 2 ? n - x : n + (5 - x)) << endl;

    return 0;
}