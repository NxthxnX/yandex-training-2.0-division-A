#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iterator>

using namespace std;

struct Party {
	long long v;
	int p;
	int id;
};

bool compareParties(Party a, Party b);
long long votes(int i, long long cut, vector <Party>& parties, vector <long long>& suffixsum);

int main() {
	int n;
	long long ans{}, minsum = numeric_limits<long long>::max(), cursum = 0;
	cin >> n;
	vector <Party> parties(n);
	vector <long long> suffixsum(n);
	vector <long long> ansvotes(n);
	for (int i = 0; i < n; ++i) {
		cin >> parties.at(i).v >> parties.at(i).p;
		parties.at(i).id = i;
	}

	sort(parties.begin(), parties.end(), &compareParties);
	for (int i = n - 1; i >= 0; --i) {
		cursum += parties.at(i).v;
		suffixsum.at(i) = cursum;
	}

	for (int i = 0; i < n; ++i) {
		if (parties.at(i).p == -1)
			continue;

		int l = 0, r = 1000001, m;
		long long sum_i, curvote, not_in_need;
		while (r - l > 1) {
			m = (l + r) / 2;
			if (votes(i, m, parties, suffixsum) + parties.at(i).v > m)
				l = m;
			else
				r = m;
		}

		curvote = votes(i, l, parties, suffixsum);
		sum_i = curvote;
		if (curvote + parties.at(i).v > l + 2) {
			not_in_need = min(curvote + parties.at(i).v - (l + 2), curvote);
			sum_i -= not_in_need;
		}
		sum_i += parties.at(i).p;

		if (sum_i < minsum) {
			minsum = sum_i;
			ans = i;
		}
	}

	// getting the answer
	int l = 0, r = 1000001, m;
	long long sum_i, curvote, not_in_need;
	while (r - l > 1) {
		m = (l + r) / 2;
		if (votes(ans, m, parties, suffixsum) + parties.at(ans).v > m)
			l = m;
		else
			r = m;
	}
	curvote = votes(ans, l, parties, suffixsum);
	sum_i = curvote;
	for (int i = n - 1; i >= 0; --i) {
		if (parties.at(i).v < l)
			break;
		if (i == ans)
			continue;
		parties.at(i).v = l;
	}

	if (curvote + parties.at(ans).v > l + 2) {
		not_in_need = min(curvote + parties.at(ans).v - (l + 2), curvote);
		int takeback = 0, i = n - 1;
		while (takeback != not_in_need) {
			if (i == ans) {
				--i;
				continue;
			}
			++parties.at(i).v;
			--i;
			++takeback;
		}
		sum_i -= not_in_need;
	}
	parties.at(ans).v += sum_i;
	sum_i += parties.at(ans).p;

	for (const Party& a : parties)
		ansvotes.at(a.id) = a.v;

	cout << minsum << endl << parties.at(ans).id + 1 << endl;
	copy(ansvotes.begin(), ansvotes.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}

bool compareParties(Party a, Party b) {
	if (a.v != b.v)
		return a.v < b.v;
	return a.id < b.id;
}

long long votes(int i, long long cut, vector <Party>& parties, vector <long long>& suffixsum) {
	int l = -1, r = parties.size() - 1, m;
	long long curvotes = 0;
	while (r - l > 1) {
		m = (l + r) / 2;
		if (parties.at(m).v < cut)
			l = m;
		else
			r = m;
	}
	curvotes += suffixsum.at(r) - (parties.size() - r) * cut;
	if (i >= r)
		curvotes -= parties.at(i).v - cut;

	return curvotes;
}
