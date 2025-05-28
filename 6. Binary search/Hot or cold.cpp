#include <iostream>

using namespace std;

int main() {
	int lx = 0, rx = 1000000001, ly = 0, ry = 1000000001, mx{}, prevx{}, my{}, prevy{}, ans;

	cout << rx - 1 << ' ' << ry - 1 << endl;
	cout.flush();
	cin >> ans;
	prevx = rx - 1;
	prevy = ry - 1;

	while (rx - lx > 1) {
		mx = (lx + rx) / 2;

		cout << mx - 1 << ' ' << ry - 1 << endl;
		cout.flush();
		cin >> ans;
		cout << mx << ' ' << ry - 1 << endl;
		cout.flush();
		cin >> ans;
		if (ans == 1) {
			lx = mx;
		}
		else if (ans == 0) {
			rx = mx;
		}
		else
			break;
	}


	while (ry - ly > 1) {
		my = (ly + ry) / 2;

		cout << lx << ' ' << my - 1 << endl;
		cout.flush();
		cin >> ans;
		cout << lx << ' ' << my << endl;
		cout.flush();
		cin >> ans;
		if (ans == 1) {
			ly = my;
		}
		else if (ans == 0) {
			ry = my;
		}
		else
			break;
	}

	cout << "A " << lx << ' ' << ly << endl;
	cout.flush();

	return 0;
}
