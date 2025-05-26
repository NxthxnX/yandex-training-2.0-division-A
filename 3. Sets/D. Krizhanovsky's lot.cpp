#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, ansnum = 0, ansppl = -1;
    array <int, 102> count{};
    cin >> n;
    vector <int> score(n), nums(n);
    for (int i = 0; i < n; ++i)
        cin >> score.at(i);
    for (int i = 0; i < n - 1; ++i)
        cin >> nums.at(i);

    for (const int& number : nums)
        ++count.at(number);

    for (int i = 1; i <= 101; ++i) {
        ++count.at(i);
        nums.at(n - 1) = i;

        int minnum = -1, addscore = 0, winner = 0, lessppl = 0;
        for (int j = 1; j <= 101; ++j)
            if (count.at(j) == 1) {
                minnum = j;
                break;
            }

        if (minnum != -1) {
            winner = distance(nums.begin(), find(nums.begin(), nums.end(), minnum));
            addscore = minnum;
        }

        score.at(winner) += addscore;

        for (const int& personscore : score)
            if (personscore < score.at(n - 1))
                ++lessppl;

        if (lessppl > ansppl) {
            ansppl = lessppl;
            ansnum = i;
        }

        --count.at(i);
        score.at(winner) -= addscore;
    }

    cout << ansnum << endl;

    return 0;
}
