#include <iostream>
#include <array>

using namespace std;

int main() {
    int n;
    array <array <int, 10>, 10> chess{};

    cin >> n;
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        chess.at(x).at(y) = 1;
    }

    int p = 0;

    for (int i = 1; i < 9; ++i)
        for (int j = 1; j < 9; ++j)
            if (chess.at(i).at(j) == 1) {
                int sum = 0;
                sum += chess.at(i - 1).at(j);
                sum += chess.at(i).at(j - 1);
                sum += chess.at(i + 1).at(j);
                sum += chess.at(i).at(j + 1);
                p += 4 - sum;
            }

    cout << p << endl;

    return 0;
}
