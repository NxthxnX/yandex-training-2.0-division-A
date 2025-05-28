#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int M, N;
	cin >> M >> N;
	vector <pair <int, int> > raindeer(M), elves(N);
	for (int i = 0, a; i < M; ++i) {
		cin >> a;
		raindeer.at(i) = make_pair(a, i);
	}
	for (int i = 0, b; i < N; ++i) {
		cin >> b;
		elves.at(i) = make_pair(b, i);
	}

	sort(raindeer.begin(), raindeer.end());
	sort(elves.begin(), elves.end());

	int l = 0, r = M + 1, m;
	while (r - l > 1) {
		m = (l + r) / 2;
		if (2 * m > N) {
			r = m;
			continue;
		}

		int ib = 0, jb = N - m, ia = 0, count = 0;
		while (jb < N) {
			while (ia < M && raindeer.at(ia).first <= elves.at(ib).first)
				++ia;
			if (ia == M || raindeer.at(ia).first >= elves.at(jb).first)
				break;

			++ib;
			++jb;
			++ia;
			++count;
		}

		if (count < m)
			r = m;
		else
			l = m;
	}

	vector <pair <int, pair <int, int> > > ans(l);

	int ib = 0, jb = N - l, ia = 0, count = 0;
	while (jb < N) {
		while (ia < M && raindeer.at(ia).first <= elves.at(ib).first)
			++ia;

		ans.at(ib) = make_pair(raindeer.at(ia).second, make_pair(elves.at(ib).second, elves.at(jb).second));
		++ib;
		++jb;
		++ia;
		++count;
	}

	cout << l << endl;
	for (const auto& [d, e] : ans) {
		cout << d + 1 << ' ' << e.first + 1 << ' ' << e.second + 1 << endl;
	}

	return 0;
}
