#include <iostream>

using namespace std;

int main() {
    int p, A, B, C, a, b, c;
    cin >> p;
    A = p / 3;
    B = (p - A) / 2;
    C = p - A - B;
    a = (p + 1) % 2 + 1;
    b = (p - a) / 2;
    c = b;

    if (p == 4)
        cout << -1 << endl;
    else {
        cout << A << ' ' << B << ' ' << C << endl;
        cout << a << ' ' << b << ' ' << c << endl;
    }

    return 0;
}
