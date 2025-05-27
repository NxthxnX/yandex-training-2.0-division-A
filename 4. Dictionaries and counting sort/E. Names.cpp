#include <iostream>
#include <string>
#include <array>

using namespace std;

int main() {
    string x, y, ans{};
    getline(cin, x);
    getline(cin, y);
    array <int, 26> xletters{}, yletters{};

    for (const char& c : x)
        ++xletters.at(static_cast<int>(c - 'a'));
    for (const char& c : y)
        ++yletters.at(static_cast<int>(c - 'a'));

    int numoflttrs, xcurpos = 0, ycurpos = 0, crossedout;
    for (int i = 25; i >= 0; --i) {
        if (!xletters.at(i) || !yletters.at(i))
            continue;

        numoflttrs = min(xletters.at(i), yletters.at(i));

        crossedout = 0;
        do {
            --xletters.at(static_cast<int>(x.at(xcurpos) - 'a'));
            if (static_cast<int>(x.at(xcurpos) - 'a') == i)
                ++crossedout;
            ++xcurpos;
        } while (crossedout != numoflttrs);

        crossedout = 0;
        do {
            --yletters.at(static_cast<int>(y.at(ycurpos) - 'a'));
            if (static_cast<int>(y.at(ycurpos) - 'a') == i)
                ++crossedout;
            ++ycurpos;
        } while (crossedout != numoflttrs);

        ans.append(numoflttrs, static_cast<char>(i + 'a'));
    }

    cout << ans << endl;

    return 0;
}
