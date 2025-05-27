#include <iostream>
#include <vector>

using namespace std;

int main() {
	int k, n = 0;
	cin >> k;
	vector <pair <int, int> > input(k);
	for (int i = 0; i < k; ++i) {
		cin >> input.at(i).first >> input.at(i).second;
		n += input.at(i).second;
	}

	int i = 0, j = n - 1, ik = 0, jk = k - 1, ii = 0, jj = 0;
	long long candyleft = input.at(0).first, candyright = input.at(k - 1).first, addleft = 0, addright = 0;
	while (j - i > 1) {
		if (candyleft < candyright) {
			candyright -= candyleft;
			addright += candyleft;
			++i;
			++ii;
			if (input.at(ik).second == ii) {
				ii = 0;
				++ik;
			}
			candyleft += input.at(ik).first + addleft;
			addleft = 0;
		}
		else if (candyleft > candyright) {
			candyleft -= candyright;
			addleft += candyright;
			--j;
			++jj;
			if (input.at(jk).second == jj) {
				jj = 0;
				--jk;
			}
			candyright += input.at(jk).first + addright;
			addright = 0;
		}
		else {
			++i;
			++ii;
			if (input.at(ik).second == ii) {
				ii = 0;
				++ik;
			}
			candyleft += input.at(ik).first + addleft;
			addleft = 0;

			--j;
			++jj;
			if (input.at(jk).second == jj) {
				jj = 0;
				--jk;
			}
			candyright += input.at(jk).first + addright;
			addright = 0;
		}
	}

	if (i == j)
		cout << 1 << endl << candyleft + candyright - input.at(ik).first << endl;
	else
		cout << 2 << endl << candyleft + addright << ' ' << candyright + addleft << endl;

	return 0;
}
