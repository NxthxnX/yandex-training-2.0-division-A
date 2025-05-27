#include <iostream>
#include <string>
#include <array>

using namespace std;

int main() {
    string a, b, ans{};
    getline(cin, a);
    getline(cin, b);
    array <int, 10> acount{}, bcount{}, anscount{};

    for (const char& c : a)
        ++acount.at(static_cast<int>(c - '0'));
    for (const char& c : b)
        ++bcount.at(static_cast<int>(c - '0'));

    for (int i = 0; i < 10; ++i)
        anscount.at(i) = min(acount.at(i), bcount.at(i));

    for (int i = 9; i >= 0; --i)
        ans.append(anscount.at(i), static_cast<char>(i + '0'));

    bool nonzero = false;
    for (int i = 1; i < 10; ++i)
        if (anscount.at(i))
            nonzero = true;

    if (ans.empty())
        cout << -1 << endl;
    else if (!nonzero)
        cout << 0 << endl;
    else
        cout << ans << endl;

    return 0;
}
