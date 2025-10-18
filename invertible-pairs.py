# Problem: https://csacademy.com/ieeextreme-practice/task/invertible-pairs
# Solution by: Osama Khallouf (Exeedo)

import sys
sys.setrecursionlimit(200050)

def cal(index, started, dp):
    # 0 for not started, 1 for started
    if index == n:
        return 0
    
    ans = dp[index][started]
    if ans != -1:
        return ans

    ans = 0
    # calculate the best of 4 cases
    if (started == 0):
        ans = max(ans, cal(index + 2, 0, dp))
        ans = max(ans, cal(index + 2, 1, dp) + abs(arr[index+1]))
    ans = max(ans, cal(index + 2, 1, dp) + abs(arr[index] + arr[index+1]))
    ans = max(ans, abs(arr[index]))
    
    dp[index][started] = ans
    return ans


def solve():
    dp = [[-1 for _ in range(2)] for x in range(n+1)]
    return cal(0, 0, dp)

t = int(input())
for _ in range(t):
    n = int(input())
    arr = [int(x) for x in input().split()]
    print(solve())
