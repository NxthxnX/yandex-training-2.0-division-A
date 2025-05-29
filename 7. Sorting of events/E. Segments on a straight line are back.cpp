#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iterator>

using namespace std;

struct Segment {
	int a, b, id;
	bool operator<(const Segment& segment) const {
		if (b != segment.b)
			return b < segment.b;
		return a > segment.a;
	}
};

int main() {
	int n;
	cin >> n;
	vector <Segment> lines(n);
	vector <int> ans(n, 0);
	for (int i = 0, a, b; i < n; ++i) {
		Segment l;
		cin >> a >> b;
		l.a = a;
		l.b = b;
		l.id = i;
		lines.at(i) = l;
	}

	sort(lines.begin(), lines.end());

	stack <Segment> curlines;
	for (const Segment& seg : lines) {
		while (curlines.size() && curlines.top().a >= seg.a) {
			Segment instack = curlines.top();
			curlines.pop();
			ans.at(instack.id) = seg.id + 1;
		}
		
		curlines.push(seg);
	}

	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
