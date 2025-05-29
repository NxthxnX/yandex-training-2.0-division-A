#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
	int xl, xr, y, type;
	Segment(int xl, int xr, int y, int type) : xl(xl), xr(xr), y(y), type(type) {}
	bool operator<(const Segment& segment) const {
		return y < segment.y;
	}
};

int main() {
	int n;
	long long ans = 0;
	cin >> n;
	vector <long long> x(2 * n);
	vector <Segment> y(2 * n, Segment(0, 0, 0, 0));
	for (int i = 0, x1, y1, x2, y2; i < n; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		x.at(2 * i) = x1;
		x.at(2 * i + 1) = x2;
		y.at(2 * i) = Segment(x1, x2, y1, -1);
		y.at(2 * i + 1) = Segment(x1, x2, y2, 1);
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	for (int i = 1; i < 2 * n; ++i) {
		long long count = 0, prev = 0;
		for (Segment yseg : y) {
			if (yseg.xr <= x.at(i - 1) || yseg.xl >= x.at(i))
				continue;
			if (count == 0)
				prev = yseg.y;
			count += yseg.type;
			if (count == 0)
				ans += (yseg.y - prev) * (x.at(i) - x.at(i - 1));
		}
	}

	cout << ans << endl;

	return 0;
}
