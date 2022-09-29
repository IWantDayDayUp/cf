#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; ; i++) {
        for (int j = 1; j < i; j++) {
            long long x, y;
            std::cout << "? " << i << " " << j << std::endl;
            std::cin >> x;
            std::cout << "? " << j << " " << i << std::endl;
            std::cin >> y;
            if (x == -1 || y == -1) {
                std::cout << "! " << i - 1 << std::endl;
                return 0;
            }
            if (x != y) {
                std::cout << "! " << x + y << std::endl;
                return 0;
            }
        }
    }

    return 0;
}