# Problem: https://csacademy.com/ieeextreme-practice/task/icarus
# Solution by: Osama Khallouf (Exeedo)

import sys
import heapq

def no_sol():
    print(-1)
    sys.exit(0)

def dfs(u):
    vis[u] = 1
    for v in adj[u]:
        if vis[v] == 1:
            no_sol()
        if vis[v] == 0:
            dfs(v)
    vis[u] = 2

def solve():
    for i in range(1, n+1):
        if vis[i] == 0:
            dfs(i)

    min_heap = []
    for node in range(1, n+1):
        if not adj[node]:
            heapq.heappush(min_heap, (group_id[node], node))

    while min_heap:
        _, u = heapq.heappop(min_heap)
        print(u, end=' ')
        for v in rev_adj[u]:
            adj[v].remove(u)
            if not adj[v]:
                heapq.heappush(min_heap, (group_id[v], v))

n, m = [int(x) for x in input().split()]
group_id = [0] + [int(x) for x in input().split()]

adj = [set() for _ in range(n+1)]
rev_adj = [set() for _ in range(n+1)]
for _ in range(m):
    a, b = [int(x) for x in input().split()]
    adj[b].add(a)
    rev_adj[a].add(b)

vis = [0 for _ in range(n+1)]

solve()
