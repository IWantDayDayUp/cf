#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    long long n = a / b, m = a % b;

    cout << (n < m ? "niuniu eats more than others" : n == m ? "same" : "niuniu eats less than others") << endl;

    return 0;
}