#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <string> ans(n);

    for (int i = 0; i < n; ++i) {
        array <int, 4> x, y;
        array <array <int, 4>, 4> length;
        array <int, 3> points{ 2, 3, 4 };
        for (int j = 0; j < 4; ++j)
            cin >> x.at(j) >> y.at(j);
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                length.at(j).at(k) = \
                (x.at(j) - x.at(k)) * (x.at(j) - x.at(k)) + \
                (y.at(j) - y.at(k)) * (y.at(j) - y.at(k));

        bool isparallel = false;
        for (int j = 0; j < 3; ++j) {
            int p1 = j + 1, p2 = (j + 1) % 3 + 1, p3 = (j + 2) % 3 + 1;
            if (length.at(0).at(p1) == length.at(p2).at(p3) && \
                (x.at(0) - x.at(p1)) * (y.at(p2) - y.at(p3)) == \
                (x.at(p2) - x.at(p3)) * (y.at(0) - y.at(p1)))
                isparallel = true;
        }

        ans.at(i) = isparallel ? "YES" : "NO";
    }

    copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, "\n"));

    return 0;
}
