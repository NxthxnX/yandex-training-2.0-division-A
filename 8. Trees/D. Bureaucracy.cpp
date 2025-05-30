#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

void subcnt(int prev, int cur, const vector <set <int> >& subordinates, vector <int>& subcount);
void money(int prev, int cur, const vector <set <int> >& subordinates, vector <int>& subcount, vector <long long>& sum);

int main() {
    int n, ans = 0;
    cin >> n;
    vector <int> subcount(n, 0);
    vector <long long> sum(n);
    vector <set <int> > subordinates(n);
    for (int i = 1, a; i < n; ++i) {
        cin >> a;
        subordinates.at(a - 1).insert(i);
    }

    subcnt(-1, 0, subordinates, subcount);
    money(-1, 0, subordinates, subcount, sum);

    copy(sum.begin(), sum.end(), ostream_iterator<long long>(cout, " "));
    cout << endl;

    return 0;
}

void subcnt(int prev, int cur, const vector <set <int> >& subordinates, vector <int>& subcount) {
    for (const int& child : subordinates.at(cur)) {
        if (child == prev)
            continue;
        subcnt(cur, child, subordinates, subcount);
    }
    subcount.at(cur) = 0;
    for (const int& child : subordinates.at(cur)) {
        if (child == prev)
            continue;
        subcount.at(cur) += subcount.at(child) + 1;
    }
}

void money(int prev, int cur, const vector <set <int> >& subordinates, vector <int>& subcount, vector <long long>& sum) {
    for (const int& child : subordinates.at(cur)) {
        if (child == prev)
            continue;
        money(cur, child, subordinates, subcount, sum);
    }
    sum.at(cur) = 1;
    for (const int& child : subordinates.at(cur)) {
        if (child == prev)
            continue;
        sum.at(cur) += sum.at(child) + subcount.at(child) + 1;
    }
}
