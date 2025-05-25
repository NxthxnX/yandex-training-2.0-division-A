#include <iostream>
#include <vector>

using namespace std;

int main() {
    bool acceptable = true;
    vector <vector <int> > xo(3, vector <int>(3));
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> xo.at(i).at(j);

    int numofx = 0, numofo = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (xo.at(i).at(j) == 1)
                ++numofx;
            else if (xo.at(i).at(j) == 2)
                ++numofo;

    int winx = 0, wino = 0;
    for (int i = 0; i < 3; ++i)
        if (xo.at(i).at(0) == xo.at(i).at(1) && xo.at(i).at(1) == xo.at(i).at(2)) {
            if (xo.at(i).at(0) == 1)
                ++winx;
            else if (xo.at(i).at(0) == 2)
                ++wino;
        }
    for (int i = 0; i < 3; ++i)
        if (xo.at(0).at(i) == xo.at(1).at(i) && xo.at(1).at(i) == xo.at(2).at(i)) {
            if (xo.at(0).at(i) == 1)
                ++winx;
            else if (xo.at(0).at(i) == 2)
                ++wino;
        }
    if (xo.at(0).at(0) == xo.at(1).at(1) && xo.at(1).at(1) == xo.at(2).at(2)) {
        if (xo.at(0).at(0) == 1)
            ++winx;
        else if (xo.at(0).at(0) == 2)
            ++wino;
    }
    if (xo.at(0).at(2) == xo.at(1).at(1) && xo.at(1).at(1) == xo.at(2).at(0)) {
        if (xo.at(0).at(2) == 1)
            ++winx;
        else if (xo.at(0).at(2) == 2)
            ++wino;
    }

    if (!(0 <= numofx - numofo && numofx - numofo <= 1))
        acceptable = false;
    if (winx && (wino || numofx == numofo) || wino && numofx > numofo)
        acceptable = false;

    cout << (acceptable ? "YES" : "NO") << endl;

    return 0;
}
