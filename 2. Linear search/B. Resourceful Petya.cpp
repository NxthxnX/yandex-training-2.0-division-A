#include <iostream>
#include <string>

using namespace std;

int main() {
    string x, z;
    getline(cin, x);
    getline(cin, z);

    int ans = 0;
    for (int i = z.length() - 1; i >= 0; --i) {
        int k = x.length() - 1;
        bool correct = true;
        for (int j = i; j >= 0; --j) {
            if (x.at(k) == z.at(j)) {
                k = (k + x.length() - 1) % x.length();
            }
            else {
                correct = false;
                break;
            }
        }
        if (correct) {
            ans = i + 1;
            break;
        }
    }

    cout << z.substr(ans) << endl;

    return 0;
}
