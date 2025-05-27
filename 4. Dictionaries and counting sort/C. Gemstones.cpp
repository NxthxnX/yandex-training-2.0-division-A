#include <iostream>
#include <string>
#include <set>
#include <array>
#include <ranges>

using namespace std;

int main() {
    int n, k;
    long long ans = 0;
    char a, b;
    string s;
    cin >> n >> k;
    cin.ignore();
    getline(cin, s);
    array <set <int>, 26 > pairs;
    array <long long, 26> count{};

    for (int i = 0; i < k; ++i) {
        a = getchar();
        b = getchar();
        cin.ignore();
        pairs.at(static_cast<int>(a - 'a')).insert(static_cast<int>(b - 'a'));
    }

    for (const char& c : ranges::reverse_view{ s }) {
        int charnum = static_cast<int>(c - 'a');
        for (int i = 0; i < 36; ++i)
            if (pairs.at(charnum).find(i) != pairs.at(charnum).end())
                ans += count.at(i);

        ++count.at(charnum);
    }

    cout << ans << endl;

    return 0;
}
