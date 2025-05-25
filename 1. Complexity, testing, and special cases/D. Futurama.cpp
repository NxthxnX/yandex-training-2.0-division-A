#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> souls(n);
    iota(souls.begin(), souls.end(), 0);

    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        swap(souls.at(a - 1), souls.at(b - 1));
    }

    for (int i = 0; i < n - 2; ++i) {
        if (i == souls.at(i))
            continue;

        int next = i;
        do {
            cout << next + 1 << ' ' << n - 1 << endl;
            swap(souls.at(next), souls.at(n - 2));

            next = souls.at(n - 2);

        } while (souls.at(next) != i);

        cout << next + 1 << ' ' << n << endl;
        swap(souls.at(next), souls.at(n - 1));

        cout << i + 1 << ' ' << n << endl;
        swap(souls.at(i), souls.at(n - 1));

        cout << next + 1 << ' ' << n - 1 << endl;
        swap(souls.at(next), souls.at(n - 2));
    }

    if (souls.at(n - 2) != n - 2) {
        cout << n - 1 << ' ' << n << endl;
        swap(souls.at(n - 2), souls.at(n - 1));
    }

    return 0;
}
