#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    
    cin >> n >> k;
    vector <long long> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b.at(i);

    const auto [bmin, bmax] = minmax_element(b.begin(), b.end());

    cout << *bmax - *bmin << endl;
    
    return 0;
}
