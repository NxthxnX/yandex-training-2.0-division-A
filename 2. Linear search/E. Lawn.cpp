#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long x1, y1, x2, y2, x3, y3, r, ans = 0;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r;
    for (long long y = max(y1, y3 - r); y <= min(y2, y3 + r); ++y) {
        long long dx = static_cast<long long>(floor(sqrt(r * r - (y - y3) * (y - y3))));
        ans += max(0ll, min(x2, x3 + dx) - max(x1, x3 - dx) + 1);
    }

    cout << ans << endl;

    return 0;
}
