// Problem: https://csacademy.com/ieeextreme-practice/task/sierpinski
// Solution by: Osama Khallouf (Exeedo)

#include <bits/stdc++.h>
using namespace std;

// 1 << x -> 2^x
int solve(int x, int y, int step=30) {
    int size = 3 * (1 << (step-1));
    int half = size >> 1;
    if (x == size) {
        return 0;
    }
    if (step == 1) {
        return 1;
    }
    // T1
    if (x <= half) {
        return solve(x, y, step - 1);
    }
    // T3
    if (y > half) {
        return solve(x-half, y-half, step - 1);
    }
    
    // T2
    if (x - y >= half) {
        return solve(x-half, y, step - 1);
    }
    
    return 0;
}

int main()
{
    int q, x, y;
    cin >> q;
    while (q--) {
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }
	return 0;
}
