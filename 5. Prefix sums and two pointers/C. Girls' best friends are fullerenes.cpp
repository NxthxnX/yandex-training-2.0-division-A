#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	long long ans = 0;
	cin >> n;
	vector <long long> len(n);
	for (int i = 0; i < n; ++i)
		cin >> len.at(i);

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1, kmin = j + 1, kmax = j + 1; j < n; ++j) {
			while (kmax < n && len.at(i) + len.at(j) > len.at(kmax))
				++kmax;
			while (kmin < n && len.at(i) * len.at(i) + len.at(j) * len.at(j) >= len.at(kmin) * len.at(kmin))
				++kmin;

			ans += kmax - kmin;
		}
	}

	cout << ans << endl;

	return 0;
}
