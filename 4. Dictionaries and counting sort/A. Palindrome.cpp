#include <iostream>
#include <cstdio>
#include <array>

using namespace std;

int main() {
    int n, firsthalf;
    string ans{};
    array <int, 26> letters{};

    char c;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        c = getchar();
        ++letters.at(static_cast<int>(c - 'A'));
    }

    for (int i = 0; i < 26; ++i)
        ans.append(letters.at(i) / 2, static_cast<char>(i + 'A'));

    firsthalf = ans.length();

    for (int i = 0; i < 26; ++i)
        if (letters.at(i) % 2) {
            ans += static_cast<char>(i + 'A');
            break;
        }

    for (int i = firsthalf - 1; i >= 0; --i)
        ans += ans.at(i);

    cout << ans << endl;

    return 0;
}
