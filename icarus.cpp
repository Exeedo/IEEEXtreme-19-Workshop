// Problem: https://csacademy.com/ieeextreme-practice/task/icarus
// Solution by: Osama Khallouf (Exeedo)

#include <bits/stdc++.h>
using namespace std;

string moves;

void solve() {
    int count_r = 0, count_u = 0;
    for (char move : moves) {
        if(move == 'R') {
            count_r++;
        }
        if (move == 'U') {
            count_u++;
        }
    }
    int n = max(count_u, count_r) + 1;
    if (count_u == 0 || count_r == 0) {
        n = 2;
    }
    int start = 1;
    int end = n;
    if (count_r >= count_u) {
        start = n;
        end = 1;
    }
    cout << n << ' ' << start << ' ' << end << endl;
    for (int i = 1; i < n; i++) {
        cout << "0 " << i + 1 << endl;
    }
    cout << "0 0\n";
}

int main()
{
    cin >> moves;
    solve();
	return 0;
}

