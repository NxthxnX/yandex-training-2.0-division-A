#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <limits>

using namespace std;

struct Event {
	int id, time, type;
	bool operator<(Event a) {
		if (time != a.time)
			return time < a.time;
		return type < a.type;
	}
};

int main() {
	int n, ansmin = numeric_limits<int>::max();
	pair <int, int> anspair{};
	const int CLOSE = -1, OPEN = 1;
	cin >> n;
	vector <Event> civil(2 * n);
	Event c;
	for (int i = 0, s, e; i < n; ++i) {
		cin >> s >> e;
		c.id = i + 1;
		c.time = s;
		c.type = OPEN;
		civil.at(2 * i) = c;
		c.time = e;
		c.type = CLOSE;
		civil.at(2 * i + 1) = c;
	}

	sort(civil.begin(), civil.end());

	int prevt, previ;
	set <int> curcivil;
	for (const Event& c : civil) {
		if (c.type == OPEN) {
			curcivil.insert(c.id);

			prevt = c.time;
			previ = c.id;
		}
		else if (c.type == CLOSE) {
			curcivil.erase(c.id);

			if (curcivil.empty())
				continue;

			if (c.time - prevt < ansmin) {
				ansmin = c.time - prevt;
				anspair.first = c.id;
				if (previ == c.id)
					anspair.second = *curcivil.begin();
				else
					anspair.second = previ;
				if (anspair.first > anspair.second)
					swap(anspair.first, anspair.second);
			}
		}
	}

	if (ansmin == numeric_limits<int>::max())
		cout << 0 << endl;
	else
		cout << anspair.first << ' ' << anspair.second << endl;

	return 0;
}
