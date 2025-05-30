#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    vector <int> banks(n), mark(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> banks.at(i);

    for (int i = 0; i < n; ++i)
        if (!mark.at(i)) {
            int num = i;
            while (!mark.at(num)) {
                mark.at(num) = i + 1;
                num = banks.at(num) - 1;
            }
            if (mark.at(num) == mark.at(i))
                ++ans;
        }

    cout << ans << endl;

    return 0;
}
