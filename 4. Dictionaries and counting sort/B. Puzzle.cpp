#include <iostream>
#include <cstdio>
#include <array>

using namespace std;

int main() {
    int n, m;
    string s, ans{};
    array <int, 26> letters{};

    char c;
    cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c = getchar();
            ++letters.at(static_cast<int>(c - 'A'));
        }
        cin.ignore();
    }

    for (int i = 0; i < m; ++i) {
        cin >> s;
        for (char ch : s)
            --letters.at(static_cast<int>(ch - 'A'));
    }

    for (int i = 0; i < 26; ++i)
        ans.append(letters.at(i), static_cast<char>(i + 'A'));

    cout << ans << endl;

    return 0;
}
