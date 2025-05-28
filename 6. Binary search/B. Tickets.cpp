#include <iostream>

using namespace std;

int main() {
	long long a, b, c, x, k, m, sum;
	cin >> a >> b >> c >> x >> k;
	long long l = 0, r = x + 1;

	if (b + 1 <= x && (b + 1) * k <= x)
		l = b + 1;

	while (r - l > 1) {
		m = (l + r) / 2;
		sum = m * k * 100;
		if (a <= m && m <= b)
			sum += m * k * c;
		if (sum > x * 100)
			r = m;
		else
			l = m;
	}

	cout << l << endl;

	return 0;
}
