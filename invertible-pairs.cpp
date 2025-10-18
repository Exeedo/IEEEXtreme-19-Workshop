// Problem: https://csacademy.com/ieeextreme-practice/task/invertible-pairs
// Solution by: Osama Khallouf (Exeedo)

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
const int N = 200'005;

int dp[N][2];

int cal(int index, int started) {
    // 0 for not started, 1 for started
    if (index == n) {
        return 0;
    }
    int ans = dp[index][started];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    // calculate the best of 4 cases
    if (started == 0) {
        ans = max(ans, cal(index + 2, 0));
        ans = max(ans, cal(index + 2, 1) + abs(arr[index+1]));
    }
    ans = max(ans, cal(index + 2, 1) + abs(arr[index] + arr[index+1]));
    ans = max(ans, abs(arr[index]));
    
    dp[index][started] = ans;
    return ans;
}


int solve() {
    for(int i = 0; i < n; i++) {
        dp[i][0] = dp[i][1] = -1;
    }
    return cal(0, 0);
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        arr.resize(n);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        cout << solve() << endl;
    }
	return 0;
}
