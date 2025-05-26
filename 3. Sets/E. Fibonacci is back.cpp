#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int n;
    string s;
    long long p = 274876858367; // a prime Carol number
    set <long long> fbnums;

    fbnums.insert(1);
    long long prevprev = 1, prev = 1, cur;
    // we consider f_40000 to have more than 5000 symbols (f_n ~~ 2^n)
    for (int i = 0; i < 40000; ++i) {
        cur = (prevprev + prev) % p;
        fbnums.insert(cur);
        prevprev = prev;
        prev = cur;
    }

    cin >> n;
    vector <string> ans(n);
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        getline(cin, s);

        long long modulo = 0;
        for (char c : s) {
            modulo = (modulo * 10 + static_cast<long long>(c - '0')) % p;
        }

        if (fbnums.find(modulo) != fbnums.end())
            ans.at(i) = "Yes";
        else
            ans.at(i) = "No";
    }

    copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, "\n"));

    return 0;
}
