#include <iostream>
#include <vector>
#include <array>
#include <limits>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	array <vector <int>, 4> clothes;
	array <int, 4> n, index{}, minel{};

	for (int i = 0; i < 4; ++i) {
		cin >> n.at(i);
		for (int j = 0, el; j < n.at(i); ++j) {
			cin >> el;
			clothes.at(i).push_back(el);
		}
	}

	for (int i = 0; i < 4; ++i)
		sort(clothes.at(i).begin(), clothes.at(i).end());

	int mindiff = numeric_limits<int>::max(), maxcolor, mincolor, maxindex, minindex;

	bool gonext = true;
	while (gonext) {
		maxcolor = numeric_limits<int>::min();
		mincolor = numeric_limits<int>::max();
		for (int i = 0; i < 4; ++i) {
			if (maxcolor < clothes.at(i).at(index.at(i))) {
				maxcolor = clothes.at(i).at(index.at(i));
				maxindex = i;
			}
			if (mincolor > clothes.at(i).at(index.at(i))) {
				mincolor = clothes.at(i).at(index.at(i));
				minindex = i;
			}
		}
		
		if (maxcolor - mincolor < mindiff) {
			mindiff = maxcolor - mincolor;
			for (int i = 0; i < 4; ++i)
				minel.at(i) = clothes.at(i).at(index.at(i));
		}

		++index.at(minindex);

		for (int i = 0; i < 4; ++i)
			if (index.at(i) >= n.at(i))
				gonext = false;
	}

	copy(minel.begin(), minel.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
