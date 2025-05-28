#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
	int N, M, R, maxscore = 0;
	unordered_map <int, set <pair <int, bool> > > students;
	cin >> N >> M >> R;

	for (int i = 0, id, region, score, medalist; i < N; ++i) {
		cin >> id >> region >> score >> medalist;
		if (students.find(region) == students.end())
			students.insert({ region, set <pair <int, bool> > {} });
		students.at(region).insert(make_pair(score, static_cast<bool>(medalist)));
		maxscore = max(score, maxscore);
	}
	int l = -1, r = maxscore + 1, m;
	while (r - l > 1) {
		m = (l + r) / 2;
		int sum = 0;
		for (const auto& [region, result] : students) {
			int sum_i = 0;
			for (const auto& [score, medalist] : result)
				if (medalist || score >= m)
					++sum_i;
			if (sum_i == 0)
				++sum_i;
			sum += sum_i;
		}

		if (sum > M)
			l = m;
		else
			r = m;
	}
	
	cout << r << endl;

	return 0;
}
