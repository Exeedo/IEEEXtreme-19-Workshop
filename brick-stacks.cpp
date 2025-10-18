// Problem: https://csacademy.com/ieeextreme-practice/task/brick-stacks
// Solution by: Osama Khallouf (Exeedo)

#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> arr;
vector<vector<int>> stacks;

void print_ans() {
    cout << stacks.size() << endl;
    for (auto &stack : stacks) {
        cout << stack.size() << " ";
        for (auto element : stack) {
            cout << element << " ";
        }
        cout << endl;
    }
}

bool test(int s) {
    // can we divide the bricks into s stacks?
    for (int i =0 ; i+s < n; i++) {
        if (arr[i] - arr[i+s] < x){
            return false;
        }
    }
    return true;
}

void distribute(int s) {
    // distribute bricks into s stacks
    stacks.resize(s);
    for (int i =0; i < n; i++) {
        stacks[i % s].push_back(arr[i]);
    }
}

void solve() {
    sort(arr.rbegin(), arr.rend());
    int l = 1, r = n;
    int md;
    int s;
    while (l <= r) {
        md = (r+l) / 2;
        if (test(md)) {
            s = md;
            r = md - 1;
        } else {
            l = md + 1;
        }
    }
    distribute(s);
    print_ans();
}

int main()
{
    cin >> n >> x;
    arr.resize(n);
    for(int &number : arr) cin >> number;
    solve();
	return 0;
}
