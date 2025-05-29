#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Event {
	int id;
	int time;
	int stop_at;
	int type;
};

bool operator<(const Event& a, const Event& b);

int main() {
	int n, k, p;
	const int BUS = 1, PERSON = -1;
	set <Event> events;

	cin >> n >> k;
	vector <vector <int> > buses(k);
	vector <set <int> > awaiting(n, set <int>{});

	for (int i = 0, l; i < k; ++i) {
		cin >> l;
		for (int j = 0, a; j < l; ++j) {
			cin >> a;
			buses.at(i).push_back(a - 1);
		}
	}

	cin >> p;
	vector <vector <int> > people(p);
	vector <int> start(p), minutes(p, 0);
	vector <pair <int, int> > ans(p, pair <int, int>{});

	for (int i = 0, m; i < p; ++i) {
		cin >> start.at(i);
		--start.at(i);
		cin >> m;
		for (int j = 0, c; j < m; ++j) {
			cin >> c;
			people.at(i).push_back(c);
		}
	}

	for (int i = 0, l; i < k; ++i) {
	int time = 0;
		for (int j = 0; j < buses.at(i).size(); ++j) {
			Event cur;
			cur.id = i;
			cur.stop_at = buses.at(i).at(j);
			cur.time = time;
			cur.type = BUS;

			++time;
			events.insert(cur);
		}
	}

	for (int i = 0; i < p; ++i) {
		Event cur;
		cur.id = i;
		cur.stop_at = start.at(i);
		cur.time = 0;
		cur.type = PERSON;

		awaiting.at(cur.stop_at).insert(cur.id);
		events.insert(cur);
	}

	int noppl = 0;
	while (events.size()) {
		Event stop = *events.begin();
		if (stop.type == BUS) {
			int index = stop.time % buses.at(stop.id).size();
			for (const int& pplwaiting : awaiting.at(stop.stop_at)) {
				Event cur;
				cur.id = pplwaiting;
				cur.stop_at = buses.at(stop.id).at((index + people.at(pplwaiting).at(minutes.at(pplwaiting))) % buses.at(stop.id).size());
				cur.time = stop.time + people.at(pplwaiting).at(minutes.at(pplwaiting)) + 1;
				cur.type = PERSON;

				++minutes.at(pplwaiting);
				events.insert(cur);
			}
			awaiting.at(stop.stop_at).clear();

			Event next;
			next.id = stop.id;
			next.stop_at = buses.at(stop.id).at((index + 1) % buses.at(stop.id).size());
			next.time = stop.time + 1;
			next.type = BUS;
			events.insert(next);

			++noppl;
		}
		else if (stop.type == PERSON) {
			noppl = 0;
			if (minutes.at(stop.id) == people.at(stop.id).size())
				ans.at(stop.id) = make_pair(max(stop.time - 1, 0), stop.stop_at + 1);
			else
				awaiting.at(stop.stop_at).insert(stop.id);
		}

		events.erase(stop);

		if (noppl > 50 * 50 * 2)
			break;
	}

	for (const auto& [anstime, ansplace] : ans)
		cout << anstime << ' ' << ansplace << endl;

	return 0;
}

bool operator<(const Event& a, const Event& b) {
	if (a.time != b.time)
		return a.time < b.time;
	if (a.type != b.type)
		return a.type < b.type;
	return a.id < b.id;
}
