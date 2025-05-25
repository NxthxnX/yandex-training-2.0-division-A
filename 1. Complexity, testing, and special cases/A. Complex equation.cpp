#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0) {
        if (b == 0)
            cout << "INF" << endl;
        else
            cout << "NO" << endl;
    }
    else if (b % a == 0) {
        int x = -b / a;
        if (c * x + d)
            cout << x << endl;
        else
            cout << "NO" << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}
