#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int nowblnce = 0;
	long long n, ans = 0;
	string s;
	getline(cin, s);
	n = s.length();
	vector <int> balance(n, 0);

	for (int i = 0; i < n; ++i) {
		if (s.at(i) == '(')
			++nowblnce;
		else if (s.at(i) == ')')
			--nowblnce;
		balance.at(i) = nowblnce;
	}

	ans += (n + 1) * (n + 2) / 2;

	long long l = 0, r = 0;
	while (r < n) {
		while (l < n && balance.at(l) == 0)
			++l;
		r = l;
		while (r < n && balance.at(r) != 0)
			++r;

		ans += (r - l) * (r - l + 1) / 2;
		l = r;
	}

	cout << ans << endl;

	return 0;
}
