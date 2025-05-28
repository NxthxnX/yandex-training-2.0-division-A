#include <iostream>
#include <array>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <numeric>
#include <ranges>

using namespace std;

int main() {
	int n;
	long long ans = 0;
	array <int, 26> lttrcount{};
	map <pair <char, char>, set <pair <long long, long long> > > characters{};
	vector <pair <char, int> > str;
	string s;
	getline(cin, s);
	n = s.length();
	int l = 0, r = 0;
	while (l < n) {
		while (r < n && s.at(r) == s.at(l))
			++r;
		str.push_back(make_pair(s.at(l), r - l));
		l = r;
	}
	
	for (const auto& [c, count] : str) {
		int integer = static_cast<int>(c - 'a');
		lttrcount.at(integer) = max(count, lttrcount.at(integer));
	}

	ans += reduce(lttrcount.begin(), lttrcount.end());

	for (int i = 0; i < str.size() - 1; ++i) {
		pair <char, char> cur = make_pair(str.at(i).first, str.at(i + 1).first);
		if (characters.find(cur) == characters.end())
			characters.insert({ cur, set <pair <long long, long long> > {} });
		characters.at(cur).insert({ str.at(i).second, str.at(i + 1).second });
	}
	
	for (const auto& [chpair, chset] : characters) {
		long long bmax = 0;
		for (const auto& [a, b] : ranges::reverse_view{ chset }) {
			if (b > bmax) {
				ans += (b - bmax) * a;
				bmax = b;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
