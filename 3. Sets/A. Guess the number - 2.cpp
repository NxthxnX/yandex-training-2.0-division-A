#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int n, a, suitsize;
    string s;
    stringstream ss;
    cin >> n;
    cin.ignore();
    set <int> unsuitable, guessed, diff, everything, ansset;
    vector <string> ans;

    for (int i = 1; i <= n; ++i)
        everything.insert(i);

    while (getline(cin, s) && s != "HELP") {
        ss << s;
        while (ss >> a)
            guessed.insert(a);
        ss.str(string{});
        ss.clear();
        set_difference(guessed.begin(), guessed.end(), unsuitable.begin(), unsuitable.end(), inserter(diff, diff.end()));
        suitsize = n - unsuitable.size();
        if (diff.size() > suitsize / 2) {
            diff.clear();
            set_difference(everything.begin(), everything.end(), guessed.begin(), guessed.end(), inserter(diff, diff.end()));
            unsuitable.insert(diff.begin(), diff.end());

            ans.push_back("YES");
        }
        else {
            unsuitable.insert(diff.begin(), diff.end());

            ans.push_back("NO");
        }

        diff.clear();
        guessed.clear();
    }

    set_difference(everything.begin(), everything.end(), unsuitable.begin(), unsuitable.end(), inserter(ansset, ansset.end()));

    copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, "\n"));
    copy(ansset.begin(), ansset.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
