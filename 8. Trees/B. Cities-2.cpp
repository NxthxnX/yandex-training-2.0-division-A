#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void subcities(int prev, int cur, const vector <set <int> >& cities, vector <int>& subcount);
long long rootremoteness(int prev, int cur, const vector <set <int> >& cities, vector <int>& subcount);
void remoteness(int prev, int cur, const vector <set <int> >& cities, vector <int>& subcount, vector <long long>& remote);

int main() {
    int n;
    const int ROOT = 0;
    cin >> n;

    vector <set <int> > cities(n);
    vector <long long> remote(n, 0);
    vector <int> subcount(n, 0);

    for (int i = 0; i < n - 1; ++i) {
        int child, parent;
        cin >> child >> parent;
        cities.at(child - 1).insert(parent - 1);
        cities.at(parent - 1).insert(child - 1);
    }

    subcities(-1, ROOT, cities, subcount);
    remote.at(ROOT) = rootremoteness(-1, ROOT, cities, subcount);
    remoteness(-1, ROOT, cities, subcount, remote);

    long long minlen;
    int count = 0;
    minlen = *min_element(remote.begin(), remote.end());
    for (const long long& a : remote)
        if (a == minlen)
            ++count;

    cout << minlen << ' ' << count << ' ';


    for (int i = 0; i < n; ++i)
        if (remote.at(i) == minlen)
            cout << i + 1 << ' ';
    cout << endl;

    return 0;
}

void subcities(int prev, int cur, const vector <set <int> >& cities, vector <int>& subcount) {
    for (const int& child : cities.at(cur)) {
        if (child == prev)
            continue;
        subcities(cur, child, cities, subcount);
    }
    subcount.at(cur) = 0;
    for (const int& child : cities.at(cur)) {
        if (child == prev)
            continue;
        subcount.at(cur) += subcount.at(child) + 1;
    }
}

long long rootremoteness(int prev, int cur, const vector <set <int> >& cities, vector <int>& subcount) {
    long long ans = 0;
    for (const int& child : cities.at(cur)) {
        if (child == prev)
            continue;
        ans += rootremoteness(cur, child, cities, subcount) + subcount.at(child) + 1;
    }
    return ans;
}

void remoteness(int prev, int cur, const vector <set <int> >& cities, vector <int>& subcount, vector <long long>& remote) {
    if (prev != -1) {
        int n = remote.size();
        remote.at(cur) = remote.at(prev) - subcount.at(cur) + (n - subcount.at(cur) - 2);
    }
    for (const int& child : cities.at(cur)) {
        if (child == prev)
            continue;
        remoteness(cur, child, cities, subcount, remote);
    }
}
