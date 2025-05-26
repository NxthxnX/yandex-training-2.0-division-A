#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    set <int> strikes;

    for (int i = 0, a, b; i < k; ++i) {
        cin >> a >> b;
        for (int j = a; j <= n; j += b)
            if (j % 7 != 6 && j % 7 != 0)
                strikes.insert(j);
    }

    cout << strikes.size() << endl;

    return 0;
}
