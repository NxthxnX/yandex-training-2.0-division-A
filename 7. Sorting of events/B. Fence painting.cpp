#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector <long long> friends(n);
	for (int i = 0; i < n; ++i)
		cin >> friends.at(i);

	sort(friends.begin(), friends.end());

	long long l = 0, r = friends.back() + 1, m;
	while (r - l > 1) {
		m = (l + r) / 2;

		long long painted = 0, cur;
		for (int i = 0; i < n; ++i)
			painted = max(friends.at(i), painted + m);
		
		if (painted > k || friends.at(0) < m)
			r = m;
		else
			l = m;
	}

	cout << l << endl;

	return 0;
}
