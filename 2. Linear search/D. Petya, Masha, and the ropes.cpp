#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n, maxrope, sum;
    cin >> n;
    vector <int> ropes(n);
    for (int i = 0; i < n; ++i)
        cin >> ropes.at(i);
    
    maxrope = *max_element(ropes.begin(), ropes.end());
    sum = reduce(ropes.begin(), ropes.end());

    if (sum - maxrope < maxrope)
        cout << maxrope - (sum - maxrope) << endl;
    else
        cout << sum << endl;

    return 0;
}
