#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void length(int prev, int cur, const vector <set <int> >& cities, vector <int>& lendown);
void remoteness(int prev, int prevprev, int cur, const vector <set <int> >& cities, vector <int>& lendown, vector <int>& lenup);

int main() {
    int n;
    const int ROOT = 0;
    cin >> n;

    vector <set <int> > cities(n);
    vector <int> lendown(n, 0), lenup(n, 0), remote(n, 0);

    for (int i = 0; i < n - 1; ++i) {
        int child, parent;
        cin >> child >> parent;
        cities.at(child - 1).insert(parent - 1);
        cities.at(parent - 1).insert(child - 1);
    }

    length(-1, ROOT, cities, lendown);
    remoteness(-1, -1, ROOT, cities, lendown, lenup);

    int minlen, count = 0;
    for (int i = 0; i < n; ++i)
        remote.at(i) = max(lendown.at(i), lenup.at(i));
    minlen = *min_element(remote.begin(), remote.end());
    for (const int& a : remote)
        if (a == minlen)
            ++count;

    cout << minlen << ' ' << count << ' ';


    for (int i = 0; i < n; ++i)
        if (remote.at(i) == minlen)
            cout << i + 1 << ' ';
    cout << endl;

    return 0;
}

void length(int prev, int cur, const vector <set <int> >& cities, vector <int>& lendown) {
    if (prev == -1) {
        for (const int& child : cities.at(cur)) {
            length(cur, child, cities, lendown);
        }
        for (const int& child : cities.at(cur)) {
            lendown.at(cur) = max(lendown.at(child) + 1, lendown.at(cur));
        }
    }
    else {
        lendown.at(cur) = 0;
        for (const int& child : cities.at(cur)) {
            if (child == prev)
                continue;
            length(cur, child, cities, lendown);
            lendown.at(cur) = max(lendown.at(child) + 1, lendown.at(cur));
        }
    }
}

void remoteness(int prev, int prevprev, int cur, const vector <set <int> >& cities, vector <int>& lendown, vector <int>& lenup) {
    if (prev == -1) {
        lenup.at(cur) = 0;
        for (const int& child : cities.at(cur)) {
            remoteness(cur, prev, child, cities, lendown, lenup);
        }
    }
    else {
        int maxlen = 0;
        for (const int& child : cities.at(prev)) {
            if (child == cur || child == prevprev)
                continue;
            maxlen = max(lendown.at(child) + 1, maxlen);
        }
        lenup.at(cur) = max(lenup.at(prev), maxlen) + 1;
        for (const int& child : cities.at(cur)) {
            if (child == prev)
                continue;
            remoteness(cur, prev, child, cities, lendown, lenup);
        }
    }
}
