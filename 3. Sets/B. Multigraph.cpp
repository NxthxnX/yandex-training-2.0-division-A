#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m, mnew = 0;
    set <pair <int, int> > graph;
    cin >> n >> m;
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        if (a == b)
            continue;
        if (b < a)
            swap(a, b);
        if (graph.find({ make_pair(a, b) }) != graph.end())
            continue;
        graph.insert({ make_pair(a, b) });
        ++mnew;
    }

    cout << n << ' ' << mnew << endl;
    for (const auto& [a, b] : graph)
        cout << a << ' ' << b << endl;

    return 0;
}
