#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main() {
    int n, v;
    const int INF = 5001;
    cin >> n >> v;
    vector <int> operation((n - 1) / 2 + 1), ischangeable((n - 1) / 2 + 1);
    vector <array <int, 2> > changes(n + 1);
    for (int i = 1, g, c; i <= (n - 1) / 2; ++i) {
        cin >> g >> c;
        operation.at(i) = g;
        ischangeable.at(i) = c;
    }
    for (int i = (n - 1) / 2 + 1, a; i <= n; ++i) {
        cin >> a;
        changes.at(i).at(a) = 0;
        changes.at(i).at(1 - a) = INF;
    }

    for (int i = (n - 1) / 2; i >= 1; --i) {
        int add;
        changes.at(i).at(0) = INF;
        changes.at(i).at(1) = INF;
        if (operation.at(i) == 0 || ischangeable.at(i) == 1) {
            add = 0;
            if (operation.at(i) == 1)
                ++add;
            changes.at(i).at(0) = changes.at(2 * i).at(0) + changes.at(2 * i + 1).at(0) + add;
            changes.at(i).at(1) = min(changes.at(2 * i).at(1), changes.at(2 * i + 1).at(1)) + add;
        }
        if (operation.at(i) == 1 || ischangeable.at(i) == 1) {
            add = 0;
            if (operation.at(i) == 0)
                ++add;
            changes.at(i).at(0) = min(min(changes.at(2 * i).at(0), changes.at(2 * i + 1).at(0)) + add, changes.at(i).at(0));
            changes.at(i).at(1) = min(changes.at(2 * i).at(1) + changes.at(2 * i + 1).at(1) + add, changes.at(i).at(1));
        }
    }

    if (changes.at(1).at(v) < INF)
        cout << changes.at(1).at(v) << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
